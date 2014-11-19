/***********************************************************************
//                          codeGen.h
//Name: Mark Safran
//Date: November 10, 2014
//Class: Compiler Construction
//Instrcutor: Professor King
//Purpose:  New functions for Part 3 of the main project.
//********************************************************************/

FILE *outFile;
int regCount = 1;
int opCount = 0;

struct exprNode{
	int offset;   //same as tree Node
	int baseRegNum; //the reg it's in
	int memory;   //0 not in mem, 1 is in mem
	int value;    //its value if constant
	int isConstant; //0 if constant, 1 if variable, -1 if null
	int isLocal; //0 is not local, 1 is local
	int walkedback; //0 is local, 1 walked back
	struct exprNode* next;
};


typedef struct exprNode exprNode;


void walkBackProc(int regNum, int loopCount)
{
	int i;

	//fprintf(outFile, "%d  r%d := b\n", opCount++, regNum);
	//opCount++;

	for(i = 0; i < loopCount; i++){
		fprintf(outFile, "%d  r%d := contents r%d, 2\n", opCount++,
				regNum, regNum);
	}
	
}//end walkBack



void walkBack(int regNum, int loopCount)
{
	int i;

	fprintf(outFile, "%d  r%d := b\n", opCount++, regNum);
	//opCount++;

	for(i = 0; i < loopCount; i++){
		fprintf(outFile, "%d  r%d := contents r%d, 2\n", opCount++, regNum, regNum);
	}

}//end walkBack



int searchStack(char *searchSym)
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

	return found;

}//end searchSym



void functionCall(int wbCount, Node *procNode)
{
	fprintf(outFile, "PROCEDURE CALL\n");


	//start AR
	fprintf(outFile, "%d  r%d := b\n", opCount++, regCount);
	fprintf(outFile, "%d  b := contents r%d, 0\n", opCount++, regCount);
	
	//dynamic link
	fprintf(outFile, "%d  contents b, 3 := r%d\n", opCount++, regCount);
	
	//static link
	if(wbCount > 0){
		walkBackProc(regCount, wbCount);
		//fprintf(outFile, "%d  contents b, 2 := contents r%d, 2\n", opCount++, regCount++);
	}
	fprintf(outFile, "%d  contents b, 2 := r%d\n", opCount++, regCount++);
	

	//fix next base
	fprintf(outFile, "%d  r%d := %d\n", opCount++, regCount, procNode->data->sizeAR);
	fprintf(outFile, "%d  contents b, 0 := b + r%d\n", opCount++, regCount++);

	fprintf(outFile, "%d  r%d := %d\n", opCount++, regCount, opCount+3);
	fprintf(outFile, "%d  contents b, 1 := r%d\n", opCount++, regCount++);

	fprintf(outFile, "%d  pc := %d\n", opCount++, procNode->data->jump);


}

void emitAssign(int walkBackCount, char *leftSide, exprNode *rightSide)
{

	Node* tempNode = NULL;
	tempNode = searchSymbol(leftSide);

	fprintf(outFile, "ASSIGNMENT\n");

	if(walkBackCount <= 0){
		if(rightSide->isConstant == 0){
			fprintf(outFile, "%d  r%d :=  %d\n", opCount++, regCount,
					rightSide->value);
			fprintf(outFile, "%d  contents b, %d := r%d\n", opCount++,
					tempNode->data->offset, regCount);

		}
		else if(rightSide->memory == 1){
			fprintf(outFile, "%d  contents b, %d := r%d\n", opCount++,
					tempNode->data->offset, regCount);

		}
		else{
			if(rightSide->isLocal == 1){
				fprintf(outFile, "%d  contents b, %d := contents b, %d\n", opCount++,
						tempNode->data->offset, rightSide->offset);
				
			}else{
				/*
				fprintf(outFile, "%d  r%d := contents r%d, %d\n", opCount++, regCount, 
						rightSide->baseRegNum, rightSide->offset);
				*/
				fprintf(outFile, "%d  contents b, %d := contents r%d, %d\n", opCount++,
						tempNode->data->offset, rightSide->baseRegNum, 
						rightSide->offset);	
			}
		}
	}else{
		walkBack(regCount, walkBackCount);
		if(rightSide->isConstant == 0){
			fprintf(outFile, "%d  r%d :=  %d\n", opCount++, ++regCount,
					rightSide->value);
			fprintf(outFile, "%d  contents r%d, %d :=  r%d\n", opCount++, 
					regCount-1, tempNode->data->offset, regCount);

		}else{
			if(rightSide->isLocal == 1){
				fprintf(outFile, "%d  contents r%d, %d := contents b, %d\n", opCount++, 
						regCount, tempNode->data->offset, rightSide->offset);
			
			}else{
				fprintf(outFile, "%d  r%d := contents r%d, %d\n", opCount++, ++regCount, 
						rightSide->baseRegNum, rightSide->offset);

				fprintf(outFile, "%d  contents r%d, %d := r%d\n", opCount++, 
						regCount-1, tempNode->data->offset, regCount);
			}
		}
		
	}

	//  	regCount++;

}//end emitAssign

