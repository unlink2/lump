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

  // trim
  while (input[i] && isspace(input[i])) {
    i++;
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

int lump_slice(char *dst, char *input, int len, int from, int to) {
  if (len >= from || len >= to || from < to) {
    return -1;
  }

  strncpy(dst, input, len);

  return to - from;
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
