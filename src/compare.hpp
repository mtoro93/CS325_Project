#include "struct.hpp"
/* function used to compare two TYPE values to each other, define this in your compare.c file */
int compare(struct city* left,struct city* right);
int compareID(struct city* left, struct city* right);
int compareY(struct city* left, struct city* right);
/* function used to print TYPE values, define this in your compare.c file */
void print_type(struct city* curval);