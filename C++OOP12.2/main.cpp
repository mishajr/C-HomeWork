#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Shape {
public:
    virtual void Show() const = 0;
    virtual void Save(ofstream& file) const = 0;
    virtual void Load(ifstream& file) = 0;
};

class Square : public Shape {
private:
    int topLeftX, topLeftY;
    int sideLength;

public:
    Square(int x, int y, int length) : topLeftX(x), topLeftY(y), sideLength(length) {}

    void Show() const override {
        cout << "Square: Top Left Corner (" << topLeftX << ", " << topLeftY
             << "), Side Length: " << sideLength << endl;
    }

    void Save(ofstream& file) const override {
        file << "Square " << topLeftX << " " << topLeftY << " " << sideLength << endl;
    }

    void Load(ifstream& file) override {
        file >> topLeftX >> topLeftY >> sideLength;
    }
};

int main() {
    vector<Shape*> shapes;
    shapes.push_back(new Square(5, 7, 5));

    ofstream outFile("shapes.txt");
    if (outFile.is_open()) {
        for (auto shape : shapes) {
            shape->Save(outFile);
        }
        outFile.close();
    } else {
        cerr << "Unable to open file for writing." << endl;

    }

    ifstream inFile("shapes.txt");
    if (inFile.is_open()) {
        while (!inFile.eof()) {
            string type;
            inFile >> type;

            if (type == "Square") {
                int x, y, length;
                inFile >> x >> y >> length;
                Square square(x, y, length);
                square.Show();
            }
        }
        inFile.close();
    } else {
        cerr << "Unable to open file for reading." << endl;
        return 1;
    }

    for (auto shape : shapes) {
        delete shape;
    }
    shapes.clear();


}
