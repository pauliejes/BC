#include "symbol_table.h"
Symbol_table::Symbol_table(void)
{
	table = new Symbol_ptr[211];
}

int Symbol_table::hash(const char * name) 
{
	int hashVal = 0;
	hashVal += atoi(name);

	return hashVal % 211;
}

Symbol_ptr Symbol_table::insert (char * name) 
{
	Symbol_ptr ptr;
	int hashVal = hash(name);

	return ptr;
}

Symbol_ptr Symbol_table::lookup(char * name) 
{
	Symbol_ptr ptr;
	int hashVal = this->hash(name);

	return ptr;
}