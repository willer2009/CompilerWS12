/*
 * TType.h
 *
 *  Created on: 22.10.2011
 *      Author: sylvain
 */

#ifndef TTYPE_H_
#define TTYPE_H_

namespace TType {
	enum TType{
		PRINT,
		READ,
		ERROR2,
		INTEGER,
		IDENTIFIER,
		SIGN_PLUS,
		SIGN_MINUS,
		SIGN_MULTI,
		SIGN_DIV,
		SIGN_INFERIOR,
		SIGN_SUPERIOR,
		SIGN_EQUAL,
		SIGN_UNEQUAL,			 //<=>
		SIGN_EXCLAMATION,
		SIGN_SEMICOLON,
		SIGN_COLON,
		SIGN_LEFT_PARENTHESIS,   //(
		SIGN_RIGHT_PARENTHESIS,	 //)
		SIGN_LEFT_SQUAREBRACE,	 //[
		SIGN_RIGHT_SQUAREBRACE,	 //]
		SIGN_LEFT_BRACE,		 //{
		SIGN_RIGHT_BRACE		 //}
	};
}

#endif /* TTYPE_H_ */
