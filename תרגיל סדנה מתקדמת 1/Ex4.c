/*This Project was the result of blood sweat and tears of:
Shay Mualem ID: 200332435  |Grop num 661108-62
Maxim Gromov ID: 317225332 |Grop num 61108-61
*/

#include<stdio.h>
#include<malloc.h>
#include "doubly_list.h"

/* Function declarations */
Ex4list* createList(Ex4list *lst);
void Insert(Ex4list* lst, unsigned int value);
void Delete(Ex4list* lst, Ex4node *to_delete);
void Ex4();
/*-----------------------*/

void Ex4()
{
	printf("\n-------------(EX4)--------------\n");

	// Allocation and initiallization of the lists that will be used
	Ex4list *list = (Ex4list*)malloc(sizeof(Ex4list));
	Ex4list *uneven_list = (Ex4list*)malloc(sizeof(Ex4list));
	initList(list);
	initList(uneven_list);

	// Getting input from the user into the Linked List
	_scanfLinkedList(list);

	// Moving the uneven numbers to a new Linked List
	uneven_list = createList(list);

	// Printing the even and uneven Linked Lists
	printf("Even List:\n");
	_printLinkedList(list);
	printf("\n");
	printf("Uneven List:\n");
	_printLinkedList(uneven_list);
	printf("\n");

	// Freeing the allocation of both Linked Lists
	_freeLinkedList(list);
	_freeLinkedList(uneven_list);
}

Ex4list* createList(Ex4list *lst)
{
	// Allocation and initiallization of the pointers and lists that will be used
	Ex4list *uneven_lst = (Ex4list*)malloc(sizeof(Ex4list));
	initList(uneven_lst);
	Ex4node *head = lst->head,*temp;

	//if the head of the list is an uneven number - create it in the uneven list and delete from original list
	while ((head != NULL) && (head->value % 2)) 
	{
		Insert(uneven_lst, head->value);
		temp = head;
		head = head->next;
		free(temp);
		lst->head = head;
	}
	//if a link in the list is an uneven number - create it in the uneven list and delete from original list
	while (head != NULL)
	{
		if ((head->value % 2))
		{
			head = head->prev;
			Insert(uneven_lst, head->next->value);
			Delete(lst, head->next);
		}
		head = head->next;
	}
	return uneven_lst;
}

// Creates a new link and adds it to the specified list
void Insert(Ex4list* lst, unsigned int value)
{
	Ex4node *item = allocItem(value);
	insertLast(lst, item);
}

// Deletes a specified link from a list
void Delete(Ex4list* lst, Ex4node *to_delete)
{
	deleteLink(lst, to_delete);
}