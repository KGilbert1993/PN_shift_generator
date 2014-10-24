#include <stdio.h>
#include <stdlib.h>

#include "pn_gen.h"

int pn_cycle(int *input, pn_gen *gen, int iteration) {
	gen->memory[iteration] = (gen->internal_state & 0x01);
	gen->feedback = (gen->memory[iteration] ^ ((gen->internal_state & 0x08)>>3)) << 5;
	gen->internal_state &= 0x1F;
	gen->internal_state |= gen->feedback;
	gen->internal_state >>= 1;
	return gen->memory[iteration];
}

int pn_scramble_cycle(int *input, pn_gen *gen, int iteration) {
	gen->memory[iteration] = (gen->internal_state & 0x01);
	gen->feedback = (gen->memory[iteration] ^ ((gen->internal_state & 0x08)>>3)) << 5;
	gen->internal_state &= 0x1F;
	gen->internal_state |= gen->feedback;
	gen->internal_state >>= 1;
	return gen->memory[iteration];
}


