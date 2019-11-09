#include <stdio.h>
#include <limits>
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	char str[] = "Тип переменной";
	char dq[] = "|";
	char str2[] = "Размер,";
	char str3[] = "Значение";
	char str4[] = "Количество";
	char str5[] = "байт";
	char str6[] = "Минимальное";
	char str7[] = "Максимальное";
	char str8[] = "значимых бит";
	char str9[] = "bool";
	char str10[] = "unsigned short";
	char str11[] = "short";
	char str12[] = "unsigned int";
	char str13[] = "int";
	char str14[] = "unsigned long";
	char str15[] = "long";
	char str16[] = "unsigned long long";
	char str17[] = "long long";
	char str18[] = "char";
	char str19[] = "float";
	char str20[] = "double";
	printf("%s%5s%10s%5s%20s%15s%15s", str, dq, str2, dq, str3, dq, str4);
	printf("\n");
	printf("%19s%8s%7s%13s%4s%15s%3s%16s", dq, str5, dq, str6, dq, str7, dq, str8);
	printf("\n");
	for (int i = 0; i < 91; ++i)
	{
		printf("-");
	}
	printf("\n");
	printf("bool\t|\t%d|\t%d|\t%d|\t%d|", sizeof(bool), numeric_limits<bool>::min(), numeric_limits<bool>::max, numeric_limits<bool>::digits);
	printf("unsigned short\t|\t%d|\t%d|\t%d|\t%d|", sizeof(unsigned short), numeric_limits<unsigned short>::min(), numeric_limits<unsigned short>::max, numeric_limits<unsigned short>::digits);
	printf("short\t|\t%d|\t%d|\t%d|\t%d|", sizeof(short), numeric_limits<short>::min(), numeric_limits<short>::max, numeric_limits<short>::digits);
	printf("unsigned int\t|\t%d|\t%d|\t%d|\t%d|", sizeof(unsigned int), numeric_limits<unsigned int>::min(), numeric_limits<unsigned int>::max, numeric_limits<unsigned int>::digits);
	printf("int\t|\t%d|\t%d|\t%d|\t%d|", sizeof(int), numeric_limits<int>::min(), numeric_limits<int>::max, numeric_limits<int>::digits);
	printf("unsigned long\t|\t%d|\t%d|\t%d|\t%d|", sizeof(unsigned long), numeric_limits<unsigned long>::min(), numeric_limits<unsigned long>::max, numeric_limits<unsigned long>::digits);
	printf("long\t|\t%d|\t%d|\t%d|\t%d|", sizeof(long), numeric_limits<long>::min(), numeric_limits<long>::max, numeric_limits<long>::digits);
	printf("unsigned long long\t|\t%d|\t%d|\t%d|\t%d|", sizeof(unsigned long long), numeric_limits<unsigned long long>::min(), numeric_limits<unsigned long long>::max, numeric_limits<unsigned long long>::digits);	
	printf("long long\t|\t%d|\t%d|\t%d|\t%d|", sizeof(long long), numeric_limits<long long>::min(), numeric_limits<long long>::max, numeric_limits<long long>::digits);
	printf("char\t|\t%d|\t%d|\t%d|\t%d|", sizeof(char), numeric_limits<char>::min(), numeric_limits<char>::max, numeric_limits<char>::digits);
	printf("float\t|\t%d|\t%d|\t%d|\t%d|", sizeof(float), numeric_limits<float>::min(), numeric_limits<float>::max, numeric_limits<float>::digits);
	printf("double\t|\t%d|\t%d|\t%d|\t%d|", sizeof(double), numeric_limits<double>::min(), numeric_limits<double>::max, numeric_limits<double>::digits);



