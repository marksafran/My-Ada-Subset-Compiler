/***********************************************************************
//                          moreStatements.h
//Name: Mark Safran
//Date: November 13, 2014
//Class: Compiler Construction
//Instrcutor: Professor King
//Purpose:  New structures and functions for Part 4 of the main project.
//           Helps with Loops, Arrays, If/Else Stmts, and I/O operations
//********************************************************************/


void emitRead(exprNode *theExpr)
{

	struct exprNode *tempNode = NULL;
	tempNode = malloc(sizeof(struct exprNode));
	tempNode = theExpr;

	if(tempNode->next != NULL){
		yyerror("Can only read single ID");
	}else if(tempNode->isConstant == 0){
		yyerror("Cannot read into constant");
	}else if(tempNode->isLocal == 1){
		fprintf(outFile, "%d  read contents b, %d\n", opCount++, 
				tempNode->offset);
	}else{
		fprintf(outFile, "%d  read contents r%d, %d\n", opCount++, 
				tempNode->baseRegNum, tempNode->offset);
	}

}//end emitRead

void emitWrite(exprNode *theExpr)
{

	struct exprNode *tempNode = NULL;
	tempNode = malloc(sizeof(struct exprNode));
	tempNode = theExpr;

	while(tempNode != NULL){

		if(tempNode->isConstant == 0){
			fprintf(outFile, "%d  r%d := %d\n", opCount++, regCount, tempNode->value);
			fprintf(outFile, "%d  write r%d\n", opCount++, regCount);
		}else if(tempNode->isLocal == 1){
			fprintf(outFile, "%d  write contents b, %d\n", opCount++, tempNode->offset);
		}else{
			fprintf(outFile, "%d  write contents r%d, %d\n", opCount++,
					tempNode->baseRegNum, tempNode->offset);
		}

		tempNode = tempNode->next;
	}

}//end emitWrite


void emitArrayAssign(Node *theArray, exprNode *theExpr)
{

	struct exprNode *tempNode = NULL;
	tempNode = malloc(sizeof(struct exprNode));
	tempNode = theExpr;

	fprintf(outFile, "%d  contents \n", opCount++);





}//end emitArrayAssign