int emitExp(exprNode *base, exprNode *exponent)
{

	int opCountStart = opCount;

	int baseReg = regCount++;
	int expReg = regCount++;
	int solutionReg = regCount++;
	int counterReg = regCount++;
	int zeroReg = regCount++;
	int comparisonReg = regCount++;
	int oneReg = regCount++;
	

	if(base->isConstant == 0){
		fprintf(outFile, "%d  r%d := r%d\n", opCount++, baseReg, base->baseRegNum);
	}else if(base->isLocal == 1){
		fprintf(outFile, "%d  r%d := contents b, %d\n", opCount++, baseReg,
				base->offset);
	}else{
		fprintf(outFile, "%d  r%d := contents r%d, %d\n", opCount++, baseReg,
				base->baseRegNum, base->offset);
	}

	if(exponent->isConstant == 0){
		fprintf(outFile, "%d  r%d := r%d\n", opCount++, expReg, exponent->baseRegNum);
	}else if(exponent->isLocal == 1){
		fprintf(outFile, "%d  r%d := contents b, %d\n", opCount++, expReg,
				exponent->offset);
	}else{
		fprintf(outFile, "%d  r%d := contents b, %d\n", opCount++, expReg,
				exponent->baseRegNum, exponent->offset);
	}

	//initializes a register to hold the solution
	fprintf(outFile, "%d  r%d := 1\n", opCount++, solutionReg);

	//initializes counter to exponent value
	fprintf(outFile, "%d  r%d := r%d\n", opCount++, counterReg, expReg);

	//puts 0 in a reg for comparison
	fprintf(outFile, "%d  r%d := 0\n", opCount++, zeroReg);

	//compares counter to 0 ->case if exp is 0 and answer will just be 1
	fprintf(outFile, "%d  r%d := r%d = r%d\n", opCount++, comparisonReg,
			counterReg, zeroReg);

	int endOpNum;
	endOpNum = (opCount + 12);


	//jump to end if counter is 0
	fprintf(outFile, "%d  pc := %d if r%d\n", opCount++, endOpNum, comparisonReg);
	
	//put 1 in a reg for computation
	fprintf(outFile, "%d  r%d := 1\n", opCount++, oneReg);

	//compares counter to 0 ->begins the loop (kind of)
	fprintf(outFile, "%d  r%d := r%d <= r%d\n", opCount++, comparisonReg,
			zeroReg, counterReg);

	fprintf(outFile, "%d  pc := %d if r%d\n", opCount++, (opCount + 2),
			comparisonReg);	

	//fix if exponent is negative
	fprintf(outFile, "%d  r%d := -r%d\n", opCount++, expReg, expReg);

	//beginning of loop
	int loopStart = opCount;
	fprintf(outFile, "%d  r%d := r%d * r%d\n", opCount++, solutionReg,
			solutionReg, baseReg);

	fprintf(outFile, "%d  r%d := r%d - r%d\n", opCount++, counterReg,
			counterReg, oneReg);

	fprintf(outFile, "%d  r%d := r%d < r%d\n", opCount++, comparisonReg,
			zeroReg, counterReg);

	fprintf(outFile, "%d  pc := %d if r%d\n", opCount++, loopStart, comparisonReg);


	//Done with looping
	fprintf(outFile, "%d  r%d := r%d <= r%d\n", opCount++, comparisonReg,
			zeroReg, expReg);

	fprintf(outFile, "%d  pc := %d if r%d\n", opCount++, (opCount +3),
			comparisonReg);	

	//not sure if this should be here v
   	fprintf(outFile, "%d  r%d := r%d / r%d\n", opCount++, solutionReg, oneReg,
			solutionReg);
	
	fprintf(outFile, "the solution register is: r%d\n", solutionReg);

	return solutionReg;

}//end emitExp


