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

	void Id_Correct(Book* arr, int size) {
		int max, count;
		max = 0;
		count = 1;
		for (int i = 0; i < size; i++) {
			if (arr[i].Id > max) {
				max = arr[i].Id;
			}
		}
		sortId(arr, size);
		for (int i = 0; i < size-1; i++) {
			if (arr[i].Id == arr[i + 1].Id) {
				arr[i].Id = max + count;
				count++;
				i = 0;
				sortId(arr, size);
			}
		}

	}

	void saveBookDb(Book arr[], int size) {
		clearBinary();
		for (int i = 0; i < size; i++) {
			BinInput(arr[i]);
		}
	}


	void IdEdit(int countt) {
		ofstream IdFile("id");
		IdFile << countt;
		IdFile.close();
	}

	void WriteAllBooks(Book arr[], int size) {
		cout << "Название\t\t|Автор\t\t|ID\t|Цена\t|Количество" << endl;
		for (int i = 0; i < size; i++) {
			cout << arr[i].Title << "\t\t" << arr[i].Author << "\t\t" << arr[i].Id << "\t" << arr[i].Price << "\t" << arr[i].Quantity << "\t" << endl;
		}
		char end;
		cin >> end;
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

	void AddBook(Book* arr, int size, Book AddBook) {
		Book* arr2 = new Book[size + 1];
		for (int i = 0; i < size; i++) {
			arr2[i] = arr[i];
		}
		arr2[size] = AddBook;
		delete arr;
		arr = arr2;
		delete arr2;
	}

	void copy(char* ptr, const string& temp)
	{
		strcpy_s(ptr, Book::BUFFER_SIZE, temp.c_str());
	}

	void IdSearchEdit(Book* arr, int size, int ID) {
		Id_Correct(arr, size);
		bool ostalos_6_chasov_do_deadlineA_a_ya_tolko_2_funciyu_pilu_mne_tochno_ne_zhit;
		for (int i = 0; i < size; i++) {
			if (arr[i].Id == ID) {
				cout << "Сменить колличество? 1/0" << endl;
				cin >> ostalos_6_chasov_do_deadlineA_a_ya_tolko_2_funciyu_pilu_mne_tochno_ne_zhit;
				if (ostalos_6_chasov_do_deadlineA_a_ya_tolko_2_funciyu_pilu_mne_tochno_ne_zhit) {
					cin >> arr[i].Quantity;
				}
				cout << "Сменить Цену? 1/0" << endl;
				cin >> ostalos_6_chasov_do_deadlineA_a_ya_tolko_2_funciyu_pilu_mne_tochno_ne_zhit;
				if (ostalos_6_chasov_do_deadlineA_a_ya_tolko_2_funciyu_pilu_mne_tochno_ne_zhit) {
					cin >> arr[i].Price;
				}
				cout << "Сменить Название? 1/0" << endl;
				cin >> ostalos_6_chasov_do_deadlineA_a_ya_tolko_2_funciyu_pilu_mne_tochno_ne_zhit;
				if (ostalos_6_chasov_do_deadlineA_a_ya_tolko_2_funciyu_pilu_mne_tochno_ne_zhit) {
					cin >> arr[i].Title;
				}
				cout << "Сменить Автора? 1/0" << endl;
				cin >> ostalos_6_chasov_do_deadlineA_a_ya_tolko_2_funciyu_pilu_mne_tochno_ne_zhit;
				if (ostalos_6_chasov_do_deadlineA_a_ya_tolko_2_funciyu_pilu_mne_tochno_ne_zhit) {
					cin >> arr[i].Author;
				}
				break;
			}
		}
	}



	void sortAuthor(Book* arr, int size) {
		Book swap;
		for (int i = 0; i < size - 1; ++i) {
			if (arr[0].Author > arr[1].Author) {
				i = 0;
			}
			if (arr[i].Author > arr[i + 1].Author) {
				swap = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = swap;
				i = 0;
			}
		}
	}
	void sortName(Book* arr, int size) {
		Book swap;
		for (int i = 0; i < size - 1; ++i) {
			if (arr[0].Title > arr[1].Title) {
				i = 0;
			}
			if (arr[i].Title > arr[i + 1].Title) {
				swap = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = swap;
				i = 0;
			}
		}
	}
	void sortId(Book* arr, int size) {
		Book swap;
		for (int i = 0; i < size - 1; ++i) {
			if (arr[0].Id > arr[1].Id) {
				i = 0;
			}
			if (arr[i].Id > arr[i + 1].Id) {
				swap = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = swap;
				i = 0;
			}
		}
	}
	void sortPrice(Book* arr, int size) {
		Book swap;
		for (int i = 0; i < size - 1; ++i) {
			if (arr[0].Price > arr[1].Price) {
				i = 0;
			}
			if (arr[i].Price > arr[i + 1].Price) {
				swap = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = swap;
				i = 0;
			}
		}
	}
	void sortQuantity(Book* arr, int size) {
		Book swap;
		for (int i = 0; i < size - 1; ++i) {
			if (arr[0].Quantity > arr[1].Quantity) {
				i = 0;
			}
			if (arr[i].Quantity > arr[i + 1].Quantity) {
				swap = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = swap;
				i = 0;
			}
		}
	}



	void clearBinary() {
		ofstream fout("Books.bin", istream::out | istream::binary);
		fout.close;
	}













	///_______________________________________________________\

	void searchB(Book* arr, int size, int id) {
		int i = 0;
		while (arr[i].Id != id) {
			i++;
		}
		cout << "Название" << endl;
		cout << arr[i].Title;
		cout << "Автор" << endl;
		cout << arr[i].Author;
		cout << "Количество" << endl;
		cout << arr[i].Quantity;
		cout << "Цена" << endl;
		cout << arr[i].Price;
		cout << "Id" << endl;
		cout << arr[i].Id;
		cin >> i;
	}
	void searchB(Book* arr, int size, char name[]) {
		int i = 0;
		while (arr[i].Title != name) {
			i++;
		}
		cout << "Название" << endl;
		cout << arr[i].Title;
		cout << "Автор" << endl;
		cout << arr[i].Author;
		cout << "Количество" << endl;
		cout << arr[i].Quantity;
		cout << "Цена" << endl;
		cout << arr[i].Price;
		cout << "Id" << endl;
		cout << arr[i].Id;
		cin >> i;
	}
	void searchBa(Book* arr, int size, char autor[]) {
		int i = 0;
		while (arr[i].Author != autor) {
			i++;
		}
		cout << "Название" << endl;
		cout << arr[i].Title;
		cout << "Автор" << endl;
		cout << arr[i].Author;
		cout << "Количество" << endl;
		cout << arr[i].Quantity;
		cout << "Цена" << endl;
		cout << arr[i].Price;
		cout << "Id" << endl;
		cout << arr[i].Id;
		cin >> i;
	}
	///_______________________________________________________/




	Book InputBook(){
		Book outt;
		string temp;
		ifstream IdFile("id");

		cout << "input Title" << endl;
		getline(std::cin, temp);
		copy(outt.Title, temp);
		cout << "input Autor" << endl;
		getline(std::cin, temp);
		copy(outt.Author, temp);
		cout << "input Price" << endl;
		std::cin >> outt.Price;
		cout << "input Quantity" << endl;
		std::cin >> outt.Quantity;
		std::cin.ignore(100, '\n');
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










	///_______________________________________________________
	/*


	*/
}
