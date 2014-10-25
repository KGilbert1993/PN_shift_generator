#include <stdio.h>
#include <stdlib.h>

#include "pn_gen.h"

//#define SCRAMBLEROUT

int main(int argc, char **argv) {
	int out[255];
	int out2[255];
	int internal_state = 0x05;
	int unscrambler = 0x05;
	int i, feedback;
	int input = 1;
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
		feedback = (input ^ ((internal_state&0x01) ^ ((internal_state & 0x08)>>3)));
		out[i] = feedback;
		feedback <<= 5;
		internal_state &= 0x1F;
		internal_state |= feedback;
		internal_state >>= 1;
		// scrambled

		unscrambler &= 0x1F;
		unscrambler |= feedback;
		
		out2[i] = ((unscrambler & 0x08)>>3) ^ ((unscrambler & 0x20) >> 5) ^ (unscrambler & 0x01);

		unscrambler >>= 1;		

	#ifdef SCRAMBLEROUT
		printf("%0.2d --> %d | internal state:%0.2d\n",i,out[i],internal_state);
	#else
		printf("%0.2d --> %d | internal state; %0.2d\n",i,out2[i],unscrambler);
	#endif
	}
}
