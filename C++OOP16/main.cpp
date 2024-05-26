#include <iostream>
#include <vector>
#include <fstream>

#include <string>

using namespace std;



class Train {

public:
    int number;

    string departureTime;

    string destination;

    Train() : number(0), departureTime(""), destination("") {}

    Train(int num, const string& time, const string& dest): number(num), departureTime(time), destination(dest) {}

    friend ostream& operator<<(ostream& os, const Train& train) {

        os << train.number << "  " << train.departureTime << " " << train.destination;

        return os;

    }

    friend istream& operator>>(istream& is, Train& train) {

        is >> train.number >> train.departureTime >> train.destination;

        return is;
    }

};

class TrainStation {

    vector<Train> trains;


public:

    void addTrain(const Train& train) {

        trains.push_back(train);
    }

    void displayAllTrains() const {

        for (const auto& train : trains) {

            cout << train << endl;

        }
    }

    void displayTrainByNumber(int number) const {
        for (const auto& train : trains) {

            if (train.number == number) {

                cout << train << endl;

                return;
            }
        }

        cout << "Train not found!" << endl;

    }

    void editDepartureTime(int number, const string& newTime) {

        for (auto& train : trains) {

            if (train.number == number) {

                train.departureTime = newTime;

                return;
            }
        }

        cout << "Train not found!" << endl;

    }

    void sortTrainsByTime() {

        for (size_t i = 0; i < trains.size() - 1; ++i) {

            for (size_t j = i + 1; j < trains.size(); ++j) {

                if (trains[i].departureTime > trains[j].departureTime) {

                    swap(trains[i], trains[j]);

                }
            }
        }
    }

    void displayTrainsByDestination(const string& destination) const {

        for (const auto& train : trains) {


            if (train.destination == destination) {

                cout << train << endl;

            }
        }
    }

    void saveToFile(const string& filename) const {

        ofstream outFile(filename);

        if (!outFile) {

            cerr << "Error opening file for writing!" << endl;

            return;
        }
        for (const auto& train : trains) {

            outFile << train << endl;


        }

        outFile.close();
    }

    void loadFromFile(const string& filename) {
        ifstream inFile(filename);

        if (!inFile) {

            cerr << "Error opening file for reading!" << endl;

            return;
        }

        trains.clear();

        Train train;

        while (inFile >> train) {

            trains.push_back(train);

        }

        inFile.close();
    }
};

void handleUserChoice(int choice, TrainStation& station) {

    int number;

    string time, destination, filename;

    switch (choice) {

        case 1:
            cout << "Enter train number, departure time (HH:MM), and destination: " << endl;

            cin >> number >> time >> destination;
            station.addTrain(Train(number, time, destination));

            break;

        case 2:

            station.displayAllTrains();

            break;
        case 3:

            cout << "Enter train number: " << endl;

            cin >> number;

            station.displayTrainByNumber(number);

            break;
        case 4:

            cout << "Enter train number and new departure time (HH:MM): " << endl;

            cin >> number >> time;

            station.editDepartureTime(number, time);

            break;
        case 5:
            station.sortTrainsByTime();

            break;
        case 6:

            cout << "Enter destination: " <<endl;

            cin >> destination;
            station.displayTrainsByDestination(destination);

            break;

        case 7:

            cout << "Enter filename: " << endl;

            cin >> filename;

            station.saveToFile(filename);
            break;

        case 8:

            cout << "Enter filename: " << endl;

            cin >> filename;

            station.loadFromFile(filename);
            break;

        case 0:

            cout << "Exiting..." << endl;

            break;

        default:
            cout << "Invalid !" << endl;
            break;

    }
}

int main() {
    TrainStation station;
    int choice;

    do {
        cout << "1. Add Train" << endl;
        cout << "2. Display All Trains" << endl;
        cout << "3. Display Train by Number" << endl;
        cout << "4. Edit Departure Time" << endl;
        cout << "5. Sort Trains by Time" << endl;
        cout << "6. Display Trains by Destination" << endl;
        cout << "7. Save to File" << endl;
        cout << "8. Load from File" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: " << endl;
        cin >> choice;
        handleUserChoice(choice, station);
    } while (choice != 0);


}
