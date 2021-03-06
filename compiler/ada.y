/***********************************************************************
//                          ada.y
//Name: Mark Safran
//Date: October 8, 2014
//Class: Compiler Construction
//Instrcutor: Professor King
//Purpose:  This YACC specification defines the ADA grammar subset we
//           will be using for our main project.
//*********************************************************************/


%{ /* YACC/ada.y */

#define max(a,b) (a < b) ? a : b

	//extern int yydebug;
	//yydebug = 1;


%}

%token ENDIF ENDREC ENDLOOP EXITWHEN IS OF BEG END DOTDOT TICK
PROCEDURE TYPE ARRAY RECORD IN OUT RANGE CONSTANT ASSIGN EXCEPTION
NULLWORD LOOP IF THEN ELSEIF ELSE EXIT WHEN AND OR NOT EQ NEQ GT LT
GTE LTE EXP RAISE OTHERS ARROW ID NUMBER

%type <integer> NUMBER index loopStart
%type <var> ID mode typeName relationalOp booleanOp
%type <idList> idList
%type <nodeThing> arrayRecordRange option array range record parameter parameterList
%type <nodeThing> optionalParams pushHead procHead
%type <expr> primary factor expr term simpleExpr relation exprs
%type <operation> multiplyingOp addingOp

%union {
	int integer;
	char *var;
	char operation;
	struct idnode *idList;
	struct node *nodeThing;
	struct exprNode *expr;
}
%%

program: procedure ';'
{

	fprintf(outFile, "Instruction Count = %d\n", opCount-1);

	printf("THE END\n");

}
; 

procedure: procHead procDecls procStmts procExceptions
{
	//printf("%d, program\n", lineno);

}
;


procHead: pushHead optionalParams
{

	//printf("%d, procedure head\n", lineno);

	if($1 != NULL){
		$1->data->next = $2;
	}

	/*
	push($2->data->name);
	theOffset = 4;
	printf("*******\nPushing new scope for %s\n", $2);
	*/

	$$ = $1;

}
;

pushHead: PROCEDURE ID
{
	Node *tempNode = NULL;
	int good;

	if(stackCount > 0){
	
		good = insertSymbol($2);
		if(good == 1){
			tempNode = searchSymbol($2);
			tempNode->data->kind = memAndCopy("procedure");

			push($2);
			theOffset = 4;
			printf("*******\nPushing new scope for %s\n", $2);
			
		}else{
			//printf("ERROR: Duplicate IDs");
			yyerror("Procedure ID not allowed");
			return(1);
		}
	}else{
		//Object Code Stuff
		fprintf(outFile, "%d  b := ?\n", opCount++);
		fprintf(outFile, "%d  contents b, 0 := ?\n", opCount++);
		fprintf(outFile, "%d  contents b, 1 := 4\n", opCount++);
		fprintf(outFile, "%d  pc := ?\n", opCount++);
		fprintf(outFile, "%d  halt\n", opCount++);

		//****************

		push($2);
		theOffset = 4;
		printf("*******\nPushing new scope for %s\n", $2);
	}

	$$ = tempNode;

}

;

optionalParams: '(' parameterList ')'
{
	$$ = $2;

}
              |
{
	$$ = NULL;

}
;

procDecls: IS decls begin
{

}
         | IS begin
{


}
;

decls : decl ';' decls
{
	//printf("%d, decls List\n", lineno);

}
      | decl ';'
{
	//printf("%d, decls\n", lineno);

}
;

begin: BEG
{
	//printf("%d, begin\n", lineno);
	
	//fprintf(outFile, "reg count is: %d\n", regCount);
	
	//printf(" HERE: stack count is: %d", stackCount);
	
	if(stackCount > 1){
		Node *tempNode = NULL;
		tempNode = searchSymbol(theStack[stackCount].name);
		//printf("node is: %s\n", tempNode->data->name);
		
		
		tempNode->data->sizeAR = theOffset;
		tempNode->data->jump = opCount;	
			
		//printf(" NOW: %s size is %d\n", theStack[stackCount].name, tempNode->data->sizeAR);
		//printf(" NOW: %s jump is %d\n", theStack[stackCount].name, tempNode->data->jump);
	}
	
	//if its for main?
	if(stackCount == 1){
		mainARsize = theOffset;
		prologJump = opCount;
	}
	
}
;

