#include "ListInterface.h"
/* some code here (e.g., #include directives, static functions) */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void Initialize (List *L) 
{
	L->size = 0;
}

void Insert (Item X, int position, List *L) 
{
	int i;
	ListNode *current, *temp, *newListNode;

	newListNode = malloc(sizeof(ListNode)*1);
	newListNode->item = X;
	if(position>L->size||position<0||L->size==MAXLISTSIZE)
	{
		printf("Could not insert condition of list not met");
		exit(1);
	}

	current = L->head;
	/*Loop through the List*/
	for(i=0;i<position;i++)
	{
		current = current->next;
	}
	temp = current->next;
	current->next->item = X;
	newListNode->next = temp;
	L->size++;

}

void Remove (int position, List *L) 
{
	int i;
	ListNode *current;
	/* loop through list until att position, set the pointer of teh preceding element to the element that the objeect to be removed is pointing to*/
	/*then subtract form list size*/
	current = L->head; 
	for(i=0;i<position-1;i++)
	{
		current = current->next;
	}
	current->next = current->next;

	L->size--;
}

/*return True is list full*/
int Full (List *L) 
{
	if(L->size>=MAXLISTSIZE)
	{
		return 1;
	}
	else
	{
		return 0;
	} 
}
/*return true if list is empty*/
int Empty (List *L) 
{
	if(L->size==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
/*return number of items in the list*/
int Size (List *L) 
{
	int theSize;
	theSize = L->size;
	return theSize; 
}

void Peek (int position, List *L, Item *X) 
{
	/*For loop through all the linked elements then return the one we get*/
	ListNode *current;
	int i;

	current = L->head;
	for(i=0;i<position;i++)
	{
		current = current->next;
	}
	X = &current->item;

}

void Destroy (List *L) 
{
	/*might have to loop through the list and remove each item as well*/
	/* BURN THE LIST*/
	free(L);
}