#include "parse.h"
#include <ctype.h>

int lump_tok(char *dst, const char *input, int max_len) {
  int written = 0;

  return written;
}

const char *lump_trim(const char *tok, int *len) {
  while (*tok && isspace(*tok)) {
    tok++;
    *len = *len - 1;
  }

  return tok;
}
