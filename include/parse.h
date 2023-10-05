#ifndef PARSE_H_
#define PARSE_H_

#include <stddef.h>
#include <stdbool.h>

/**
 * Writes the next token into dst
 *
 * returns the amount of bytes consumed
 */
int lump_tok(char *dst, const char *input, int len);
int lump_slice(char *dst, const char *input, int len, int from, int to);

bool lump_strisspace(const char *s, int len);

const char *lump_trim(const char *tok, int *len);

#endif