procStmts: stmts
{
    //printf("%d, stmts\n", lineno);

}
;

procExceptions: exception END 
{
	if(stackCount > 0){
		printf("\n************");
		printf("Popping scope for %s, so print tree.\n", theStack[stackCount].name);
		printTree(theStack[stackCount].p);
		
		pop();
	}else{
		printf("END PROGRAM");
	}
}
              | END
{
	if(stackCount > 0){
		printf("\n************");
		printf("Popping scope for %s, so print tree.\n", theStack[stackCount].name);
		printTree(theStack[stackCount].p);
		
		pop();
	}else{
		printf("END PROGRAM\n");
	}

	
	fprintf(outFile, "END PROCEDURE\n");



	fprintf(outFile, "%d  r%d := contents b, 1\n", opCount++, regCount);
	fprintf(outFile, "%d  b := contents b, 3\n", opCount++);
	fprintf(outFile, "%d  pc := r%d\n", opCount++, regCount++);

	fprintf(outFile, "the reg count is: %d\n", regCount-1);


	int basePatch;
	int dynamicPatch;
	int jumpPatch;
	//if main just got popped off
	if(stackCount == 0){
		basePatch = opCount;
	}

}
;


stmts : stmts stmt 
      | stmt 
{
	//printf("%d, stmtsList\n", lineno);
}
;

parameterList : parameter ';' parameterList 
{

	$1->data->next = $3;
	//print($1);
	printf("%s 's next is %s\n", $1->data->name, $3->data->name);
	
	$$ = $1;

}
              | parameter 
{
	//printf("%d, parameterList\n", lineno);

	//print($1);
	$$ = $1;
	printf("%s 's next is %s\n", $1->data->name, $1->data->next);
	

}
;
parameter : idList ':' mode typeName
{
	//printf("%d, parameter\n", lineno);

	Node *tempNode = NULL;
	Node *nextFinder = NULL;
	struct idnode *theList = $1;
	int good;

	while(theList != NULL){
		good = insertSymbol(theList->name);
		if(good == 1){
			tempNode = search(theStack[stackCount].p, theList->name);
			tempNode->data->kind = memAndCopy("parameter");
			tempNode->data->mode = memAndCopy($3);
			tempNode->data->parentType = searchSymbol($4);
			tempNode->data->size = tempNode->data->parentType->data->size;
			tempNode->data->offset = theOffset;
			theOffset = theOffset + tempNode->data->size;

		
			if(nextFinder != NULL){
				nextFinder->data->next = tempNode;
			}
			nextFinder = tempNode;
			//printTree(tempNode);
			theList = theList->next;
		}else{
			//printf("ERROR: Duplicate IDs\n");
			yyerror("Duplicate ID");
			return(1);
		}
	}
	
	$$ = tempNode;
}
;

mode: IN
{
	$$ = memAndCopy("in");
}
    | OUT
{
	$$ = memAndCopy("out");
}
    | IN OUT
{
	$$ = memAndCopy("in out");
}
    |
{
	$$ = memAndCopy("in");
}
;
typeName: ID
{
	//printf("%d, typeName\n", lineno);

	$$ = memAndCopy($1);

}
;


