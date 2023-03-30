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

	cout << "\n-------------------------------" << endl;
	cout << "\nEnter Array Element" << endl;
	cout << "\n-------------------------------" << endl;

	for (int i = 0; i < n; i++) {
		cout << "<" << (i + 1) << ">";
		cin >> arr[i];
	}
}

//swaps the element at index x with the element at index y
void swap(int x, int y) {
	int temp;

	temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

void quick_sort(int low, int high) {
	int pivot, i, j;
	if (low > high)
		return;

	pivot = arr[low];

	i = low + 1;
	j = high;

	while (i <= j) {
		//search for an element greater than pivot
		while ((arr[i] <= pivot) && (j <= high)) {
			i++;
			cmp_count++;
		}
		//search for an element less than or equal to pivot
		while ((arr[j] > pivot) && (j >= low)) {
			j--;
			cmp_count++;
		}
		cmp_count++;

		if (i < j) {					//if the greater element is on the left of the element
			swap(i, j);					//swap the element at index i with the element at index
			mov_count++;
		}
	}
	
	if (low < j) {						//j now containt the index of the last element in the sorted list
		swap(low, j);
		mov_count++;
	}
	quick_sort(low, j - 1);

	//sort of the lost on the right of pivot using quick sort
	quick_sort(j + i, high);
}

void display() {
	cout << "\n-------------------------------" << endl;
	cout << "Sorted Array" << endl;
	cout << "\n-------------------------------" << endl;

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << "\n\nNumber of Comparasions : " << cmp_count << endl;
	cout << "Number of data movement : " << mov_count << endl;
}

int main() {
	input();

	//sort the array using quick sort
	quick_sort(0, n - 1);
	display();
	system("pause");
	return 0;
}