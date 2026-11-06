#include<iostream>
using namespace std;
template <typename T>
int linearsearch(T arr[], T key , int size) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == key) {
			return i;
		}
	}
	return -1;
}

template <typename T>
void printresult(int index, T key) {
	if (index != -1){
	cout << "Key " << key << " found at index " << index << endl;
	}
	else {
		cout << "Key " << key << " not found"  << endl;
	}
}

int main() {
		int intArray[5] = { 64, 25, 12, 22, 11 };
		int intKey = 12;
		int intIndex = linearsearch(intArray, intKey ,5);
		printresult(intIndex, intKey);
		float floatArray[4] = { 3.14, 2.71, 1.62, 0.57 };
		float floatKey = 1.62;
		int floatIndex = linearsearch(floatArray, floatKey , 4);
		printresult(floatIndex, floatKey);
		string stringArray[4] = { "apple", "orange", "banana", "grape" };
		string stringKey = "banana";
		int stringIndex = linearsearch(stringArray, stringKey , 4);
		printresult(stringIndex, stringKey);
		return 0;
}