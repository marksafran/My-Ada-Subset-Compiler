/***********************************************************************
//                          patchList.h
//Name: Mark Safran
//Date: November 13, 2014
//Class: Compiler Construction
//Instrcutor: Professor King
//Purpose:  New structures and functions for Part 4 of the main project.
//           Helps with Loops, Arrays, If/Else Stmts, and I/O operations
//********************************************************************/

struct patchList{
	int instructionNum;
	int fillNum;
	struct patchList* next;
};

typedef struct patchList patchList;

struct toPatch{
	int instructionNum;
	struct toPatch* next;
};
typedef struct toPatch toPatch;

struct stack{
	toPatch *list;
};
struct stack patchStack[100];
int patchStackCount = 0;

struct patchList *thePatchList;


//generic swap function, from rshart15, from interwebs
// http://faculty.salina.k-state.edu/tim/CMST302/study_guide/topic7/bubble.html
patchList *list_switch( patchList *l1, patchList *l2 )
{
    l1->next = l2->next;
    l2->next = l1;
    return l2;

}

//classic bubble sort, from rshart15, from interwebs
// http://faculty.salina.k-state.edu/tim/CMST302/study_guide/topic7/bubble.html
patchList *sort(patchList *start )
{
    patchList *p, *q, *top;
    int changed = 1;


    if( (top = malloc(sizeof(struct patchList))) == NULL) {
        fprintf( stderr, "Memory Allocation error.\n" );
        exit(1);
    }

    top->next = start;
    if( start != NULL && start->next != NULL ) {
        /*
        * This is a survival technique with the variable changed.
        *
        * Variable q is always one item behind p. We need q, so
        * that we can make the assignment q->next = list_switch( ... ).
        */

        while( changed ) {
            changed = 0;
            q = top;
            p = top->next;
            while( p->next != NULL ) {
                /* push bigger items down */
                if( p->instructionNum > p->next->instructionNum ) {
                    q->next = list_switch( p, p->next );
                    changed = 1;
                }
                q = p;
                if( p->next != NULL )
                    p = p->next;
            }
        }
    }
    p = top->next;
    free( top );
    return p;
}


void printPatches()
{
	thePatchList = sort(thePatchList);
	
	patchList *tempList = NULL;
	tempList = malloc(sizeof(struct patchList));
	tempList = thePatchList;

	while(tempList != NULL){
		printf("%d  pc := %d\n", tempList->instructionNum, tempList->fillNum);
		tempList = tempList->next;
	}

}


//puts individual instructions and their patched jump addresses
// into the entire patch list, in order
void addInOrder(int instruction, int jumpAddress)
{
	patchList *counter = thePatchList;

	patchList *tempPatch = NULL;
	tempPatch = malloc(sizeof(struct toPatch));
	tempPatch->instructionNum = instruction;
	tempPatch->fillNum = jumpAddress;
	
	if(thePatchList == NULL){
		tempPatch->next = NULL;
		thePatchList = tempPatch;
	}else{
		while(counter->next != NULL){
			counter = counter->next;
		}
		counter->next = tempPatch;
		tempPatch->next = NULL;
	}
	
	

}//end addInOrder


//helper function that runs through an entire toPatch list
// and adds it to the greater PatchList with a call to AddInOrder
void addPatchList(toPatch *toPL, int jumpAddress)
{
	toPatch *tempList = NULL;
	tempList = malloc(sizeof(struct toPatch));
	tempList = toPL;
	
	
	//for all items in the toPatch list
	while(tempList != NULL){
		addInOrder(tempList->instructionNum, jumpAddress);
		tempList = tempList->next;

	}

}//end addPatchList

void printPatchList(toPatch *toPL)
{
	toPatch *tempList = NULL;
	tempList = malloc(sizeof(struct toPatch));
	tempList = toPL;

	while(tempList != NULL){
		tempList = tempList->next;
	}

}


void destroyStackLevel(toPatch *theLevel)
{
	if(theLevel != NULL){
		destroyStackLevel(theLevel->next);
		free(theLevel);
	}


}//end destroyStackLevel

//adds another level to the stack of toPatch lists
pushPatch()
{
	patchStackCount++;
	patchStack[patchStackCount].list = NULL;

   
}//end pushPatch

//adds all the elements in the top of the toPatch stack to the
// PatchList with a call to addPatchList, before removing
popPatch(int jumpAddress)
{
	if(patchStackCount <= 0){
		return;
	}else{
		addPatchList(patchStack[patchStackCount].list, jumpAddress);
		printPatchList(patchStack[patchStackCount].list);
	
		
		destroyStackLevel(patchStack[patchStackCount].list);
		patchStackCount--;
	}

}//end popPatch

//adds an instruction element to the toPatch list on the top
// of the toPatch stack
insertToPatch(int stackLevel, int newPatchNum)
{
	toPatch *counter = patchStack[stackLevel].list;
	toPatch *prev;
	int exists;

	exists = searchToPatch(newPatchNum);
	if(exists != 0){
		printf("already added this instruction!!\n");
		return;
	}else{
		toPatch *tempPatch = NULL;
		tempPatch = malloc(sizeof(struct toPatch));
		tempPatch->instructionNum = newPatchNum;
	
		if(patchStack[stackLevel].list == NULL){
			tempPatch->next = NULL;
			patchStack[stackLevel].list = tempPatch;
		}else{
			while(counter->next != NULL){
				counter = counter->next;
			}
			counter->next = tempPatch;
			tempPatch->next = NULL;
		}
	}


}//end insertToPatch

//searches a single level of the toPatch stack for an
// instruction element
int searchPL(toPatch *thePL, int searchPatchNum)
{
	if(thePL == NULL){
		return 0;
	}else if(thePL->instructionNum == searchPatchNum){
		return 1;
	}else{
		searchPL(thePL->next, searchPatchNum);
	}

}//end searchPL

//helper function to search all levels of the stack.
// calls searchPL
int searchToPatch(int searchPatchNum)
{
	int didSearch;
	int found = 0;
	int i;

	for(i = patchStackCount; i >=0; i--){
		didSearch = searchPL(patchStack[i].list, searchPatchNum);
	
		if(didSearch != 0){
			found = i;
			break;
		}
	}
	return found;
}//end searchToPatch





