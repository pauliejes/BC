%{
#include"calc.tab.hpp"
extern int var[26];

yyFlexLexer lexer;
int yylex(void)
{
	return lexer.yylex();
}
%}

%option noyywrap
delim		[ \t]
ws			{delim}+
letter		[a-z]
id			{letter}({letter}|{digit})*
digit		[0-9]
number		{digit}+
%%
{ws}		{/*no action*/}
{id}		{yylval.var_pos = sym_table.lookup(yytext);return(ID);}
{number}	{yylval.val = atoi(yytext);return(NUMBER);}
"\n"		{return(NEWLINE);}
"+"			{return(PLUS);}
"*"			{return(MULT);}
"-"			{return(MINUS);}
"/"			{return(DIV);}
"%"			{return(MOD);}
"^"			{return(POW);}
"("			{return(LPAREN);}
")"			{return(RPAREN);}
"="			{return(EQUAL);}
"quit"		{exit(0);}
%%