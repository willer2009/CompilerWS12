/*
 * ISymtable.h
 *
 *  Created on: 22.10.2011
 *      Author: sylvain
 */

#ifndef ISYMTABLE_H_
#define ISYMTABLE_H_

#include "Information.h"
#include "TType.h"
#include "ListElement.h"

class ISymtable{
public:
	//virtual int insert(char* lexem, TType::TType type) = 0;
	virtual ListElement* insert(char* lexem, TType::TType type) = 0;
	virtual Information lookup(const ListElement *listEl) = 0;
	virtual ~ISymtable(){}
};



#endif /* ISYMTABLE_H_ */
