#ifndef STATE_H_INCLUDED
#define STATE_H_INCLUDED

/**
 * Aufzählung der Zustände des Automaten
 *
 * @author Daniela Grammlich
 *
 */

 namespace State {

    /*
     * Zustände des Automaten
     */
	 enum State {
	     START,         // 0 Startzustand
	     FAIL,          // 1 Fehler
	     DIGIT,         // 2 einzelne Ziffer oder mehrere
		 LESSTHAN,		// 3 <, erstes Zeichen von <=>
		 EQUALS,		// 4 =, zweites Zeichen von <=>
	     LETTER,        // 5 einzelner Buchstabe oder mehrere (Bezeichner)
	     SIGN,          // 6 Symbole
		 COMMENT,		// 7 Kommentar
		 END_OF_FILE	// 8 Dateiende
	 };
}

#endif // STATE_H_INCLUDED