decl: arrayRecordRange  
{
	//printf("%d, decl arrayRecordRange\n", lineno);
}
    | variable          
{
	//printf("%d, decl variable\n", lineno);
}
    | constant          
{
	//printf("%d, decl constant\n", lineno);
}
    | exceptionDecl     
{
	//printf("%d, decl exceptionDecl\n", lineno);
}
    | procedure         
{
	//printf("%d, decl new procedure\n", lineno);
}
;
arrayRecordRange: TYPE ID IS option
{
	//printf("%d, arrayRecordRange\n", lineno);

	Node *tempNode = NULL;
	int good;
 
	good = insertSymbol($2);
	if(good == 1){
		tempNode = searchSymbol($2);
		tempNode->data->kind = memAndCopy($4->data->kind);
		tempNode->data->lower = $4->data->lower;
		tempNode->data->upper = $4->data->upper;
		tempNode->data->componentType = $4->data->componentType;
		tempNode->data->size = $4->data->size;
		//tempNode->data->offset = theOffset;
		//theOffset = theOffset + tempNode->data->size;
	}else{
		//printf("ERROR: Duplicate IDs\n");
		yyerror("Duplicate ID");
		return(1);
	}
	$$ = $4;

}
;

option: array 
{
	//printf("%d, option Array\n", lineno);

	$$ = $1;

}
      | record 
{
	printf("%d, option Record\n", lineno);

}
      | range 
{
	//printf("%d, option Range\n", lineno);

	$$ = $1;

}
;

array : ARRAY '(' index DOTDOT index ')' OF ID
{
	//printf("%d, array\n", lineno);


	int arrayLength;
	arrayLength = (($5 - $3)+1);
	Node *tempNode = NULL;
	tempNode = malloc(sizeof(struct node));
	tempNode->data = malloc(sizeof(struct symbol));


	tempNode->data->kind = memAndCopy("type (array)");
	tempNode->data->lower = $3;
	tempNode->data->upper = $5;
	tempNode->data->componentType = searchSymbol($8);

	tempNode->data->size = (tempNode->data->componentType->data->size * arrayLength);
	//printf("size");

	$$ = tempNode;
}
;

;
index: NUMBER 
{
	//printf("%d, index NUMBER\n", lineno);

	$$ = $1;

}
     | ID 
{
	//printf("%d, index ID\n", lineno);

	Node *tempNode = NULL;
	tempNode = searchSymbol($1);
	if(tempNode == NULL){
		yyerror("ID not found");
	}else{
		$$ = tempNode->data->value;
	}

}
;

record: RECORD componentList ENDREC
{printf("%d, record\n", lineno);}
;
componentList: componentList component
             | component
{printf("%d, componentList\n", lineno);}
;
component: variable ';'
{printf("%d, componentList\n", lineno);}
;

range: RANGE index DOTDOT index
{
	//printf("%d, right\n", lineno);
	
	int rangeLength;
	rangeLength = (($4 - $2)+1);
	Node *tempNode = NULL;
	tempNode = malloc(sizeof(struct node));
	tempNode->data = malloc(sizeof(struct symbol));

	tempNode->data->kind = memAndCopy("type (range)");
	tempNode->data->lower = $2;
	tempNode->data->upper = $4;
	tempNode->data->size = 1;

	$$ = tempNode;
}
;

variable: idList ':' ID
{
	printf("line#: %d - ", lineno);
	print($1);
	printf(": %s\n", $3);

	Node *tempNode = NULL;
	int good;

	while($1 != NULL){
		good = insertSymbol($1->name);
		if(good == 1){
			tempNode = search(theStack[stackCount].p, $1->name);
			tempNode->data->kind = memAndCopy("object");
			tempNode->data->parentType = searchSymbol($3);
			tempNode->data->size = tempNode->data->parentType->data->size;
			tempNode->data->offset = theOffset;
			theOffset = theOffset + tempNode->data->size;
		}else{
			//printf("ERROR: Duplicate IDs\n");
			yyerror("Duplicate ID");
			return(1);
		}
		$1 = $1->next;
	}
}
;
idList: idList ',' ID
{
	//printf("%d, idList multiple\n", lineno);

	theList = add($1, $3);
	$$ = theList;

}
      | ID             
{
	//printf("%d, idList id\n", lineno);
	
	theList = delete(theList);
	theList = add(theList, $1);
	$$ = theList;
	
}
;

