#include <iostream>

using namespace std;
//
//void copyArray(int *source, int *destination, int size) {
//    for (int i = 0; i < size; i++) {
//        *(destination + i) = *(source + i);
//    }
//}
//==================================================================



//void reverseArray(int *arr, int size) {
//    int *start = arr;
//    int *end = arr + size - 1;
//
//    while (start < end) {
//
//        int temp = *start;
//        *start = *end;
//        *end = temp;
//
//
//        start++;
//        end--;
//    }
//}











//==================================================================



void reverseCopyArray(int *source, int *destination, int size) {
    int *sourcePtr = source + size - 1;
    int *destinationPtr = destination;

    for (int i = 0; i < size; i++) {
        *destinationPtr = *sourcePtr;
        sourcePtr--;
        destinationPtr++;
    }
}














int main() {






//    int sourceArray[] = {1, 2, 3, 4, 5};
//    int destinationArray[5];
//
//
//    copyArray(sourceArray, destinationArray, 5);
//
//    cout << "Source Array: ";
//    for (int i = 0; i < 5; i++) {
//        cout << sourceArray[i] << " ";
//    }
//    cout << endl;
//
//    cout << "Copied Array: ";
//    for (int i = 0; i < 5; i++) {
//        cout << destinationArray[i] << " ";
//    }
//    cout << endl;




//==================================================================






//    int arr[] = {1, 2, 3, 4, 5};
//
//
//    cout << "Original Array: ";
//    for (int i = 0; i < 5; i++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;
//
//
//    reverseArray(arr, 5);
//
//
//    cout << "Reversed Array: ";
//    for (int i = 0; i < 5; i++) {
//        cout << arr[i] << " ";
//    }
//    cout << endl;




//==================================================================

    int sourceArray[] = {1, 2, 3, 4, 5};
    int destinationArray[5];

    reverseCopyArray(sourceArray, destinationArray, 5);

    cout << "Source Array: ";
    for (int i = 0; i < 5; i++) {
        cout << sourceArray[i] << " ";
    }
    cout << endl;

    cout << "Reversed Copy Array: ";
    for (int i = 0; i < 5; i++) {
        cout << destinationArray[i] << " ";
    }
    cout << endl;



}
