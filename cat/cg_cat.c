#include "cg_cat.h"
// make -v flag support
int main(int argc, char *argv[]) {
  char opt;
  int is_error = 0, longind = 0;
  while (!is_error &&
         (opt = getopt_long(argc, argv, OPTIONS, longopts, &longind)) != -1) {
    switch (opt) {
      case 'b':
        options.b = 1;
        options.n = 0;
        break;
      case 'e':
        options.e = 1;
        options.v = 1;
        break;
      case 'n':
        options.n = 1;
        options.b = 0;
        break;
      case 's':
        options.s = 1;
        break;
      case 't':
        options.t = 1;
        options.v = 1;
        break;
      case 'E':
        options.e = 1;
        break;
      case 'T':
        options.t = 1;
        break;
      case 'v':
        options.v = 1;
        break;
      default:
        is_error = 1;
        break;
    }
  }
  if (!is_error) {
    while (optind < argc) {
      print(argv[optind]);
      optind++;
    }
  } else {
    printf("not such option");
  }
  return 0;
}

int print(const char *filename) {
  int line = 0;
  char ch = '\0';
  int is_line = 1;
  int count_space_line = 1;
  FILE *file = fopen(filename, "r");

  if (file != NULL) {
    while (!feof(file) && (ch = fgetc(file)) != EOF) {
      if (ch == '\n' && options.s && count_space_line >= 2) {
        continue;
      }
      if (is_line && ((options.b && ch != '\n') || options.n)) {
        printf("%6d\t", ++line);
        is_line = 0;
      }
      if (options.e && ch == '\n') {
        printf("$");
      }
      if (options.t && ch == '\t') {
        printf("^|");
      } else {
        if (ch == '\n') {
          is_line = 1;
          count_space_line++;
        } else {
          count_space_line = 0;
        }
        options.v ? check_print(ch) : printf("%c", ch);
      }
    }
  }
  return 0;
}

void check_print(char ch) {
  if (ch < -96)
    printf("M-^%c", ch + 192);
  else if (ch < 0)
    printf("M-%c", ch + 128);
  else if (ch == 9 || ch == 10)
    printf("%c", ch);
  else if (ch < 32)
    printf("^%c", ch + 64);
  else if (ch < 127)
    printf("%c", ch);
  else
    printf("^?");
}