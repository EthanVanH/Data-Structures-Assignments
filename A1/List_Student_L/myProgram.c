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

int main (void) 
{
	char *txtFileName, *line, *temp;
	char *operation, *position,*name,*value;
	FILE *txtFile;
	List *theList;
	Student newStudent;
	Student *newStudentPtr;

	line = (char*)malloc(255);
	temp = (char*)malloc(100);
	
	/*Get filename from user*/
	txtFileName = malloc(sizeof(char*)*30);
	printf("Please enter the name of the text file\n");
	scanf("%s",txtFileName);
	txtFileName[strlen(txtFileName)] = '\0';

	/*ensure text file is opened*/
	if(!(txtFile = fopen(txtFileName, "r")))
	{
		perror("Could not open file");
		exit(EXIT_FAILURE);
	}


	/*initialize list*/
	theList = malloc(sizeof(List)*1);
	Initialize(theList);
	
	newStudentPtr = malloc(sizeof(Student)*1);
	/*This loop handles every line of the file*/
	while(fgets(line,100,txtFile) != NULL&& strcmp(line, " ") != 0)
	{
		printListInfo(theList);
		temp = strtok(line, " ");
		operation = temp;
		if(strcmp("Insert",operation)==0)
		{
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
	/*close the text file*/
	fclose(txtFile);
	/*Perform all frees here*/
	Destroy(theList);
	free(txtFileName);
    return EXIT_SUCCESS;
}

/*
 * This function will print all available information in the list whenever it is called
 * takes a pointer to the list, returns nothing
 * if the list does not exist bad things will happen
*/
void printListInfo(List *L)
{
	int i;
	Item *X;
	Item Y;
	X = malloc(sizeof(Item)*1);
	X= &Y;
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
	for(i = 0; i<MAXLISTSIZE;i++)
	{
		Peek(i,L,X);
		/*printf("%d:%s %d\n",i,NameOfStudent(Y),GradeOfStudent(Y));*/
	}
}