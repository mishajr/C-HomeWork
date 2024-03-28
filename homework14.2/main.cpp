#include <iostream>
using namespace std;




void cleenMemory(int** arr, int size) {
 for (int i = 0; i < size; i++)
 {
  delete[]arr[i];
 }delete[]arr;

 arr = nullptr;
}
void AddLast(int** pArr, int cols, int value) {
 int** pArrApp = new int* [cols];
 int newSize = cols + 1;
 for (int i = 0; i < cols; i++)
 {
  pArrApp[i] = new int[newSize];

 }
 for (int i = 0; i < cols; i++)
 {
  int k = cols;
  for (int j = newSize; j > 0; j--, k--)
  {
   pArrApp[i][j] = pArr[i][k];
  }
  pArrApp[i][0] = value;
 }
 for (int i = 0; i < cols; i++)
 {
  for (int j = 0; j < newSize; j++)
  {
   cout << pArrApp[i][j] << " ";
  }cout << endl;
 }


 cleenMemory(pArrApp, cols);
}

void initArray(int** arr, int size) {


 for (int i = 0; i < size; i++)
 {
  arr[i] = new int[size];
 }
 for (int i = 0; i < size; i++)
 {
  for (int j = 0; j < size; j++)
  {
   arr[i][j] = rand() % 100;
  }
 }
}


void AddRow(int** pArr, int cols, int position,int value) {
 int newSize = cols + 1;
 int** pArrApp = new int* [cols];


 for (int i = 0; i < cols; i++) {
  pArrApp[i] = new int[newSize];
 }


 for (int i = 0; i < cols; i++) {
  for (int j = 0; j < newSize; j++) {
   if (j < position) {
    pArrApp[i][j] = pArr[i][j];
   }
   else if ((j-1) == position) {
    pArrApp[i][j] = value;
   }
   else {
    pArrApp[i][j] = pArr[i][j-1];
   }

  }
 }
 for (int i = 0; i < cols; i++)
 {
  for (int j = 0; j < newSize; j++) 
  {
   cout << pArrApp[i][j] << " ";
  }cout << endl;
 }

 cleenMemory(pArrApp, cols);
}

int main()
{




 srand(time(0));

 int size;
 cout << "enter tratata :" << endl;
 cin >> size;
 int position;
 cout << "enter position :" << endl;
 cin >> position;
 int** parr = new int* [size];


 initArray(parr, size);
 AddRow(parr,size,position,6);
 //AddLast(parr, size, 55);
 cleenMemory(parr, size);





}