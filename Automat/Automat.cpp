/**
 *
 *
 * @author	Daniela Grammlich <grda1011@hs-karlsruhe.de>
 *
*/

#include "Automat.h"
#include "State.h"
#include "../GlobalTypes/Token.h"
#include "../GlobalTypes/TokenType.h"
#include <stdlib.h>
#include <errno.h>
#include "../GlobalTypes/Helper.h"
#include <limits.h>

/**
 * Konstruktor
 *
 * @param buffer
 */
Automat::Automat(IOBuffer* buffer) {
	this->currentLine       = 1;
	this->currentColumn     = 0;

	this->buffer = buffer;
	this->token  = Token();
}

/**
 * Destruktor
 */
Automat::~Automat() {
}

Token* Automat::searchLexem() {
	State::State state = State::START;
	this->token.clear();

	bool commentTrigger = false;
	bool commentEndTrigger = false;
	
	int chCount = 0;

	while(true) {
		this->lexem[chCount] = buffer->getChar();
		currentColumn++;

		switch(state) {
			/* ********* START ********* */
			case State::START:
				if(commentTrigger == true && this->lexem[chCount] != '*') {
					buffer->ungetChar(1);
					currentColumn--;
					state = State::SIGN;
					commentTrigger = false;
				} else if(this->isLinebreak(this->lexem[chCount])) {
					currentLine++;
					currentColumn = 0;

				} else if(this->lexem[chCount] == '\0') {
					state = State::END_OF_FILE;

				} else if(this->isDigit(this->lexem[chCount])) {

					this->token.setColumn(this->currentColumn);
					this->token.setLine(this->currentLine);
					chCount++;
					state = State::DIGIT;

				} else if(this->isLetter(this->lexem[chCount])) {

					this->token.setColumn(this->currentColumn);
					this->token.setLine(this->currentLine);
					chCount++;
					state = State::LETTER;

				} else if(this->isSign(this->lexem[chCount])) {

					this->token.setColumn(this->currentColumn);
					this->token.setLine(this->currentLine);
					
					if(this->lexem[chCount] == '<') {
						state = State::LESSTHAN;
					} else if(this->lexem[chCount] == '(') {
						commentTrigger = true;
					} else if(commentTrigger == true && this->lexem[chCount] == '*') {
						state = State::COMMENT;
					} else {
						state = State::SIGN;					
					}
					chCount++;
				} else if(this->isSpace(this->lexem[chCount])) {
				} else {
					this->token.setColumn(this->currentColumn);
					this->token.setLine(this->currentLine);
					state = State::FAIL;
					chCount++;
				}
				break;

				/* ********* DIGIT ********* */
			case State::DIGIT:

				if(this->isDigit(this->lexem[chCount])) {
					chCount++;
				} else {
					buffer->ungetChar(1);
					currentColumn--;
					
					long tmp = strtol(this->lexem, NULL, 10);
					if( !(	(errno == ERANGE && (tmp == LONG_MAX || tmp == LONG_MIN))
						||	(errno != 0 && tmp == 0)
						 )) {
						this->token.setIntValue(tmp);

						this->lexem[chCount] = '\0';
						chCount = 0;
						this->token.setTokenType(TokenType::INTEGER);
						this->token.setLexem(this->lexem);
						return &token;
					} else {
						state = State::FAIL;
					}
				}
				break;

				/* ********* LESS THAN ********* */
			case State::LESSTHAN:

				if(this->lexem[chCount] == '=') {
					chCount++;
					state = State::EQUALS;
				} else {
					currentColumn--;
					buffer->ungetChar(1); 
					state = State::SIGN;
				}
				break;

				/* ********* EQUALS ********* */
			case State::EQUALS:

				if(this->lexem[chCount] == '>') {
					chCount++;
					this->token.setTokenType(TokenType::UNEQUAL);
					state = State::SIGN;
				} else {
					currentColumn -= 2;
					buffer->ungetChar(2);
					chCount--;
					state = State::SIGN;
				}
				break;

				/* ********* LETTER ********* */
			case State::LETTER:

				if(this->isLetter(this->lexem[chCount]) || this->isDigit(this->lexem[chCount])) {
					chCount++;
				} else {
					currentColumn--;
					buffer->ungetChar(1);
					this->lexem[chCount]='\0';
					chCount = 0;
					if (Helper::compareCaseInsensitive(this->lexem, "print")) {
						token.setTokenType(TokenType::PRINT);
					} else if (Helper::compareCaseInsensitive(this->lexem, "read")) {
						token.setTokenType(TokenType::READ);
					} else if (Helper::compareCaseInsensitive(this->lexem, "if")) {
						token.setTokenType(TokenType::IF);
					} else if (Helper::compareCaseInsensitive(this->lexem, "else")) {
						token.setTokenType(TokenType::ELSE);
					} else if (Helper::compareCaseInsensitive(this->lexem, "while")) {
						token.setTokenType(TokenType::WHILE);
					} else if (Helper::compareCaseInsensitive(this->lexem, "int")) {
						token.setTokenType(TokenType::INT);
					} else {
						token.setTokenType(TokenType::IDENTIFIER);
					}
					token.setLexem(this->lexem);
					return &token;
				}
				break;

				/* ********* SIGN ********* */
			case State::SIGN:
				this->lexem[chCount]='\0';
				chCount=0;

				currentColumn--;
				buffer->ungetChar(1);

				this->token.setLexem(this->lexem);
				return &token;
				break;

				/* ********* FAIL ********* */
			case State::FAIL:
				if(lexem[chCount] == '\0') {
					return 0;
				}

				this->lexem[chCount] = '\0';
				chCount = 0;
				if (errno == ERANGE) {
					this->token.setTokenType(TokenType::OUTOFRANGE);
				errno=0;}
				else
					this->token.setTokenType(TokenType::UNKNOWN);
				this->token.setLexem(this->lexem);
				
				currentColumn--;
				buffer->ungetChar(1);

				return &token;
				break;

				/* ********* COMMENT ********** */
			case State::COMMENT:
				if(lexem[chCount] == '*') {
					commentEndTrigger = true;
				} else if (lexem[chCount] == ')' && commentEndTrigger) {
					chCount = 0;
					state = State::START;
					commentEndTrigger = false;
					commentTrigger = false;
				} else if (lexem[chCount] == '\0') {
					state = State::FAIL;
					break;
				} else if (this->isLinebreak(lexem[chCount])) {
					currentLine++;
					currentColumn = 0;
				} else {
					commentEndTrigger = false;
				}
				break;

				/* ********* END_OF_FILE ********* */
			case State::END_OF_FILE:
				return 0;
				break;
		}
	}
}

