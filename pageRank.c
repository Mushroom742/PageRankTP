#include "pageRank.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

transition_m* create_transition_m() {
	transition_m* mat = malloc(sizeof(transition_m));
	mat->nb_val = NB_EDGE;
	mat->row = malloc(NB_EDGE * sizeof(int));
	mat->col = malloc(NB_EDGE * sizeof(int));
	mat->val = malloc(NB_EDGE * sizeof(float));

	FILE *fp;
	fp = fopen(DATA_PATH, "r");
	char* line = NULL;
	size_t len = 0;
	ssize_t read;
	char delim[] = "\t";
	char* p_token = NULL;
	int cpt = 0;
	int nb_link = 1;

	while((read = getline(&line, &len, fp)) != -1) {
		if(line[0] != '#') {
			p_token = strtok(line, delim);
			mat->col[cpt] = atoi(p_token);
			p_token = strtok(NULL, delim);
			mat->row[cpt] = atoi(p_token);

			if (cpt != 0) {
				if (mat->col[cpt] == mat->col[cpt - 1]) {
					nb_link ++;
				}
				else {
					for(int i = 1; i <= nb_link; i++) {
						mat->val[cpt - i] = 1.0/nb_link;
					}
					nb_link = 1;
				}
			}

			cpt++;
		}
	}
	fclose(fp);
	if (line) {
		free(line);
	}

	return mat;
}

void free_transition_m(transition_m* mat) {
	free(mat->row);
	free(mat->col);
	free(mat->val);
	free(mat);
}