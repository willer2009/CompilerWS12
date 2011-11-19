/*
 * Information.h
 *
 *  Created on: 22.10.2011
 *      Author: sylvain
 */

#ifndef INFORMATION_H_
#define INFORMATION_H_

#include "TType.h"

class Information {
private:
    char *lexem;
    TType::TType type;
public:
    Information();
    Information(char* lexem, TType::TType type);
    virtual ~Information();
    char *getLexem() const;

    TType::TType getType() const;
    void setLexem(char *lexem);
    void setType(TType::TType type);
};

#endif /* INFORMATION_H_ */