constant: idList ':' CONSTANT ASSIGN constantExpr
{printf("%d, constant\n", lineno);}
;
constantExpr: expr
{printf("%d, constantExpr\n", lineno);}
;

exceptionDecl: idList ':' EXCEPTION
{printf("%d, exception declaration\n", lineno);}
;

stmt : ID ASSIGN expr ';'
{

	//fprintf(outFile, "at stmt is ASSIGN, we have r%d\n", $3->baseRegNum);

	//printf("%d, stmt ID assign\n", lineno);
	//printf(" here ID is: %s\n", $1);

	Node *tempNode = NULL;
	tempNode = searchSymbol($1);
	
	//printf("ID here is: %s\n", tempNode->data->name);

	int walkBackCount;
	walkBackCount = (stackCount - searchStack(tempNode->data->name));
	
	emitAssign(walkBackCount, $1, $3);

}
/*
     | ID '(' expr ')' ASSIGN expr ';'
{
	Node *tempNode = NULL;
	tempNode = searchSymbol($1);

	if(strcmp(tempNode->data->kind, "type (array)") == 0){
		//handle array assigns
	
		emitArrayAssign(tempNode, $3);
		
	}else{
		yyerror("Cannot assign subset of non-array variable");
	}

}
*/
     | ID '(' exprs ')' ';'
{

	//printf("%d, stmt ID params\n", lineno);

	Node *tempNode = NULL;
	tempNode = searchSymbol($1);

	if(strcmp(tempNode->data->kind, "read_routine") == 0){
		//do reads

		emitRead($3);

	}else if(strcmp(tempNode->data->kind, "write_routine") == 0){
		//do writes

		emitWrite($3);
	}

}
     | ID ';'
{
	//printf("%d, stmt ID\n", lineno);

	Node *tempNode = NULL;
	tempNode = searchSymbol($1);

	if(strcmp(tempNode->data->kind, "procedure") == 0){
		//do a call
		int walkBackCount;
		walkBackCount = (stackCount - searchStack(tempNode->data->name));

		functionCall(walkBackCount, tempNode);

	}
}
     | NULLWORD ';'
{
	printf("%d, stmt NULL\n", lineno);
	//do nothing
}
     | loopOption ';'
{
	//printf("%d, stmt loopOption\n", lineno);
}
     | ifStmt ';'
{
	//printf("%d, stmt ifStmt\n", lineno);
}
     | RAISE ID ';'
{
	printf("%d, stmt RAISE ID\n", lineno);
}
;


loopOption: loopStart loopStmts ENDLOOP
{
	//printf("loop ENDS here\n\n");

	//end of loop -> doesn't need patching
	fprintf(outFile, "%d  pc := %d\n", opCount++, $1);
	popPatch(opCount);

	
}
;
loopStart: LOOP
{
	//printf("\nNew LOOP starting here\n");
	//start of loop -> no instruction, .: no patching
	pushPatch();
	
	//insertToPatch(opCount);
	//fprintf(outFile, "%d  pc := ?\n", opCount++);
	
	$$ = opCount;

}
;
loopStmts: loopStmts loopStmt
{
	//printf("%d, loopStmts\n", lineno);

}
         | loopStmt
{

}
;
loopStmt: stmt
{
	//printf("loops stmt assign or nested\n");
}

        | EXIT ';'
{
	//printf("%d, sequenceStmt EXIT\n", lineno);

	insertToPatch(patchStackCount, opCount);
	fprintf(outFile, "%d  pc := ?\n", opCount++);


}
        | EXITWHEN expr ';'
{
	printf("%d, sequenceStmt EXITWHEN\n", lineno);

	//NOT HANDLING YET --> PART 5

}
;

