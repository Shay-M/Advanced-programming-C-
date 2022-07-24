/*This Project was the result of blood sweat and tears of:
Shay Mualem  |Grop num 661108-62
Maxim Gromov |Grop num 61108-61
*/

#include<stdio.h>
#include<malloc.h>
#include "doubly_list.h"

/* Function declarations */
Ex4list* createList2(Ex4list *lst);
void Ex5();
/*-----------------------*/

void Ex5()
{
	printf("\n-------------(EX5)--------------\n");
	Ex4list *list = (Ex4list*)malloc(sizeof(Ex4list));
	Ex4list *uneven_list = (Ex4list*)malloc(sizeof(Ex4list));
	initList(list);
	initList(uneven_list);
	_scanfLinkedList(list);
	uneven_list = createList2(list);
	printf("Even List:\n");
	_printLinkedList(list);
	printf("\n");
	printf("Uneven List:\n");
	_printLinkedList(uneven_list);
	printf("\n");
	_freeLinkedList(list);
	_freeLinkedList(uneven_list);
}

Ex4list* createList2(Ex4list *lst)
{
	// Allocation and initiallization of the pointers and lists that will be used
	Ex4list *uneven_lst = (Ex4list*)malloc(sizeof(Ex4list));
	initList(uneven_lst);
	Ex4node *head = lst->head, *temp;

	//if the head of the list is an uneven number - transfer it to the uneven list
	while ((head != NULL) && (head->value % 2))
	{
		temp = head;
		head = head->next;
		transferFirst(lst, uneven_lst);
		lst->head = head;
	}
	//if a link in the list is an uneven number - transfer it to the uneven list
	while (head != NULL)
	{
		if ((head->value % 2))
		{
			head = head->prev;
			Transfer(head->next, lst, uneven_lst);
		}
		head = head->next;
	}
	return uneven_lst;
}
