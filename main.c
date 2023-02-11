#include <errno.h>
#include <stdio.h>
#include <string.h>

#define LEN 100

int main() {
  char str[LEN];
  FILE *file;
  int countItem = 1;
  file = fopen("data.txt", "r");
  if (file != NULL) {
    while (fgets(str, LEN, file)) {
      int count = 0;
      char value[10];
      int validateStaus = 0;
      int skobCount = 0;
      int findNameStatus = 0;
      for (size_t i = 0; i < LEN; i++) {
        if (str[i] != '(' && findNameStatus == 0) {
          count++;
          value[i] = str[i];
        } else {
          findNameStatus = 1;
          break;
        }
      }
      if (strcmp(value, "triangle") == 0) {
        printf("%d. ", countItem);
        countItem++;
        for (int i = 0; i < 10; i++) {
          printf("%c", value[i]);
        }
        validateStaus += 1;

      } else {
        printf("\nError at column %d: wrong name figure expected 'circle', "
               "'triangle' or 'polygon'\n",
               count);
        return 0;

        break;
      }
      if (validateStaus == 1) {
        for (size_t i = count; i < LEN; i++) {
          if (validateStaus != 3) {
            if (str[i] == '(') {
              count++;
              skobCount++;
              validateStaus += 1;
              printf("%c", str[i]);
            } else {
              printf("\nError at column %d: wrong symbol, expected ('\n",
                     count);
              return 0;
              break;
            }
          }
        }
      }
      if (validateStaus == 3) {

        int n = count;
        while (str[n] != ')') {
          if (!(str[n] >= 'a' && str[n] <= 'z') && (str[n] != '(')) {
            if (!((str[n] == '.' && str[n + 1] == '0') ||
                  (str[n - 1] == '.' && str[n] == '0'))) {
              printf("%c", str[n]);
            }

            count++;
            n++;
          } else if ((str[n] == '(')) {
            printf("\nError at column %d: wrong symbol, expected ('\n", count);
            return 0;

            break;
          } else if ((str[n] >= 'a' && str[n] <= 'z')) {
            printf("\nError at column %d: wrong symbol, expected <double>'\n",
                   count);
            return 0;
          }
        }
        for (size_t i = 0; i < skobCount; i++) {
          printf(")");
        }

        printf("\n");
      }
    }
  } else {
    printf("File wasn't open\n");
  }
  return 0;
}