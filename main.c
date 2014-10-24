#include <stdio.h>
#include "pn_gen.h"

int main(int argc, char **argv) {
	int out[MEMSIZE];
	int i, tmp;
	pn_gen gen1;
	gen1.internal_state = 0x05;

	if(argc < 2) {
		printf("Please enter number of cycles to simulate\n");
		return 1;
	}
	if(atoi(argv[1]) > 255) {
		printf("Please enter a number less than 255\n");
		return 2;
	}
	for(i=0; i<(atoi(argv[1]));i++) {
		out[i] = pn_cycle(&tmp, &gen1, i);
		printf("%0.2d --> %d | internal state:%0.2d\n",i,out[i],gen1.internal_state);
	}
	return 0;	
}

