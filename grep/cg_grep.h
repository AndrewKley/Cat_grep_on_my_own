#ifndef GREP_CG_GREP_H_
#define GREP_CG_GREP_H_

#include <getopt.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OPTIONS ":e:ivclnhsf:o"
#define SIZE 2000
#define COUNT_TEMPLATES 1000

typedef struct {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;
} option;

option options = {0};

int expression_handling(regex_t *templates, int count_templates, char *filename,
                        int is_files);
int expressions_from_file(regex_t *templates, int *count_templates,
                          char *filename);
void free_templates(regex_t *templates, int count_template);
void output_stand_file(char *line, char *filename, int count_line,
                       int is_files);
void output_o_option(regmatch_t regmatch, char *line, char *filename,
                     int count_line, int is_files);
void match(int *count_match_line, int *count_line, int count_templates,
           regex_t *templates, char *line, char *filename, int is_files);

#endif // GREP_CG_GREP_H_
