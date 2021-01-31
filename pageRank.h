#ifndef PAGE_RANK_H
#define PAGE_RANK_H

#define DATA_PATH "soc-Epinions1.txt"
#define NB_NODE 75879
#define NB_EDGE 508837
#define RES_PATH "result.txt"

typedef struct transition_m
{
	int nb_val;
	int* row;
	int* col;
	float* val;
} transition_m;

typedef struct vector
{
	int nb_val;
	float* val;
} vector;

transition_m* create_transition_m();
void free_transition_m(transition_m* mat);
vector* create_vector();
void free_vector(vector* vect);
void product_matrix_vector(transition_m* mat, vector* vect, vector* res);
void copy_result(vector* vect, vector* res);
void write_result(vector* vect);


#endif