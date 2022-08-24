#ifndef q1_H_
#define q1_H_
#include <stdio.h>
#include "mat.h"

int sumOfRow(int* mat, int size);
void checkboard(int* mat, int* nums, int rows, int cols);
int exactValues(int* const mat, int* const nums, int cols);
int blackCounter(int *pValue, int cols);
int isSame(int * pLeftnums, int cols, int value, int *index);




#endif
