#ifndef AUTOMAT_H_INCLUDED
#define AUTOMAT_H_INCLUDED

/**
 *
 *
 * @author Daniela Grammlich
 *
 */

#include "../GlobalTypes/Setup.h"
#include "../GlobalTypes/Token.h"
#include "../IOBuffer/IOBuffer.h"


class Automat{
private:
    char*   currentChar;
    //char*   buffer;
    char    lexem[MAX_LEXEM_LENGTH];    // Char-Array, in welches das aktuell eingelesene Lexem Char f�r Char gespeichert wird
    int     currentColumn;              // aktuelle Spalte, wird im Token hinterlegt
    int     currentLine;                // aktuelle Zeile, wird im Token hinterlegt
    //char    lastReadChar[2];            // Mini-Puffer

    Token   	token;
	IOBuffer*	buffer;

	// Pr�fmethoden
    bool    isDigit(char foundChar);
    bool    isLetter(char foundChar);
    bool    isLinebreak(char foundChar);
    bool    isSign(char foundChar);
    bool    isSpace(char foundChar);

public:
            Automat(IOBuffer* buffer);		// Konstruktor, nimmt Buffer-Pointer
            ~Automat();						// Destruktor

    Token*  searchLexem();					// Automat: Lexem ermitteln

    int     getColumn();
    int     getLine();
    char*   getLexem();
    Token   getToken();
};

#endif // AUTOMAT_H_INCLUDED
