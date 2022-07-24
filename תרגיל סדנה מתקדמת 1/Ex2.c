/*This Project was the result of blood sweat and tears of:
Shay Mualem ID:   |Grop num 661108-62
Maxim Gromov ID:  |Grop num 61108-61
*/

#include<stdio.h>
#include<malloc.h>
#define COL_A  4
#define ROW_B  5
#define COMMON_SIZE 3


/* Function declarations */
int* matrixMultiplication(int _A[COL_A][COMMON_SIZE], int _B[COMMON_SIZE][ROW_B], int A_rows, int A_cols, int B_rows, int B_cols);
void _printArrayA(int _A[][COMMON_SIZE], int _rows, int _cols);
void _printArrayB(int _B[][ROW_B], int _rows, int _cols);
void _getAMatrix(int _A[][COMMON_SIZE], int rows, int cols);
void _getBMatrix(int _B[][ROW_B], int rows, int cols);
void Ex2();
/*-----------------------*/

void Ex2()
{
	printf("\n-------------(EX2)--------------\n");
	//Definition of the Matrixes 
	int **mat;
	int B[COMMON_SIZE][ROW_B];
	int A[COL_A][COMMON_SIZE];

	//Input values to Matrixes A and B
	_getAMatrix(A, COL_A, COMMON_SIZE);
	_getBMatrix(B, COMMON_SIZE, ROW_B);

	//Printing both A and B to the user
	printf("input is:\n");
	_printArrayA(A, COL_A, COMMON_SIZE);
	_printArrayB(B, COMMON_SIZE, ROW_B);

	//Multiplying A and B and inserting the result into a new pointer
	mat = matrixMultiplication(A, B, COL_A, COMMON_SIZE, COMMON_SIZE, ROW_B);

	//Printing the result of the multiplication
	printf("Multiplication: ");
	_printMatrix(mat, COL_A, ROW_B);

	//freeing the result Matrix
	_freeMatrix(mat, COL_A);
}

int * matrixMultiplication(int _A[COL_A][COMMON_SIZE], int _B[COMMON_SIZE][ROW_B], int A_rows, int A_cols, int B_rows, int B_cols)
{
	//Definition of the result Matrix and indexes
	int **arr, i, j, k;

	//Initiallization of the result Matrix
	arr = _creatMatrix(A_rows, B_cols);

	//Multiplication of the matrixes
	for (i = 0; i < A_rows; i++)
	{
		for (j = 0; j < B_cols; j++)
		{
			for (k = 0; k < A_cols; k++)
			{
				arr[i][j] += _A[i][k] * _B[k][j];
			}
		}
	}

	// Return the pointer to the result Matrix
	return arr;
}

// Printing Matrix A
void _printArrayA(int _A[][COMMON_SIZE], int _rows, int _cols) {
	printf("\nArray A:\n");
	int i, j;
	for (i = 0; i < _rows; i++)
	{
		for (j = 0; j < _cols; j++)
		{
			printf("%6d", _A[i][j]);
		}
		printf("\n");
	}
}

//Printing Matrix B
void _printArrayB(int _B[][ROW_B], int _rows, int _cols) {
	printf("\nArray B:\n");
	int i, j;
	for (i = 0; i < _rows; i++)
	{
		for (j = 0; j < _cols; j++)
		{
			printf("%6d", _B[i][j]);
		}
		printf("\n");
	}
}

//Input values to Matrix A
void _getAMatrix(int _A[][COMMON_SIZE], int _rows, int _cols)
{
	int i, j;
	printf("Enter A(%dX%d) Matrix: \n", _rows, _cols);

	for (i = 0; i < _rows; i++)
		for (j = 0; j < _cols; j++) {
			printf(" (%dX%d): ", i, j);
			scanf_s("%d", &_A[i][j]);
		}
}

//Input values to Matrix B
void _getBMatrix(int _B[][ROW_B], int _rows, int _cols)
{
	int i, j;
	printf("Enter B(%dX%d) Matrix: \n", _rows, _cols);

	for (i = 0; i < _rows; i++)
		for (j = 0; j < _cols; j++) {
			printf(" (%dX%d): ", i, j);
			scanf_s("%d", &_B[i][j]);
		}
}

