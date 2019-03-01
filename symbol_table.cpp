#include "symbol_table.h"
#include <iostream>
using namespace std;

Symbol_node::Symbol_node(char * id) {
	cout << "initilizing and setting ID!!!!!!!!\n";
        this->id = new char[strlen(id)+1];
	strcpy(this->id,id);
}

Symbol_node::~Symbol_node(void){}

void Symbol_node::putval(int val) {
	//cout << "id = " << this->id << " val = '" << val << "'\n" ;
	this->val = val;
}

int Symbol_node::getval(void) {
	cout << "RUNNING GETVAL | id = " << this->id << " getting value = " << val << endl;
	return this->val;
}

Symbol_node * Symbol_node::getNext() {
	return this->next;
}

void Symbol_node::setNext(Symbol_node * next) {
	this->next = next;
}

char * Symbol_node::getId() {
	return this->id;
}

void Symbol_node::setId(char * id) {
	this->id = id;
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
//insert the new node at the head of the list in the bucket
Symbol_ptr Symbol_table::insert (char * name, Symbol_ptr mother_node) 
{
	cout << "called insert\n";
	Symbol_ptr ptr;
	int hashVal = this->hash(name);

	//set cur_ptr initially to address of first node in bucket (or 0 if there
	//is not one)
	Symbol_ptr cur_ptr = this->table[hashVal];
	cout << "cur_ptr = " << cur_ptr << endl;
	bool inserted = false;

	//if no nodes in list
	if (cur_ptr == 0) {
		cout << "inserting " << name << " into root\n";
		ptr = this->table[hashVal] = new Symbol_node(name);
		cout << "inserted " << this->table[hashVal]->getId() << " into root\n";
	} else {
		while(!inserted) 
		{
			//if at end of list
			if(cur_ptr->next == 0) 
			{
				cout << "inserted symbol " << name << endl;
				cur_ptr->next = new Symbol_node(name);
				ptr = cur_ptr->next;
				inserted = true;
			}
			//set current pointer to pointer to the next node in the list
			cur_ptr = cur_ptr->next;
		}
	}

	//mother_node->next = new Symbol_node(name);
	//ptr = mother_node->getNext();
	//ptr->setNext(0);
	cout << "id = " << this->table[hashVal]->getId() << endl;
	cout << "returning from insert\n\n";
	return ptr;
}
//just return the location of the dang variable if it's already in the 
//symbol table, or return a null pointer if it aint
Symbol_ptr Symbol_table::lookup(char * name) 
{
	Symbol_ptr ptr;
	int hashVal = this->hash(name);
	//while loop vars
	Symbol_ptr cur_ptr = table[hashVal];
	
	
	Symbol_ptr last_ptr = table[hashVal];
	bool found = false;

	cout << "current pointer : " << cur_ptr << endl;
	do {
		if(cur_ptr == 0) 
		{
			//symbol not found, insert it
			cout << "symbol not found\n";
			//cout << "name: " << name << "   last_ptr: " << last_ptr << endl;
			ptr = this->insert(name, last_ptr);
			found = true;
		} else {
			cout << "lookup node_id = " << this->table[hashVal]->getId() << endl << endl;
			//cout << "current pointer id = " << cur_ptr->getId() << endl;
			cout << "name to find = " << name << endl;
			if(strcmp(cur_ptr->getId(), name) == 0) 
			{
				//name matches node id
				cout << "found an id match! : " << cur_ptr->getId() << " = " << name << endl;
				last_ptr = ptr;
				ptr = cur_ptr;
				found = true;
			} else {
				cur_ptr = cur_ptr->next;
			}
		}
	} while (found == false);
	
	cout << "returning ptr = " << ptr << " from lookup\n\n";
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