int emitArithmetic(exprNode *leftSide, char operation, exprNode *rightSide)
{
	//fprintf(outFile, "left side const is: %d\n", leftSide->isConstant);
	//fprintf(outFile, "left side memory is: %d\n", leftSide->memory);

	//fprintf(outFile, "right side const is: %d\n", rightSide->isConstant);
	//fprintf(outFile, "right side memory is: %d\n", rightSide->memory);

	if(leftSide->isLocal == 1){
		if(rightSide->isConstant == 0){
			fprintf(outFile, "%d  r%d := %d\n", opCount++, regCount, rightSide->value);
			fprintf(outFile, "%d  r%d := contents b, %d %c r%d\n", opCount++,
					regCount, leftSide->offset, operation, rightSide->baseRegNum);
		}else if(rightSide->memory == 1){
			fprintf(outFile, "%d  r%d := contents b, %d %c r%d\n", 
					opCount++, regCount, leftSide->offset, operation, 
					rightSide->baseRegNum);
		}else if(rightSide->isLocal == 1){
			fprintf(outFile, "%d  r%d := contents b, %d %c contents b, %d\n", 
					opCount++, regCount, leftSide->offset, operation, 
					rightSide->offset);
		}else{
			fprintf(outFile, "%d  r%d := contents b, %d %c contents r%d, %d\n", 
					opCount++, regCount, leftSide->offset, operation, 
					rightSide->baseRegNum, rightSide->offset);
		}
	}else if(leftSide->isConstant == 0){
		if(rightSide->isConstant == 0){
			fprintf(outFile, "%d  r%d := %d\n", opCount++, regCount, leftSide->value);
			fprintf(outFile, "%d  r%d :=  r%d %c r%d\n", opCount++,
					regCount, regCount, operation, rightSide->baseRegNum);
		}else if(rightSide->isLocal == 1){
			fprintf(outFile, "%d  r%d := %d\n", opCount++, regCount, leftSide->value);
			fprintf(outFile, "%d  r%d :=  r%d %c contents b, %d\n", opCount++,
					regCount, regCount, operation, rightSide->offset);
		}else{
			fprintf(outFile, "%d  r%d := %d\n", opCount++, regCount, leftSide->value);
			fprintf(outFile, "%d  r%d :=  r%d %c contents r%d, %d\n", opCount++,
					regCount, regCount, operation, rightSide->baseRegNum,
					rightSide->offset);
		}
		//****************
	}else if(leftSide->memory == 1){
		if(rightSide->isConstant == 0){
			fprintf(outFile, "%d  r%d := %d\n", opCount++, ++regCount, rightSide->value);
			fprintf(outFile, "%d  r%d :=  r%d %c r%d\n", opCount++,
					regCount, leftSide->baseRegNum, operation, regCount);
		}else if(rightSide->isLocal == 1){
			//fprintf(outFile, "%d  r%d := %d\n", opCount++, regCount, leftSide->value);
			fprintf(outFile, "%d  r%d :=  r%d %c contents b, %d\n", opCount++,
					regCount, leftSide->baseRegNum, operation, rightSide->offset);
		}else{
			//fprintf(outFile, "%d  r%d := %d\n", opCount++, regCount, leftSide->value);
			fprintf(outFile, "%d  r%d :=  r%d %c contents r%d, %d\n", opCount++,
					regCount, leftSide->baseRegNum, operation, rightSide->baseRegNum,
					rightSide->offset);
		}

		//***************************

	}else{
		if(rightSide->memory == 1){
			fprintf(outFile, "%d  r%d :=  contents r%d, %d %c r%d\n", opCount++,
					regCount, leftSide->baseRegNum, leftSide->offset,
					operation, rightSide->baseRegNum);
		}else if(rightSide->isLocal == 1){
			fprintf(outFile, "%d  r%d :=  contents r%d, %d %c contents b, %d\n",
					opCount++, regCount, leftSide->baseRegNum, leftSide->offset,
					operation, rightSide->offset);
		}else{
			fprintf(outFile, "%d  r%d :=  contents r%d, %d %c contents r%d, %d\n", 
					opCount++, regCount, leftSide->baseRegNum, leftSide->offset,
					operation, rightSide->offset);
		}
	}

	return regCount;

}//end emitArithmetic


