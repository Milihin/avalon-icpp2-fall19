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
	
	using fuck = charString;
	void append(charString* &str, char symbol);
	void print(charString* str);
	/* ������� ��������� ��� ��������� : ������������ ������ � ��� �����.������� ������� �������� ���������� ��������(������ ��������) � �������� �������(������ ��������) ������������ ������.
	��������, ���� ������������ ������ - 'abcdefg', ������ �������� - 2, ������ - 3. �� ����� ������ ������� �������� ������������ ������ ������ ����� 'aefg'.*/
	void removeChars(fuck str, int start, int ent);

}