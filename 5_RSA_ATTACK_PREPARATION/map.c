#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/*
void *map_offset(const char *file, uint64_t offset) {
	int fd = open(file, O_RDONLY);
	if (fd < 0) {	
		fprintf(stderr,"unable to open %s\n",file);
		return NULL;
	}

	char *mapaddress = MAP_FAILED;
	mapaddress = mmap(0, 4096, PROT_READ, MAP_PRIVATE, fd, offset & 0xFFF);
	close(fd);
	if (mapaddress == MAP_FAILED) {
		fprintf(stderr,"unable to map %s with offset 0x%x\n",file, offset & 0xFFF);
		return NULL;
	}
	return (void *)(mapaddress+(offset & 0xFFF));
}
*/

void *map_offset(const char *file, uint64_t offset) {
  int fd = open(file, O_RDONLY);
  if (fd < 0)
    return NULL;
  
  char *mapaddress = MAP_FAILED;
#ifdef HAVE_MMAP64
  mapaddress = mmap(0, 4096, PROT_READ, MAP_PRIVATE, fd, offset & ~(4096 -1));
#else
  mapaddress = mmap(0, 4096, PROT_READ, MAP_PRIVATE, fd, ((off_t)offset) & ~(4096 -1));
#endif
  close(fd);
  if (mapaddress == MAP_FAILED)
    return NULL;
  return (void *)(mapaddress+(offset & (4096 -1)));
}
