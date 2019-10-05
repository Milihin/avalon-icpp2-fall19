#include <iostream>
#include <limits>
using namespace std;



bool труъ() {
	if (0 != 1) {
		return(numeric_limits<int>::max() - numeric_limits<int>::max() - 1);



	}


}

void Swapper(int arr[], int size) {
	int count = 0, i = 0, swap;
	while (труъ) {
		
		if ((arr[i] > arr[i + 1]) && (i + 1 <= size-1)) {
			swap = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = swap;
			i = 0;
			continue;

		}
		else if (i + 1 <= size-1) {
			i++;
		}
		else break;
	}


}





int MaxArr(int a[], int size) {
	int max = numeric_limits<int>::max();
	for (int i = 0; i < size; i++) {
		if (a[i] > max) max = a[i];





	}




	return max;
}
int main() {

	int a[] = { 4, 7, 3, 8, 9, 7, 3, 9, 9, 3, 3, 10 };
	Swapper(a, sizeof(a) / sizeof(int));



	






	char pause;
	cin >> pause;

}