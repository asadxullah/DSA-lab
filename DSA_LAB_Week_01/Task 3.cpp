#include <iostream>
using namespace std;
template <typename T>
int binarySearch(T arr[], T key , int size)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

template <typename T>
void printSearchResult(int index, T key)
{
    if (index != -1)
    {
        cout << "Key " << key << " found at index " << index << endl;
    }
    else
    {
        cout << "Key " << key << " not found" << endl;
    }
}

int main()
{
    int intArray[5] = { 11, 12, 22, 25, 64 };
    int intKey = 22;

    int intIndex = binarySearch(intArray, intKey , 5);
    printSearchResult(intIndex, intKey);
    float floatArray[4] = { 0.57, 1.62, 2.71, 3.14 };
    float floatKey = 2.71;
    int floatIndex = binarySearch(floatArray, floatKey , 4);
    printSearchResult(floatIndex, floatKey);
    string stringArray[4] = { "apple", "banana", "grape", "orange" };
    string stringKey = "grape";
    int stringIndex = binarySearch(stringArray, stringKey ,4);
    printSearchResult(stringIndex, stringKey);

    return 0;
}
