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

  // count non-space chars
  int non_space_chars = 0;
  char first = '\0';

  // the only thing that will terminate a default case
  while (i < len - 1 && input[i]) {
    char c = input[i];
    if (!first) {
      first = c;
    }

    dst[wrt] = c;

    // tokens that need to be at the start of a
    // line
    if (non_space_chars == 0) {
      switch (c) {
      // h1-h6 needs to be a token
      case '#':
        goto end;
      default:
        break;
      }
    }

    i++;
    wrt++;

    non_space_chars += !isspace(c);

    // treat entierly empty line as a single token
    if (non_space_chars == 0 && c == '\n') {
      break;
    }
  }
end:
  dst[wrt] = '\0';

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
