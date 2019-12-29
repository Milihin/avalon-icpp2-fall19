#include <iostream>
#include <fstream>
#include "Book DB.hpp"


using namespace std;
using namespace ext;








int main() {

	IdEdit(0);
	cout << endl;



	ifstream OutBooks("Books.bin", istream::out | istream::binary);

	//это здесь потому что € люблю ASCII-арты
	char str1[] = "__________               __     ________ __________ ";
	char str2[] = "\\______   \\ ____   ____ |  | __ \\______ \\\\______   \\";
	char str3[] = " |    |  _//  _ \\ /  _ \\|  |/ /  |    |  \\|    |  _/";
	char str4[] = " |    |   (  <_> |  <_> )    <   |    `   \\    |   \\";
	char str5[] = " |______  /\\____/ \\____/|__|_ \\ /_______  /______  /";
	char str6[] = "        \\/                   \\/         \\/       \\/ ";

	char mstr1[] = "___  ___                 ";
	char mstr2[] = "|  \\/  |                 ";
	char mstr3[] = "| .  . | ___ _ __  _   _ ";
	char mstr4[] = "| |\\/| |/ _ \\ '_ \\| | | |";
	char mstr5[] = "| |  | |  __/ | | | |_| |";
	char mstr6[] = "\\_|  |_/\\___|_| |_|\\__,_|";





	cout << str1 << endl << str2 << endl << str3 << endl << str4 << endl << str5 << endl << str6 << endl;
	int size = CountBooks(OutBooks);
	



	Book* books = new Book[size];

	int choise = 0;
	cout << "have bin file? 1/0 ";
	std::cin >> choise;
	if (choise != 0) {
		for (int i = 0; i < size; i++) {
			OutBooks.read(reinterpret_cast<char*>(&books[i]), sizeof(Book));
		}
	}
	choise = 10;
	int choise_search;
	Book TempBook;
	int SearchID;

	while (choise != 0) {
		cout << mstr1 << endl << mstr2 << endl << mstr3 << endl << mstr4 << endl << mstr5 << endl << mstr6 << endl;
		cout << "1 - добавить книгу" << endl;
		cout << "2 - редактировать по ID" << endl;
		cout << "3 - найти информацию о книге" << endl;
		cout << "4 - сортировать книги" << endl;
		cout << "5 - показать все книги" << endl;
		cout << "6 - у мен€ всЄ таки был бинарник, но € ответил 1 и теперь не знаю как вытащить данные из него(" << endl;
		cout << "7 - сохранить" << endl;
		cout << "0 - выход" << endl;
		std::cin >> choise;
		switch (choise)
		{
		case 1:
			TempBook = InputBook();
			AddBook(books, size, TempBook);
			size++;
			break;
		case 2:
			cout << "ID" << endl;
			std::cin >> SearchID;
			IdSearchEdit(books, size, SearchID);
			break;
		case 3:
			cout << "что вы знаете об этой книге?" << endl;
			cout << "1 - ID" << endl;
			cout << "2 - Ќазвание" << endl;
			cout << "3 - јвтора" << endl;
			std::cin >> choise_search;
			switch (choise_search)
			{
			case 1:
				int id;
				searchB(books, size, id);
				break;
			case 2:
				char autor[books->BUFFER_SIZE];
				searchBa(books, size, autor);
				break;
			case 3:
				char nname[books->BUFFER_SIZE];
				searchB(books, size, nname);
				break;
			default:
				cout << "fuck again" << endl;
				break;
			}

			break;
		case 4:
			cout << "как вы желаете соритровать книги?" << endl;
			cout << "1 - ID" << endl;
			cout << "2 - Ќазвание" << endl;
			cout << "3 - јвтор" << endl;
			cout << "4 - ÷ена" << endl;
			cout << "5 -  ол-во" << endl;
			std::cin >> choise_search;
			switch (choise_search)
			{
			case 1:
				sortId(books, size);
				break;
			case 2:
				sortName(books, size);
				break;
			case 3:
				sortAuthor(books, size);
				break;
			case 4:
				sortPrice(books, size);
				break;
			case 5:
				sortQuantity(books, size);
				break;
			default:
				cout << "fuck again and again and again..." << endl;
				break;
			}
			break;
		case 5:
			WriteAllBooks(books, size);
			break;
		case 6:
			int size2;
			size2 = CountBooks(OutBooks);

			for (int i = (0 + size); i < (size2 + size); i++) {
				OutBooks.read(reinterpret_cast<char*>(&books[i]), sizeof(Book));
			}
			size += size2;
			Id_Correct(books, size);
			break;

		case 7:
			saveBookDb(books, size);
			break;
		default:
			cout << "fuck";
			break;
		}




		std::system("cls");
	}







	//Book Test;
	//while(0 == 0) {
	//	Test = InputBook();
	//	BinInput(Test);
	//	if (string(Test.Author) == "Ass") break;
	//}
	//
	//IdEditBook(3);








	char pause;
	std::cin >> pause;
}