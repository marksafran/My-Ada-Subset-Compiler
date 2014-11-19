/***********************************************************************
//                          ada.l
//Name: Mark Safran
//Date: October 19, 2014
//Class: Compiler Construction
//Instrcutor: Professor King
//Purpose:  A lexical analyzer for our ADA subset grammar
//*********************************************************************/

%{
#include "y.tab.h"
int lineno;
char linebuff[500];
%}

%%
"end if" {return ENDIF;}
"end record" {return ENDREC;}
"end loop" {return ENDLOOP;}
"exit when" {return EXITWHEN;}
"is" {return IS;}
"of" {return OF;}
"begin" {return BEG;}
"end" {return END;}
".." {return DOTDOT;}
"'" {return TICK;}
"procedure" {return PROCEDURE;}
"type" {return TYPE;}
"array" {return ARRAY;}
"record" {return RECORD;}
"in" {return IN;}
"out" {return OUT;}
"range" {return RANGE;}
"constant" {return CONSTANT;}
":=" {return ASSIGN;}
"exception" {return EXCEPTION;}
"null" {return NULLWORD;}
"loop" {return LOOP;}
"if" {return IF;}
"then" {return THEN;}
"elsif" {return ELSEIF;}
"else" {return ELSE;}
"exit" {return EXIT;}
"when" {return WHEN;}
"and" {return AND;}
"or" {return OR;}
"not" {return NOT;}
"=" {return EQ;}
"/=" {return NEQ;}
">" {return GT;}
"<" {return LT;}
">=" {return GTE;}
"<=" {return LTE;}
"**" {return EXP;}
"raise" {return RAISE;}
"others" {return OTHERS;}
"=>" {return ARROW;}

[a-zA-Z][0-9a-zA-Z_]* {yylval.var = malloc(sizeof(strlen(yytext)-1));
		       strcpy(yylval.var, yytext);
                       return ID;}

[0-9]+ {yylval.integer = atoi(yytext);
        return NUMBER;}

[ \t] ;
\n.* {strcpy(linebuff, yytext+1);
      lineno++;
      yyless(1);}

"--"[^\n\r]* ;
. {return yytext[0];}

%%

void yyerror(char *s)
{
    printf("ERROR: %d: %s at %s in this line:\n%s\n", lineno, s, yytext, linebuff);
}