#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	int out[255];;
	int internal_state = 0x05;
	int i, feedback;

	for(i=0; i<(atoi(argv[1]));i++) {
		out[i] = (internal_state & 0x01);
		feedback = (out[i] ^ ((internal_state & 0x08)>>3)) << 5;
		internal_state &= 0x1F;
		internal_state |= feedback;
		internal_state >>= 1;
		printf("%0.2d --> %d | internal state:%0.2d\n",i,out[i],internal_state);
	}
	
}
