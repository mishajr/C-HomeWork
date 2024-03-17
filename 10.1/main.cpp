#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

template<typename T>
void initializeMatrix(T** matrix, int size) {
    srand(time(0));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = rand() % 100;
        }
    }
}

template<typename T>
void printMatrix(T** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

template<typename T>
void findMinMaxOnDiagonal(T** matrix, int size, T& minElem, T& maxElem) {
    minElem = matrix[0][0];
    maxElem = matrix[0][0];
    for (int i = 1; i < size; ++i) {
        if (matrix[i][i] < minElem) minElem = matrix[i][i];
        if (matrix[i][i] > maxElem) maxElem = matrix[i][i];
    }
}

template<typename T>
void sortRows(T** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        sort(matrix[i], matrix[i] + size);
    }
}

int main() {
    int size;
    cout << "Enter the size of the square matrix: ";
    cin >> size;

    int** intMatrix = new int*[size];
    for (int i = 0; i < size; ++i) {
        intMatrix[i] = new int[size];
    }

    initializeMatrix(intMatrix, size);

    cout << "Square matrix of integers:\n";
    printMatrix(intMatrix, size);

    int minElem, maxElem;
    findMinMaxOnDiagonal(intMatrix, size, minElem, maxElem);
    cout << "Minimum element on the main diagonal: " << minElem << endl;
    cout << "Maximum element on the main diagonal: " << maxElem << endl;

    sortRows(intMatrix, size);
    cout << "Sorted rows of the matrix:\n";
    printMatrix(intMatrix, size);
// мені вискакумала постійно помилка що б я замінив значення на T** і я запитав в чат жбт він нічого не пояснив і сказв писати так і добавив int** я хз що це надіюсь дасте відповідь на парах...
}