ifStmt: beginIf thenPart stmtsPart elseifOption elseOption ENDIF
{
	//printf("%d, ifStmt\n", lineno);

	popPatch(opCount);
	ifCount--;

}
;
beginIf: IF
{
	pushPatch();
	ifCount++;
	theBase[ifCount] = patchStackCount;

}
;
thenPart: expr THEN
{
	pushPatch();
	insertToPatch(patchStackCount, opCount);
	fprintf(outFile, "%d  pc := ? if not r%d\n", opCount++, regCount);

}
;
stmtsPart: stmts
{
	insertToPatch(theBase[ifCount], opCount);
	fprintf(outFile, "%d  pc := ?\n", opCount++);

	printPatchList(patchStack[patchStackCount].list);
	//popPatch(opCount);

}
elseifOption: elseifOption beginElseif thenPart stmtsPart
{
	printf("%d, elseifs w Else\n", lineno);

}
            |
;
beginElseif:  ELSEIF
{
	popPatch(opCount);
}
;

elseOption: beginElse stmtsPart
{
	//popPatch(opCount);
}
          |
{
	popPatch(opCount);
}
;
beginElse: ELSE
{
	popPatch(opCount);
}
;
exprs: expr ',' exprs
{
	$1->next = $3;
	$$ = $1;
}
     | expr
{
	$$ = $1;
}
;

expr: expr booleanOp relation
{
	printf("%d, expr\n", lineno);

	$$->baseRegNum = emitRelational($1, $2, $3);
	$$->isConstant = 1;

}
    | relation
{
	$$ = $1;
	//fprintf(outFile, "at expr is relation, we pass up r%d\n", $$->baseRegNum);
}
;
booleanOp: AND 
{
	printf("%d, booleanOp AND\n", lineno);

	$$ = memAndCopy("and");
}
         | OR  
{
	printf("%d, booleanOp OR\n", lineno);

	$$ = memAndCopy("or");
} 
;
relation: relation relationalOp simpleExpr
{
	//fprintf(outFile, "left is r%d -- right is r%d\n", $1->baseRegNum, $3->baseRegNum);

	//fprintf(outFile, "left is %d -- right is %d\n", $1->isConstant, $3->isConstant);



	$$->baseRegNum = emitRelational($1, $2, $3);
	$$->isConstant = 1;
	

}
        | simpleExpr
{
	//printf("%d, relation\n", lineno);

	$$ = $1;
}
;
relationalOp: EQ   
{
	$$ = memAndCopy("=");
}
            | NEQ  
{
	$$ = memAndCopy("!=");
}
            | LT   
{
	$$ = memAndCopy("<");
}
            | LTE  
{
	$$ = memAndCopy("<=");
}
            | GT   
{
	$$ = memAndCopy(">");
}
            | GTE  
{
	$$ = memAndCopy(">=");
}
;
simpleExpr: '-' term  
{
	//printf("%d, simpleExpr '- term'\n", lineno);
	
	if($2->isConstant == 0){
		$$ = $2;
		$$->value = ($2->value * -1);
	}else{
		if($2->memory == 1){
			fprintf(outFile, "%d  r%d := - r%d\n", opCount++, regCount, $2->baseRegNum);
			$$->isConstant = 1;
			$$->isLocal = 1;
			$$->memory = 1;
		}else if($2->isLocal == 1){
			fprintf(outFile, "%d  r%d := - contents b, %d\n", opCount++, regCount, 
					$2->offset);
			$$->isLocal = 1;
			$$->isConstant = 1;
		}else{
			fprintf(outFile, "%d  r%d := - contents r%d, %d\n", opCount++, regCount, 
					$2->baseRegNum, $2->offset);
			$$->isLocal = 0;
			$$->isConstant = 1;
		}
	}
	$$->baseRegNum = $2->baseRegNum;

}
          | term
{
	//printf("%d, simpleExpr term\n", lineno);

	$$ = $1;
	//fprintf(outFile, "at simpleExpr is term, we pass up r%d\n", $$->baseRegNum);


}
          | simpleExpr addingOp term
{
	//printf("%d, optionalSimpleExpr List\n", lineno);
	//printf("left side value is: %d | right side val: %d\n", $1->value, $3->value);

	if(($1->isConstant + $3->isConstant) == 0){
		fprintf(outFile, "CONSTANT ADDITION / SUBTRACTION\n");
		if($2 == '+'){
			$$->value = $1->value + $3->value;
		}else if($2 == '-'){
			$$->value = $1->value - $3->value;
		}
	}else{
		fprintf(outFile, "ADD / SUBTRACT\n");
		$$->baseRegNum  = emitArithmetic($1, $2, $3);
		$$->memory = 1;
		$$->isConstant = 1;
		$$->isLocal = 0;
		
		//do if vars
	}
	

}
;
addingOp: '+'
{
	//printf("%d, addingOp +\n", lineno);

	$$ = '+';
}
        | '-'
{
	//printf("%d, addingOp -\n", lineno);

	$$ = '-';
}
;
term: factor
{
	//printf("%d, term\n", lineno);

	
	if($1->isConstant == 0){
		$$ = $1;
	}else if($1->walkedback == 1){
		$$->baseRegNum = $1->baseRegNum;
	}else{
		$$->memory = 1;
		$$->baseRegNum = $1->baseRegNum;
		//fprintf(outFile, "at term, we pass up r%d\n", $$->baseRegNum);
	}



}
    | term multiplyingOp factor
{

	if(($1->isConstant + $3->isConstant) == 0){
		if($2 == '*'){
			$$->value = $1->value * $3->value;
			$$->isConstant = 0;
		}else if($2 == '/'){
			$$->value = $1->value / $3->value;
			$$->isConstant = 0;
		}
	}else{
		fprintf(outFile, "MULT / DIVIDE\n");
		$$->baseRegNum  = emitArithmetic($1, $2, $3);
		$$->memory = 1;
		$$->isConstant = 1;
		$$->isLocal = 0;
	}

}
;


