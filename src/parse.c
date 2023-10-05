#include "parse.h"
#include <assert.h>
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

  int non_space_chars = 0;

  // the only thing that will terminate a default case
  while (i < len && input[i]) {
    char c = input[i];
    dst[wrt] = c;

    i++;
    wrt++;

    non_space_chars += !isspace(c);

    if (c == '\n' && !non_space_chars) {
      break;
    }
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
