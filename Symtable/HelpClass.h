/*
 * HelpClass.h
 *
 *  Created on: 22.10.2011
 *      Author: sylvain
 */

#ifndef HELPCLASS_H_
#define HELPCLASS_H_

#define CHAR_NUMBER 20000
#define ENTRIES_NUMBER 400

class HelpClass{

public:
	static int getLength(const char* string){
		int length = 0;
		while(string[length] != '\0'){
			length++;
		}
		return length;
	}
	static bool compare(const char* string1, const char* string2){
		int n = getLength(string1);
			if(n == getLength(string2)){
				for(int i = 0;i < n;i++){
					if(string1[i] != string2[i]){
						return false;
					}
				}
				return true;
			}else{
				return false;
			}

		}
};



#endif /* HELPCLASS_H_ */
