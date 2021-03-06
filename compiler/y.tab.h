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
typedef union {
	int integer;
	char *var;
	char operation;
	struct idnode *idList;
	struct node *nodeThing;
	struct exprNode *expr;
} YYSTYPE;
extern YYSTYPE yylval;
