#pragma once
//--как тигр рычит?
//--rrr
//--€ же по ночам буду рычать "charptrrr"


namespace xxx {
	struct charString
	{
		char symbol;
		charString* nextSymbol;
	};
	
	using fuck = charString;
	void append(charString* &str, char symbol);
	void print(charString* str);
	/* функци€ принимает три аргумента : динамическую строку и два числа.‘ункци€ удал€ет заданное количество символов(третий аргумент) с заданной позиции(второй аргумент) динамической строки.
	Ќапример, если динамическа€ строка - 'abcdefg', второй агрумент - 2, третий - 3. “о после работы функции исходна€ динамическа€ строка должна стать 'aefg'.*/
	void removeChars(fuck str, int start, int ent);

}