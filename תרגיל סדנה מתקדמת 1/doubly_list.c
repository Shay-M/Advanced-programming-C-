/*This Project was the result of blood sweat and tears of:
Shay Mualem  |Grop num 661108-62
Maxim Gromov  |Grop num 61108-61
*/

#include <stdlib.h>
#include "doubly_list.h"

//Initiallization of a Linked List (NULLing the pointers)
void initList(Ex4list *lst)
{
	lst->head = lst->tail = NULL;	
}

//is list empty
int isEmpty(Ex4list *lst)
{
	
	return lst->head == NULL;
}

//allocate a new item
Ex4node* allocItem(unsigned int value)
{
	Ex4node* item = (Ex4node*)malloc(sizeof(Ex4node));
	item->value = value;
	item->next = NULL;
	item->prev = NULL;
	return item;
}

//insert item at the last location
int insertLast(Ex4list *lst, Ex4node *item)
{
	if (item != NULL)
	{
		//reset item pointers
		item->next = item->prev = NULL;
	
		if(isEmpty(lst))
		{
			//make head & tail pointing to item
			lst->head = lst->tail = item;
		}
		else 
		{
			//update last next link
			lst->tail->next = item;     
			//point item to old last link
			item->prev = lst->tail;
			//point last to new last node
			lst->tail = item;
		}
		return 1;
	}
	return 0;
}

//delete first item
int deleteFirst(Ex4list *lst)
{	
	//if list is empty there is nothing to delete
	if (!isEmpty(lst))
	{
		//save reference to first link
		Ex4node *temp = lst->head;

		//if only one link
		if(temp->next == NULL)
		{			
			initList(lst);
		}
		else
		{
			lst->head->next->prev = NULL;
			lst->head = lst->head->next;
		}
		free(temp);
		return 1;
	}
	return 0;
}

//delete link at the last location
int deleteLast(Ex4list *lst)
{
	//if list is empty there is nothing to delete
	if (!isEmpty(lst))
	{
		//save reference to last link
		Ex4node *temp = lst->tail;

		//if only one link
		if(temp->prev == NULL)
		{
			initList(lst);
		}
		else
		{
			lst->tail->prev->next = NULL;
			lst->tail = lst->tail->prev;
		}
		free(temp);
		return 1;
	}
	return 0;
}

//delete link from list
int deleteLink(Ex4list *lst, Ex4node *link)
{
	if (!isEmpty(lst))
	{
		if (link == NULL)
			return 0;
		if (link == lst->head)
			return deleteFirst(lst);
		if (link == lst->tail)
			return deleteLast(lst);

		//bypass the current link
		link->prev->next = link->next;
		link->next->prev = link->prev;
		free(link);
		return 1;
	}
	return 0;
}

//move a link from one list to another using pointer alteration
int Transfer(Ex4node *link, Ex4list *lst,Ex4list *transfer_list)
{
	if (!isEmpty(lst))
	{
		if (link == NULL)
			return 0;
		if (link == lst->head)
			return transferFirst(lst, transfer_list);
		if (link == lst->tail)
			return transferLast(lst, transfer_list);

		//bypass the current link
		link->prev->next = link->next;
		link->next->prev = link->prev;
		insertLast(transfer_list, link);
		return 1;
	}
	return 0;
}

//move the last link of one list to another using pointer alteration
int transferLast(Ex4list *lst, Ex4list *transfer_list)
{
	//if list is empty there is nothing to delete
	if (!isEmpty(lst))
	{
		//save reference to last link
		Ex4node *temp = lst->tail;

		//if only one link
		if (temp->prev == NULL)
		{
			initList(lst);
		}
		else
		{
			lst->tail->prev->next = NULL;
			lst->tail = lst->tail->prev;
		}
		insertLast(transfer_list, temp);
		return 1;
	}
	return 0;
}

//move the first link of one list to another using pointer alteration
int transferFirst(Ex4list *lst, Ex4list *transfer_list)
{
	//if list is empty there is nothing to delete
	if (!isEmpty(lst))
	{
		//save reference to first link
		Ex4node *temp = lst->head;

		//if only one link
		if (temp->next == NULL)
		{
			initList(lst);
		}
		else
		{
			lst->head->next->prev = NULL;
			lst->head = lst->head->next;
		}
		insertLast(transfer_list, temp);
		return 1;
	}
	return 0;
}
