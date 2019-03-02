LEX = flex
YACC = bison
CC = g++
bc:			calc.tab.o lex.yy.o symbol_table.o
			$(CC)  -o bc calc.tab.o lex.yy.o symbol_table.o -lfl -lm

lex.yy.o:		lex.yy.cc calc.tab.hpp

lex.yy.o calc.tab.o:	general.h

calc.tab.cpp calc.tab.hpp:	calc.ypp	
			$(YACC) -d calc.ypp

lex.yy.cc:		calc.l
			$(LEX) -+ calc.l

symbol_table.o:	symbol_table.cpp symbol_table.h
			$(CC) -c symbol_table.cpp

clean:
			rm bc lex.yy.* calc.tab.* symbol_table.o

