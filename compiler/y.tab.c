#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#include <stdlib.h>
#include <string.h>

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20070509

#define YYEMPTY (-1)
#define yyclearin    (yychar = YYEMPTY)
#define yyerrok      (yyerrflag = 0)
#define YYRECOVERING (yyerrflag != 0)

extern int yyparse(void);

static int yygrowstack(void);
#define YYPREFIX "yy"
#line 12 "ada.y"
 /* YACC/ada.y */

#define max(a,b) (a < b) ? a : b

	/*extern int yydebug;*/
	/*yydebug = 1;*/


#line 35 "ada.y"
typedef union {
	int integer;
	char *var;
	char operation;
	struct idnode *idList;
	struct node *nodeThing;
	struct exprNode *expr;
} YYSTYPE;
#line 41 "y.tab.c"
#define ENDIF 257
#define ENDREC 258
#define ENDLOOP 259
#define EXITWHEN 260
#define IS 261
#define OF 262
#define BEG 263
#define END 264
#define DOTDOT 265
#define TICK 266
#define PROCEDURE 267
#define TYPE 268
#define ARRAY 269
#define RECORD 270
#define IN 271
#define OUT 272
#define RANGE 273
#define CONSTANT 274
#define ASSIGN 275
#define EXCEPTION 276
#define NULLWORD 277
#define LOOP 278
#define IF 279
#define THEN 280
#define ELSEIF 281
#define ELSE 282
#define EXIT 283
#define WHEN 284
#define AND 285
#define OR 286
#define NOT 287
#define EQ 288
#define NEQ 289
#define GT 290
#define LT 291
#define GTE 292
#define LTE 293
#define EXP 294
#define RAISE 295
#define OTHERS 296
#define ARROW 297
#define ID 298
#define NUMBER 299
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,   27,   17,   16,   15,   15,   28,   28,   31,   31,
   32,   29,   30,   30,   34,   34,   14,   14,   13,    3,
    3,    3,    3,    4,   33,   33,   33,   33,   33,    8,
    9,    9,    9,   10,    1,    1,   12,   40,   40,   41,
   11,   37,    7,    7,   38,   42,   39,   36,   36,   36,
   36,   36,   36,   36,   43,    2,   45,   45,   46,   46,
   46,   44,   47,   48,   49,   50,   50,   52,   51,   51,
   53,   24,   24,   20,   20,    6,    6,   23,   23,    5,
    5,    5,    5,    5,    5,   22,   22,   22,   26,   26,
   21,   21,   25,   25,   19,   19,   19,   18,   18,   18,
   18,   35,   54,   54,   55,   55,   56,   56,
};
short yylen[] = {                                         2,
    2,    4,    2,    2,    3,    0,    3,    2,    3,    2,
    1,    1,    2,    1,    2,    1,    3,    1,    4,    1,
    1,    2,    0,    1,    1,    1,    1,    1,    1,    4,
    1,    1,    1,    8,    1,    1,    3,    2,    1,    2,
    4,    3,    3,    1,    5,    1,    3,    4,    5,    2,
    2,    2,    2,    3,    3,    1,    2,    1,    1,    2,
    3,    6,    1,    2,    1,    4,    0,    1,    2,    0,
    1,    3,    1,    3,    1,    1,    1,    3,    1,    1,
    1,    1,    1,    1,    1,    2,    1,    3,    1,    1,
    1,    3,    1,    1,    3,    1,    2,    1,    1,    4,
    3,    2,    3,    2,    3,    3,    3,    1,
};
short yydefred[] = {                                      0,
    0,    0,    0,    0,    0,    4,    0,    3,    0,    0,
    1,   44,    0,    0,    0,   11,    0,    0,   25,   29,
    0,    8,    0,   26,   27,   28,    0,   56,   63,    0,
    0,    0,    0,    0,   16,    0,    0,    0,    0,    0,
    0,    5,    0,    0,    7,    0,   51,    0,    0,   50,
    0,    0,    0,   59,    0,   58,   14,    0,    2,    0,
   15,   52,   53,    0,    0,   98,    0,    0,   96,    0,
    0,    0,    0,    0,    0,    0,   21,    0,   43,   17,
    0,    0,   47,   42,    9,   54,    0,    0,    0,    0,
   60,   55,   57,    0,    0,   13,   97,    0,    0,    0,
    0,   64,   76,   77,    0,   93,   94,    0,   90,   89,
    0,   80,   81,   84,   82,   85,   83,    0,    0,   67,
   22,   24,   19,    0,    0,    0,   30,   31,   33,   32,
    0,   48,    0,    0,   61,    0,    0,  104,    0,    0,
    0,  101,   95,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   39,   36,   35,    0,    0,   45,   72,   49,
    0,    0,    0,  103,  100,   68,   71,    0,    0,    0,
    0,    0,   40,   37,   38,    0,    0,  107,    0,   62,
    0,   69,    0,   41,   66,    0,    0,    0,   34,
};
short yydgoto[] = {                                       2,
  156,   32,   78,  123,  118,  105,   13,   19,  127,  128,
  129,  130,   14,   15,    8,    3,    4,   69,   70,   71,
   72,   73,   74,   89,  108,  111,   20,   10,   33,   59,
   21,   22,   23,  119,   60,   35,   24,   25,   26,  152,
  153,  158,   36,   37,   55,   56,   38,   75,  120,  148,
  168,  169,  170,   95,  138,  139,
};
short yysindex[] = {                                   -250,
 -275,    0,    2, -186,   47,    0, -185,    0, -189, -140,
    0,    0,  -23,   74,   95,    0, -158,   49,    0,    0,
 -119,    0,   92,    0,    0,    0,  102,    0,    0, -121,
  -37, -175, -135, -140,    0,  119,  120,  -40, -239, -118,
 -185,    0,  -80, -164,    0, -208,    0,  123,  -40,    0,
  -40,  -40,  124,    0, -206,    0,    0, -100,    0,  -79,
    0,    0,    0,  -36,  146,    0,  -40,  -38,    0, -107,
 -137,   80,   81, -122, -140,  -84,    0, -108,    0,    0,
 -182,  -86,    0,    0,    0,    0,  -52,  -43,  150,  -46,
    0,    0,    0, -146,  -92,    0,    0,  -40,  -33,   80,
  -36,    0,    0,    0,  -40,    0,    0,  -38,    0,    0,
  -38,    0,    0,    0,    0,    0,    0,  -40, -140,    0,
    0,    0,    0,  153, -185, -145,    0,    0,    0,    0,
  -40,    0,  -40,  135,    0, -102,   72,    0,  -99, -146,
  -31,    0,    0, -122, -107,   80,   81, -109, -145,   67,
  138, -246,    0,    0,    0,  -66, -110,    0,    0,    0,
 -140,  -98, -140,    0,    0,    0,    0,  -56,  -40, -140,
  -63,  -94,    0,    0,    0, -145, -140,    0, -140,    0,
 -140,    0, -145,    0,    0,  162,  -57,  -91,    0,
};
short yyrindex[] = {                                      0,
    0,    0,  -55,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  167,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -129,    0,    0,    0,    0,  -89,    0,
    0,    0,    0,    0,    0,  -51,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -16,    0,    0,    0,    0,    3,
    0,   39,   87,  -35,    0,  -88,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  170,    0,    0,
    0,    0,    0,    0,  -50,    0,    0,    0,    0,   56,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0, -187,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  -82,    0,    0,    0,
    0,    0,    0,  115,   22,   73,  101,  -44,    0,    0,
    0,    0,    0,    0,    0,    0,   92,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -248,    0, -188,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
 -115,    0,    0,    0,    0,    0,    5,    0,    0,    0,
    0,    0,    0,  175,    0,    0,    0,  -45,  109,  -12,
  -53,  100,  114,   88,    0,    0,  220,    0,    0,    0,
  176,  202,    0,    1,    0,  -14,  -95,    0,    0,    0,
   75,    0,    0,    0,    0,  169,    0,   57, -132,    0,
    0,    0,    0,    0,   85,   66,
};
#define YYTABLESIZE 401
short yytable[] = {                                      67,
  133,   67,   51,   67,   68,   75,  132,  142,   75,  165,
   34,  174,  135,   18,  100,  106,    1,   54,   97,   61,
   40,   50,    6,   75,   99,   99,   99,   99,   99,  151,
   99,   76,   77,  171,   39,  106,   87,  182,   88,   90,
   54,    7,   99,   91,   91,   91,   91,   91,  185,   91,
   18,   12,   92,   52,   99,  143,  151,  146,    1,   17,
  184,   91,   92,   92,   92,   92,   92,  186,   92,   65,
   27,   28,   29,   16,    9,  105,   53,    1,   17,   87,
   92,   87,   87,   87,   52,  141,  124,  125,   30,   12,
  126,   31,   40,   65,   65,  105,   86,   87,   86,   86,
   86,   27,   28,   29,   61,   11,   44,   53,   12,   82,
   40,   83,   12,   88,   86,   88,   88,   88,  157,   30,
   88,  106,   31,  110,  172,  109,  107,   79,   57,  150,
   79,   88,   41,   84,   12,   42,   27,   28,   29,   43,
   58,   78,  102,   16,   78,   79,   12,  103,  104,  136,
   46,  137,  154,  155,   30,   74,  150,   31,   74,   78,
   47,  177,   61,  179,   61,  112,  113,  114,  115,  116,
  117,  166,  167,   74,  103,  104,   48,   62,   63,   79,
   81,   86,   91,   94,   96,   98,  101,  121,  131,  122,
  134,  140,  149,  160,  161,  162,  173,  163,  176,  137,
  180,  183,  187,   84,  188,    6,  189,   18,   23,   20,
   73,   10,   70,  102,  108,   80,  145,  147,  144,    5,
  159,   85,   45,   93,  164,  181,  175,  178,    0,    0,
    0,    0,  103,  104,    0,    0,    0,   49,  103,  104,
    0,  103,  104,    0,   75,    0,   64,    0,   64,   75,
   75,  103,  104,  103,  104,    0,    0,   65,   66,   65,
   66,   65,   66,   99,    0,    0,    0,    0,   99,   99,
    0,   99,   99,   99,   99,   99,   99,   99,    0,    0,
    0,    0,   91,    0,    0,    0,    0,   91,   91,    0,
   91,   91,   91,   91,   91,   91,    0,    0,    0,    0,
    0,   92,    0,    0,    0,    0,   92,   92,    0,   92,
   92,   92,   92,   92,   92,    0,    0,    0,   87,    0,
    0,    0,    0,   87,   87,    0,   87,   87,   87,   87,
   87,   87,    0,    0,    0,   86,    0,    0,    0,    0,
   86,   86,    0,   86,   86,   86,   86,   86,   86,    0,
    0,    0,   88,    0,    0,    0,    0,   88,   88,    0,
   88,   88,   88,   88,   88,   88,   79,    0,    0,    0,
    0,   79,   79,    0,   79,   79,   79,   79,   79,   79,
   78,    0,    0,    0,    0,   78,   78,    0,   78,   78,
   78,   78,   78,   78,   74,    0,    0,    0,    0,   74,
   74,
};
short yycheck[] = {                                      40,
   44,   40,   40,   40,   45,   41,   59,   41,   44,   41,
   10,  258,   59,    9,   68,  264,  267,   32,   64,   34,
   44,   59,  298,   59,   41,   42,   43,   44,   45,  125,
   47,  271,  272,  149,   58,  284,   49,  170,   51,   52,
   55,   40,   59,   41,   42,   43,   44,   45,  181,   47,
   46,  298,  259,  260,   67,  101,  152,  111,  267,  268,
  176,   59,   41,   42,   43,   44,   45,  183,   47,  257,
  277,  278,  279,  263,  261,  264,  283,  267,  268,   41,
   59,   43,   44,   45,  260,   98,  269,  270,  295,  298,
  273,  298,   44,  281,  282,  284,   41,   59,   43,   44,
   45,  277,  278,  279,  119,   59,   58,  283,  298,  274,
   44,  276,  298,   41,   59,   43,   44,   45,  131,  295,
  133,   42,  298,   43,   58,   45,   47,   41,  264,  125,
   44,   59,   59,  298,  264,   41,  277,  278,  279,  298,
  276,   41,  280,  263,   44,   59,  276,  285,  286,  296,
   59,  298,  298,  299,  295,   41,  152,  298,   44,   59,
   59,  161,  177,  163,  179,  288,  289,  290,  291,  292,
  293,  281,  282,   59,  285,  286,  298,   59,   59,  298,
  261,   59,   59,  284,  264,   40,  294,  272,  275,  298,
   41,  284,   40,   59,  297,  124,   59,  297,  265,  298,
  257,  265,   41,  298,  262,  261,  298,   41,  298,  298,
   41,  263,  257,  264,  297,   41,  108,  118,  105,    0,
  133,   46,   21,   55,  140,  169,  152,  162,   -1,   -1,
   -1,   -1,  285,  286,   -1,   -1,   -1,  275,  285,  286,
   -1,  285,  286,   -1,  280,   -1,  287,   -1,  287,  285,
  286,  285,  286,  285,  286,   -1,   -1,  298,  299,  298,
  299,  298,  299,  280,   -1,   -1,   -1,   -1,  285,  286,
   -1,  288,  289,  290,  291,  292,  293,  294,   -1,   -1,
   -1,   -1,  280,   -1,   -1,   -1,   -1,  285,  286,   -1,
  288,  289,  290,  291,  292,  293,   -1,   -1,   -1,   -1,
   -1,  280,   -1,   -1,   -1,   -1,  285,  286,   -1,  288,
  289,  290,  291,  292,  293,   -1,   -1,   -1,  280,   -1,
   -1,   -1,   -1,  285,  286,   -1,  288,  289,  290,  291,
  292,  293,   -1,   -1,   -1,  280,   -1,   -1,   -1,   -1,
  285,  286,   -1,  288,  289,  290,  291,  292,  293,   -1,
   -1,   -1,  280,   -1,   -1,   -1,   -1,  285,  286,   -1,
  288,  289,  290,  291,  292,  293,  280,   -1,   -1,   -1,
   -1,  285,  286,   -1,  288,  289,  290,  291,  292,  293,
  280,   -1,   -1,   -1,   -1,  285,  286,   -1,  288,  289,
  290,  291,  292,  293,  280,   -1,   -1,   -1,   -1,  285,
  286,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 299
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,0,0,0,0,0,
"':'","';'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'|'",0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,"ENDIF","ENDREC","ENDLOOP","EXITWHEN","IS","OF","BEG","END","DOTDOT",
"TICK","PROCEDURE","TYPE","ARRAY","RECORD","IN","OUT","RANGE","CONSTANT",
"ASSIGN","EXCEPTION","NULLWORD","LOOP","IF","THEN","ELSEIF","ELSE","EXIT",
"WHEN","AND","OR","NOT","EQ","NEQ","GT","LT","GTE","LTE","EXP","RAISE","OTHERS",
"ARROW","ID","NUMBER",
};
char *yyrule[] = {
"$accept : program",
"program : procedure ';'",
"procedure : procHead procDecls procStmts procExceptions",
"procHead : pushHead optionalParams",
"pushHead : PROCEDURE ID",
"optionalParams : '(' parameterList ')'",
"optionalParams :",
"procDecls : IS decls begin",
"procDecls : IS begin",
"decls : decl ';' decls",
"decls : decl ';'",
"begin : BEG",
"procStmts : stmts",
"procExceptions : exception END",
"procExceptions : END",
"stmts : stmts stmt",
"stmts : stmt",
"parameterList : parameter ';' parameterList",
"parameterList : parameter",
"parameter : idList ':' mode typeName",
"mode : IN",
"mode : OUT",
"mode : IN OUT",
"mode :",
"typeName : ID",
"decl : arrayRecordRange",
"decl : variable",
"decl : constant",
"decl : exceptionDecl",
"decl : procedure",
"arrayRecordRange : TYPE ID IS option",
"option : array",
"option : record",
"option : range",
"array : ARRAY '(' index DOTDOT index ')' OF ID",
"index : NUMBER",
"index : ID",
"record : RECORD componentList ENDREC",
"componentList : componentList component",
"componentList : component",
"component : variable ';'",
"range : RANGE index DOTDOT index",
"variable : idList ':' ID",
"idList : idList ',' ID",
"idList : ID",
"constant : idList ':' CONSTANT ASSIGN constantExpr",
"constantExpr : expr",
"exceptionDecl : idList ':' EXCEPTION",
"stmt : ID ASSIGN expr ';'",
"stmt : ID '(' exprs ')' ';'",
"stmt : ID ';'",
"stmt : NULLWORD ';'",
"stmt : loopOption ';'",
"stmt : ifStmt ';'",
"stmt : RAISE ID ';'",
"loopOption : loopStart loopStmts ENDLOOP",
"loopStart : LOOP",
"loopStmts : loopStmts loopStmt",
"loopStmts : loopStmt",
"loopStmt : stmt",
"loopStmt : EXIT ';'",
"loopStmt : EXITWHEN expr ';'",
"ifStmt : beginIf thenPart stmtsPart elseifOption elseOption ENDIF",
"beginIf : IF",
"thenPart : expr THEN",
"stmtsPart : stmts",
"elseifOption : elseifOption beginElseif thenPart stmtsPart",
"elseifOption :",
"beginElseif : ELSEIF",
"elseOption : beginElse stmtsPart",
"elseOption :",
"beginElse : ELSE",
"exprs : expr ',' exprs",
"exprs : expr",
"expr : expr booleanOp relation",
"expr : relation",
"booleanOp : AND",
"booleanOp : OR",
"relation : relation relationalOp simpleExpr",
"relation : simpleExpr",
"relationalOp : EQ",
"relationalOp : NEQ",
"relationalOp : LT",
"relationalOp : LTE",
"relationalOp : GT",
"relationalOp : GTE",
"simpleExpr : '-' term",
"simpleExpr : term",
"simpleExpr : simpleExpr addingOp term",
"addingOp : '+'",
"addingOp : '-'",
"term : factor",
"term : term multiplyingOp factor",
"multiplyingOp : '*'",
"multiplyingOp : '/'",
"factor : factor EXP primary",
"factor : primary",
"factor : NOT primary",
"primary : NUMBER",
"primary : ID",
"primary : ID '(' expr ')'",
"primary : '(' expr ')'",
"exception : EXCEPTION exHandler",
"exHandler : exHandler WHEN afterWhen",
"exHandler : WHEN afterWhen",
"afterWhen : choice ARROW stmts",
"afterWhen : OTHERS ARROW stmts",
"choice : ID '|' choice",
"choice : ID",
};
#endif
#if YYDEBUG
#include <stdio.h>
#endif

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 500

