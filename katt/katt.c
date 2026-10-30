#include <stdio.h>
#include <stdlib.h>

#include "../lib/io.h"

int main(int argc, char *argv[])
{
  (void)argc;
  FILE *fp;
  char *filename = *(argv + 1);
  if (filename != NULL) {
    fp = fopen(filename, "r");
  } else {
    filename = "STDIN";
    fp = stdin;
  }

  fline line;
  int lineno = 1;
  printf("═ Filename: %s\n", filename);
  while ((line = readline(fp)).buffer != NULL) {
    printf("%-5d │ %-5d │ %s\n", lineno, line.length, line.buffer);
    free(line.buffer);
    lineno++;
  }
  fclose(fp);
  return 0;
}
