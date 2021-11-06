/*This Project was the result of blood sweat and tears of:
Shay Mualem ID: 200332435  |Grop num 661108-62
Maxim Gromov ID: 317225332 |Grop num 61108-61
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "doubly_list.h"

#define COL_A  4
#define ROW_B  5
#define COMMON_SIZE 3
#define num 5

/* Declarations of the main functions of the assignment */
void Ex1();
void Ex2();
void Ex3();
void Ex4();
void Ex5();
/*-----------------------*/

/* Declarations of dynamic print, scan and free functions */
int ** _creatMatrix(int rows, int cols);
void _freeMatrix(int ** a, int _rows);
void _printLinkedList(Ex4list* lst);
void _scanfLinkedList(Ex4list* lst);
void _freeLinkedList(Ex4list *list);
void _printThreeList(_ThreeList * t);
void _freeThreeList(_ThreeList * head);
void _printThree(_Three * t, int count);
void _scanfMatrix(int **mat, int rows, int cols);
void _printMatrix(int **a, int rows, int cols);
/* ------------------------------------------------------ */

int main()
{
	int select = 0, i, all_Ex_in_loop = 0;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf("%d", &all_Ex_in_loop) == 1)
		do
		{
			printf("-------------------------------\n");
			for (i = 1; i <= num; i++)
				printf("Ex%d---> %d\n", i, i);
			printf("\nEXIT--> 0\n");
			do {
				select = 0;
				printf("\nplease select 0-%d : ", num);
				scanf("%d", &select);
			} while ((select < 0) || (select > num));
			switch (select)
			{
			case 1: Ex1(); break;
			case 2: Ex2(); break;
			case 3: Ex3(); break;
			case 4: Ex4(); break;
			case 5: Ex5(); break;

			}
		} while (all_Ex_in_loop && select);
		return 0;
}

/* Definitions of dynamic print, scan and free functions */

// Create a 2D Matrix using dymanic allocation - EX2 and EX3
int ** _creatMatrix(int rows, int cols)
{
	int  **arr, i;
	arr = (int**)calloc(rows, sizeof(int*));
	for (i = 0; i < rows; i++)
		arr[i] = (int*)calloc(cols, sizeof(int));
	return arr;
}

// Freeing dymanically allocated 2d Matrix - EX2 and EX3
void _freeMatrix(int ** a, int _rows) {
	int i;
	for (i = 0; i < _rows; i++)
	{
		free(a[i]);
	}
	free(a);
}


// Printing a 2D Matrix - EX2 and EX3
void _printMatrix(int ** a, int _rows, int _cols)
{
	printf("Matrix:\n");
	int i, j;
	for (i = 0; i < _rows; i++)
	{
		for (j = 0; j < _cols; j++)
		{
			printf("%6d", a[i][j]);
		}
		printf("\n");
	}
}

// Printing of a Linked List - EX4 and EX5
void _printLinkedList(Ex4list* lst)
{
	Ex4node *current = lst->head;
	int count = 0;
	if (current == NULL)
	{
		printf("List is Empty\n");
	}
	else
	{
		while (current != NULL)
		{
			count++;
			printf("link no.%d : value: %u\n", count, current->value);
			current = current->next;
		}
	}
}

// Getting input from user to Linked List - EX4 and EX5
void _scanfLinkedList(Ex4list* lst)
{
	int value = 0;
	Ex4node* item;
	while (value > -1)
	{
		printf("Enter a value for a new link. When you're done insert a negative number:\t");
		scanf_s("%d", &value);
		printf("\n");
		if (value > -1)
		{
			item = allocItem(value);
			insertLast(lst, item);
		}
	}
}

// Freeing dynamically allocated Linked List - EX4 and EX5
void _freeLinkedList(Ex4list *list)
{
	Ex4node *temp, *head = list->head;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}

//Printing Triplets from dynamically allocated Array - EX3
void _printThree(_Three * t, int count)
{
	int k;
	printf("\n\n*FROM ARRAY\n");
	for (k = 0; k < count; k++)
		printf("Element: %d,  i: %d,  j: %d.\n", t[k].X, t[k].i, t[k].j);
}

// Printing Triplets from dynamically allocated Linked List - EX3
void _printThreeList(_ThreeList *head)
{
	_ThreeList* p = head;
	printf("\n\n*FROM LIST\n");
	while (p != NULL)
	{
		printf("Element: %d,  i: %d,  j: %d. \n", p->thr.X, p->thr.i, p->thr.j);
		p = p->next;
	}
}

// Free dynamically allocated Linked List of Triplets - EX3
void _freeThreeList(_ThreeList * head)
{
	_ThreeList *toFree = head;
	while (toFree != NULL)
	{
		head = head->next;
		free(toFree);
		toFree = head;
	}
}

// Getting input from the user to 2D Matrix - EX2 and EX3
void _scanfMatrix(int **arr, int rows, int cols)
{
	int i, j;
	printf("Enter A(%dX%d) Matrix: \n", rows, cols);

	for (i = 0; i < rows; i++)
		for (j = 0; j < cols; j++) {
			printf("(%dX%d): ", i, j);
			scanf_s("%d", &arr[i][j]);
		}
	printf("\n");
}
/* ------------------------------------------------ */

