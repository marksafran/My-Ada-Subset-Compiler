//***********************************************************************
//                            structList.c
//Name: Mark Safran
//Date: September 29, 2014
//Class: CSCI364 - Compiler Construction
//Instructor: Professor King
//Purpose: This program creates a dynamic list of structs as preparation
//          for another data structure required in our main project.
//***********************************************************************

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct idnode {
	char *name;
	struct idnode *next;
};

typedef struct idnode *idnodeptr;

void print(idnodeptr theList)
{

	idnodeptr tempList;
	tempList = malloc(sizeof(struct idnode));
	tempList = theList;
	if(theList == NULL){
		return;
	}else{
		printf("%s ", tempList->name);
		print(tempList->next);
	}

}//print


idnodeptr add(idnodeptr theList, char *theName)
{

	if(theList == NULL){
		idnodeptr tempNode;
		tempNode = malloc(sizeof(struct idnode));
		theList = malloc(sizeof(struct idnode));
		tempNode->name = malloc(strlen(theName));
		strcpy(tempNode->name, theName);
		tempNode->next = NULL;
		theList = tempNode;
	}else{
		theList->next = add(theList->next, theName);
	}
	return theList;
}//add
		

idnodeptr delete(idnodeptr theList)
{
	theList = NULL;

	return theList;
}

/*
idnodeptr handleMenu(idnodeptr theList, char input)
{

	char *tempSymbol;
	tempSymbol = malloc(100);

	switch(input){
	   case 'p': print(theList);
		         break;
       case 'a': printf("Enter the name of the struct you wish to add: ");
		         scanf( "\n%s", tempSymbol);
		         theList = add(theList, tempSymbol);
		         break;
	   case 'q': return;
	   default:  printf("Not a valid menu option.\n");
		         return;
	}
	
	return theList;
}//end handleMenu
*/
/*
main()
{

	idnodeptr theList;
	//theList = malloc(sizeof(idnodeptr));
	//strcpy(theList->name, "first");
	//theList->next = NULL;

	char input;
	
	do{
		printf( "\n\n(P)rint:   Print the list of structs. \n");
		printf( "(A)dd:    Add a struct to the list\n");
		printf("(Q)uit:   Quit this program. \n\n");
		
		printf("Input your command: ");
		scanf( "\n%c", &input);
		theList = handleMenu(theList, input);
	}while(input != 'q');
	

}//main
*/
