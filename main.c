#include "pageRank.h"

#include <stdio.h>

#define NB_REP 100

int main(int argc, char const *argv[])
{
	transition_m* mat = create_transition_m();
	vector* vect = create_vector();
	vector* res = create_vector();

	vect->val[0] = 1.0;

	for(int rep = 0; rep < NB_REP; rep++) {
		product_matrix_vector(mat, vect, res);
		improved_vector(vect, res);
		copy_result(vect, res);
	}
	
	write_result(vect);

	free_transition_m(mat);
	free_vector(vect);
	free_vector(res);
	return 0;
}