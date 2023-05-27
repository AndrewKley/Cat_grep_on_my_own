#ifndef COMMON_HEADER_H
#define COMMON_HEADER_H

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

int expression_handling(regex_t *templates, int count_templates, char *expression, char *filename, int is_files);
void o_case(char *line, char *expression);
int expressions_from_file(regex_t *templates, int *count_templates, char *filename);
void free_templates(regex_t *templates, int count_template);

#endif  // COMMON_HEADER_H
