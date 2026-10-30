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
    fp = stdin;
  }

  char *line;
  while ((line = readline(fp)) != NULL) {
    printf("%s\n", line);
    free(line);
  }
  fclose(fp);
  return 0;
}
