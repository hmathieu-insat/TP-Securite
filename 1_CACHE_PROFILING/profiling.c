#include <stdio.h>

#include "cache.h"

#define RUNS  1000
#define LIMIT 500

int main(int ac, char **av) {
	
	uint32_t cache_hit_cycles [RUNS];
	uint32_t cache_miss_cycles[RUNS];
	uint32_t cache_hit_histogram [LIMIT];   
	uint32_t cache_miss_histogram[LIMIT];
	
	memset(cache_hit_histogram ,0,LIMIT*sizeof(uint32_t));
	memset(cache_miss_histogram,0,LIMIT*sizeof(uint32_t));
	
		
	void* ptr = map_offset("profiling.c",0);
	
	
	// Cache hit cycles profiling //
	/** (Question 1) **/
	for (int i = 0; i < RUNS; i++) {
		cache_hit_cycles[i] = memaccesstime(ptr);
	}
	
	
	
	// Cache miss cycles profiling //
	/** (Question 1) **/  
	for (int i = 0; i < RUNS; i++) {
		clflush(ptr);
		cache_miss_cycles[i] = memaccesstime(ptr);
	}
	
	
	
	// Compute histogram //
	/** (Question 2) **/
	for (int i = 0; i < RUNS; i++) {
		if (cache_hit_cycles[i] < LIMIT) {
			cache_hit_histogram[cache_hit_cycles[i]]++;
		}
	}

	for (int i = 0; i < RUNS; i++) {
		if (cache_miss_cycles[i] < LIMIT) {
			cache_miss_histogram[cache_miss_cycles[i]]++;
		}
	}
	
	
	
	
	// Export to csv file // 
	
	FILE* fcache_profiling = fopen("cache_profiling.csv","w");
	fprintf(fcache_profiling,"index;cache hit;cache miss\n");
	
	for(size_t i = 0; i < LIMIT;++i) fprintf(fcache_profiling,"%d;%d;%d;\n",
						  i,
						  cache_hit_histogram[i],
						  cache_miss_histogram[i]);
	
	fclose(fcache_profiling);
	
	return 0;
}
