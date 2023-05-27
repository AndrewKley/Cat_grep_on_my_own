#ifndef CAT_CG_CAT_H_
#define CAT_CG_CAT_H_

#include <getopt.h>
#include <stdio.h>

#define OPTIONS ":benstvET"

static struct option longopts[] = {{"number-nonblank", 0, 0, 'b'},
                                   {"number", 0, 0, 'n'},
                                   {"squeeze-blank", 0, 0, 's'},
                                   {0, 0, 0, 0}};

typedef struct {
  int b;
  int e;
  int n;
  int s;
  int t;
  int v;
} option;

option options = {0};

int print(const char *filename);
void check_print(char ch);

#endif // CAT_CG_CAT_H_
