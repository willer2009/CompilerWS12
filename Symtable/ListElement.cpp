/*
 * ListElement.cpp
 *
 *  Created on: 22.10.2011
 *      Author: sylvain
 */

#include "ListElement.h"

ListElement::ListElement(SymtabEntry* symtabEntry) {
	// TODO Auto-generated constructor stub
	this->element = symtabEntry;
	this->nextElement = 0;
}

SymtabEntry* ListElement::getElement() const
{
    return element;
}

ListElement *ListElement::getNextElement() const
{
    return nextElement;
}

void ListElement::setElement(SymtabEntry* element)
{
    this->element = element;
}

void ListElement::setNextElement(ListElement *nextElement)
{
    this->nextElement = nextElement;
}

ListElement::~ListElement() {
	// TODO Auto-generated destructor stub
}

