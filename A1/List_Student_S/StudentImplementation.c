#include "StudentInterface.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* some code here (e.g., #include directives, static functions) */

void InitializeStudent (char *name, int grade, Student *S) 
{
	/*Assign Data*/
	strcpy(S->name,name);
	S->grade = grade;
	#ifdef DEBUG
	if(strcmp(NameOfStudent(*S),"") ==0 ||GradeOfStudent(*S) ==0 )
	{
		printf("Postconditions: NameOfStudent(%s)---GradeOfStudent(%d)",NameOfStudent(*S),GradeOfStudent(*S));
	}
	#endif
}
/*Returns the character name of the student*/
char *NameOfStudent(Student S) 
{
	char *toReturn;
	toReturn = malloc(sizeof(S.name)*1);
	strcpy(toReturn,S.name);
	return toReturn;
}
/*Returns an integer grade from the student*/
int GradeOfStudent(Student S) 
{
	int grade;
	grade = S.grade;
	return grade; 
}
/*In my expiriance this will just break everything*/
void FreeStudent(Student *S) 
{
	free(S);
}