multiplyingOp: '*'
{
	//printf("%d, multiplyingOp *\n", lineno);

	$$ = '*';

}
             | '/'
{
	//printf("%d, multiplyingOp /\n", lineno);

	$$ = '/';
}
;
factor: factor EXP primary
{
	//printf("%d, factor primary\n", lineno);

	if(($1->isConstant + $3->isConstant) == 0){
		$$->value = pow($1->value, $3->value);
		$$->isConstant = 0;
	}else{
		$$->baseRegNum = emitExp($1, $3);
		$$->isConstant = 1;
		//fprintf(outFile, "passing up: r%d\n", $$->baseRegNum);
	}
					

}
      | primary	  
{

	$$ = $1;
	//fprintf(outFile, "passing up: r%d\n", $$->baseRegNum);


}
      | NOT primary
{
	//printf("%d, factor not primary\n", lineno);

	if($2->isConstant == 0){
		fprintf(outFile, "%d  r%d := not r%d\n", opCount++, regCount, $2->baseRegNum);
	}else if($2->isLocal == 1){
		fprintf(outFile, "%d  r%d := not contents b, %d\n", opCount++, regCount, $2->offset);
		$$->isLocal = 1;
		$$->isConstant = 1;
	}else{
		fprintf(outFile, "%d  r%d := not contents r%d, %d\n", opCount++, regCount, 
				$2->baseRegNum, $2->offset);
		$$->isConstant = 1;
		$$->isLocal = 0;
	}

	$$->baseRegNum = regCount;
}
;