int      yydebug;
int      yynerrs;
int      yyerrflag;
int      yychar;
short   *yyssp;
YYSTYPE *yyvsp;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* variables for the parser stack */
static short   *yyss;
static short   *yysslim;
static YYSTYPE *yyvs;
static int      yystacksize;
#line 1132 "ada.y"
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
#line 486 "y.tab.c"
/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(void)
{
    int newsize, i;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = yystacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = yyssp - yyss;
    newss = (yyss != 0)
          ? (short *)realloc(yyss, newsize * sizeof(*newss))
          : (short *)malloc(newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    yyss  = newss;
    yyssp = newss + i;
    newvs = (yyvs != 0)
          ? (YYSTYPE *)realloc(yyvs, newsize * sizeof(*newvs))
          : (YYSTYPE *)malloc(newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    yyvs = newvs;
    yyvsp = newvs + i;
    yystacksize = newsize;
    yysslim = yyss + newsize - 1;
    return 0;
}

#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse(void)
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;

    if (yyss == NULL && yygrowstack()) goto yyoverflow;
    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yyssp >= yysslim && yygrowstack())
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

#ifdef lint
    goto yyerrlab;
#endif

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yysslim && yygrowstack())
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yyvsp[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 46 "ada.y"
{

	fprintf(outFile, "Instruction Count = %d\n", opCount-1);

	printf("THE END\n");

}
break;
case 2:
#line 56 "ada.y"
{
	/*printf("%d, program\n", lineno);*/

}
break;
case 3:
#line 64 "ada.y"
{

	/*printf("%d, procedure head\n", lineno);*/

	if(yyvsp[-1].nodeThing != NULL){
		yyvsp[-1].nodeThing->data->next = yyvsp[0].nodeThing;
	}

	/*
	push($2->data->name);
	theOffset = 4;
	printf("*******\nPushing new scope for %s\n", $2);
	*/

	yyval.nodeThing = yyvsp[-1].nodeThing;

}
break;
case 4:
#line 84 "ada.y"
{
	Node *tempNode = NULL;
	int good;

	if(stackCount > 0){
	
		good = insertSymbol(yyvsp[0].var);
		if(good == 1){
			tempNode = searchSymbol(yyvsp[0].var);
			tempNode->data->kind = memAndCopy("procedure");

			push(yyvsp[0].var);
			theOffset = 4;
			printf("*******\nPushing new scope for %s\n", yyvsp[0].var);
			
		}else{
			/*printf("ERROR: Duplicate IDs");*/
			yyerror("Procedure ID not allowed");
			return(1);
		}
	}else{
		/*Object Code Stuff*/
		fprintf(outFile, "%d  b := ?\n", opCount++);
		fprintf(outFile, "%d  contents b, 0 := ?\n", opCount++);
		fprintf(outFile, "%d  contents b, 1 := 4\n", opCount++);
		fprintf(outFile, "%d  pc := ?\n", opCount++);
		fprintf(outFile, "%d  halt\n", opCount++);

		/******************/

		push(yyvsp[0].var);
		theOffset = 4;
		printf("*******\nPushing new scope for %s\n", yyvsp[0].var);
	}

	yyval.nodeThing = tempNode;

}
break;
case 5:
#line 126 "ada.y"
{
	yyval.nodeThing = yyvsp[-1].nodeThing;

}
break;
case 6:
#line 131 "ada.y"
{
	yyval.nodeThing = NULL;

}
break;
case 7:
#line 138 "ada.y"
{

}
break;
case 8:
#line 142 "ada.y"
{


}
break;
case 9:
#line 149 "ada.y"
{
	/*printf("%d, decls List\n", lineno);*/

}
break;
case 10:
#line 154 "ada.y"
{
	/*printf("%d, decls\n", lineno);*/

}
break;
case 11:
#line 161 "ada.y"
{
	/*printf("%d, begin\n", lineno);*/
	
	/*fprintf(outFile, "reg count is: %d\n", regCount);*/
	
	/*printf(" HERE: stack count is: %d", stackCount);*/
	
	if(stackCount > 1){
		Node *tempNode = NULL;
		tempNode = searchSymbol(theStack[stackCount].name);
		/*printf("node is: %s\n", tempNode->data->name);*/
		
		
		tempNode->data->sizeAR = theOffset;
		tempNode->data->jump = opCount;	
			
		/*printf(" NOW: %s size is %d\n", theStack[stackCount].name, tempNode->data->sizeAR);*/
		/*printf(" NOW: %s jump is %d\n", theStack[stackCount].name, tempNode->data->jump);*/
	}
	
	/*if its for main?*/
	if(stackCount == 1){
		mainARsize = theOffset;
		prologJump = opCount;
	}
	
}
break;
case 12:
#line 191 "ada.y"
{
    /*printf("%d, stmts\n", lineno);*/

}
break;
case 13:
#line 198 "ada.y"
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
break;
case 14:
#line 210 "ada.y"
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
	/*if main just got popped off*/
	if(stackCount == 0){
		basePatch = opCount;
	}

}
break;
case 16:
#line 247 "ada.y"
{
	/*printf("%d, stmtsList\n", lineno);*/
}
break;
case 17:
#line 253 "ada.y"
{

	yyvsp[-2].nodeThing->data->next = yyvsp[0].nodeThing;
	/*print($1);*/
	printf("%s 's next is %s\n", yyvsp[-2].nodeThing->data->name, yyvsp[0].nodeThing->data->name);
	
	yyval.nodeThing = yyvsp[-2].nodeThing;

}
break;
case 18:
#line 263 "ada.y"
{
	/*printf("%d, parameterList\n", lineno);*/

	/*print($1);*/
	yyval.nodeThing = yyvsp[0].nodeThing;
	printf("%s 's next is %s\n", yyvsp[0].nodeThing->data->name, yyvsp[0].nodeThing->data->next);
	

}
break;
case 19:
#line 274 "ada.y"
{
	/*printf("%d, parameter\n", lineno);*/

	Node *tempNode = NULL;
	Node *nextFinder = NULL;
	struct idnode *theList = yyvsp[-3].idList;
	int good;

	while(theList != NULL){
		good = insertSymbol(theList->name);
		if(good == 1){
			tempNode = search(theStack[stackCount].p, theList->name);
			tempNode->data->kind = memAndCopy("parameter");
			tempNode->data->mode = memAndCopy(yyvsp[-1].var);
			tempNode->data->parentType = searchSymbol(yyvsp[0].var);
			tempNode->data->size = tempNode->data->parentType->data->size;
			tempNode->data->offset = theOffset;
			theOffset = theOffset + tempNode->data->size;

		
			if(nextFinder != NULL){
				nextFinder->data->next = tempNode;
			}
			nextFinder = tempNode;
			/*printTree(tempNode);*/
			theList = theList->next;
		}else{
			/*printf("ERROR: Duplicate IDs\n");*/
			yyerror("Duplicate ID");
			return(1);
		}
	}
	
	yyval.nodeThing = tempNode;
}
break;
case 20:
#line 312 "ada.y"
{
	yyval.var = memAndCopy("in");
}
break;
case 21:
#line 316 "ada.y"
{
	yyval.var = memAndCopy("out");
}
break;
case 22:
#line 320 "ada.y"
{
	yyval.var = memAndCopy("in out");
}
break;
case 23:
#line 324 "ada.y"
{
	yyval.var = memAndCopy("in");
}
break;
case 24:
#line 329 "ada.y"
{
	/*printf("%d, typeName\n", lineno);*/

	yyval.var = memAndCopy(yyvsp[0].var);

}
break;
case 25:
#line 339 "ada.y"
{
	/*printf("%d, decl arrayRecordRange\n", lineno);*/
}
break;
case 26:
#line 343 "ada.y"
{
	/*printf("%d, decl variable\n", lineno);*/
}
break;
case 27:
#line 347 "ada.y"
{
	/*printf("%d, decl constant\n", lineno);*/
}
break;
case 28:
#line 351 "ada.y"
{
	/*printf("%d, decl exceptionDecl\n", lineno);*/
}
break;
case 29:
#line 355 "ada.y"
{
	/*printf("%d, decl new procedure\n", lineno);*/
}
break;
case 30:
#line 360 "ada.y"
{
	/*printf("%d, arrayRecordRange\n", lineno);*/

	Node *tempNode = NULL;
	int good;
 
	good = insertSymbol(yyvsp[-2].var);
	if(good == 1){
		tempNode = searchSymbol(yyvsp[-2].var);
		tempNode->data->kind = memAndCopy(yyvsp[0].nodeThing->data->kind);
		tempNode->data->lower = yyvsp[0].nodeThing->data->lower;
		tempNode->data->upper = yyvsp[0].nodeThing->data->upper;
		tempNode->data->componentType = yyvsp[0].nodeThing->data->componentType;
		tempNode->data->size = yyvsp[0].nodeThing->data->size;
		/*tempNode->data->offset = theOffset;*/
		/*theOffset = theOffset + tempNode->data->size;*/
	}else{
		/*printf("ERROR: Duplicate IDs\n");*/
		yyerror("Duplicate ID");
		return(1);
	}
	yyval.nodeThing = yyvsp[0].nodeThing;

}
break;
case 31:
#line 387 "ada.y"
{
	/*printf("%d, option Array\n", lineno);*/

	yyval.nodeThing = yyvsp[0].nodeThing;

}
break;
case 32:
#line 394 "ada.y"
{
	printf("%d, option Record\n", lineno);

}
break;
case 33:
#line 399 "ada.y"
{
	/*printf("%d, option Range\n", lineno);*/

	yyval.nodeThing = yyvsp[0].nodeThing;

}
break;
case 34:
#line 408 "ada.y"
{
	/*printf("%d, array\n", lineno);*/


	int arrayLength;
	arrayLength = ((yyvsp[-3].integer - yyvsp[-5].integer)+1);
	Node *tempNode = NULL;
	tempNode = malloc(sizeof(struct node));
	tempNode->data = malloc(sizeof(struct symbol));


	tempNode->data->kind = memAndCopy("type (array)");
	tempNode->data->lower = yyvsp[-5].integer;
	tempNode->data->upper = yyvsp[-3].integer;
	tempNode->data->componentType = searchSymbol(yyvsp[0].var);

	tempNode->data->size = (tempNode->data->componentType->data->size * arrayLength);
	/*printf("size");*/

	yyval.nodeThing = tempNode;
}
break;
case 35:
#line 433 "ada.y"
{
	/*printf("%d, index NUMBER\n", lineno);*/

	yyval.integer = yyvsp[0].integer;

}
break;
case 36:
#line 440 "ada.y"
{
	/*printf("%d, index ID\n", lineno);*/

	Node *tempNode = NULL;
	tempNode = searchSymbol(yyvsp[0].var);
	if(tempNode == NULL){
		yyerror("ID not found");
	}else{
		yyval.integer = tempNode->data->value;
	}

}
break;
case 37:
#line 455 "ada.y"
{printf("%d, record\n", lineno);}
break;
case 39:
#line 459 "ada.y"
{printf("%d, componentList\n", lineno);}
break;
case 40:
#line 462 "ada.y"
{printf("%d, componentList\n", lineno);}
break;
case 41:
#line 466 "ada.y"
{
	/*printf("%d, right\n", lineno);*/
	
	int rangeLength;
	rangeLength = ((yyvsp[0].integer - yyvsp[-2].integer)+1);
	Node *tempNode = NULL;
	tempNode = malloc(sizeof(struct node));
	tempNode->data = malloc(sizeof(struct symbol));

	tempNode->data->kind = memAndCopy("type (range)");
	tempNode->data->lower = yyvsp[-2].integer;
	tempNode->data->upper = yyvsp[0].integer;
	tempNode->data->size = 1;

	yyval.nodeThing = tempNode;
}
break;
case 42:
#line 485 "ada.y"
{
	printf("line#: %d - ", lineno);
	print(yyvsp[-2].idList);
	printf(": %s\n", yyvsp[0].var);

	Node *tempNode = NULL;
	int good;

	while(yyvsp[-2].idList != NULL){
		good = insertSymbol(yyvsp[-2].idList->name);
		if(good == 1){
			tempNode = search(theStack[stackCount].p, yyvsp[-2].idList->name);
			tempNode->data->kind = memAndCopy("object");
			tempNode->data->parentType = searchSymbol(yyvsp[0].var);
			tempNode->data->size = tempNode->data->parentType->data->size;
			tempNode->data->offset = theOffset;
			theOffset = theOffset + tempNode->data->size;
		}else{
			/*printf("ERROR: Duplicate IDs\n");*/
			yyerror("Duplicate ID");
			return(1);
		}
		yyvsp[-2].idList = yyvsp[-2].idList->next;
	}
}
break;
case 43:
#line 512 "ada.y"
{
	/*printf("%d, idList multiple\n", lineno);*/

	theList = add(yyvsp[-2].idList, yyvsp[0].var);
	yyval.idList = theList;

}
break;
case 44:
#line 520 "ada.y"
{
	/*printf("%d, idList id\n", lineno);*/
	
	theList = delete(theList);
	theList = add(theList, yyvsp[0].var);
	yyval.idList = theList;
	
}
break;
case 45:
#line 531 "ada.y"
{printf("%d, constant\n", lineno);}
break;
case 46:
#line 534 "ada.y"
{printf("%d, constantExpr\n", lineno);}
break;
case 47:
#line 538 "ada.y"
{printf("%d, exception declaration\n", lineno);}
break;
case 48:
#line 542 "ada.y"
{

	/*fprintf(outFile, "at stmt is ASSIGN, we have r%d\n", $3->baseRegNum);*/

	/*printf("%d, stmt ID assign\n", lineno);*/
	/*printf(" here ID is: %s\n", $1);*/

	Node *tempNode = NULL;
	tempNode = searchSymbol(yyvsp[-3].var);
	
	/*printf("ID here is: %s\n", tempNode->data->name);*/

	int walkBackCount;
	walkBackCount = (stackCount - searchStack(tempNode->data->name));
	
	emitAssign(walkBackCount, yyvsp[-3].var, yyvsp[-1].expr);

}
break;
case 49:
#line 578 "ada.y"
{

	/*printf("%d, stmt ID params\n", lineno);*/

	Node *tempNode = NULL;
	tempNode = searchSymbol(yyvsp[-4].var);

	if(strcmp(tempNode->data->kind, "read_routine") == 0){
		/*do reads*/

		emitRead(yyvsp[-2].expr);

	}else if(strcmp(tempNode->data->kind, "write_routine") == 0){
		/*do writes*/

		emitWrite(yyvsp[-2].expr);
	}

}
break;
case 50:
#line 598 "ada.y"
{
	/*printf("%d, stmt ID\n", lineno);*/

	Node *tempNode = NULL;
	tempNode = searchSymbol(yyvsp[-1].var);

	if(strcmp(tempNode->data->kind, "procedure") == 0){
		/*do a call*/
		int walkBackCount;
		walkBackCount = (stackCount - searchStack(tempNode->data->name));

		functionCall(walkBackCount, tempNode);

	}
}
break;
case 51:
#line 614 "ada.y"
{
	printf("%d, stmt NULL\n", lineno);
	/*do nothing*/
}
break;
case 52:
#line 619 "ada.y"
{
	/*printf("%d, stmt loopOption\n", lineno);*/
}
break;
case 53:
#line 623 "ada.y"
{
	/*printf("%d, stmt ifStmt\n", lineno);*/
}
break;
case 54:
#line 627 "ada.y"
{
	printf("%d, stmt RAISE ID\n", lineno);
}
break;
case 55:
#line 634 "ada.y"
{
	/*printf("loop ENDS here\n\n");*/

	/*end of loop -> doesn't need patching*/
	fprintf(outFile, "%d  pc := %d\n", opCount++, yyvsp[-2].integer);
	popPatch(opCount);

	
}
break;
case 56:
#line 645 "ada.y"
{
	/*printf("\nNew LOOP starting here\n");*/
	/*start of loop -> no instruction, .: no patching*/
	pushPatch();
	
	/*insertToPatch(opCount);*/
	/*fprintf(outFile, "%d  pc := ?\n", opCount++);*/
	
	yyval.integer = opCount;

}
break;
case 57:
#line 658 "ada.y"
{
	/*printf("%d, loopStmts\n", lineno);*/

}
break;
case 58:
#line 663 "ada.y"
{

}
break;
case 59:
#line 668 "ada.y"
{
	/*printf("loops stmt assign or nested\n");*/
}
break;
case 60:
#line 673 "ada.y"
{
	/*printf("%d, sequenceStmt EXIT\n", lineno);*/

	insertToPatch(patchStackCount, opCount);
	fprintf(outFile, "%d  pc := ?\n", opCount++);


}
break;
case 61:
#line 682 "ada.y"
{
	printf("%d, sequenceStmt EXITWHEN\n", lineno);

	/*NOT HANDLING YET --> PART 5*/

}
break;
case 62:
#line 691 "ada.y"
{
	/*printf("%d, ifStmt\n", lineno);*/

	popPatch(opCount);
	ifCount--;

}
break;
case 63:
#line 700 "ada.y"
{
	pushPatch();
	ifCount++;
	theBase[ifCount] = patchStackCount;

}
break;
case 64:
#line 708 "ada.y"
{
	pushPatch();
	insertToPatch(patchStackCount, opCount);
	fprintf(outFile, "%d  pc := ? if not r%d\n", opCount++, regCount);

}
break;
case 65:
#line 716 "ada.y"
{
	insertToPatch(theBase[ifCount], opCount);
	fprintf(outFile, "%d  pc := ?\n", opCount++);

	printPatchList(patchStack[patchStackCount].list);
	/*popPatch(opCount);*/

}
break;
case 66:
#line 725 "ada.y"
{
	printf("%d, elseifs w Else\n", lineno);

}
break;
case 68:
#line 732 "ada.y"
{
	popPatch(opCount);
}
break;
case 69:
#line 738 "ada.y"
{
	/*popPatch(opCount);*/
}
break;
case 70:
#line 742 "ada.y"
{
	popPatch(opCount);
}
break;
case 71:
#line 747 "ada.y"
{
	popPatch(opCount);
}
break;
case 72:
#line 752 "ada.y"
{
	yyvsp[-2].expr->next = yyvsp[0].expr;
	yyval.expr = yyvsp[-2].expr;
}
break;
case 73:
#line 757 "ada.y"
{
	yyval.expr = yyvsp[0].expr;
}
break;
case 74:
#line 763 "ada.y"
{
	printf("%d, expr\n", lineno);

	yyval.expr->baseRegNum = emitRelational(yyvsp[-2].expr, yyvsp[-1].var, yyvsp[0].expr);
	yyval.expr->isConstant = 1;

}
break;
case 75:
#line 771 "ada.y"
{
	yyval.expr = yyvsp[0].expr;
	/*fprintf(outFile, "at expr is relation, we pass up r%d\n", $$->baseRegNum);*/
}
break;
case 76:
#line 777 "ada.y"
{
	printf("%d, booleanOp AND\n", lineno);

	yyval.var = memAndCopy("and");
}
break;
case 77:
#line 783 "ada.y"
{
	printf("%d, booleanOp OR\n", lineno);

	yyval.var = memAndCopy("or");
}
break;
case 78:
#line 790 "ada.y"
{
	/*fprintf(outFile, "left is r%d -- right is r%d\n", $1->baseRegNum, $3->baseRegNum);*/

	/*fprintf(outFile, "left is %d -- right is %d\n", $1->isConstant, $3->isConstant);*/



	yyval.expr->baseRegNum = emitRelational(yyvsp[-2].expr, yyvsp[-1].var, yyvsp[0].expr);
	yyval.expr->isConstant = 1;
	

}
break;
case 79:
#line 803 "ada.y"
{
	/*printf("%d, relation\n", lineno);*/

	yyval.expr = yyvsp[0].expr;
}
break;
case 80:
#line 810 "ada.y"
{
	yyval.var = memAndCopy("=");
}
break;
case 81:
#line 814 "ada.y"
{
	yyval.var = memAndCopy("!=");
}
break;
case 82:
#line 818 "ada.y"
{
	yyval.var = memAndCopy("<");
}
break;
case 83:
#line 822 "ada.y"
{
	yyval.var = memAndCopy("<=");
}
break;
case 84:
#line 826 "ada.y"
{
	yyval.var = memAndCopy(">");
}
break;
case 85:
#line 830 "ada.y"
{
	yyval.var = memAndCopy(">=");
}
break;
case 86:
#line 835 "ada.y"
{
	/*printf("%d, simpleExpr '- term'\n", lineno);*/
	
	if(yyvsp[0].expr->isConstant == 0){
		yyval.expr = yyvsp[0].expr;
		yyval.expr->value = (yyvsp[0].expr->value * -1);
	}else{
		if(yyvsp[0].expr->memory == 1){
			fprintf(outFile, "%d  r%d := - r%d\n", opCount++, regCount, yyvsp[0].expr->baseRegNum);
			yyval.expr->isConstant = 1;
			yyval.expr->isLocal = 1;
			yyval.expr->memory = 1;
		}else if(yyvsp[0].expr->isLocal == 1){
			fprintf(outFile, "%d  r%d := - contents b, %d\n", opCount++, regCount, 
					yyvsp[0].expr->offset);
			yyval.expr->isLocal = 1;
			yyval.expr->isConstant = 1;
		}else{
			fprintf(outFile, "%d  r%d := - contents r%d, %d\n", opCount++, regCount, 
					yyvsp[0].expr->baseRegNum, yyvsp[0].expr->offset);
			yyval.expr->isLocal = 0;
			yyval.expr->isConstant = 1;
		}
	}
	yyval.expr->baseRegNum = yyvsp[0].expr->baseRegNum;

}
break;
case 87:
#line 863 "ada.y"
{
	/*printf("%d, simpleExpr term\n", lineno);*/

	yyval.expr = yyvsp[0].expr;
	/*fprintf(outFile, "at simpleExpr is term, we pass up r%d\n", $$->baseRegNum);*/


}
break;
case 88:
#line 872 "ada.y"
{
	/*printf("%d, optionalSimpleExpr List\n", lineno);*/
	/*printf("left side value is: %d | right side val: %d\n", $1->value, $3->value);*/

	if((yyvsp[-2].expr->isConstant + yyvsp[0].expr->isConstant) == 0){
		fprintf(outFile, "CONSTANT ADDITION / SUBTRACTION\n");
		if(yyvsp[-1].operation == '+'){
			yyval.expr->value = yyvsp[-2].expr->value + yyvsp[0].expr->value;
		}else if(yyvsp[-1].operation == '-'){
			yyval.expr->value = yyvsp[-2].expr->value - yyvsp[0].expr->value;
		}
	}else{
		fprintf(outFile, "ADD / SUBTRACT\n");
		yyval.expr->baseRegNum  = emitArithmetic(yyvsp[-2].expr, yyvsp[-1].operation, yyvsp[0].expr);
		yyval.expr->memory = 1;
		yyval.expr->isConstant = 1;
		yyval.expr->isLocal = 0;
		
		/*do if vars*/
	}
	

}
break;
case 89:
#line 897 "ada.y"
{
	/*printf("%d, addingOp +\n", lineno);*/

	yyval.operation = '+';
}
break;
case 90:
#line 903 "ada.y"
{
	/*printf("%d, addingOp -\n", lineno);*/

	yyval.operation = '-';
}
break;
case 91:
#line 910 "ada.y"
{
	/*printf("%d, term\n", lineno);*/

	
	if(yyvsp[0].expr->isConstant == 0){
		yyval.expr = yyvsp[0].expr;
	}else if(yyvsp[0].expr->walkedback == 1){
		yyval.expr->baseRegNum = yyvsp[0].expr->baseRegNum;
	}else{
		yyval.expr->memory = 1;
		yyval.expr->baseRegNum = yyvsp[0].expr->baseRegNum;
		/*fprintf(outFile, "at term, we pass up r%d\n", $$->baseRegNum);*/
	}



}
break;
case 92:
#line 928 "ada.y"
{

	if((yyvsp[-2].expr->isConstant + yyvsp[0].expr->isConstant) == 0){
		if(yyvsp[-1].operation == '*'){
			yyval.expr->value = yyvsp[-2].expr->value * yyvsp[0].expr->value;
			yyval.expr->isConstant = 0;
		}else if(yyvsp[-1].operation == '/'){
			yyval.expr->value = yyvsp[-2].expr->value / yyvsp[0].expr->value;
			yyval.expr->isConstant = 0;
		}
	}else{
		fprintf(outFile, "MULT / DIVIDE\n");
		yyval.expr->baseRegNum  = emitArithmetic(yyvsp[-2].expr, yyvsp[-1].operation, yyvsp[0].expr);
		yyval.expr->memory = 1;
		yyval.expr->isConstant = 1;
		yyval.expr->isLocal = 0;
	}

}
break;
case 93:
#line 951 "ada.y"
{
	/*printf("%d, multiplyingOp *\n", lineno);*/

	yyval.operation = '*';

}
break;
case 94:
#line 958 "ada.y"
{
	/*printf("%d, multiplyingOp /\n", lineno);*/

	yyval.operation = '/';
}
break;
case 95:
#line 965 "ada.y"
{
	/*printf("%d, factor primary\n", lineno);*/

	if((yyvsp[-2].expr->isConstant + yyvsp[0].expr->isConstant) == 0){
		yyval.expr->value = pow(yyvsp[-2].expr->value, yyvsp[0].expr->value);
		yyval.expr->isConstant = 0;
	}else{
		yyval.expr->baseRegNum = emitExp(yyvsp[-2].expr, yyvsp[0].expr);
		yyval.expr->isConstant = 1;
		/*fprintf(outFile, "passing up: r%d\n", $$->baseRegNum);*/
	}
					

}
break;
case 96:
#line 980 "ada.y"
{

	yyval.expr = yyvsp[0].expr;
	/*fprintf(outFile, "passing up: r%d\n", $$->baseRegNum);*/


}
break;
case 97:
#line 988 "ada.y"
{
	/*printf("%d, factor not primary\n", lineno);*/

	if(yyvsp[0].expr->isConstant == 0){
		fprintf(outFile, "%d  r%d := not r%d\n", opCount++, regCount, yyvsp[0].expr->baseRegNum);
	}else if(yyvsp[0].expr->isLocal == 1){
		fprintf(outFile, "%d  r%d := not contents b, %d\n", opCount++, regCount, yyvsp[0].expr->offset);
		yyval.expr->isLocal = 1;
		yyval.expr->isConstant = 1;
	}else{
		fprintf(outFile, "%d  r%d := not contents r%d, %d\n", opCount++, regCount, 
				yyvsp[0].expr->baseRegNum, yyvsp[0].expr->offset);
		yyval.expr->isConstant = 1;
		yyval.expr->isLocal = 0;
	}

	yyval.expr->baseRegNum = regCount;
}
break;
case 98:
#line 1009 "ada.y"
{
	/*printf("%d, primary NUMBER\n", lineno);*/

	exprNode *tempNode = NULL;
	tempNode = malloc(sizeof(struct exprNode));

	tempNode->value = yyvsp[0].integer;
	tempNode->isConstant = 0;
	tempNode->isLocal = 0;
	tempNode->baseRegNum = regCount;

	yyval.expr = tempNode;

}
break;
case 99:
#line 1024 "ada.y"
{
	/*printf("%d, primary ID\n", lineno);*/

	exprNode *tempNode = NULL;
	tempNode = malloc(sizeof(struct exprNode));

	Node *tempTreeNode = NULL;
	tempTreeNode = malloc(sizeof(struct node));

	tempTreeNode = searchSymbol(yyvsp[0].var);

	int walkBackCount;
	walkBackCount = (stackCount - searchStack(yyvsp[0].var));

	/* v Not sure about this line here v*/
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
	/*tempNode->isConstant = 1;*/
	/*fprintf(outFile, "ID %s noted with offset %d\n", tempTreeNode->data->name, */
			/*tempNode->offset);*/
	
	yyval.expr = tempNode;

}
break;
case 100:
#line 1067 "ada.y"
{
	/*ID must be a parameter*/
	/* if its not a parameter, then we yyerror and tap out*/


	exprNode *tempNode = NULL;
	tempNode = malloc(sizeof(struct exprNode));

	Node *tempTreeNode = NULL;
	tempTreeNode = malloc(sizeof(struct node));

	tempTreeNode = searchSymbol(yyvsp[-3].var);

	int walkBackCount;
	walkBackCount = (stackCount - searchStack(yyvsp[-3].var));


	if(strcmp(tempTreeNode->data->kind, "type (array)") == 0){
		if(walkBackCount > 0){
			/*fprintf(outFile, "wbCount is: %d\n", walkBackCount);*/
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
break;
case 101:
#line 1105 "ada.y"
{
	printf("%d, primary (expr)\n", lineno);

	yyval.expr = yyvsp[-1].expr;

}
break;
case 102:
#line 1115 "ada.y"
{printf("%d, exception\n", lineno);}
break;
case 103:
#line 1118 "ada.y"
{printf("%d, exHandler List\n", lineno);}
break;
case 104:
#line 1120 "ada.y"
{printf("%d, exHandler\n", lineno);}
break;
case 105:
#line 1123 "ada.y"
{printf("%d, exception choice\n", lineno);}
break;
case 106:
#line 1125 "ada.y"
{printf("%d, exception when choice\n", lineno);}
break;
case 107:
#line 1127 "ada.y"
{printf("%d, choice 'ID|choice'\n", lineno);}
break;
case 108:
#line 1128 "ada.y"
{printf("%d, choice 'ID'\n", lineno);}
break;
#line 1849 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yysslim && yygrowstack())
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    return (1);

yyaccept:
    return (0);
}
