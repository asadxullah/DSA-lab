#include<iostream>
using namespace std;

template <typename T>
void selectionsort(T arr[] , int size) {
	for (int i = 0; i < size - 1; i++) {
		int minindex = i;
		for (int j = i + 1; j < size; j++) {
			if (arr[j] < arr[minindex]) {
				minindex = j;
			}
		}
		T temp = arr[i];
		arr[i] = arr[minindex];
		arr[minindex] = temp;
	}
}

template<typename T>
void printarray(T arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int intArray[5] = { 64, 25, 12, 22, 11 };
	cout << "Original integer array: ";
	printarray(intArray , 5);
	selectionsort(intArray , 5);
	cout << "Sorted integer array: ";
	printarray(intArray , 5);
	string stringArray[4] = { "apple", "orange", "banana", "grape" };
	cout <<endl << "Original string array: ";
	printarray(stringArray , 4);
	selectionsort(stringArray , 4);
	cout << "Sorted string array: ";
	printarray(stringArray , 4);
	return 0;
}