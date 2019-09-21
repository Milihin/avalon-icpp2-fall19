#include <iostream>

using namespace std;

int sum(long long inp) {
	int outp = 0, bins = 0;
	long long dex = 1;
	for (int i = 13; i > 1;i--) {
		dex = 1;
		for (int j = i; j > 1; j--) {
			dex *= 10;
		}
		if (i % 2 == 1) bins = 1;
		else bins = 3;
		
		outp += ((inp / dex) % 10) * bins;
		cout << ((inp / dex) % 10) * bins << endl;

	}




	return outp;



}







int main() {
	long long n, inp, fin, mid5um, checksum;
	cin >> n;
	cout << "\n";


	for (int i = 0; i < n; i++) {
		cin >> inp;
		fin = inp % 10;
		mid5um = sum(inp);

		checksum = 10 - (mid5um % 10);
		if (fin == checksum) {
			cout << "valid\n";
		}
		else {
			cout << "invalid\n";
		}
		mid5um = 0;
		fin = 0;
	}





	char pause;
	cin >> pause;
}