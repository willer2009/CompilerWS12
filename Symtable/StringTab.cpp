/*
 * StringTab.cpp
 *
 *  Created on: 22.10.2011
 *      Author: sylvain
 */

#include "StringTab.h"
#include "HelpClass.h"

StringTab::StringTab() {
	this->first = new StringTabNode();
	this->currentNode = this->first;
	this->freeP = first->getVector();
	this->freeSpace = CHAR_NUMBER;
}

StringTabNode *StringTab::getFirst() const
{
    return first;
}

char *StringTab::getFreeP() const
{
    return freeP;
}

int StringTab::getFreeSpace() const
{
    return freeSpace;
}

void StringTab::setFirst(StringTabNode *first)
{
    this->first = first;
}

void StringTab::setFreeP(char *freeP)
{
    this->freeP = freeP;
}

void StringTab::setFreeSpace(int freeSpace)
{
    this->freeSpace = freeSpace;
}

StringTab::~StringTab() {
	// TODO Auto-generated destructor stub

}

char *StringTab::insert(char *lexem, int size)
{
	char* tmp = this->freeP;
	if(size < this->freeSpace){
		memcpy(this->freeP, lexem, size + 1);
		this->freeP[size] = '\0';
		this->freeP += size + 1;
		this->freeSpace -= size + 1;
	}else{
		this->currentNode->setNext(new StringTabNode());
		this->currentNode = this->currentNode->getNext();
		this->freeP = this->currentNode->getVector();
		this->freeSpace = CHAR_NUMBER;
		tmp = this->freeP;
		memcpy(this->freeP, lexem, size + 1);
				this->freeP[size] = '\0';
				this->freeP += size + 1;
				this->freeSpace -= size + 1;
	}
	return tmp;
}



