#include <stdio.h>
#include <limits>
#include <iostream>
#include "char.h"
using namespace std;
using namespace assT;
using fuck = char*;
using fuuuck = int*;

int main()
{
	fuck str = new char[5]{ "hel-" };
	fuck str2 = new char[]{"llo"};
	char result = characterAt(str, 1);
	concatenate();
	cout << result;

}








