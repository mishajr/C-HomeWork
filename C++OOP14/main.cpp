#include <iostream>
using namespace std;
namespace MyMath {


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
            cout << numerator << "/" << denominator << endl;
        }
    };
}
namespace SimpleNumSpace{

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
}



int main() {
    cout << "----------Drib----------" << endl;
    MyMath::Drib f1(1, 2);
    MyMath::Drib f2(1, 3);

    MyMath::Drib sum = f1 + f2;
    MyMath::Drib difference = f1 - f2;
    MyMath::Drib product = f1 * f2;
    MyMath::Drib quotient = f1 / f2;

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

    SimpleNumSpace::SimpleNum num1(10);
    SimpleNumSpace::SimpleNum num2(3);

    SimpleNumSpace::SimpleNum sum1 = num1 + num2;
    SimpleNumSpace::SimpleNum difference2= num1 - num2;
    SimpleNumSpace::SimpleNum product3 = num1 * num2;
    SimpleNumSpace::SimpleNum quotient4 = num1 / num2;

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
