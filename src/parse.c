#include "parse.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int lump_tok(char *dst, const char *input, int len) {
  int i = 0;
  int wrt = 0;
  memset(dst, 0, len);

  // empty length is an error
  if (!len) {
    return -1;
  }

  // default case if the first char is not a markdown special token
  // or a html tag
  while (i < len && input[i] && !isspace(input[i])) {
    dst[wrt] = input[i];
    i++;
    wrt++;
  }

  return i;
}

bool lump_strisspace(const char *s, int len) {
  for (int i = 0; i < len && s[i]; i++) {
    if (!isspace(s[i])) {
      return false;
    }
  }

  return true;
}

const char *lump_trim(const char *tok, int *len) {
  while (*tok && isspace(*tok)) {
    tok++;
    *len = *len - 1;
  }

  return tok;
}
