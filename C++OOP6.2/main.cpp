#include <iostream>
#include <queue>
#include <cstdlib>

using namespace std;

class Passenger {
public:
    Passenger(int id) : id(id) {}
    int getId() const { return id; }
private:
    int id;
};

class Shuttle {
public:
    Shuttle(int capacity) : capacity(capacity) {}
    void addPassenger(Passenger passenger) {
        passengers.push(passenger);
    }
    int getCapacity() const { return capacity; }
    queue
            <Passenger> passengers;
private:
    int capacity;
};

int main() {
    int average_passenger_arrival_time = 5;
    int average_shuttle_arrival_time = 15;
    int max_capacity = 20;
    int max_passengers = 10;

    srand(time(NULL));

    cout  << average_passenger_arrival_time << " min" << endl;
    cout << average_shuttle_arrival_time << " min" << endl;


}
