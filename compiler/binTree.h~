//***************************************************************
//                      binTree.h
//Name: Mark Safran
//Date: Sept 15, 2014
//Class: CSCI 364 - Compiler Constuction
//Instructor: Professor King
//Purpose: This program creates an editable and searchable stack
//          of binary search trees.
//***************************************************************

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct node{
	struct symbol* data;
	struct node* left;
	struct node* right;
};

struct symbol{
	char *kind; //describe the kind of node (i.e. parameter, proced, var, etc)
	char *name; //identifier name
	struct node* parentType; //parent type if kind is a var
	int value; //if int, value of the int
	char *mode; //if formal param, param type (i.e. in, out, in out, etc)
	struct node* next;
	struct node* componentType; //if array, type of the array elements
	int lower, upper; //first and last indices for array types
	int size; //the size of the symbol in the stack/memory
	int offset; //used for activation stack accessing
	int sizeAR;
	int jump;
};

typedef struct node Node;

struct treeLabel{
	char *name;
	Node *p;
};

struct treeLabel theStack[100];
int stackCount = 0;


push(char *newTree)
{
	stackCount++;
	theStack[stackCount].p = NULL;
	theStack[stackCount].name = malloc(strlen(newTree));
	strcpy(theStack[stackCount].name, newTree);
	printf ("\n\n");

}//end push


pop()
{
	if(stackCount <= 0){
		//printf("Stack is empty!");
		return;
	}else{
		//printf("Destroying tree %s...\n", theStack[stackCount].name);
		destroyTree(theStack[stackCount].p);
		//printf("Tree %s successfully popped off the stack.\n", 
		//theStack[stackCount].name);
		stackCount--;
		//printf("There are now %d tree(s) in the stack\n", stackCount);
	}
	if(stackCount > 0){
		//printf("Top of stack is now tree %s\n", theStack[stackCount].name);
	}else{
		//printf("Stack is empty!!\n");
	}
}


destroyTree(Node *theRoot)
{
	if(theRoot != NULL){
		destroyTree(theRoot->left);
		destroyTree(theRoot->right);
		free(theRoot);
	}	

}//end destroyTree


printTree(Node *theTree)
{
	if(theTree == NULL){
		//printf("Tree is empty!\n");
		return;
	}else{
		printTree(theTree->left);
		printf("%s - %s ", theTree->data->name, theTree->data->kind);
		if(theTree->data->mode != NULL){
			printf("(type %s) ", theTree->data->mode);
		}
		if(theTree->data->parentType != NULL){
			printf("w/ parent type %s ", theTree->data->parentType->data->name);
		}
		
		printf("and offset: %d ", theTree->data->offset);
		printf("and size: %d", theTree->data->size);
		printf("\n");

		printTree(theTree->right);
		
	}
	
		
}


Node* search(Node *theTree, char *searchSym)
{
	if(theTree == NULL){
		return theTree;
	}else if(strcmp(searchSym, theTree->data->name) == 0){
		return theTree;
	}else if(strcmp(searchSym, theTree->data->name) < 0){
		search(theTree->left, searchSym);
	}else if(strcmp(searchSym, theTree->data->name) > 0){
		search(theTree->right, searchSym);
	}
   
}//end search

Node* searchSymbol(char *searchSym)
{
	
	Node *returnTree;
	returnTree = malloc(sizeof(struct node));
	int i;
	int found = -1;
	for(i = stackCount; i >= 0; i=i-1){
		returnTree = search(theStack[i].p, searchSym);

		if(returnTree != NULL){
			found = i;
			break;
		}
	}
	/*
	if(found == -1){
		printf("\n\nSymbol not found in the stack.\n\n");
	}else{
		printf("Symbol %s found in stack %s.", searchSym, theStack[found].name);
	}
	*/
	return returnTree;

}//end searchSym



Node* insert(Node *theTree, char *newData)
{
	Node *tempNode = NULL;
	if(theTree == NULL){
		tempNode = (Node *)malloc(sizeof(Node));
		tempNode->data = malloc(sizeof(struct symbol));
		tempNode->data->name = malloc(strlen(newData));
		strcpy(tempNode->data->name, newData);
		tempNode->left = NULL;
		tempNode->right = NULL;
		theTree = tempNode;
	}else{
		if(strcmp(theTree->data->name, newData) > 0){
			theTree->left = insert(theTree->left, newData);
		}else if(strcmp(theTree->data->name, newData) < 0){
			theTree->right = insert(theTree->right, newData);
		}
	}
	return theTree;

}//end insert


int insertSymbol(char *tempSymbol)
{
	int didInsert;
	Node *returnVal;
	returnVal = malloc(sizeof(struct node));
	returnVal = search(theStack[stackCount].p, tempSymbol);
	if(returnVal != NULL){
		//printf( "Symbol %s already in the current table.\n\n", tempSymbol);
		didInsert = 0;
	}else{
		theStack[stackCount].p = insert(theStack[stackCount].p, tempSymbol);
		didInsert = 1;
	}

	return didInsert;
}//end insertSymbol

/*
handleMenu(char input)
{

	char *tempSymbol;
	tempSymbol = malloc(100);

	switch(input){
	   case 'u': printf("Please enter the name of the new tree: ");
		         scanf( "\n%s", tempSymbol);
		         push(tempSymbol);
		         break;
	   case 'o': pop();
		         break;
   	   case 'a': //addNewData();
				 printf("Please enter the symbol you wish to add: ");
				 scanf( "\n%s", tempSymbol);
			   	 insertSymbol(tempSymbol);
		         break;
	   case 's': printf("Please enter the symbol you want to search for: ");
		         scanf( "\n%s", tempSymbol);
				 searchSymbol(tempSymbol);
				 break;
       case 'q': printf("\nQuitting BST\nDestroying Stack\n");
		         while(stackCount > 0){
					 pop();
				 }
				 printf("\nGoodbye\n");
				 return;
	   default:  printf("Not a valid menu option.\n");
		         return;
	}
	

}//end handleMenu
*/		
/*
init()
{
	stackCount = 1;
	Node *tempNode = NULL;
	tempNode = (Node *)malloc(sizeof(Node));
	tempNode->name = "OC";
	tempNode->left = NULL;
	tempNode->right = NULL;
	
	theStack[1].name = "O";
	theStack[1].p = tempNode;

}
*/
 /* 
main()
{
	//init();
	char input;

	do{
		printf( "\n\np(U)sh:   Push a new empty tree onto the stack. \n");
		printf(	"p(O)p:    Pop the top tree off the stack. \n");
		printf( "(A)dd:    Add a symbol to the binary tree on the top\n");
		printf( "           of the stack. \n");
		printf("(S)earch: Search for a symbol. \n");
		printf("(Q)uit:   Quit this program. \n\n");
		
		printf("Input your command: ");
		scanf( "\n%c", &input);
		handleMenu(input);
	}while(input != 'q');
	
	
}//end main

 */
