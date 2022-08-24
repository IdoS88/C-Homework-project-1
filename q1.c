#include <stdio.h>
#include "q1.h"
#include "mat.h"
#include <limits.h>


int doFindMaxSubMatrix(int *mat, int rows, int cols, int rowsOfSmallMat, int colsOfSmallMat, int *indexCols, int *indexRows)
{
	int* pSub = mat;
	int sum = INT_MIN, temp = 0;
	int i, j, k, l;
	*indexCols = 0, *indexRows = 0;
	for (i = 0; i <= rows - rowsOfSmallMat; i++)
	{
		for (j = 0; j <= cols - colsOfSmallMat; j++)
		{
			pSub += (i * COLS) + j;
			temp = 0;
			for (k = 0; k < rowsOfSmallMat; k++)
			{
				for (l = 0; l < colsOfSmallMat; l++)
				{
					temp += *(pSub + l);
				}
				pSub += COLS;
			}
			pSub = mat;
			if (temp > sum)
			{
				sum = temp;
				*indexRows = i;
				*indexCols = j;
			}
		}
	}
	return sum;
}
void printEffectiveMat(int *mat,int* rowsEffective,int* colsEffective)
{
	do {
	printf("Please enter number of rows beetween 1 to %d\nPlease enter number of cols beetween 1 to %d\n",ROWS,COLS);
	
	scanf ("%d %d",rowsEffective,colsEffective);
	if ((*colsEffective <= COLS && *colsEffective >= 1) && (*rowsEffective <= ROWS && *rowsEffective >= 1))
	{
		printf("rows for effective matrix is: %d\ncols for effective matrix is: %d\n\n", *rowsEffective, *colsEffective);
		printMat((int*)mat, *(rowsEffective), *(colsEffective));
	}
	}while(*colsEffective > COLS || *colsEffective < 1 || *rowsEffective > ROWS || *rowsEffective < 1);

}
void printSubMatSize(int rows, int cols,int *subRows,int* subCols)
{
	do {
	printf("please enter numbers of rows and cols for sub matrix\n");
	scanf("%d %d", subRows,subCols);
	if ((*subRows > 0 && *subRows <= rows) && (*subCols > 0 && *subCols <= cols))
		printf("num of rows for sub matrix: %d\nnum of cols for sub matrix: %d\n",*subRows,*subCols);
	} while (*subRows <= 0 || *subRows > rows || *subCols <= 0 || *subCols > cols);
	
}