int Automat::getColumn() {
	return this->token.getColumn();
}

char* Automat::getLexem() {
	return this->token.getLexem();
}

int Automat::getLine() {
	return this->token.getLine();
}

Token Automat::getToken() {
	return this->token;
}

bool Automat::isDigit(char foundChar) {
	return (foundChar >= '0' && foundChar <= '9');
}

bool Automat::isLetter(char foundChar) {
	return ((foundChar >= 'A' && foundChar <= 'Z') || (foundChar >= 'a' && foundChar <= 'z'));
}

bool Automat::isLinebreak(char foundChar) {
	switch(foundChar) {
		case '\n':   
			return true;
			break;
		default:    
			return false;
			break;
	}
}

bool Automat::isSign(char foundChar) {
	switch(foundChar) {
		case '+':   token.setTokenType(TokenType::PLUS); return true;
		case '-':   token.setTokenType(TokenType::MINUS); return true;
		case '/':   token.setTokenType(TokenType::SLASH); return true;
		case '*':   token.setTokenType(TokenType::ASTERISK); return true;
		case '<':   token.setTokenType(TokenType::L_BRACKET); return true;
		case '>':   token.setTokenType(TokenType::R_BRACKET); return true;
		case '=':   token.setTokenType(TokenType::EQUALS); return true;
		case '!':   token.setTokenType(TokenType::EXCLAMATIONMARK); return true;
		case '&':   token.setTokenType(TokenType::AMPERSAND); return true;
		case ';':   token.setTokenType(TokenType::SEMICOLON); return true;
		case ':':   token.setTokenType(TokenType::COLON); return true;
		case '(':   token.setTokenType(TokenType::L_PARENTHESIS); return true;
		case ')':   token.setTokenType(TokenType::R_PARENTHESIS); return true;
		case '{':   token.setTokenType(TokenType::L_BRACE); return true;
		case '}':   token.setTokenType(TokenType::R_BRACE); return true;
		case '[':   token.setTokenType(TokenType::L_SQUAREBRACE); return true;
		case ']':   token.setTokenType(TokenType::R_SQUAREBRACE); return true;
		default:    return false;
	}
}

bool Automat::isSpace(char foundChar) {
	if(this->isLinebreak(foundChar)) {
		return false;
	} else {
		switch(foundChar) {
			case ' ':
			case '\t':
			case '\r':  return true;
			default:    return false;
		}
	}
}
