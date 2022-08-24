#ifndef q2_H_
#define q2_H_

#define COLOR 3

int paint(int* board, int rows, int cols, int indexRow, int indexCol, int colorNum);
int isNotSame(int* mat, int rows, int cols);
void expandColor(int* board, int rows, int cols, int indexRow, int indexCol,int colorNum, int numOfTurn);
void colorTheBoard(int* board, int* startValues);
void initBoard(int* board, int* startValues);
int isFull(int* board, int rows, int cols);
void endPaint(int* board, int rows, int cols, int colorNum);
#endif
