/*
 * Symtable.h
 *
 *  Created on: 22.10.2011
 *      Author: sylvain
 */

#ifndef SYMTABLE_H_
#define SYMTABLE_H_



#include "ISymtable.h"
#include "StringTab.h"
#include "SymtabEntry.h"
#include "HelpClass.h"
#include "List.h"
#include "TType.h"
#include "ListElement.h"

class Symtable : public ISymtable{
private:
	StringTab stringTab;
	List* hashtable[ENTRIES_NUMBER];
	int hashcode(const char* key, int length);
public:
	Symtable();
	virtual ~Symtable();
//	virtual int insert(char* lexem, TType::TType type);
	virtual ListElement* insert(char* lexem, TType::TType type);
	virtual Information lookup(const ListElement *listEl);

};

#endif /* SYMTABLE_H_ */
