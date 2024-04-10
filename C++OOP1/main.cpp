#include <iostream>

using namespace std;

class Drib {
private:
    int numerator;
    int denominator;

public:

    Drib(int num, int denom) {
        numerator = num;
        denominator = denom;
    }

    void simplify() {
        int gcd = gcdCalc(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
    }

    int gcdCalc(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    Drib add(const Drib& other) const {
        int resultNumerator = numerator * other.denominator + other.numerator * denominator;
        int resultDenominator = denominator * other.denominator;
        Drib result(resultNumerator, resultDenominator);
        result.simplify();
        return result;
    }

    Drib subtract(const Drib& other) const {
        int resultNumerator = numerator * other.denominator - other.numerator * denominator;
        int resultDenominator = denominator * other.denominator;
        Drib result(resultNumerator, resultDenominator);
        result.simplify();
        return result;
    }

    Drib multiply(const Drib& other) const {
        int resultNumerator = numerator * other.numerator;
        int resultDenominator = denominator * other.denominator;
        Drib result(resultNumerator, resultDenominator);
        result.simplify();
        return result;
    }

    Drib divide(const Drib& other) const {
        int resultNumerator = numerator * other.denominator;
        int resultDenominator = denominator * other.numerator;
        Drib result(resultNumerator, resultDenominator);
        result.simplify();
        return result;
    }

    void display() const {
        cout << numerator << "/" << denominator << endl;
    }
};

int main() {
    Drib Drib1(3, 4);
    Drib Drib2(1, 2);


    cout << "Dodavaniya:" << endl;
    Drib result_add = Drib1.add(Drib2);
    result_add.display();  


    cout << "Vidnimania:" << endl;
    Drib result_subtract = Drib1.subtract(Drib2);
    result_subtract.display();


    cout << "mnojenia:" << endl;
    Drib result_multiply = Drib1.multiply(Drib2);
    result_multiply.display();


    cout << "dilennia:" << endl;
    Drib result_divide = Drib1.divide(Drib2);
    result_divide.display();
//Голову зламати можна,як би не інтернет я б не зробив навіть цього...

}
