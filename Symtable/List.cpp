/*
 * List.cpp
 *
 *  Created on: 22.10.2011
 *      Author: sylvain
 */

#include "List.h"

List::List() {
	// TODO Auto-generated constructor stub
	this->first = 0;
	this->last = 0;
	this->size = 0;
}

ListElement *List::getFirst() const
{
    return first;
}

ListElement *List::getLast() const
{
    return last;
}

int List::getSize() const
{
    return size;
}

void List::setFirst(ListElement *first)
{
    this->first = first;
}

void List::setLast(ListElement *last)
{
    this->last = last;
}

void List::addElement(ListElement *element)
{
	if(this->size == 0){
		first = element;
		last = element;
	}else{
		last->setNextElement(element);
		this->setLast(element);
	}
	this->size++;
}

void List::setSize(int size)
{
    this->size = size;
}

List::~List() {
	// TODO Auto-generated destructor stub
}

bool List::contains(const char *lexem)
{
	if(this->size == 0){
		return false;
	}else{
		ListElement* tmp = first;
		while(tmp->getNextElement() != 0){
			if(HelpClass::compare(tmp->getElement()->getInfo().getLexem(), lexem)){
				return true;
			}
			tmp = tmp->getNextElement();
		}

		//das letzte Element auch testen, weil die While-Schleife überprüft es nicht
		if(HelpClass::compare(tmp->getElement()->getInfo().getLexem(), lexem)){
			return true;
		}
	}
	return false;
}



