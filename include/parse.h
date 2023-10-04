#ifndef PARSE_H_
#define PARSE_H_

#include <stddef.h>
#include <stdbool.h>

/**
 * Writes the next token into dst
 * Note: it is possible for input to consist of only
 * a single token (e.g. a paragraph). This means that dst
 * should be at least as long as input to hold the entire token!
 */
int lump_tok(char *dst, const char *input, int len);

bool lump_strisspace(const char *s, int len);

const char *lump_trim(const char *tok, int *len);

#endif
