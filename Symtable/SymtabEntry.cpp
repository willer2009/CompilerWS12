/*
 * SymtabEntry.cpp
 *
 *  Created on: 22.10.2011
 *      Author: sylvain
 */

#include "SymtabEntry.h"

/*SymtabEntry::SymtabEntry() {
	// TODO Auto-generated constructor stub

}*/

Information SymtabEntry::getInfo()
{
	return this->info;
}

void SymtabEntry::setInfo(char *lexem, TType::TType type)
{
	this->info.setLexem(lexem);
	this->info.setType(type);
}

SymtabEntry::SymtabEntry(Information info)
{
	this->info = info;
}

SymtabEntry::~SymtabEntry() {
	// TODO Auto-generated destructor stub
}

