%{
#include"symbol_table.h"
#include"calc.tab.hpp"
//#include"general.h"
//extern int var[26];
extern Symbol_table sym_table;

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
"quit"		{exit(0);}
"dump"		{sym_table.dump_table();}
{ws}		{/*no action*/}
{id}		{yylval.symbol_ptr = sym_table.insert(yytext);return(ID);}
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
%%