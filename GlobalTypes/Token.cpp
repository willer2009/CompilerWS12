#include "Token.h"

	/*
	* Initialisiert ein neues leeres Token
	*/
	Token::Token() {
		this->line = 0;
		this->column = 0;
		this->intValue = 0;
		this->tokenType = TokenType::UNKNOWN;
	}

	/*
	* Löscht das Token aus dem Speicher
	*/
	Token::~Token() {

	}

	void Token::clear() {
	    this->line = 0;
		this->column = 0;
		this->intValue = 0;
		this->tokenType = TokenType::UNKNOWN;
		this->hashKey = 0;
    }

	/*
	* Setter für Zeilennummer
	*/
	void Token::setLine(int line) {
		this->line = line;
	}

	/*
	* Setter für Spaltennummer
	*/
	void Token::setColumn(int column) {
		this->column = column;
	}

	/*
	* Setter für den ganzzahligen Wert eines Tokens
	*/
	void Token::setIntValue(unsigned int intValue) {
		this->intValue = intValue;
	}


	/*
	* Setter für Typ des Tokens
	*/
	void Token::setTokenType(TokenType::TokenType tokenType) {
		this->tokenType = tokenType;
	}

	/*
	* Setter für das Lexem
	*/
	void Token::setLexem(char* lexem) {
        for (int i = 0; lexem[i] != '\0'; i++) {
                this->lexem[i] = lexem[i];
                this->lexem[i + 1] = '\0';
        }
	}

	/*
	* Setter für HashKey
	*/
	void Token::setHashKey(int key) {
		this->hashKey = key;
	}

	/*
	* Getter für Zeilennummer
	*/
	int Token::getLine() {
		return this->line;
	}

	/*
	* Getter für Spaltennnummer
	*/
	int Token::getColumn() {
		return this->column;
	}

	/*
	* Getter für HashKey
	*/
	int Token::getHashKey() {
		return this->hashKey;
	}

	/*
	* Getter für den ganzzahligen Wert eines Tokens
	*/
	unsigned int Token::getIntValue() {
		return this->intValue;
	}


	/*
	* Getter für Typ des Tokens
	*/
	TokenType::TokenType Token::getTokenType() {
		return this->tokenType;
	}

	/*
	* Getter für das Lexem
	*/
	char* Token::getLexem() {
		return this->lexem;
	}


