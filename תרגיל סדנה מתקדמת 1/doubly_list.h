/*This Project was the result of blood sweat and tears of:
Shay Mualem ID: 200332435  |Grop num 661108-62
Maxim Gromov ID: 317225332 |Grop num 61108-61
*/

#include"trgoStruct.h"
typedef _Three list_type;

/* Structs for EX3 */
//Struct for Node
typedef struct node 
{
   list_type value;	
   struct node *next;
   struct node *prev;
}node;

//Struct for List
typedef struct list
{
	node *head;
	node *tail;
}list;
/*------------------*/

/* Structs for EX4 */
//Struct for Node
typedef struct Ex4node
{
	unsigned int value;
	struct Ex4node *next;
	struct Ex4node *prev;
}Ex4node;

//Struct for List
typedef struct Ex4list
{
	Ex4node *head;
	Ex4node *tail;
}Ex4list;
/*------------------*/


void initList(Ex4list *lst);

int isEmpty(Ex4list *lst);

Ex4node* allocItem(unsigned int value);

int insertLast(Ex4list *lst, Ex4node *item);

int deleteFirst(Ex4list *lst);

int deleteLast(Ex4list *lst);

int deleteLink(Ex4list *lst, Ex4node *link);

int Transfer(Ex4node *link, Ex4list *lst, Ex4list *transfer_list);

int transferLast(Ex4list *lst, Ex4list *transfer_list);

int transferFirst(Ex4list *lst, Ex4list *transfer_list);
