#include <iostream>

using namespace std;
//
//struct Fraction {
//    int numerator;
//    int denominator;
//
//    Fraction add(const Fraction& other) const {
//        Fraction result;
//        result.numerator = numerator * other.denominator + other.numerator * denominator;
//        result.denominator = denominator * other.denominator;
//        return result;
//    }
//
//    Fraction subtract(const Fraction& other) const {
//        Fraction result;
//        result.numerator = numerator * other.denominator - other.numerator * denominator;
//        result.denominator = denominator * other.denominator;
//        return result;
//    }
//
//    Fraction multiply(const Fraction& other) const {
//        Fraction result;
//        result.numerator = numerator * other.numerator;
//        result.denominator = denominator * other.denominator;
//        return result;
//    }
//
//    Fraction divide(const Fraction& other) const {
//        Fraction result;
//        result.numerator = numerator * other.denominator;
//        result.denominator = denominator * other.numerator;
//        return result;
//    }
//
//    void print() const {
//        cout << numerator << "/" << denominator;
//    }
//};

//===================================================================================

//const int MAX_STRING_LENGTH = 50;
//
//struct Car {
//    double length;
//    double clearance;
//    double engineVolume;
//    int enginePower;
//    double wheelDiameter;
//    char color[MAX_STRING_LENGTH];
//    char transmissionType[MAX_STRING_LENGTH];
//};
//
//void setValues(Car& car, double len, double clr, double engVol, int engPow, double wheelDiam, const char* clr_, const char* transType) {
//    car.length = len;
//    car.clearance = clr;
//    car.engineVolume = engVol;
//    car.enginePower = engPow;
//    car.wheelDiameter = wheelDiam;
//    for (int i = 0; clr_[i] != '\0'; ++i) {
//        car.color[i] = clr_[i];
//    }
//    for (int i = 0; transType[i] != '\0'; ++i) {
//        car.transmissionType[i] = transType[i];
//    }
//}
//
//void display(const Car& car) {
//    cout << "Length: " << car.length << " meters" << endl;
//    cout << "Clearance: " << car.clearance << " meters" << endl;
//    cout << "Engine Volume: " << car.engineVolume << " liters" << endl;
//    cout << "Engine Power: " << car.enginePower << " hp" << endl;
//    cout << "Wheel Diameter: " << car.wheelDiameter << " inches" << endl;
//    cout << "Color: " << car.color << endl;
//    cout << "Transmission Type: " << car.transmissionType << endl;
//}
//
//int search(const Car& car, double len, double clr, double engVol, int engPow, double wheelDiam, const char* clr_, const char* transType) {
//    int colorMatch = 1;
//    int transTypeMatch = 1;
//
//    for (int i = 0; clr_[i] != '\0'; ++i) {
//        if (car.color[i] != clr_[i]) {
//            colorMatch = 0;
//            break;
//        }
//    }
//
//    for (int i = 0; transType[i] != '\0'; ++i) {
//        if (car.transmissionType[i] != transType[i]) {
//            transTypeMatch = 0;
//            break;
//        }
//    }
//
//    return (car.length == len && car.clearance == clr && car.engineVolume == engVol && car.enginePower == engPow &&
//            car.wheelDiameter == wheelDiam && colorMatch && transTypeMatch);
//}
int main() {
//    Fraction a = {7, 3};
//    Fraction b = {8, 9};
//
//    cout << "a + b = ";
//    a.add(b).print();
//    cout << endl;
//
//    cout << "a - b = ";
//    a.subtract(b).print();
//    cout << endl;
//
//    cout << "a * b = ";
//    a.multiply(b).print();
//    cout << endl;
//
//    cout << "a / b = ";
//    a.divide(b).print();
//    cout << endl;

//===============================================================
//    Car myCar;
//    setValues(myCar, 4.5, 0.2, 2.0, 150, 17.0, "red", "automatic");
//
//    cout << "Car details:" << endl;
//    display(myCar);
//    cout << endl;
//
//    cout << "Searching for a car with specific details..." << endl;
//    if (search(myCar, 4.5, 0.2, 2.0, 150, 17.0, "red", "automatic")) {
//        cout << "Car found!" << endl;
//    } else {
//        cout << "Car not found!" << endl;
//    }

}
