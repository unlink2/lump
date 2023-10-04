#include "platform.h"

#ifdef __OpenBSD__

#ifdef LUMP_ALLOW_EXEC 

#define LUMP_PLEDGE "stdio proc exec"
#else 

#define LUMP_PLEDGE "stdio"

#endif 

#include <unistd.h>

int lump_pledge(void) { return pledge(LUMP_PLEDGE, NULL); }

#else

int lump_pledge(void) { return 0; }

#endif
