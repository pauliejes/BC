#include "symbol_table.h"
#include <iostream>
using namespace std;

Symbol_node::Symbol_node(char * id) {
	this->id = id;
}

Symbol_node::~Symbol_node(void){}

void Symbol_node::putval(int val) {
	//cout << "id = " << this->id << " val = '" << val << "'\n" ;
	this->val = val;
}

int Symbol_node::getval(void) {
	//cout << "id = " << this->id << " getting value = " << val << endl;
	return this->val;
}

Symbol_table::Symbol_table(void)
{
	table = new Symbol_ptr[211];
	for (int i = 0; i < 211; ++i)
	{
		table[i] = 0;
	}
}

Symbol_table::~Symbol_table(void){

}

int Symbol_table::hash(const char * name) 
{
	int hashVal = 0;
	for (int i = 0; i < sizeof(name)/sizeof(char); ++i)
	{
		hashVal += int(name[i]);
	}
	return hashVal % 211;
}

Symbol_ptr Symbol_table::insert (char * name) 
{
	Symbol_ptr ptr;
	int hashVal = hash(name);

	//if bucket is empty put node address in
	if(this->table[hashVal] == 0) {
		//cout << "adding new node\n";
		this->table[hashVal] = new Symbol_node(name);
		ptr = this->table[hashVal];
	} else {
		//cout << "finding old node\n";
		ptr = table[hashVal];
	}
	return ptr;
}

Symbol_ptr Symbol_table::lookup(char * name) 
{
	Symbol_ptr ptr;
	int hashVal = this->hash(name);
	//cout << "hashVal " << hashVal << endl; 
	ptr = this->table[hashVal];
	//cout << "past the fucking table thign\n";
	return ptr;
}

void Symbol_table::dump_table(void) {
	for (int i = 0; i < 211; ++i)
	{
		if (this->table[i] == 0)
		{
			cout << i+1 << " | " << "empty" << endl;
		} else {
			cout << i+1 << " | " << this->table[i]->id << " = " << this->table[i]->val << endl;
		}
	}
}