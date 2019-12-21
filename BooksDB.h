#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
namespace ext {
	struct Book
	{
		static const int BUFFER_SIZE = 20;
		int Id;
		char Title[BUFFER_SIZE];
		char Author[BUFFER_SIZE];
		float Price;
		int Quantity;
	};


	void IdClear() {
		ofstream IdFile("id");
		IdFile << 0;
		IdFile.close;
	}




	//Book getBook() {
	//	
	//	Book outt;
	//	string temp;
	//	
	//	cout << "input Title" << endl;
	//	getline(cin, temp);
	//	copy(outt.Title, temp);
	//	cout << "input Autor" << endl;
	//	getline(cin, temp);
	//	copy(outt.Author, temp);
	//	cout << "input Price" << endl;
	//	cin >> outt.Price;
	//	cout << "input Quantity" << endl;
	//	cin >> outt.Quantity;
	//	cin.ignore(100, '\n');
	//	return outt;
	//}












	void copy(char* ptr, const string& temp)
	{
		strcpy_s(ptr, Book::BUFFER_SIZE, temp.c_str());
	}

	Book InputBook() {
		Book outt;
		string temp;
		ifstream IdFile("id");

		cout << "input Title" << endl;
		getline(cin, temp);
		copy(outt.Title, temp);
		cout << "input Autor" << endl;
		getline(cin, temp);
		copy(outt.Author, temp);
		cout << "input Price" << endl;
		cin >> outt.Price;
		cout << "input Quantity" << endl;
		cin >> outt.Quantity;
		cin.ignore(100, '\n');
		IdFile >> outt.Id;
		IdFile.close();

		ofstream IdFile1("id");
		IdFile1 << (outt.Id + 1);
		IdFile1.close();
		return outt;
	}



	int CountBooks(ifstream& fin) {
		fin.seekg(0, ios_base::end);
		int size = fin.tellg();
		int count = size / sizeof(Book);
		fin.seekg(0, ios_base::beg);
		return count;
	}



	void BinInput(Book ToFile) {
		ofstream fout("Books.bin", istream::out | istream::binary | iostream::ate);
		fout.write(reinterpret_cast<char*>(&ToFile), sizeof(Book));
		fout.close();
	}



	//void IdEditBook(const int id) {
	//	ifstream inpBin("Books.bin", istream::out | istream::binary);
	//	int count = 0;
	//	Book search;
	//	inpBin.read(reinterpret_cast<char*>(&search), sizeof(Book));
	//	while(search.Id != id) {
	//		count++;
	//		inpBin.read(reinterpret_cast<char*>(&search), sizeof(Book));						
	//	}
	//	
	//	ofstream fout("Bookstemp.bin", istream::out | istream::binary);
	//
	//	Book edited;
	//	string temp;
	//	edited.Id = search.Id;
	//	cout << "input Title" << endl;
	//	getline(cin, temp);
	//	copy(edited.Title, temp);
	//	cout << "input Autor" << endl;
	//	getline(cin, temp);
	//	copy(edited.Author, temp);
	//	cout << "input Price" << endl;
	//	cin >> edited.Price;
	//	cout << "input Quantity" << endl;
	//	cin >> edited.Quantity;
	//	inpBin.seekg(0, ios_base::beg);
	//	Book tempp;
	//	int sizzz = CountBooks(inpBin);
	//	for (int i = 0; i > count; i++) {
	//		inpBin.read(reinterpret_cast<char*>(&tempp), sizeof(Book));
	//		fout.write(reinterpret_cast<char*>(&tempp), sizeof(Book));
	//	}
	//	fout.write(reinterpret_cast<char*>(&edited), sizeof(Book));
	//	for (int i = count+1; i > sizzz; i++) {
	//		inpBin.read(reinterpret_cast<char*>(&tempp), sizeof(Book));
	//		fout.write(reinterpret_cast<char*>(&tempp), sizeof(Book));
	//	}

	//	inpBin.close();
	//	fout.close();
	//	ifstream ft("Bookstemp.bin", istream::out | istream::binary | iostream::ate);
	//	ofstream outBin("Books.bin", istream::out | istream::binary);

	//	for (int i = 0; i > sizzz; i++) {
	//		ft.read(reinterpret_cast<char*>(&temp), sizeof(Book));
	//		outBin.write(reinterpret_cast<char*>(&temp), sizeof(Book));


	//	}

	//}

	///*Book BinSearch(const int id) {
	//	ifstream fout("Books.bin", istream::binary);
	//	Book outpp;


	//}*/


	//void showStat() {

	//}



}