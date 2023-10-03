#include "parse.h"
#include <ctype.h>

int lump_tok(char *dst, const char *input, int len) {
  int i = 0;

  // new line will 100% cause the next token to begin
  while (i < len && input[i] && input[i] != '\n') {
    i++;

    dst[i] = input[i];
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
