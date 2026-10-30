#include <stdlib.h>
#include "io.h"

fline readline(FILE *fp)
{
  fline ret; 
  ret.length = 0;
  int offset = 0;
  int bufsize = 64;
  int c;

  ret.buffer = malloc(bufsize);
  if (ret.buffer == NULL) {
    return ret;
  }

  while ((c = fgetc(fp)) != EOF && c != '\n') {
    if (offset == bufsize - 1) {
      bufsize *= 2;
      char *newbuf = realloc(ret.buffer, bufsize);
      if (newbuf == NULL) {
        free(ret.buffer);
        ret.buffer = NULL;
        return ret;
      }
      ret.buffer = newbuf;
    }

    ret.buffer[offset++] = (char)c;
    ret.length++;
  }

  // Empty file
  if (c == EOF && offset == 0) {
    free(ret.buffer);
    ret.buffer = NULL;
    return ret;
  }

  if (offset < bufsize - 1) {
    char *newbuf = realloc(ret.buffer, offset + 1);
    if (newbuf != NULL) {
      ret.buffer = newbuf;
    }
  }

  ret.buffer[offset] = '\0';
  return ret;
}
