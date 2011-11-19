/**
 * Hier werden die Tokentypen definiert
 *
 * @author	Daniela Grammlich <grda1011@hs-karlsruhe.de>
 */

#ifndef _TOKENTYPE_INCLUDED_
#define _TOKENTYPE_INCLUDED_

/**
 * Festlegung der verschiedenen Token Typen
 */
namespace TokenType {
	enum TokenType 
	{
		UNKNOWN,			// ErrorType
		INTEGER,			// Integer
		IDENTIFIER,			// Bezeichner
		PLUS,				// +
		MINUS,				// -
		SLASH,				// /
		ASTERISK,			// *
		L_BRACKET,			// <
		R_BRACKET,			// >
		EQUALS,				// =
		EXCLAMATIONMARK,	// !
		AMPERSAND,			// &
		SEMICOLON,			// ;
		COLON,				// :
		L_PARENTHESIS,		// (
		R_PARENTHESIS,		// )
		L_BRACE,			// {
		R_BRACE,			// }
		L_SQUAREBRACE,		// [
		R_SQUAREBRACE,		// ]
		UNEQUAL,			// <=>
		PRINT,				// PRINT
		READ,				// READ
		OUTOFRANGE,			// OOR
		IF,					// IF
		ELSE,				// ELSE
		WHILE,				// WHILE
		INT					// INT
	};
}

#endif //_TOKENTYPE_INCLUDED