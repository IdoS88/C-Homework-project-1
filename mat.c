#include <ctype.h>
#include "mat.h"
#include <stdlib.h> 
#include <time.h>  
#include <stdio.h>

void printMatIndexes(int* mat, int rowsSub, int colsSub, int indexRow, int indexCol, int maxEffectiveRow, int maxEffectiveCol)
{
	int i, j;
	int* pValue = mat;
	if (indexRow + rowsSub - 1 >= maxEffectiveRow || indexCol + colsSub - 1 >= maxEffectiveCol)
	{
		printf("sub matrix is out of bounds!\n");
		return;
	}
	for (i = indexRow; i < rowsSub + indexRow && i < maxEffectiveRow; i++)
	{
		for (j = indexCol; j < colsSub + indexCol && j < maxEffectiveCol; j++)
		{
			pValue += (i * COLS) + j;
			printf("%5d ", *pValue);
			pValue = mat;
		}
		printf("\n\n");
	}
}

void	printMat(const int* mat, int rows, int cols)
{
	int i, j, k;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			printf("%5d ", *mat);
			mat++;

		}
		for (k = 0; k < COLS - cols; k++)
			mat++;
		printf("\n\n");
	}

}

void	printMatOriginal(const int* mat, int rows, int cols, char* name)
{
	int i, j;
	printf("%s:\n", name);
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			printf("%5d ", *mat);
			mat++;

		}
		printf("\n\n");
	}
	printf("\n\n");


}

void	initMat(int* mat, int rows, int cols, int min, int max)
{
	int num;


	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			num = min + (rand() % (max - min + 1));
			*(mat + cols * i + j) = num;
		}
	}


}

void	printMatSize(int rows, int cols)
{
	printf("rows size of matrix is %d\ncols size of matrix is %d\n\n", rows, cols);
}




