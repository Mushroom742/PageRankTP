#include "pageRank.h"

#include <stdio.h>

int main(int argc, char const *argv[])
{
	transition_m* mat = create_transition_m();
	for(int i = 500000; i < 500010; i++) {
		printf("row : %d col: %d val: %f \n", mat->row[i], mat->col[i], mat->val[i]);
	}
	free_transition_m(mat);
	return 0;
}