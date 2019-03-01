#include "symbol_table.h"
#include <iostream>
using namespace std;

Symbol_node::Symbol_node(char * id) {
	this->id = id;
	cout<<id<<endl;
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

Symbol_node * Symbol_node::getNext() {
	return this->next;
}

void Symbol_node::setNext(Symbol_node * next) {
	this->next = next;
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
	cout << "hash = " << hashVal % 211 << endl;
	return hashVal % 211;
}

Symbol_ptr Symbol_table::insert (char * name, Symbol_ptr mother_node) 
{
	Symbol_ptr ptr;
	mother_node->setNext(new Symbol_node(name));
	ptr = mother_node->getNext();
	ptr->setNext(0);
	
	return ptr;
}

Symbol_ptr Symbol_table::lookup(char * name) 
{
	Symbol_ptr ptr;
	int hashVal = this->hash(name);
	Symbol_ptr cur_ptr;
	
	//while loop vars
	cur_ptr = table[hashVal];
	bool found = false;
	//traverse linked list of bucket looking for symbol
	cout << "current pointer : " << cur_ptr << endl;
	while(cur_ptr != 0 && found == false) 
	{
		cout << "traversing linked list\n";
		cout << "cur_id = " << cur_ptr->id << endl;
		if(cur_ptr->id == name) {
			//found it, tell loop to stop
			cout << "found " << cur_ptr->id << " = " << name << endl;
			ptr = cur_ptr;
			found = true;
		} else {
			if(cur_ptr->next == 0) {
				cout << "not found\n";
				found = true;
				ptr = this->insert(name, cur_ptr);
			}
		}
		cur_ptr = cur_ptr->next;
	}
	//if nothing there
	if(cur_ptr == 0 && found == false) {
		cout << "nada\n";
		ptr = table[hashVal] = new Symbol_node(name);
		ptr->setNext(0);
	}
	return ptr;
}

void Symbol_table::dump_table() {
	Symbol_ptr ptrz;
	for (int i = 0; i < 211; ++i)
	{
		
			cout << table[i];
		if (this->table[i] == 0)
		{

			cout << i+1 << " | " << "empty" << endl;
		} else {
		
			ptrz = this->table[i];
			cout<<this->table[i]->id<<endl;
			do{
				cout << i+1 << " | " << ptrz->id << " = " << ptrz->val << endl;
				ptrz = ptrz->getNext();
			}while(ptrz != 0);
		}
	}
}
