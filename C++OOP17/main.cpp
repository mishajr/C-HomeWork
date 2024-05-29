#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


struct Car {
    string name;
    int year;
    double engineVolume;
    double price;

    Car(string n, int y, double eV, double p): name(n), year(y), engineVolume(eV), price(p) {}

};





void displayCar(const Car& car) {
    cout << "Name: " << car.name << endl;
    cout <<"Year: " << car.year << endl;
    cout << "Engine Volume: " << car.engineVolume << endl;
    cout << "Price: " << car.price << endl;
    cout << endl;
}




void displayAllCars(const vector<Car>& cars) {
    for (const auto& car : cars) {
        displayCar(car);

    }
}



void removeCar(vector<Car>& cars, const string& name) {
    vector<Car>::iterator it = cars.begin();
    while (it != cars.end()) {
        if (it->name == name) {
            it = cars.erase(it);
        } else {
            ++it;
        }
    }
}




bool compareByName(const Car& a, const Car& b) {
    return a.name < b.name;
}



bool compareByYear(const Car& a, const Car& b) {
    return a.year < b.year;
}



bool compareByEngineVolume(const Car& a, const Car& b) {
    return a.engineVolume < b.engineVolume;
}



bool compareByPrice(const Car& a, const Car& b) {
    return a.price < b.price;
}
int compairByYearMore(int year){

    while(year > 2024){

        cout << "There are no cars this year..." << endl;
        cout << "Enter year: " << endl;
        cin >> year;



    }
    return year;
}






void searchByName(const vector<Car>& cars, const string& name) {
    bool found = false;
    for (const auto& car : cars) {
        if (car.name == name) {
            displayCar(car);
            found = true;
        }
    }
    if (!found) {
        cout << "No cars with the name " << name << " found." << endl;

    }
}





void menu(vector<Car>& cars) {

    int choice;

    do {
        cout << "1. Add car" <<endl;
        cout << "2. Remove car" << endl;
        cout << "3. Display all cars" << endl;
        cout << "4. Sort cars" << endl;
        cout << "5. Search car by name" << endl;
        cout << "6. Exit" << endl;
        cout << "Choose an option: " << endl;

        cin >> choice;



        switch (choice) {
            case 1: {
                string name;
                int year;
                double engineVolume, price;
//                ---------------------------------
                cout << "Enter name: " << endl;
                cin >> name;
//                ---------------------------------
                cout << "Enter year: " << endl;
                cin >> year;


//                ---------------------------------

                cout << "Enter engine volume: " << endl;
                cin >> engineVolume;
//                ---------------------------------

                cout << "Enter price: " << endl;
                cin >> price;
//                ---------------------------------

                cars.emplace_back(name, compairByYearMore(year), engineVolume, price);
                break;

            }
            case 2: {
                string name;

                cout << "Enter name of car to remove: " << endl;

                cin >> name;
                removeCar(cars, name);

                break;
            }
            case 3: {

                displayAllCars(cars);

                break;
            }
            case 4: {
                int sortChoice;

                cout << "1. Sort by name" << endl;
                cout << "2. Sort by year" << endl;
                cout << "3. Sort by engine volume" << endl;
                cout << "4. Sort by price"<< endl;
                cout << "Choose sorting parameter: " << endl;

                cin >> sortChoice;

                switch (sortChoice) {
                    case 1:

                        sort(cars.begin(), cars.end(), compareByName);
                        break;
                    case 2:

                        sort(cars.begin(), cars.end(), compareByYear);
                        break;
                    case 3:

                        sort(cars.begin(), cars.end(), compareByEngineVolume);
                        break;
                    case 4:

                        sort(cars.begin(), cars.end(), compareByPrice);

                        break;

                    default:

                        cout << "Invalid sorting choice." << endl;

                        break;
                }
                break;

            }
            case 5: {

                string name;

                cout << "Enter name to search: " << endl;

                cin >> name;
                searchByName(cars, name);

                break;
            }
            case 6: {

                cout << "Exiting program." << endl;

                break;
            }
            default: {

                cout << "Invalid choice. Please try again." << endl;

                break;
            }
        }

    } while (choice != 6);
}







int main() {

    vector<Car> cars;
    menu(cars);

}
