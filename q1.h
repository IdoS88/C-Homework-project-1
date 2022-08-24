#ifndef q1_H_
#define q1_H_
#include "mat.h"


int doFindMaxSubMatrix (int *mat, int rows, int cols, int rowsOfSmallMat,int colsOfSmallMat, int *indexCols, int *indexRows);
void printEffectiveMat(int* mat,int* colsEffective,int* rowsEffective);
void printSubMatSize(int rows, int cols,int *subRows,int* subCols);
#endif
