#include <iostream>
using namespace std;

//void addColumn(int**& matrix, int rows, int& columns, int* column, int position) {
//    if (position < 0 || position > columns) {
//        cerr << "Invalid position" << endl;
//        return;
//    }
//
//    int** newMatrix = new int*[rows];
//    for (int i = 0; i < rows; ++i) {
//        newMatrix[i] = new int[columns + 1];
//    }
//
//    for (int i = 0; i < rows; ++i) {
//        int colIndex = 0;
//        for (int j = 0; j < columns + 1; ++j) {
//            if (j == position) {
//                newMatrix[i][j] = column[i];
//            } else {
//                newMatrix[i][j] = matrix[i][colIndex++];
//            }
//        }
//    }
//
//    for (int i = 0; i < rows; ++i) {
//        delete[] matrix[i];
//    }
//    delete[] matrix;
//
//    matrix = newMatrix;
//    ++columns;
//}
//
//void printMatrix(int** matrix, int rows, int columns) {
//    for (int i = 0; i < rows; ++i) {
//        for (int j = 0; j < columns; ++j) {
//            cout << matrix[i][j] << " ";
//        }
//        cout << endl;
//    }
//}
//==============================================================

//
//void deleteColumn(int**& matrix, int rows, int& columns, int position) {
//    if (position < 0 || position >= columns) {
//        cerr << "Invalid position" << endl;
//        return;
//    }
//
//    for (int i = 0; i < rows; ++i) {
//        for (int j = position; j < columns - 1; ++j) {
//            matrix[i][j] = matrix[i][j + 1];
//        }
//    }
//    --columns;
//}
//
//void printMatrix(int** matrix, int rows, int columns) {
//    for (int i = 0; i < rows; ++i) {
//        for (int j = 0; j < columns; ++j) {
//            cout << matrix[i][j] << " ";
//        }
//        cout << endl;
//    }
//}

//==============================================================
//void cyclicShift(int** matrix, int rows, int columns, int shiftCount, bool shiftRows, bool shiftRight) {
//    if (shiftRows) {
//        for (int i = 0; i < rows; ++i) {
//            int* tempRow = new int[columns];
//            for (int j = 0; j < columns; ++j) {
//                int newIndex = shiftRight ? (j + shiftCount) % columns : (j + columns - shiftCount) % columns;
//                tempRow[newIndex] = matrix[i][j];
//            }
//            delete[] matrix[i];
//            matrix[i] = tempRow;
//        }
//    } else {
//        for (int j = 0; j < columns; ++j) {
//            int* tempColumn = new int[rows];
//            for (int i = 0; i < rows; ++i) {
//                int newIndex = shiftRight ? (i + shiftCount) % rows : (i + rows - shiftCount) % rows;
//                tempColumn[newIndex] = matrix[i][j];
//            }
//            for (int i = 0; i < rows; ++i) {
//                matrix[i][j] = tempColumn[i];
//            }
//            delete[] tempColumn;
//        }
//    }
//}
//
//void printMatrix(int** matrix, int rows, int columns) {
//    for (int i = 0; i < rows; ++i) {
//        for (int j = 0; j < columns; ++j) {
//            cout << matrix[i][j] << " ";
//        }
//        cout << endl;
//    }
//}
//==============================================================

//void transposeMatrix(int** matrix, int rows, int columns) {
//    int** transposedMatrix = new int*[columns];
//    for (int i = 0; i < columns; ++i) {
//        transposedMatrix[i] = new int[rows];
//    }
//
//    for (int i = 0; i < rows; ++i) {
//        for (int j = 0; j < columns; ++j) {
//            transposedMatrix[j][i] = matrix[i][j];
//        }
//    }
//
//    cout << "Transposed matrix:" << endl;
//    for (int i = 0; i < columns; ++i) {
//        for (int j = 0; j < rows; ++j) {
//            cout << transposedMatrix[i][j] << " ";
//        }
//        cout << endl;
//    }
//
//    for (int i = 0; i < columns; ++i) {
//        delete[] transposedMatrix[i];
//    }
//    delete[] transposedMatrix;
//}



//==========================================================


//const int MAX_RECORDS = 100;
//const int MAX_NAME_LENGTH = 50;
//const int MAX_PHONE_LENGTH = 20;
//
//struct Record {
//    char name[MAX_NAME_LENGTH];
//    char phone[MAX_PHONE_LENGTH];
//};
//
//void searchByName(const Record records[], int numRecords, const char* name) {
//    bool found = false;
//    for (int i = 0; i < numRecords; ++i) {
//        if (strcmp(records[i].name, name) == 0) {
//            cout << "Name: " << records[i].name << ", Phone: " << records[i].phone << endl;
//            found = true;
//            break;
//        }
//    }
//    if (!found) {
//        cout << "Record with name \"" << name << "\" not found." << endl;
//    }
//}
//
//void searchByPhone(const Record records[], int numRecords, const char* phone) {
//    bool found = false;
//    for (int i = 0; i < numRecords; ++i) {
//        if (strcmp(records[i].phone, phone) == 0) {
//            cout << "Name: " << records[i].name << ", Phone: " << records[i].phone << endl;
//            found = true;
//            break;
//        }
//    }
//    if (!found) {
//        cout << "Record with phone number \"" << phone << "\" not found." << endl;
//    }
//}
//



