#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	int out[255];;
	int internal_state = 0x05;
	int i, feedback;

	if(argc < 2) {
		printf("Please enter number of cycles to simulate\n");
		return 1;
	}
	if(atoi(argv[1]) > 255) {
		printf("Please enter a number less than 255\n");
		return 2;
	}
	for(i=0; i<(atoi(argv[1]));i++) {
		out[i] = (internal_state & 0x01);
		feedback = (out[i] ^ ((internal_state & 0x08)>>3)) << 5;
		internal_state &= 0x1F;
		internal_state |= feedback;
		internal_state >>= 1;
		printf("%0.2d --> %d | internal state:%0.2d\n",i,out[i],internal_state);
	}
	
}
