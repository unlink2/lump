#ifndef lumpH__
#define lumpH__

struct lump_config {
  _Bool verbose;
};

int lump_main(struct lump_config *cfg);

#endif 
