#pragma once
//--как тигр рычит?
//--rrr
//--я же по ночам буду рычать "charptrrr"


namespace xxx {
	struct charString
	{
		char symbol;
		charString* nextSymbol;
	};

	void append(charString* &str, char symbol);
	void print(charString* str);


}