#ifndef IO_H
#define IO_H

#include <stdio.h>

typedef struct {
  char *buffer;
  int length;
} fline;

fline readline(FILE *fp);

#endif
