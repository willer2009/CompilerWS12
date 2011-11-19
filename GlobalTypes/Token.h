#ifndef _TOKEN_INCLUDED_
#define _TOKEN_INCLUDED_

#include "TokenType.h"
#include "Setup.h"

class Token {

private:

	/*
    * Zeilennummer des Tokens im Quelltext
    */
    int line;

    /*
	* Spaltennummer des Tokens im Quelltext
	*/
    int column;

	/*
    * Der ganzzahlige Wert welcher in einem Token abgespeichert wird
    */
    unsigned int intValue;

    /*
	* Typ des Tokens
	*/
	TokenType::TokenType tokenType;

	/*
	* Lexem mit fester Länge
	*/
	char lexem[MAX_LEXEM_LENGTH];

	/*
	* Key aus der Symboltabelle
	* für Indetifier
	*/
	int hashKey;

public:
	/*
	* Initialisiert ein neues leeres Token
	*/
	Token();

	/*
	* Löscht das Token aus dem Speicher
	*/
	~Token();

	void clear();

	/*
	* Setter für Zeilennummer
	*/
	void setLine(int line);

	/*
	* Setter für Spaltennummer
	*/
	void setColumn(int column);

	/*
	* Setter für den ganzzahligen Wert eines Tokens
	*/
	void setIntValue(unsigned int intValue);


	/*
	* Setter für Typ des Tokens
	*/
	void setTokenType(TokenType::TokenType tokenType);

	/*
	* Setter für das Lexem
	*/
	void setLexem(char* lexem);

	/**
	* Setter für HashKey
	*/
	void setHashKey(int key);

	/*
	* Getter für Zeilennummer
	*/
	int getLine();

	/*
	* Getter für Spaltennnummer
	*/
	int getColumn();

	/*
	* Getter für den ganzzahligen Wert eines Tokens
	*/
	unsigned int getIntValue();

	/*
	* Getter für Typ des Tokens
	*/
	TokenType::TokenType getTokenType();

	/*
	* Getter für das Lexem
	*/
	char* getLexem();

	/**
	* Getter für HashKey
	*/
	int getHashKey();
};
#endif //_TOKEN_INCLUDED_
