%{
#include "y.tab.h"
extern int var[26];
int yylex(void);
%}

delim		[ \t]
ws			{delim}+
letter		[a-z]
id			{letter}({letter}|{digit})*
digit		[0-9]
number		{digit}+
%%
{ws}		{/* no action */}
{id}		{yylval.var_pos = yytext[0]-'a'; return(ID);}
{number}	{yylval.val = atoi(yytext); return(NUMBER);}
"\n"		{return(NEWLINE);}
"+"			{return(PLUS);}
"*"			{return(MULT);}
"("			{return(LPAREN);}
")"			{return(RPAREN);}
"="			{return(EQUAL);}
%%
