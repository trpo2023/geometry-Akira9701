APP_NAME = geometry
LIB_NAME = libgeometry
TEST_NAME = main_test

TESTFLAGS = -I thirdparty
CFLAGS = -Wall -Werror -I src
DEPSFLAGS = -MMD
CC = g++

BIN_DIR = bin
OBJ_DIR = obj
SRC_DIR = src
TEST_DIR = test

APP_PATH = $(BIN_DIR)/$(APP_NAME)
LIB_PATH = $(OBJ_DIR)/$(SRC_DIR)/$(LIB_NAME)/$(LIB_NAME).a
TEST_PATH = $(BIN_DIR)/$(TEST_NAME)

APP_SOURCES = $(wildcard $(SRC_DIR)/$(APP_NAME)/*.cpp)
APP_OBJECTS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(APP_SOURCES))

LIB_SOURCES = $(wildcard $(SRC_DIR)/$(LIB_NAME)/*.cpp)
LIB_OBJECTS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(LIB_SOURCES))

TEST_SOURCES = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJECTS = $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(TEST_SOURCES))

DEPS = $(APP_OBJECTS:.o=.d) $(LIB_OBJECTS:.o=.d) $(TEST_OBJECTS:.o=.d)

.PHONY: all test clean
all: $(APP_PATH)

-include $(DEPS)

# BUILD
$(APP_PATH): $(APP_OBJECTS) $(LIB_PATH)
	$(CC) $(CFLAGS) -o $@ $^ 

$(LIB_PATH): $(LIB_OBJECTS)
	ar rcs $@ $^

$(OBJ_DIR)/%.o: %.cpp
	$(CC) $(CFLAGS) $(DEPSFLAGS) -c -o $@ $< 

# TEST
test: $(LIB_PATH) $(TEST_PATH)
	$(TEST_PATH)

$(TEST_PATH): $(TEST_OBJECTS) $(LIB_PATH)
	$(CC) $(TESTFLAGS) $(CFLAGS) $(DEPSFLAGS) -o $@ $^ 

$(OBJ_DIR)/test/main.o: test/main.cpp
	$(CC) $(TESTFLAGS) $(CFLAGS) $(DEPSFLAGS) -c -o $@ $<

$(OBJ_DIR)/test/tests.o: test/tests.cpp
	$(CC) $(TESTFLAGS) $(CFLAGS) $(DEPSFLAGS) -c -o $@ $<

# RUN
run: all
	$(APP_PATH) $(BIN_DIR)/test.txt

# CLEAN
clean:
	$(RM) $(APP_PATH) $(TEST_PATH) $(OBJ_DIR)/*/*/*.[aod] $(OBJ_DIR)/test/*.[aod]