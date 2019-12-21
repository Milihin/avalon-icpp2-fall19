#include <iostream>
#include <fstream>
#include "BooksDB.h"

using namespace std;
using namespace ext;








int main() {
	
	IdClear();


	ifstream OutBooks("Books.bin", istream::out | istream::binary);

	int size = CountBooks(OutBooks);

	Book* books = new Book[size];

	bool choise = false;
	cout << "have bin file? 1/0 ";
	cin >> choise;
	if (choise) {
		for (int i = 0; i < size; i++) {

		}
	}
	else





	//Book Test;
	//while(0 == 0) {
	//	Test = InputBook();
	//	BinInput(Test);
	//	if (string(Test.Author) == "Ass") break;
	//}
	//
	//IdEditBook(3);







	char pause;
	cin >> pause;

}