//==========================================================




int main() {
//    int rows = 3;
//    int columns = 3;
//    int position = 1;
//    int* column = new int[rows];
//    column[0] = 10;
//    column[1] = 11;
//    column[2] = 12;
//
//    int** matrix = new int*[rows];
//    for (int i = 0; i < rows; ++i) {
//        matrix[i] = new int[columns];
//    }
//
//    int count = 1;
//    for (int i = 0; i < rows; ++i) {
//        for (int j = 0; j < columns; ++j) {
//            matrix[i][j] = count++;
//        }
//    }
//
//    cout << "Before adding column:" << endl;
//    printMatrix(matrix, rows, columns);
//
//    addColumn(matrix, rows, columns, column, position);
//
//    cout << "After adding column:" << endl;
//    printMatrix(matrix, rows, columns);
//
//    for (int i = 0; i < rows; ++i) {
//        delete[] matrix[i];
//    }
//    delete[] matrix;
//    delete[] column;

//==========================================================
//    int rows = 3;
//    int columns = 3;
//    int position = 1;
//
//    int** matrix = new int*[rows];
//    for (int i = 0; i < rows; ++i) {
//        matrix[i] = new int[columns];
//    }
//
//    int count = 1;
//    for (int i = 0; i < rows; ++i) {
//        for (int j = 0; j < columns; ++j) {
//            matrix[i][j] = count++;
//        }
//    }
//
//    cout << "Before deleting column:" << endl;
//    printMatrix(matrix, rows, columns);
//
//    deleteColumn(matrix, rows, columns, position);
//
//    cout << "After deleting column:" << endl;
//    printMatrix(matrix, rows, columns);
//
//    for (int i = 0; i < rows; ++i) {
//        delete[] matrix[i];
//    }
//    delete[] matrix;

//==========================================================

//    int rows, columns;
//    cout << "Enter number of rows: ";
//    cin >> rows;
//    cout << "Enter number of columns: ";
//    cin >> columns;
//
//    int** matrix = new int*[rows];
//    for (int i = 0; i < rows; ++i) {
//        matrix[i] = new int[columns];
//    }
//
//    cout << "Enter matrix elements:" << endl;
//    for (int i = 0; i < rows; ++i) {
//        for (int j = 0; j < columns; ++j) {
//            cin >> matrix[i][j];
//        }
//    }
//
//    int shiftCount;
//    cout << "Enter number of shifts: ";
//    cin >> shiftCount;
//
//    bool shiftRows, shiftRight;
//    cout << "Shift rows? (1 for yes, 0 for no): ";
//    cin >> shiftRows;
//    cout << "Shift to the right? (1 for yes, 0 for no): ";
//    cin >> shiftRight;
//
//    cyclicShift(matrix, rows, columns, shiftCount, shiftRows, shiftRight);
//
//    cout << "Matrix after cyclic shift:" << endl;
//    printMatrix(matrix, rows, columns);
//
//    for (int i = 0; i < rows; ++i) {
//        delete[] matrix[i];
//    }
//    delete[] matrix;
//==========================================================

//    int rows, columns;
//    cout << "Enter number of rows: ";
//    cin >> rows;
//    cout << "Enter number of columns: ";
//    cin >> columns;
//
//    int** matrix = new int*[rows];
//    for (int i = 0; i < rows; ++i) {
//        matrix[i] = new int[columns];
//    }
//
//    cout << "Enter matrix elements:" << endl;
//    for (int i = 0; i < rows; ++i) {
//        for (int j = 0; j < columns; ++j) {
//            cin >> matrix[i][j];
//        }
//    }
//
//    transposeMatrix(matrix, rows, columns);
//
//    for (int i = 0; i < rows; ++i) {
//        delete[] matrix[i];
//    }
//    delete[] matrix;
//



//==========================================================

//    Record records[MAX_RECORDS];
//    int numRecords = 0;
//
//    char choice;
//    do {
//        cout << "Enter name: ";
//        cin.getline(records[numRecords].name, MAX_NAME_LENGTH);
//
//        cout << "Enter phone: ";
//        cin.getline(records[numRecords].phone, MAX_PHONE_LENGTH);
//
//        ++numRecords;
//
//        cout << "Do you want to add another record? (y/n): ";
//        cin >> choice;
//        cin.ignore();
//    } while (choice == 'y' && numRecords < MAX_RECORDS);
//
//    cout << "Records added:" << endl;
//    for (int i = 0; i < numRecords; ++i) {
//        cout << "Name: " << records[i].name << ", Phone: " << records[i].phone << endl;
//    }
//
//    char searchName[MAX_NAME_LENGTH];
//    cout << "Enter name to search: ";
//    cin.getline(searchName, MAX_NAME_LENGTH);
//    searchByName(records, numRecords, searchName);
//
//    char searchPhone[MAX_PHONE_LENGTH];
//    cout << "Enter phone number to search: ";
//    cin.getline(searchPhone, MAX_PHONE_LENGTH);
//    searchByPhone(records, numRecords, searchPhone);


//==========================================================

}











