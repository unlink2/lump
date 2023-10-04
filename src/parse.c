#include "parse.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool lump_ismdterm(char c) { return c == '#'; }

int lump_tokh(char *dst, const char *input, int len) {
  int i = 0;

  while (i < len && input[i] && input[i] == '#') {
    dst[i] = input[i];
    i++;
  }

  return i;
}

int lump_tok(char *dst, const char *input, int len) {
  int i = 0;
  int wrt = 0;
  memset(dst, 0, len);

  // empty length is an error
  if (!len) {
    return -1;
  }

  switch (input[i]) {
  case '#':
    return lump_tokh(dst, input, len);
  case '\n':
    i++;
    break;
  default:
    // go to default case
    break;
  }

  char first_nonspace = '\0';

  // default case if the first char is not a markdown special token
  // or a html tag
  while (i < len && input[i] && input[i] != '\n') {
    if (!first_nonspace && !isspace(input[i])) {
      first_nonspace = input[i];
      if (lump_ismdterm(first_nonspace)) {
        break;
      }
    }

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
