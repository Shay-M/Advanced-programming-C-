/*This Project was the result of blood sweat and tears of:
Shay Mualem   |Grop num 661108-62
Maxim Gromov  |Grop num 61108-61
*/

#include<stdio.h>
#include<malloc.h>
#include"trgoStruct.h"

/* Function declarations */
void Ex3();
int createArrayAndList(int **mat, int _rows, int _cols, _Three ** arr, _ThreeList ** list);
_Three createThree(int, int);
_Three * createThreeArr(int** mat, int count, int _rows, int _cols);
_ThreeList * createThreeList(int** mat, int count, int _rows, int _cols);
/*-----------------------*/

void Ex3()
{
	printf("\n-------------(EX3)--------------\n");
	int **matrix, rows, cols, count;
	_Three *arr = NULL;
	_ThreeList *list = NULL;

	printf("Enter How Much Rows: ");
	scanf_s("%d", &rows);
	printf("Enter How Much Columns: ");
	scanf_s("%d", &cols);

	matrix = _creatMatrix(rows, cols);//Initialization of a new Matrix
	_scanfMatrix(matrix, rows, cols);// Input of values to the Matrix  

	_printMatrix(matrix, rows, cols);//Print the matrix to the user

	count = createArrayAndList(matrix, rows, cols, &arr, &list);//Creating a Linked List and Array of triplets and counting how many are there
	
	//If there are any values - print the list and array and free their memory, else print that they are empty
	if (count != 0)
	{
		_printThree(arr, count);
		_printThreeList(list);

		_freeMatrix(matrix, rows);
		free(arr);
		_freeThreeList(list);
	}
	else
	{
		printf("\n\n No Triplets to play with! Array and List are empty\n");
	}
}

// Creates a list and array of triplets, and return the number of triplets found in the matrix
int createArrayAndList(int **mat, int _rows, int _cols, _Three ** arr, _ThreeList ** list)
{
	int  i, j, count = 0;

	for (i = 0; i < _rows; i++)// going through the matrix and checking for values that equal to i+j
		for (j = 0; j < _cols; j++)
			if (mat[i][j] == (i + j))
				count++;
	//Printing the amount of found triplets
	printf("find %d match! \n", count);

	if (count != 0)// If there is at least one Triplet - create a list and array
	{
		*arr = createThreeArr(mat, count, _rows, _cols);
		*list = createThreeList(mat, count, _rows, _cols);
	}
	//return the number of triplets
	return count;
}

//Create a new Triplet
_Three createThree(int i, int j)
{
	_Three temp;
	temp.X = i + j;
	temp.i = i;
	temp.j = j;

	return temp;
}

//Create an array of triplets
_Three * createThreeArr(int** mat, int count, int _rows, int _cols)//ôåð÷öéä îáå÷ùú
{
	_Three* arr = (_Three*)malloc(count * sizeof(_Three));
	int i, j, k = 0;

	for (i = 0; i < _rows; i++)
		for (j = 0; j < _cols; j++)
			// Add triplets to array while there are any left
			if (mat[i][j] == i + j && count) {
				count--;
				arr[k++] = createThree(i, j);
			}
	//return address of array of triplets
	return arr;

}

//Create a Linked List of Triplets
_ThreeList * createThreeList(int** mat, int count, int _rows, int _cols)//ôåð÷öéä îáå÷ùú
{
	int i, j;
	_ThreeList * head = NULL;
	_ThreeList * temp = NULL;
	_ThreeList * p = NULL;

	for (i = 0; i < _rows; i++)
		for (j = 0; j < _cols; j++)
			//Create a new Triplet and add to List while there are any
			if (mat[i][j] == i + j && count) {
				count--;
				temp = (_ThreeList*)malloc(sizeof(_ThreeList));
				temp->thr = createThree(i, j); //value of the current link updates to the current Triplet
				temp->next = NULL;//initallization of the pointer to the next link

				//Insert the newly created link
				if (head == NULL)
				{
					head = temp;
				}
				else
				{
					p = head;
					while (p->next != NULL) {
						p = p->next;
					}
					p->next = temp;
				}
			}
	//return the head of the Linked List of Triplets
	return head;
}
