#include "ListInterface.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* This is a simple program that will read in lines from a text file. And make use of a basic list 
 * The text file is to be formatted as text.txt is currently formatted
 * Written By Ethan V.
 * September 23rd 2015
*/

void printListInfo(List *L);

int main (int argc, char const *argv[]) 
{
	char *txtFileName, *line, *temp;
	char *operation, *position,*name,*value;
	FILE * txtFile;
	List *theList;
	Student newStudent;
	Student *newStudentPtr;
	txtFileName = malloc(sizeof(argv[1]+1));
	strcpy(txtFileName,argv[1]);

	txtFile = fopen(txtFileName, "r");
	line = (char*)malloc(30);
	temp = (char*)malloc(15);

	/*initialize list*/
	theList = malloc(sizeof(List)*1);
	Initialize(theList);

	newStudentPtr = malloc(sizeof(Student)*1);

	/*This loop handles every line of the file*/
	while(fgets(line,255,txtFile) != NULL && strcmp(line, " ") != 0)
	{
		/*printListInfo(theList);*/
		printf("Debug 0");
		temp = strtok(line, " ");
		printf("Debug 1");
		operation = temp;
		if(strcmp("Insert",operation)==0)
		{
			printf("Debug 2");
			temp = strtok(NULL, " ");
			position = temp;
			temp = strtok(NULL, " ");
			name = temp;
			temp = strtok(NULL, " ");
			value = temp;
			/*Make a student with these values*/
			newStudentPtr = &newStudent;
			InitializeStudent(name,atoi(value),newStudentPtr);
			Insert(newStudent,atoi(position),theList);
	
		}
		else
		{
			temp = strtok(NULL, " ");
			position = temp;
			Remove(atoi(position),theList);

		}
	
	}
	printListInfo(theList);
	/*Perform all frees here*/
    return EXIT_SUCCESS;
}

/*
 * This function will print all available information in the list whenever it is called
 * takes a pointer to the list, returns nothing
*/
void printListInfo(List *L)
{
	/*checks if list is empty*/
	if(Empty(L))
	{
		printf("The List is empty; ");
	}
	else
	{
		printf("The List is not empty; ");
	}

	/*Checks if list is Full*/
	if(Full(L))
	{
		printf("The List is Full; ");
	}
	else
	{
		printf("The list is not Full; ");
	}

	/*Checks list size*/
	printf("List is of size : %d\n",Size(L));
}