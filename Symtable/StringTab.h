/*
 * StringTab.h
 *
 *  Created on: 22.10.2011
 *      Author: sylvain
 */

#ifndef STRINGTAB_H_
#define STRINGTAB_H_

#include "string.h"
#include "StringTabNode.h"


class StringTab {
private:
	char* freeP;
	int freeSpace;
	StringTabNode* first;
	StringTabNode* currentNode;
public:
	StringTab();
	virtual ~StringTab();
    StringTabNode *getFirst() const;
    char *getFreeP() const;
    int getFreeSpace() const;
    void setFirst(StringTabNode *first);
    void setFreeP(char *freeP);
    void setFreeSpace(int freeSpace);
    char* insert(char* lexem, int size);
};

#endif /* STRINGTAB_H_ */
