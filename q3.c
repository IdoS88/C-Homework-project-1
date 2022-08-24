#include <stdio.h>
#include "mat.h"
#include "q3.h"
void checkboard(int* mat, int* nums, int rows, int cols)
{
	int j;
	for (j = 0; j < rows; j++, mat += cols, nums += ((cols + 1) / 2))
	{

		if (sumOfRow(nums, (cols + 1) / 2) > cols)
		{
			printf("1 - Wrong attributes for row %d\n", j+1);
			return;
		}
		if (sumOfRow(nums, (cols + 1) / 2) != sumOfRow(mat, cols))
		{
			printf("2 - Wrong attributes for row %d\n", j+1);
			return;
		}
		if (!exactValues(mat, nums, cols))
		{
			printf("3 - Wrong attributes for row %d\n", j+1);
			return;
		}

	}
	printf("The checkboard is legit and valid!\n");
	return;
}
int sumOfRow(int* arr, int size)
{
	int i, sum = 0;
	for (i = 0; i < size; i++)
	{
		sum += *(arr + i);
	}
	return sum;
}

int exactValues(int* const mat, int* const nums, int cols)
{
	int i = 0, j = 0, temp; // indexes of mat and nums arrays, temp for black counters
	int leftnumsCols = (cols + 1) / 2; // size of row of leftnums array
	int *pValue = mat; // pointer for start of row of black and white array
	int *pLeft = nums; //pointer for start of row of leftnums array
		// skipping the 0s(white cases) values until we start counting the blacks

	while (i < cols && j < leftnumsCols)
	{
		while (*pValue == 0 && i < cols)
		{
			pValue += 1;
			i++;
		}
		// starting counting the first black cases until the end of the row.
		temp = blackCounter(pValue, cols - i);
		i += temp + 1; // updating index of pointer of pValue
		//checking if we didnt check the whole leftnums array
		if (j < leftnumsCols)
		{
			int indexJump = 0;
			// cheking if black counter is the same as the first value that found in the leftnums array but only in case we didnt checked the whole leftnums array
			if (!isSame(pLeft, leftnumsCols - j, temp, &indexJump))
				return 0;
			j += indexJump; // updating the index of pointer of leftnums
		}
		else
			return 0;
	}

	return 1;
}

int blackCounter(int * pValue, int cols)
{
	int i = 0; //index of pointer
	int counter = 0; // counter of black case (1s)
	// start counting the blacks but only in the bound of the row
	while (i < cols && *(pValue + i) == 1)
	{
		counter++;
		i++;
	}
	// return pointer of address to next index
	pValue += i;   // 1 1 0 1 1 
	return counter;
}

int isSame(int * pLeftnums, int cols, int value, int *index)
{

	int i = 0; //index of pointer

		// skip the 0s in the row until the end of the row 
		// because we only care about the actual values in the leftnums row
	while (*(pLeftnums + i) == 0 && i < cols)
	{
		i++;
	}
	// if we found no value after checking the whole row then return false because we didnt found a value for comparing the value we wanted to check
	if (i >= cols)
		return 0;
	else if (*(pLeftnums + i) != value)
		return 0;
	pLeftnums += i ;// returning pointer to the address after the value. value found valid.
	*index = i ;
	return 1;
}
