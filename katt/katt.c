#include <stdio.h>
#include <stdlib.h>

char *readline(FILE *fp)
{
  int offset = 0;
  int bufsize = 64;
  char *buffer;
  int c;

  buffer = malloc(bufsize);
  if (buffer == NULL) {
    return NULL;
  }

  while ((c = fgetc(fp)) != EOF && c != '\n') {
    if (offset == bufsize - 1) {
      bufsize *= 2;
      char *newbuf = realloc(buffer, bufsize);
      if (newbuf == NULL) {
        free(buffer);
        return NULL;
      }
      buffer = newbuf;
    }

    buffer[offset++] = (char)c;
  }

  // Empty file
  if (c == EOF && offset == 0) {
    free(buffer);
    return NULL;
  }

  if (offset < bufsize - 1) {
    char *newbuf = realloc(buffer, offset + 1);
    if (newbuf != NULL) {
      buffer = newbuf;
    }
  }

  buffer[offset] = '\0';
  return buffer;
}

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
