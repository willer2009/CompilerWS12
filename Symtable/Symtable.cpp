/*
 * Symtable.cpp
 *
 *  Created on: 22.10.2011
 *      Author: sylvain
 */

#include "Symtable.h"

Symtable::Symtable() {
	// TODO Auto-generated constructor stub
	for(int i = 0; i < ENTRIES_NUMBER; i++){
		this->hashtable[i] = new List();
	}

}

Symtable::~Symtable() {
	// TODO Auto-generated destructor stub
}

/*
int Symtable::insert(char *lexem, TType::TType type)
{
	int length = HelpClass::getLength(lexem);
	int pos = hashcode(lexem, length);
	if(!this->hashtable[pos]->contains(lexem)){
		char* newLexem = this->stringTab.insert(lexem, length);
		this->hashtable[pos]->addElement(new ListElement(new SymtabEntry(Information(newLexem, type))));
	}
	return pos;
}
*/

ListElement* Symtable::insert(char *lexem, TType::TType type)
{
	ListElement* el = NULL;
	int length = HelpClass::getLength(lexem);
	int pos = hashcode(lexem, length);
	if(!this->hashtable[pos]->contains(lexem)){
		char* newLexem = this->stringTab.insert(lexem, length);
		el = new ListElement(new SymtabEntry(Information(newLexem, type)));
		this->hashtable[pos]->addElement(el);
	}
	return el;
}


int Symtable::hashcode(const char *key, int length)
{
	return (key[0] + 11 * key[length - 1] + 26 * length) % ENTRIES_NUMBER;
}

Information Symtable::lookup(const ListElement *listEl)
{
	/*int pos =  hashcode(key, HelpClass::getLength(key));
	if(this->hashtable[pos]->contains(key)){
		Information info;
		return info;
	}
	Information inf;*/
	return listEl->getElement()->getInfo();
}



