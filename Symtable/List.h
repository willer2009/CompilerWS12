/*
 * List.h
 *
 *  Created on: 22.10.2011
 *      Author: sylvain
 */

#ifndef LIST_H_
#define LIST_H_

#include "ListElement.h"
#include "HelpClass.h"

class List
{
private:
    ListElement *first;
    ListElement *last;
    int size;
public:
    List();
    virtual ~List();
    void addElement(ListElement *element);
    ListElement *getFirst() const;
    ListElement *getLast() const;
    int getSize() const;
    void setFirst(ListElement *first);
    void setLast(ListElement *last);
    void setSize(int size);
    bool contains(const char* lexem);
};

#endif /* LIST_H_ */
