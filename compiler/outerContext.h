/*******************************************************************
//                        outerContext.h
//Name: Mark Safran
//Date: Nov 5, 2014
//Class: CSCI 364 - Compiler Constuction
//Instructor: Professor King
//Purpose: This program hardcodes and prints the outer context
//          of the symbol table for our main project.
//***************************************************************/

#include <stdlib.h>
#include <stdio.h>


char*  memAndCopy(char *theThing){
   char *destination;
   destination = malloc(strlen(theThing));
   if(strlen(theThing) > 0){
      strcpy(destination, theThing);
   }
   return destination;
}


void outerContext()
{
	
	//theStack[0].p = malloc(sizeof(struct node));
	theStack[0].name = malloc(strlen("OuterContext"));
	strcpy(theStack[0].name, "Outer Context");
	
	Node *newContext = NULL;
	
	

	//INTEGER
	insertSymbol("integer");
	newContext = search(theStack[0].p, "integer");
	//newContext->data = malloc(sizeof(struct symbol));
	newContext->data->kind = memAndCopy("type");
	//newContext->data->kind = malloc(sizeof("type"));
	//strcpy(newContext->data->kind, "type");
	newContext->data->size = 1;
	
	//BOOLEAN
	insert(theStack[0].p, "boolean");
	newContext = search(theStack[0].p, "boolean");
	//newContext->data = malloc(sizeof(struct symbol));
	newContext->data->kind = memAndCopy("type");
	newContext->data->size = 1;

	//TRUE
	insert(theStack[0].p, "true");
	newContext = search(theStack[0].p,"true");
	//newContext->data = malloc(sizeof(struct symbol));
	newContext->data->kind = memAndCopy("value");
	newContext->data->value = 1;

	//FALSE
	insert(theStack[0].p, "false");
	newContext = search(theStack[0].p,"false");
	//newContext->data = malloc(sizeof(struct symbol));
	newContext->data->kind = memAndCopy("value");
	newContext->data->value = 0;
	
	//MAXINT
	insert(theStack[0].p, "maxint");
	newContext = search(theStack[0].p,"maxint");
	//newContext->data = malloc(sizeof(struct symbol));
	newContext->data->kind = memAndCopy("value");
	newContext->data->value = 7;

	//READ
	insert(theStack[0].p, "read");
	newContext = search(theStack[0].p, "read");
	newContext->data->kind = memAndCopy("read_routine");
	
	//WRITE
	insert(theStack[0].p, "write");
	newContext = search(theStack[0].p, "write");
	newContext->data->kind = memAndCopy("write_routine");	


	

}//end OuterContext
