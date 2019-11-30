#include <iostream>
#include "charptrrr.h"
namespace xxx {
	void append(charString* &str, char symbol) {

		charString* ptr = new charString{symbol};
		if (str == nullptr) {
			str = ptr;
		}
		else {
			charString* tmp = str;
			while (tmp->nextSymbol != nullptr) {
				tmp = tmp->nextSymbol;

			}
			tmp->nextSymbol = ptr;
		}
	}
	void print(charString* str) {	
		while (str != nullptr) {
			std::cout << str->symbol;
			str = str->nextSymbol;
		}
	}

	void removeChars(fuck* str, int start, int ent) {
		fuck* savestr = str;
		int count = 0;
		while (count != start) {
			str = str->nextSymbol;
			count++;
		}

		fuck* temp = str->nextSymbol;
		for (int i = 0; i > ent; i++) {
			delete str;
			str = temp;
			temp = str->nextSymbol;
			
		}


	}




}




