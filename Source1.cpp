#include <iostream>
#include <string>
#include "Extention.hpp"
using namespace std;
using namespace ext;
const int N = 1000;
struct Student
{
	int Id;
	int Grade;
	string Name;
};
void Id_Correct(Student array_of_student[], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i != j) {
				if (array_of_student[i].Id == array_of_student[j].Id) {
					array_of_student[i].Id = GetRandomValue(1, 1000);
					i = 0;
					j = 0;
				}
			}
			else {
				continue;
			}
		}
	}
}
void Sort_Id(Student array_of_student[], int size) {
	Student swap;
	for (int i = 0; i < size - 1; ++i) {
		if (array_of_student[0].Id > array_of_student[1].Id) {
			i = 0;
		}
		if (array_of_student[i].Id > array_of_student[i + 1].Id) {
			swap = array_of_student[i];
			array_of_student[i] = array_of_student[i + 1];
			array_of_student[i + 1] = swap;
			i = 0;
		}
	}

}
void Sort_Grade(Student array_of_student[], int size) {
	Student swap;
	for (int i = 0; i < size - 1; ++i) {
		if (array_of_student[0].Grade > array_of_student[1].Grade) {
			i = 0;
		}
		if (array_of_student[i].Grade > array_of_student[i + 1].Grade) {
			swap = array_of_student[i];
			array_of_student[i] = array_of_student[i + 1];
			array_of_student[i + 1] = swap;
			i = 0;
		}
	}
}
void Sort_Name(Student array_of_student[], int size) {
	Student swap;
	for (int i = 0; i < size - 1; ++i) {
		if (static_cast<int>(static_cast<char>(array_of_student[0].Name[0])) > static_cast<int>(static_cast<char>(array_of_student[1].Name[0]))) {
			i = 0;
		}
		if (static_cast<int>(static_cast<char>(array_of_student[i].Name[0])) > static_cast<int>(static_cast<char>(array_of_student[i + 1].Name[0]))) {
			swap = array_of_student[i];
			array_of_student[i] = array_of_student[i + 1];
			array_of_student[i + 1] = swap;
			i = 0;
		}
	}
}
int main() {
	Student array_of_students[N];
	setlocale(LC_ALL, "Russian");
	int randName;
	for (int i = 0; i < N; i++) {
		array_of_students[i].Grade = GetRandomValue(0, 100);
		array_of_students[i].Id = GetRandomValue(1, 1000);
		randName = GetRandomValue(3, 6);
		for (int j = 0; j < randName; j++) {
			if (j == 0) {
				array_of_students[i].Name = (char)(GetRandomValue(65, 90));
			}
			else {
				array_of_students[i].Name += (char)(GetRandomValue(97, 122));
			}
		}
	}
	Id_Correct(array_of_students, (sizeof(array_of_students) / sizeof(Student)));
	int choice;
	cout << "выбор сортировки:\n1 - по Id\n2 - по оценкам\n3 - по имени\nИной функционал:\n4 - анализ\n>>";
	cin >> choice;
	switch (choice) {
	case 1:
		Sort_Id(array_of_students, (sizeof(array_of_students) / sizeof(Student)));
		cout << "Id\tGrade\tName\t" << endl;
		for (int i = 0; i < N; i++) {
			cout << array_of_students[i].Id << "\t" << array_of_students[i].Grade << "\t" << array_of_students[i].Name << "\t" << endl;
		}
		break;
	case 2:
		Sort_Grade(array_of_students, (sizeof(array_of_students) / sizeof(Student)));
		cout << "Grade\tId\tName\t" << endl;
		for (int i = 0; i < N; i++) {
			cout << array_of_students[i].Grade << "\t" << array_of_students[i].Id << "\t" << array_of_students[i].Name << "\t" << endl;
		}
		break;
	case 3:
		Sort_Name(array_of_students, (sizeof(array_of_students) / sizeof(Student)));
		cout << "Name\tId\tGrade\t" << endl;
		for (int i = 0; i < N; i++) {
			cout << array_of_students[i].Name << "\t" << array_of_students[i].Id << "\t" << array_of_students[i].Grade << "\t" << endl;
		}
		break;
	case 4:
		Sort_Grade(array_of_students, (sizeof(array_of_students) / sizeof(Student)));
		cout << "для получиения оценки лучше чем у 25% нужно набрать хотя бы -- " << array_of_students[static_cast<int>(static_cast<float>(N) * 0.25)].Grade << endl;
		cout << "для получиения оценки лучше чем у 50% нужно набрать хотя бы -- " << array_of_students[static_cast<int>(static_cast<float>(N) * 0.5)].Grade << endl;
		cout << "для получиения оценки лучше чем у 75% нужно набрать хотя бы -- " << array_of_students[static_cast<int>(static_cast<float>(N) * 0.75)].Grade << endl;
		break;
	default:
		cout << "Input Error";
		break;
	}
	char pause;
	cin >> pause;
}