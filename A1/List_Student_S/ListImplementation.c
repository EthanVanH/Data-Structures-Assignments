#include "ListInterface.h"
/* some code here (e.g., #include directives, static functions) */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void Initialize (List *L) 
{

	L = malloc(sizeof(List)*1);
	L->size = 0;

	/*Postconditions Debug*/
	#ifdef DEBUG
	if(Empty(L) != 1||Size(L)>0)
	{
		printf("Postconditions : Empty(%d) Size(%d)\n",Empty(L),Size(L));
	}
	#endif
}

void Insert (Item X, int position, List *L) 
{
	int i;
	int initSize;
	/*Preconditions*/
	#ifdef DEBUG
	if(position>MAXLISTSIZE||position<0)
	{
		printf("Position %d Full(%d)\n",position,Full(L));
		exit(1);
	}
	#endif
	initSize = L->size;

	/*loop through the list backwards bumping every item down a positon*/
	/*add to list size*/
	for(i = MAXLISTSIZE; i!=position;i--)
	{
		if(position+1 <= MAXLISTSIZE)
		{
			/*this is broken as fuck but whenever i set i instead of position size resets*/
			L->items[position+1] = L->items[position];
		}
		else
		{
			/*WE can break loop on this condition if we are given a position outside of maxsize */
			/*However im assuming that it will just be the last position*/
		}
	}

	L->items[position] = X;
	L->size++;

	/*postconditions*/
	#ifdef DEBUG
	if(Empty(L)==1||Size(L)<initSize)
	{
		printf("Insert Postconditions :Empty(%d), Size(%d)\n",Empty(L),Size(L));
		exit(1);
	}
	#endif
}

void Remove (int position, List *L) 
{
	int i;
	int initSize;

	/*Preconditions*/
	#ifdef DEBUG
	if(position<0||position>MAXLISTSIZE)
	{
		printf("Remove preeconditions position %d\n",position);
		exit(1);
	}
	#endif

	initSize = L->size;

	/* loop through list until att position, set the pointer of teh preceding element to the element that the objeect to be removed is pointing to*/
	/*then subtract form list size*/
	for(i=position;i<L->size;i++)
	{
		L->items[i] = L->items[i+1];

	}
	L->size--;

	/*postconditions*/
	#ifdef DEBUG
	if(Full(L)==1||Size(L)>initSize)
	{
		printf("Remove Postconditions :Full(%d), Size(%d)\n",Full(L),Size(L));
		exit(1);
	}
	#endif
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
	/*Preconditions*/
	#ifdef DEBUG
	if(position <0||position>MAXLISTSIZE||Empty(L))
	{
		printf("Peek Preconditions Position:%d Empty(%d)",position,Empty(L));
		exit(1);
	}
	#endif
	/* loop through list till at position or actually do i even have to loop if its an array style? */
	/*then copy the item there to item X*/
	X = &L->items[position];

}

void Destroy (List *L) 
{
	/*might have to loop through the list and remove each item as well*/
	/* BURN THE LIST*/
	free(L);
}