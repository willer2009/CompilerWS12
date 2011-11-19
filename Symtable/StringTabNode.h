/*
 * StringTabNode.h
 *
 *  Created on: 22.10.2011
 *      Author: sylvain
 */

#ifndef STRINGTABNODE_H_
#define STRINGTABNODE_H_

#include "HelpClass.h"
#include "StringTabNode.h"

class StringTabNode {
private:
    char vector[CHAR_NUMBER];
    StringTabNode *next;
public:
    StringTabNode();
    virtual ~StringTabNode();

    StringTabNode *getNext() const;
    char* getVector();
    void setNext(StringTabNode *next);
};

#endif /* STRINGTABNODE_H_ */
