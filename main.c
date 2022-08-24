#include "q3.h"
#include "mat.h"
#include "q1.h"
#include "q2.h"
#include <stdio.h>

void printEffectiveMat(int* mat,int* colsEffective,int* rowsEffective);
void printSubMatSize(int rows, int cols,int *subRows,int* subCols);
int doFindMaxSubMatrix (int *mat, int rows, int cols, int rowsOfSmallMat,int colsOfSmallMat, int *indexCols, int *indexRows);

void checkboard(int* mat, int* nums, int rows, int cols);
int main()
{
	char x;
	int mat[ROWS][COLS];
	int mat2[ROWS][COLS] = { {1,1,1,1,1},{1,0,1,0,1},{0,1,1,1,0},{1,1,0,1,1},{1,1,1,1,1} };
	int leftNums[ROWS][(COLS + 1) / 2] = { {0,0,5},{1,1,1},{0,0,3},{0,2,2},{0,0,5} };
	int board[ROWS][COLS];
	do
	{
		printf("\nPlease choose one of the following option\nS/s - Biggest Matrix Sum\n  C/c – Color Game\n B/b - Black and White Game\n E/e - Quit\n");
		scanf("%c", &x);
		while (getchar() != '\n');

		switch (x)
		{
		case 'S':
		case 's':
		{
			int rows, cols, subRows, subCols;
			int pRow = 0, pCol = 0;
			initMat((int*)mat, ROWS, COLS, -50, 50);

			printMat((int*)mat, ROWS, COLS);

			printEffectiveMat((int*)mat, &rows, &cols);

			printSubMatSize(rows, cols, &subRows, &subCols);
			printf("sum of sub mat is: %d\n", doFindMaxSubMatrix((int*)mat, rows, cols, subRows, subCols, &pRow, &pCol));
			printf("row index of sub mat is: %d\n col index of sub mat is: %d\n", pRow, pCol);
			printMatIndexes((int*)mat, subRows, subCols, pRow, pCol, rows, cols);

			break;

		}
		case 'C':
		case 'c':
		{
			initMat((int*)board, ROWS, COLS, 0, 0);
			printMatSize(ROWS, COLS);
			printf("numbers of COLORS is %d\n", COLOR);
			printMatOriginal((int*)board, ROWS, COLS,"board");
			int* startValues[COLOR][2];
			do {
				initMat((int*)startValues, COLOR, 2, 0, COLS - 1);
			} while (!isNotSame((int*)startValues, COLOR, 2));
			printMatOriginal((int*)startValues, COLOR, 2,"start values");
			colorTheBoard((int*)board,(int*) startValues);
			break;
		}
		case 'B':
		case 'b':
		{
			printMatOriginal((int*)mat2, ROWS, COLS, "matrix black and white");
			printMatOriginal((int*)leftNums, ROWS, (COLS + 1) / 2, "left numbers matrix");
			checkboard((int*)mat2, (int*)leftNums, ROWS, COLS);
		}
		break;
		case 'E':
		case 'e':
			printf("Bye Bye\n");
			break;

		default:
			printf("Error!,a characters is not correct\n");



		}
	} while (x != 'e' && x != 'E');

	return 0;
}

