#define _CRT_SECURE_NO_WARNINGS
#include "q2.h"
#include "mat.h"
#include <stdio.h>


int isNotSame(int* mat, int rows, int cols)
{
	int tempx; // index of row 
	int tempy; // index of col
	for (int i = 0; i < rows; i++) {
		tempx = *(mat + i * cols); // jump to first col
		tempy = *(mat + i * cols + 1); // jump to second col 
		for (int j = 0; j < rows; ++j) {
			//check if selected row has same values as other rows
			if (i != j && tempx == *(mat + j * cols) && tempy == *(mat + j * cols + 1)) {
				return 0;
			}
		}
	}
	return 1;
}

void expandColor(int * board, int rows, int cols, int indexRow, int indexCol, int colorNum, int numOfTurn)
{
	int i, j;
	for(i = indexRow;i<rows;i++)
		for (j = indexCol; j < cols; j++) 
		{
			if (*(board + i * rows + j) == colorNum)
				paint((int*)board, rows, cols, i, j, colorNum);
		}
	endPaint(board, rows, cols, colorNum); // color the negative values from function paint

}
int paint(int* board, int rows, int cols, int indexRow, int indexCol, int colorNum)
{
	int numberOfPainting = 0;
	for (int i = indexRow - 1; i < indexRow + 2; i++) {
		for (int j = indexCol - 1; j < indexCol + 2; j++) {
			if (i >= 0 && i < rows && j >= 0 && j < cols && (*(board + cols * i + j) == 0)) {
				*(board + cols * i + j) = -colorNum; // paint negative to sign as a current paint turn
				numberOfPainting++;
			}
		}
	}
		return numberOfPainting;
}
void endPaint(int* board, int rows, int cols, int colorNum)
{
	// a function to paint the negative values from current turn
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (*(board + cols * i + j) == -colorNum) 
				*(board + cols * i + j) = colorNum;
		}
	}


}

void colorTheBoard(int* board,int* startValues)
{
	int i, turn = 1;
	initBoard(board, startValues);
	printMatOriginal(board, ROWS, COLS,"board");
	while (!isFull(board,ROWS,COLS))
	{
		for (i = 1; i <= COLOR; i++) // i = color number
		{
			expandColor(board, ROWS, COLS, 0, 0, i, turn);
		}

		printf("turn %d:\n", turn);
		printMatOriginal(board, ROWS, COLS,"board");
		turn++;
	}
}
int isFull(int* board,int rows,int cols)
{
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			if (*(board + cols * i + j) == 0) {
				return 0; // theres still squares left to color
			}
		}
	}
	return 1;
}
void initBoard(int* board, int* startValues)
{
	int i;
	for (i = 0; i < COLOR; i++)
	{
		int x = *(startValues + i * 2); // index of row
		int y = *(startValues + i * 2 + 1); // index of col
		*(board + x * ROWS + y) = i + 1; // initiate color in selected place
	}
}

