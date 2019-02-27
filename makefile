LEX=flex
YACC=yacc
CC=g++

bc: 	y.tab.o lex.yy.o
		$(CC) -o bc y.tab.o lex.yy.o -lfl -lm
lex.yy.o: 	lex.yy.c y.tab.h
lex.yy.o y.tab.o: 	general.h
y.tab.c y.tab.h:	calc.y
					$(YACC) -d calc.y
lex.yy.c:	calc.l
			$(LEX) calc.l

clean: 	
	rm bc lex.yy.* y.tab.*
