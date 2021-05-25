#include <stdio.h>
#include "cache.h"

/* 
Question 15
	La fonction rsa_modExp étant constituée d'une simple boucle while de nombre d'itérations secret e, le temps d'exécution n'est pas indépendant du secret.
	Donc la library n'est pas sécurisée et est vulnérable à une attaque temporelle.
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

