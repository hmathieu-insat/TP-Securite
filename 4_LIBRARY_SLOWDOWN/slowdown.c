#include <stdio.h>
#include "cache.h"
#include <stdlib.h>

/* Question 12
A partir de l'anayse du fichier source de la bilbiothèqeu, on constate que la fonction modmult est  extrêmement utilisée

Question 13
La plage d'adresse associée est 145b-158e
 */

int main(int argc, char **argv) {
	// char* file = argv[1];
	// uint32_t offset = 5211;

	// if (argc > 1) {
	// 	offset = strtol(argv[2],NULL,10);
	// }
	// Add arguments of map_offset function //
	void* ptr = map_offset("librsa.so" , 5211);
	if (ptr == NULL) {
		printf("File not found \n");
		exit(-1);
		
		
	}
	
	
	while(1) {
		clflush(ptr);
		
		
		
	}
	
	return 0;
}

