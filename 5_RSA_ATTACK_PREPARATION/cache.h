#ifndef _CACHE_H_
#define _CACHE_H_

#include <stdint.h>

void*    map_offset   (const char *file, uint64_t offset);
void     delay        (uint32_t t);
void     clflush      (void* ptr);
uint32_t memaccesstime(void *v);

#endif