int emitRelational(exprNode *left, char *relation, exprNode *right)
{

	exprNode *tempNode = NULL;
	tempNode = malloc(sizeof(struct exprNode));

	if(strcmp(relation, ">") == 0){
		strcpy(relation, "<");
		tempNode = left;
		left = right;
		right = tempNode;
	}else if(strcmp(relation, ">=") == 0){
		strcpy(relation, "<=");
		tempNode = left;
		left = right;
		right = tempNode;
	}

	fprintf(outFile, "RELATIONAL\n");

	if(left->isConstant == 0){
		if(right->isConstant == 0){
			fprintf(outFile, "%d  r%d := r%d %s %d\n", opCount++,
					regCount, left->baseRegNum, relation, right->value);
		}else if(right->isLocal == 1){
			fprintf(outFile, "%d  r%d := contents b, %d\n", opCount++, regCount++,
				   right->offset);
			fprintf(outFile, "%d  r%d := r%d %s r%d\n", opCount++,
					regCount, left->baseRegNum, relation, regCount-1);
		}else{
			fprintf(outFile, "%d  r%d := contents r%d, %d\n", opCount++, regCount++,
				   right->baseRegNum, right->offset);			
			fprintf(outFile, "%d  r%d := r%d %s r%d\n", opCount++,
					regCount, left->baseRegNum, relation, regCount-1);
		}
	}else if(left->isLocal == 1){
		if(right->isConstant == 0){
			fprintf(outFile, "%d  r%d := contents b, %d\n", opCount++, regCount++,
				   left->offset);
			fprintf(outFile, "%d  r%d := r%d %s %d\n", opCount++,
					regCount, regCount-1, relation, right->value);
		}else if(right->isLocal == 1){
			fprintf(outFile, "%d  r%d := contents b, %d\n", opCount++, regCount++,
				   left->offset);
			fprintf(outFile, "%d  r%d := contents b, %d\n", opCount++, regCount++,
				   right->offset);
			fprintf(outFile, "%d  r%d := r%d %s r%d\n", 
					opCount++, regCount, regCount-2, relation, 
					regCount-1);
		}else{
			fprintf(outFile, "%d  r%d := contents b, %d\n", opCount++, regCount++,
				   left->offset);
			fprintf(outFile, "%d  r%d := contents r%d, %d\n", opCount++, regCount++,
				   right->baseRegNum, right->offset);
			fprintf(outFile, "%d  r%d := r%d %s r%d\n", 
					opCount++, regCount, regCount-2, relation, regCount-1);
		}
	}else{
		if(right->isConstant == 0){
			fprintf(outFile, "%d  r%d := contents r%d, %d\n", opCount++, regCount++,
				   left->baseRegNum, left->offset);
			fprintf(outFile, "%d  r%d := r%d %s %d\n", opCount++,
					regCount, regCount-1, relation, right->value);
		}else if(right->isLocal == 1){
			fprintf(outFile, "%d  r%d := contents r%d, %d\n", opCount++, regCount++,
				   left->baseRegNum, left->offset);
			fprintf(outFile, "%d  r%d := contents b, %d\n", opCount++, regCount++,
				    right->offset);
			fprintf(outFile, "%d  r%d := r%d %s %d\n", opCount++, regCount, 
					regCount-2, relation, regCount-1);
		}else{
			fprintf(outFile, "%d  r%d := contents r%d, %d\n", opCount++, regCount++,
				   left->baseRegNum, left->offset);
			fprintf(outFile, "%d  r%d := contents r%d, %d\n", opCount++, regCount++,
				   right->baseRegNum, right->offset);
			fprintf(outFile, "%d  r%d := r%d %s r%d\n", 
					opCount++, regCount, regCount-2, relation, regCount-1);
		}
	}
		
	return regCount;

}//end emitRelational

void patch(char *theFile, int opCount, int mainARsize, int prologJump)
{

	FILE *inFile;
	FILE *outFile;
	char * line = NULL;
	size_t len = 0;
	ssize_t read;
	char instruction[80];
	int i;

	inFile = fopen(theFile, "r");
	outFile = fopen("machineCode.txt", "w");
	
	
	//printf("INSIDE PATCH\n");

	while ((read = getline(&line, &len, inFile)) != -1) {
		//printf("inside while loop\n");

		for(i = 0; i < len; i++){
			instruction[i] = line[i];
		
			if(line[i] == '?'){
				//printf("i is a '?'\n");
				//printf("line is %s\n", line);
				if(instruction[0] == '0'){
					fprintf(outFile, "%d\n", opCount);
					break;
					//instruction[i] = opCount;
				}else if(instruction[0] == '1'){
					fprintf(outFile, "%d\n", (opCount + mainARsize + 1));
					break;
					//instruction[i] = 'S'; //(opCount + mainARsize);
				}else if(instruction[0] == '3'){
					fprintf(outFile, "%d\n", prologJump);
					break;
					//instruction[i] = 'J'; //prologJump;
				}
			}else{

				fprintf(outFile, "%c", instruction[i]);
			}
		}//end for
		//instruction = NULL;


		//	fprintf(outFile, instruction);
		
		
	}

	fclose(inFile);
	fclose(outFile);

	
		
}//end patch
