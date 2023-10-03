#ifndef PARSE_H_
#define PARSE_H_

#include <stddef.h>

int lump_tok(char *dst, const char *input, int max_len);

const char *lump_trim(const char *tok, int *len);

#endif
