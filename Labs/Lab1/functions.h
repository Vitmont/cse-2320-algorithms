#ifndef FUNCTIONS
#define FUNCTIONS

int check_arrayA(int *arrayA, int *arrayB, int i, int j);
int check_arrayB(int *arrayA, int *arrayB, int i, int j);
int binSearch(int low, int high);
void readIn(int *array, int size);
void readInRank(int *array, int size);
void findRange(int sizeA, int sizeB, int *high, int *low, int rank);

#endif