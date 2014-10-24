#define MEMSIZE 255

typedef struct pn_gen {
	int internal_state;
	int feedback;
	int memory[MEMSIZE];
} pn_gen;

int pn_cycle(int *input, pn_gen *gen, int iteration);

