#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
	srand(time(NULL));

	long unsigned int
		i, j, max_j,
		genome_1, genome_2, genome_max,
		mutator, limit, actual_limit, minimal_complexity,
		print;
	// generate two "genomes"
	minimal_complexity = 0xf;
	actual_limit = minimal_complexity;
	limit = 0xffff;

	print = 1; j = 0; max_j = 0;

	genome_1 = random() % (actual_limit+1);
	genome_2 = random() % (actual_limit+1);
	// mutator = random() % 10;


	for(i=0; genome_1 <= limit; i++) {
		if(print==1) {
			printf("surviving genome:  %8x ", genome_1, genome_2);
		}

		if (genome_1 > genome_2) {
			print = 0;
			j++;
		} else if (genome_2 > genome_1) {
			printf("(%d)", j);
			if (j>max_j) {
				max_j=j;
				genome_max = genome_1;
				printf(" *");
			}
			printf("\n");
			j = 0;
			genome_1 = genome_2;
			print = 1;
			actual_limit++;	
		} else {
			/*
			printf("actual limit has been reduced.\n");
			actual_limit--;
			genome_1 = random() % (actual_limit+1);
			*/
		}
		genome_2 = random() % (actual_limit+1);
	}
	printf("\nlast round: genome 1 (%x) vs. genome 2 (%x)", genome_1, genome_2);
	printf("\nthe longest surviving genome was %x with %d generations", genome_max, max_j);
	printf("\nthis game took %d generations to finish.\n", i);

	// repeat forever
	//printf("repeat forever\n");

	return 0;
}