primary: NUMBER
{
	//printf("%d, primary NUMBER\n", lineno);

	exprNode *tempNode = NULL;
	tempNode = malloc(sizeof(struct exprNode));

	tempNode->value = $1;
	tempNode->isConstant = 0;
	tempNode->isLocal = 0;
	tempNode->baseRegNum = regCount;

	$$ = tempNode;

}
       | ID
{
	//printf("%d, primary ID\n", lineno);

	exprNode *tempNode = NULL;
	tempNode = malloc(sizeof(struct exprNode));

	Node *tempTreeNode = NULL;
	tempTreeNode = malloc(sizeof(struct node));

	tempTreeNode = searchSymbol($1);

	int walkBackCount;
	walkBackCount = (stackCount - searchStack($1));

	// v Not sure about this line here v
	if(strcmp(tempTreeNode->data->kind, "value") == 0){
		tempNode->value = tempTreeNode->data->value;
		tempNode->baseRegNum = regCount;
		tempNode->isConstant = 0;
	}else if(walkBackCount > 0){
		fprintf(outFile, "wbCount is: %d\n", walkBackCount);
		walkBack(regCount, walkBackCount);
		tempNode->isLocal = 0;
		tempNode->walkedback = 1;
		tempNode->isConstant = 1;
		tempNode->baseRegNum = regCount;
		tempNode->memory = 0;
	}else{
		tempNode->isLocal = 1;
		tempNode->baseRegNum = regCount;
		tempNode->isConstant = 1;

	}
	tempNode->offset = tempTreeNode->data->offset;
	//tempNode->isConstant = 1;
	//fprintf(outFile, "ID %s noted with offset %d\n", tempTreeNode->data->name, 
			//tempNode->offset);
	
	$$ = tempNode;

}

       | ID '(' expr ')'
{
	//ID must be a parameter
	// if its not a parameter, then we yyerror and tap out


	exprNode *tempNode = NULL;
	tempNode = malloc(sizeof(struct exprNode));

	Node *tempTreeNode = NULL;
	tempTreeNode = malloc(sizeof(struct node));

	tempTreeNode = searchSymbol($1);

	int walkBackCount;
	walkBackCount = (stackCount - searchStack($1));


	if(strcmp(tempTreeNode->data->kind, "type (array)") == 0){
		if(walkBackCount > 0){
			//fprintf(outFile, "wbCount is: %d\n", walkBackCount);
			walkBack(regCount, walkBackCount);
			tempNode->isLocal = 0;
			tempNode->walkedback = 1;
			tempNode->isConstant = 1;
			tempNode->baseRegNum = regCount;
			tempNode->memory = 0;
		}else{
			tempNode->isLocal = 1;
			tempNode->baseRegNum = regCount;
			tempNode->isConstant = 1;
		}
		
		
	}else{
		yyerror("Cannot reference subset of non-array var");
	}
}
       | '(' expr ')'
{
	printf("%d, primary (expr)\n", lineno);

	$$ = $2;

}
;


exception: EXCEPTION exHandler
{printf("%d, exception\n", lineno);}
;
exHandler: exHandler WHEN afterWhen
{printf("%d, exHandler List\n", lineno);}
         | WHEN afterWhen
		 {printf("%d, exHandler\n", lineno);}
;
afterWhen: choice ARROW stmts
{printf("%d, exception choice\n", lineno);}
         | OTHERS ARROW stmts
{printf("%d, exception when choice\n", lineno);}
;
choice: ID '|' choice {printf("%d, choice 'ID|choice'\n", lineno);}
      | ID            {printf("%d, choice 'ID'\n", lineno);}
;

%%
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "structList.h"
#include "binTree.h"
#include "outerContext.h"
#include "codeGen.h"
#include "patchList.h"
#include "moreStatements.h"
			
extern int lineno;
int theOffset;
idnodeptr theList;
int mainARsize;
int prologJump;
int theBase[100];
int ifCount = -1;
			
			
main()
{

	outFile = fopen("output.txt", "w");

	outerContext();

	printf("About to scan.....\n");
	//outerContext();
	printf("Outer Context\n");
	printTree(theStack[0].p);
	yyparse();

	fclose(outFile);

	printPatches();

	patch("output.txt", opCount, mainARsize, prologJump);


	destroyTree(theStack[stackCount].p);

}
