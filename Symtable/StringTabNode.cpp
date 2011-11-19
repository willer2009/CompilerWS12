/*
 * StringTabNode.cpp
 *
 *  Created on: 22.10.2011
 *      Author: sylvain
 */

#include "StringTabNode.h"

StringTabNode::StringTabNode() {
	// TODO Auto-generated constructor stub

}

StringTabNode *StringTabNode::getNext() const
{
    return next;
}

char* StringTabNode::getVector()
{
    return vector;
}

void StringTabNode::setNext(StringTabNode *next)
{
    this->next = next;
}

/*void StringTabNode::setVector(char vector[20000])
{
    this->vector = vector;
}*/

StringTabNode::~StringTabNode() {
	// TODO Auto-generated destructor stub
}

