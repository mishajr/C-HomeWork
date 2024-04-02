#include <iostream>

#include <ctime>
#include <algorithm>

using namespace std;


void fillArray(int arr[], int size, int minVal, int maxVal) {

    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 100;
    }
}


void printArray(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int findMin(const int arr[], int size) {
    int minVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}


int findMax(const int arr[], int size) {
    int maxVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}


void sortArray(int arr[], int size) {
    sort(arr, arr + size);
}


void editArray(int arr[], int index, int newValue) {
    arr[index] = newValue;
}

int main() {
    srand(time(nullptr));
    const int SIZE = 5;
    int intArray[SIZE];


    fillArray(intArray, SIZE, 1, 10);


    cout << "Integer array: " << endl;
    printArray(intArray, SIZE);


    cout << "Min of Integer array: " << endl;
    cout << findMin(intArray, SIZE) << endl;
    cout << "Max of Integer array: " << endl;
    cout << findMax(intArray, SIZE) << endl;


    sortArray(intArray, SIZE);


    cout << "Sorted Integer array: " << endl;
    printArray(intArray, SIZE);


    editArray(intArray, 2, 100);


    cout << "Integer array after editing: " << endl;
    printArray(intArray, SIZE);
//я не знаю як в Слайні зроби те ж що ви показувати на кінці пари,тому інші завданян я не знаю як зробити,
}
