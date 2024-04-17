#include <iostream>
using namespace std;

struct Vagon {
    int number;
    int places;
    int passengers;
};

class Train {
    const int maxVagon;
    string model;
    int vagonCount;
    Vagon* vagon;

public:
    Train() : model{"no model"}, vagonCount{0}, vagon{nullptr}, maxVagon{0} {}
    Train(string mod, int maxVagon) : model{mod}, maxVagon{maxVagon}, vagonCount{0}, vagon{nullptr} {}

    ~Train() {
        delete[] vagon;
    }

    Train(const Train& other) : model{other.model}, maxVagon{other.maxVagon}, vagonCount{other.vagonCount} {
        vagon = new Vagon[vagonCount];
        for (int i = 0; i < vagonCount; ++i) {
            vagon[i] = other.vagon[i];
        }
    }

    void AddVagon(int number, int places) {
        if (vagonCount < maxVagon) {
            Vagon* newVagonArray = new Vagon[vagonCount + 1];
            for (int i = 0; i < vagonCount; ++i) {
                newVagonArray[i] = vagon[i];
            }
            newVagonArray[vagonCount].number = number;
            newVagonArray[vagonCount].places = places;
            newVagonArray[vagonCount].passengers = 0;
            delete[] vagon;
            vagon = newVagonArray;
            vagonCount++;
        } else {
            cout << "Cannot add more vagon." << endl;
        }
    }

    void AddPassenger(int vagonNumber) {
        if (vagonNumber >= 0 && vagonNumber < vagonCount) {
            if (vagon[vagonNumber].passengers < vagon[vagonNumber].places) {
                vagon[vagonNumber].passengers++;
                cout << "Passenger added to vagon " << vagonNumber << endl;
            } else {
                cout << "Vagon " << vagonNumber << " is full." << endl;
            }
        } else {
            cout << "Invalid vagon num" << endl;
        }
    }

    void ShowVagon() {
        cout << "Train: " << model << endl;
        cout << "Number of vagon: " << vagonCount << endl;
        for (int i = 0; i < vagonCount; ++i) {
            cout << "Vagon number: " << vagon[i].number << endl;
            cout << "Places available: " << vagon[i].places << endl;
            cout << "Passengers count: " << vagon[i].passengers << endl;
            cout << "-----------------------" << endl;
        }
    }
};

int main() {
    Train train1("Express", 3);
    train1.AddVagon(1, 50);
    train1.AddVagon(2, 40);
    train1.AddVagon(3, 30);

    train1.ShowVagon();

    Train train2 = train1;

    train2.AddPassenger(0);
    train2.AddPassenger(0);

    train2.ShowVagon();

}
