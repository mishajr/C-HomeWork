#include <iostream>
using namespace std;

int main() {


    //Завдання 1
    // 
    //int number;

    //cout << "Enter a six-digit number: ";
    //cin >> number;


    //if (number < 100000 || number > 999999) {
    //    cout << "Error: Please enter a six-digit number." << endl;
    //   
    //}

    //int firstThreeDigitsSum = number / 100000 + (number / 10000) % 10 + (number / 1000) % 10;
    //int lastThreeDigitsSum = (number / 100) % 10 + (number / 10) % 10 + number % 10;

    //if (firstThreeDigitsSum == lastThreeDigitsSum) {
    //    cout << "Congratulations! You have a lucky number." << endl;
    //}
    //else {
    //    cout << "Sorry! Your number is not lucky." << endl;
    //}

    //Завдання 2
  /*  int number;

    cout << "Enter a four-digit number: ";
    cin >> number;

    if (number < 1000 || number > 9999) {
        cout << "Error: Please enter a four-digit number." << endl;
        return 1;
    }

    int newNumber = (number % 100) * 100 + (number / 100);

    cout << "The modified number is: " << newNumber << endl;*/


    //Завдання 3
    //int a, b, c, d, e, f, g;

    //cout << "Enter 7 integers: " << endl;
    //cin >> a >> b >> c >> d >> e >> f >> g;

    //int maxNumber = a;
    //if (b > maxNumber) maxNumber = b;
    //if (c > maxNumber) maxNumber = c;
    //if (d > maxNumber) maxNumber = d;
    //if (e > maxNumber) maxNumber = e;
    //if (f > maxNumber) maxNumber = f;
    //if (g > maxNumber) maxNumber = g;

    //cout << "The maximum number is: " << maxNumber << endl;

    //Завдання 4
    //int distanceAB, distanceBC, weight;
    //float fuelConsumptionAB, fuelConsumptionBC, fuelNeeded;

    //cout << "Enter the distance between points A and B in km: ";
    //cin >> distanceAB;

    //cout << "Enter the distance between points B and C in km: ";
    //cin >> distanceBC;

    //cout << "Enter the weight of the cargo in kg: ";
    //cin >> weight;

    //if (weight <= 500)
    //    fuelConsumptionAB = 1;
    //else if (weight <= 1000)
    //    fuelConsumptionAB = 4;
    //else if (weight <= 1500)
    //    fuelConsumptionAB = 7;
    //else if (weight <= 2000)
    //    fuelConsumptionAB = 9;
    //else {
    //    cout << "The aircraft cannot lift cargo exceeding 2000 kg." << endl;
    //}

    //fuelConsumptionBC = fuelConsumptionAB;

    //fuelNeeded = distanceAB * fuelConsumptionAB + distanceBC * fuelConsumptionBC;

    //if (fuelNeeded <= 300)
    //    cout << "The minimum amount of fuel needed for refueling at point B to fly from point A to point C is: " << fuelNeeded << " liters." << endl;
    //else
    //    cout << "The aircraft cannot fly the required distance due to fuel capacity." << endl;


    //Завдання 5


    //int day1, month1, year1;
    //int day2, month2, year2;

    //cout << "Enter first date (day month year): ";
    //cin >> day1 >> month1 >> year1;
    //cout << "Enter second date (day month year): ";
    //cin >> day2 >> month2 >> year2;

    //int days = 0;


    //for (int year = year1; year < year2; year++) {
    //    days += (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) ? 366 : 365;
    //}


    //for (int month = month1; month <= 12; month++) {
    //    int daysInMonth = 0;
    //    if (month == 2) {
    //        daysInMonth = (year1 % 4 == 0 && (year1 % 100 != 0 || year1 % 400 == 0)) ? 29 : 28;
    //    }
    //    else if (month == 4 || month == 6 || month == 9 || month == 11) {
    //        daysInMonth = 30;
    //    }
    //    else {
    //        daysInMonth = 31;
    //    }
    //    days += daysInMonth;
    //    if (month == month2 && year1 == year2) break;
    //}

    //days -= day1;


    //int daysInLastMonth = (month2 == 2) ? ((year2 % 4 == 0 && (year2 % 100 != 0 || year2 % 400 == 0)) ? 29 : 28) : ((month2 == 4 || month2 == 6 || month2 == 9 || month2 == 11) ? 30 : 31);
    //days -= daysInLastMonth - day2 + 1;

    //cout << "Number of days between the two dates: " << days << endl;
 

    //Завдання 6
//    const int BASE_SALARY = 200;
//    const double RATE_1 = 0.03;
//    const double RATE_2 = 0.05;
//    const double RATE_3 = 0.08;
//    const int BONUS = 200;
//    int sales1, sales2, sales3;
//
//    cout << "Enter sales for manager 1: ";
//    cin >> sales1;
//    cout << "Enter sales for manager 2: ";
//    cin >> sales2;
//    cout << "Enter sales for manager 3: ";
//    cin >> sales3;
//
//    double salary1, salary2, salary3;
//    if (sales1 <= 500)
//        salary1 = BASE_SALARY + sales1 * RATE_1;
//    else if (sales1 <= 1000)
//        salary1 = BASE_SALARY + sales1 * RATE_2;
//    else
//        salary1 = BASE_SALARY + sales1 * RATE_3;
//
//    if (sales2 <= 500)
//        salary2 = BASE_SALARY + sales2 * RATE_1;
//    else if (sales2 <= 1000)
//        salary2 = BASE_SALARY + sales2 * RATE_2;
//    else
//        salary2 = BASE_SALARY + sales2 * RATE_3;
//
//    if (sales3 <= 500)
//        salary3 = BASE_SALARY + sales3 * RATE_1;
//    else if (sales3 <= 1000)
//        salary3 = BASE_SALARY + sales3 * RATE_2;
//    else
//        salary3 = BASE_SALARY + sales3 * RATE_3;
//
//
//    double bestManagerSalary;
//    if (sales1 >= sales2 && sales1 >= sales3) {
//        if (sales1 <= 500)
//            bestManagerSalary = BASE_SALARY + sales1 * RATE_1 + BONUS;
//        else if (sales1 <= 1000)
//            bestManagerSalary = BASE_SALARY + sales1 * RATE_2 + BONUS;
//        else
//            bestManagerSalary = BASE_SALARY + sales1 * RATE_3 + BONUS;
//    }
//    else if (sales2 >= sales1 && sales2 >= sales3) {
//        if (sales2 <= 500)
//            bestManagerSalary = BASE_SALARY + sales2 * RATE_1 + BONUS;
//        else if (sales2 <= 1000)
//            bestManagerSalary = BASE_SALARY + sales2 * RATE_2 + BONUS;
//        else
//            bestManagerSalary = BASE_SALARY + sales2 * RATE_3 + BONUS;
//    }
//    else {
//        if (sales3 <= 500)
//            bestManagerSalary = BASE_SALARY + sales3 * RATE_1 + BONUS;
//        else if (sales3 <= 1000)
//            bestManagerSalary = BASE_SALARY + sales3 * RATE_2 + BONUS;
//        else
//            bestManagerSalary = BASE_SALARY + sales3 * RATE_3 + BONUS;
//    }
//
//
//    cout << "Manager 1's salary: $" << salary1 << endl;
//    cout << "Manager 2's salary: $" << salary2 << endl;
//    cout << "Manager 3's salary: $" << salary3 << endl;
//    cout << "The best manager's salary with bonus: $" << bestManagerSalary << endl;
//
//}