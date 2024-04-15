#include <iostream>
using namespace std;

class Drib {
private:
    int numerator;
    int denominator;

public:
    Drib(int num, int denom) : numerator(num), denominator(denom) {}

    Drib operator+(const Drib& other) const {
        int resultNum = numerator * other.denominator + other.numerator * denominator;
        int resultDenom = denominator * other.denominator;
        return Drib(resultNum, resultDenom);
    }

    Drib operator-(const Drib& other) const {
        int resultNum = numerator * other.denominator - other.numerator * denominator;
        int resultDenom = denominator * other.denominator;
        return Drib(resultNum, resultDenom);
    }

    Drib operator*(const Drib& other) const {
        int resultNum = numerator * other.numerator;
        int resultDenom = denominator * other.denominator;
        return Drib(resultNum, resultDenom);
    }

    Drib operator/(const Drib& other) const {
        int resultNum = numerator * other.denominator;
        int resultDenom = denominator * other.numerator;
        return Drib(resultNum, resultDenom);
    }

    void setShow() const {
        cout << numerator << "/" << denominator;
    }
};


//===================================================================================

class SimpleNum {

    int num;

public:
    SimpleNum(int num) : num(num) {}

    SimpleNum operator+(const SimpleNum& other){
        return SimpleNum(num + other.num);
    }

    SimpleNum operator-(const SimpleNum& other){
        return SimpleNum(num - other.num);
    }

    SimpleNum operator*(const SimpleNum& other){
        return SimpleNum(num * other.num);
    }

    SimpleNum operator/(const SimpleNum& other){

        return SimpleNum(num / other.num);
    }

    void SetDisplay() const {
        cout << num;
    }
};



int main() {


    cout << "----------Drib----------" << endl;
    Drib f1(1, 2);
    Drib f2(1, 3);

    Drib sum = f1 + f2;
    Drib difference = f1 - f2;
    Drib product = f1 * f2;
    Drib quotient = f1 / f2;

    cout << "Sum: ";
    sum.setShow();
    cout << endl;

    cout << "difference: ";
    difference.setShow();
    cout << endl;

    cout << "Product: ";
    product.setShow();
    cout << endl;

    cout << "Quotient: ";
    quotient.setShow();
    cout << endl;
//===========================================================================================
    cout << "---------Simple---------" << endl;

    SimpleNum num1(10);
    SimpleNum num2(3);

    SimpleNum sum1 = num1 + num2;
    SimpleNum difference2= num1 - num2;
    SimpleNum product3 = num1 * num2;
    SimpleNum quotient4 = num1 / num2;

    cout << "Sum: ";
    sum1.SetDisplay();
    cout << endl;

    cout << "Difference: ";
    difference2.SetDisplay();
    cout << endl;

    cout << "Product: ";
    product3.SetDisplay();
    cout << endl;

    cout << "Quotient: ";
    quotient4.SetDisplay();
    cout << endl;

    cout << "------------------------" << endl;

}
