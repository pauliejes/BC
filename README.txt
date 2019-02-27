Paul Jesukiewicz
BC version 1

calc.l:
	This lex file describes the tokens of the language.

calc.y:
	Provides our symbol table along with c++ code to handle parsing and errors. 

To run:
	In the directory containing the lex and yacc files, type make.
	Run ./bc then type in a string following the defined language.
	For example - 2 + 6
	will return - 8

To clear generated files:
	make clean
