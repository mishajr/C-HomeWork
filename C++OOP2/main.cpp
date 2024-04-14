#define SIZE 81
#include <iostream>

using namespace std;

class String {
private:
    
    static int count;
    char* lines;

public:
    String() : String(SIZE) {}

    String(int size) {
        lines = new char[size + 1];
        for (int i = 0; i < size; ++i) {
            lines[i] = '\0';
        }
        lines[size] = '\0';
        count++;
    }

    String(const char* str) {
        int size = 0;
        while (str[size] != '\0') {
            size++;
        }
        lines = new char[size + 1];
        for (int i = 0; i < size; ++i) {
            lines[i] = str[i];
        }
        lines[size] = '\0';
        count++;
    }

    ~String() {
        delete[] lines;
        count--;
    }

    void input() {
        cout << "Enter a string: ";
        cin.getline(lines, SIZE + 1);
    }

    void output(){
        cout << lines << endl;
    }

    static int getCount() {
        return count;
    }
};

int String::count{0};

int main() {
    String s1;
    String s2(100);
    String s3("Hello");

    cout << "Numberobjects: " << String::getCount() << endl;

    s1.input();
    cout << "String s1: ";
    s1.output();

    cout << "Number objects: " << String::getCount() << endl;


}
