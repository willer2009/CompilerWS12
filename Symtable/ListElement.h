/*
 * ListElement.h
 *
 *  Created on: 22.10.2011
 *      Author: sylvain
 */

#ifndef LISTELEMENT_H_
#define LISTELEMENT_H_

#include "SymtabEntry.h"
class ListElement {
private:
	SymtabEntry* element;
	ListElement* nextElement;
public:
	ListElement(SymtabEntry* symtabEntry);
	virtual ~ListElement();
    SymtabEntry* getElement() const;
    ListElement *getNextElement() const;
    void setElement(SymtabEntry* element);
    void setNextElement(ListElement *nextElement);
};

#endif /* LISTELEMENT_H_ */
