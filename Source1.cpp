
#include "char.h"


namespace assT {
	int lenStr(fuck str) {
		int lengg = 0;
		while (str[lengg] != '\0') {
			lengg++;
		}
		return lengg;
	}
	char characterAt(fuck arrr, int number) { return arrr[number - 1]; }
	void concatenate(fuck& str1, fuck str2) {
		int lengg = lenStr(str1);
		int lennn = lenStr(str2);
		fuck str3 = new char[lennn + lengg + 1];
		for (int i = 0; i < lengg; i++) {
			str3[i] = str1[i];
		}
		for (int i = 0; i < lennn; i++) {
			str3[i + lennn] = str1[i];
		}
		delete str1;
		str1 = str3;
		delete str3;
		
56	}






}


