#include <iostream>
using namespace std;

//array of integers to hold values
int arr[20];
int cmp_count = 0;		//number of comparisson
int mov_count = 0;
int n;

void input() {
	while (true) {
		cout << "Masukkan Panjang Element Array : ";
		cin >> n;

		if (n <= 20)
			break;
		else 
			cout << "\nMaksimum Panjang Array Adalah 20 Element" << endl;
	}
}

int main() {
	cout << endl;
}