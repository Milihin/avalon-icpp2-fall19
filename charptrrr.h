#pragma once
//--��� ���� �����?
//--rrr
//--� �� �� ����� ���� ������ "charptrrr"


namespace xxx {
	struct charString
	{
		char symbol;
		charString* nextSymbol;
	};

	void append(charString* &str, char symbol);
	void print(charString* str);


}