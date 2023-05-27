#include "cg_grep.h"

int main(int argc, char *argv[]) {
  char opt;
  int is_error = 0, count_templates = 0;
  regex_t templates[COUNT_TEMPLATES];
  while (!is_error && (opt = getopt(argc, argv, OPTIONS)) != -1) {
    switch (opt) {
      case 'e':
        options.e = 1;
        regcomp(&templates[count_templates++], optarg,
                options.i ? REG_ICASE : REG_EXTENDED);
        break;
      case 'i':
        options.i = 1;
        break;
      case 'v':
        options.v = 1;
        break;
      case 'c':
        options.c = 1;
        break;
      case 'l':
        options.l = 1;
        break;
      case 'n':
        options.n = 1;
        break;
      case 'h':
        options.h = 1;
        break;
      case 's':
        options.s = 1;
        break;
      case 'f':
        options.f = 1;
        if (expressions_from_file(templates, &count_templates, optarg) &&
            !options.s)
          fprintf(stderr, "grep:\t%s: No such file or directory\n", optarg);
        break;
      case 'o':
        options.o = 1;
        break;
      default:
        is_error = 1;
        break;
    }
  }
  if (!is_error) {
    if (!options.e && !options.f)
      regcomp(&templates[count_templates++], argv[optind++],
              options.i ? REG_ICASE : REG_EXTENDED);
    int is_files = 0;
    while (optind < argc) {
      if (!options.h && argc - optind > 1) {
        is_files = 1;
      }
      is_error = expression_handling(templates, count_templates, argv[optind++],
                                     is_files);
      if (is_error && !options.s) {
        fprintf(stderr, "grep:\t%s: No such file or directory\n",
                argv[optind - 1]);
      }
    }
  } else {
    printf("Uncorrect command\n");
  }
  free_templates(templates, count_templates);

  return 0;
}

int expression_handling(regex_t *templates, int count_templates, char *filename,
                        int is_files) {
  int is_file_exists = 0, count_line = 0, count_match_line = 0;
  FILE *file = fopen(filename, "r");
  if (file != NULL) {
    char line[SIZE] = {0};
    while (!feof(file) && fgets(line, SIZE, file)) {
      match(&count_match_line, &count_line, count_templates, templates, line,
            filename, is_files);
    }
    if (options.c) {
      if (!options.h && is_files) {
        printf("%s:", filename);
      }
      printf("%d\n", options.l ? 1 : count_match_line);
    }
    if (options.l && count_match_line) {
      printf("%s\n", filename);
    }
    fclose(file);
  } else {
    is_file_exists = 1;
  }
  return is_file_exists;
}

void output_stand_file(char *line, char *filename, int count_line,
                       int is_files) {
  if (!options.h && is_files) {
    printf("%s:", filename);
  }
  if (options.n) {
    printf("%d:", count_line);
  }
  printf("%s", line);
}

int expressions_from_file(regex_t *templates, int *count_templates,
                          char *filename) {
  int is_exists = 0;
  char line[SIZE] = {0};

  FILE *file = fopen(filename, "r");
  if (file != NULL) {
    while (!feof(file) && fgets(line, SIZE, file)) {
      size_t len = strlen(line);
      if (line[len - 1] == '\n') {
        line[len - 1] = '\0';
      }

      regcomp(&templates[(*count_templates)++], line,
              options.i ? REG_ICASE : REG_EXTENDED);
    }
    fclose(file);
  } else {
    is_exists = 1;
  }
  return is_exists;
}

void free_templates(regex_t *templates, int count_template) {
  for (int i = 0; i < count_template; i++) {
    regfree(&templates[i]);
  }
}

void output_o_option(regmatch_t regmatch, char *line, char *filename,
                     int count_line, int is_files) {
  if (!options.h && is_files) {
    printf("%s:", filename);
  }

  if (options.n) {
    printf("%d:", count_line);
  }
  while (regmatch.rm_so < regmatch.rm_eo) {
    printf("%c", line[regmatch.rm_so]);
    regmatch.rm_so++;
  }
  printf("\n");
}

void match(int *count_match_line, int *count_line, int count_templates,
           regex_t *templates, char *line, char *filename, int is_files) {
  int is_match = 0;
  (*count_line)++;
  for (int i = 0; i < count_templates; i++) {
    regmatch_t regmatch;
    if (!regexec(&templates[i], line, 1, &regmatch, 0)) {
      if (options.o && !options.l && !options.c && !options.v) {
        output_o_option(regmatch, line, filename, *count_line, is_files);
      }
      is_match = 1;
      (*count_match_line)++;
    }
  }
  if (!is_match && !options.l && !options.c && options.v) {
    output_stand_file(line, filename, *count_line, is_files);
  }
  if (is_match && !options.c && !options.l && !options.v && !options.o) {
    output_stand_file(line, filename, *count_line, is_files);
    is_match = 0;
  }
}
