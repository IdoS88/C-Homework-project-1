#ifndef _MAT_
#define _MAT_

#define COLS 5
#define ROWS 5


	void printMatIndexes(int* mat, int rowsSub, int colsSub, int indexRow, int indexCol, int maxEffectiveRow, int maxEffectiveCol);
	void	printMat(const int* mat, int rows, int cols);
	void	printMatOriginal(const int* mat, int rows, int cols, char* name);
	void	initMat(int* mat, int rows, int cols, int min, int max);
	void	printMatSize(int rows,int cols);
#endif
