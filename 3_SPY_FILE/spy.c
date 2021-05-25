#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "cache.h"


int main(int argc, char **argv) {
	char* file = argv[1];
	uint32_t offset = 0;

	if (argc > 1) {
		offset = strtol(argv[2],NULL,10);
	}

	// Add arguments of map_offset function //
	void* ptr = map_offset(file , offset);
	if (ptr == NULL) {
		printf("Le fichier n'a pas pu être ouvert");
		exit(-1);
		
		
	}
	
	
	while(1) {
		int time = memaccesstime(ptr);
		if (time < 150) {
			printf("File USED \n");
		}

		clflush(ptr);
		delay(10000);
		
		
	}
	
	return 0;
}

