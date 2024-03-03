#include <iostream>
using namespace std;


int main()

{

	//1
	// 
	// 
	//int a;
	// 
	//int sum = 0;

	//cout << "enter first number :  ";
	// 
	//cin >> a;

	//for (int i = a; i < 500; i++)
	//{
	//	sum += a;

	//	

	//}
	
	//cout << "sum numbers a < 500 :" << sum;


//===========================================================================
	//2

	//int x, y;
	//int result = 1;

	//cout << "Enter first x: ";
	//cin >> x;

	//cout << "Enter the exponent y: ";
	//cin >> y;

	//for (int i = 0; i < y; i++) {
	//	result *= x;
	//}

	//cout << x << " raised to the power of " << y << " = " << result << endl;




//===========================================================================

	//3

	//int sum = 0;
	//int count = 0;


	//for (int i = 1; i <= 1000; i++) {
	//	sum += i;
	//	count++;
	//}

	//double average = sum / double(count);

	//cout << "The arithmetic mean of all integers from 1 to 1000: " << average << endl;






//===========================================================================

	//4

	/*int a;
	int product = 1;



	cout << "Enter an integer a (1 <= a <= 20): ";
	cin >> a;

	if (a < 1 || a > 20) {
		cout << "Error: a should be in the range from 1 to 20" << endl;
		return 1;
	}

	for (int i = a; i <= 20; ++i) {
		product *= i;
	}

	cout << "Product of all integers from " << a << " to 20: " << product << endl;
*/


//===========================================================================
// 
// 	   5
	//int i = 1,num = 0,sum = 0;



	//cin >> num;


	//while (i<11)
	//{

	//	

	//	cout << num << " * " << i << "=" << num * i<< endl;
	//	i++;



	//}






//===========================================================================

//6
//
//int count = 0;
//
//for (int num = 100; num <= 999; num++) {
//	int hundreds = num / 100;
//	int tens = (num / 10) % 10;
//	int units = num % 10;
//
//	if ((hundreds == tens) || (hundreds == units) || (tens == units)) {
//		count++;
//	}
//}
//
//cout << "The number of integers in the range from 100 to 999 with two identical digits: " << count << endl;
//






//===========================================================================


//7 

	//int n1 = 0, n2 = 0, n3 = 0, summ = 0, a = 0;

	//for (int i = 100; i <= 999; i++)
	//{
	//	n1 = i / 100;
	//	n2 = (i / 10) % 10;
	//	n3 = i % 10;

	//	if (n1 != n2 && n2 != n3 && n1 != n3)
	//	{
	//		cout << i << endl;
	//	}
	//}









//===========================================================================
//8


//int num;
//cout << "Enter any integer number: ";
//cin >> num;
//
//int result = 0;
//int power = 1; 
//
//while (num != 0) {
//	int digit = num % 10; 
//
//	if (digit != 3 && digit != 6) {
//		result += digit * power;
//		power *= 10;
//	}
//
//	num /= 10; 
//}
//
//cout << "Number with all occurrences of 3 and 6 removed: " << result << endl;











//===========================================================================
// 9
// 
//int A;
//
//cout << "Enter any integer number A: ";
//
//cin >> A;
//
//cout << "Integers B satisfying the conditions: ";
//
//for (int B = 1; B <= A; ++B) {
//
//	if (A % (B * B) == 0 && A % (B * B * B) != 0) {
//
//		cout << B << " ";
//	}
//}
//cout << endl;









//===========================================================================
//10

//int A;
//cout << "Enter an integer number A: ";
//cin >> A;
//
//int digitSum = 0;
//int temp = A;
//
//while (temp != 0) {
//	int digit = temp % 10;
//	digitSum += digit;
//	temp /= 10;
//}
//
//int sumCube = digitSum * digitSum * digitSum;
//
//if (sumCube == A * A) {
//	cout << "The cube of the sum of the digits of " << A << " equals " << A << " * " << A << endl;
//}
//else {
//	cout << "The cube of the sum of the digits of " << A << " does not equal " << A << " * " << A << endl;
//}






//===========================================================================
//11
// 
//int A;
//
//cout << "Enter number : ";
//cin >> A;
//
//cout << "vsi yzki diliatsia na " << A << endl;
//for (int i = 0; i < 100; i++)
//{
//	if (i % A == 0) {
//		
//		cout << i << endl;
//	}
//	
//}








//===========================================================================

//12
//
//
//int A,B;
//
//cout << "Enter number : ";
//cin >> A;
//cout << "Enter number : ";
//cin >> B;
//
//cout << "vsi yzki diliatsia na " << A << " i na "<< B << endl;
//for (int i = 0; i < 100; i++)
//{
//	if (i % A == 0 && i % B == 0) {
//		cout << i << endl;
//	}
//
//}






//===========================================================================




}

