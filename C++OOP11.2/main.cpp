#include <iostream>
#include <cstring>

using namespace std;

class String {

protected:

    char* str;

public:

    String() {}




    String(const char* s) {
        if (s) {
            str = new char[strlen(s) + 1];
            strcpy(str, s);
        } else {
            str = nullptr;
        }
    }





    String(const String& other) {
        if (other.str) {
            str = new char[strlen(other.str) + 1];
            strcpy(str, other.str);
        } else {
            str = nullptr;
        }
    }




    String& operator=(const String& other) {
        if (this != &other) {
            delete[] str;
            if (other.str) {
                str = new char[strlen(other.str) + 1];
                strcpy(str, other.str);
            } else {
                str = nullptr;
            }
        }
        return *this;
    }



    int length() const {
        return (str) ? strlen(str) : 0;
    }



    void clear() {
        delete[] str;
        str = nullptr;
    }



    ~String() {
        delete[] str;
    }



    String operator+(const String& other) const {
        String result;
        if (str && other.str) {
            result.str = new char[length() + other.length() + 1];
            strcpy(result.str, str);
            strcat(result.str, other.str);
        }
        return result;
    }



    String& operator+=(const String& other) {
        if (other.str) {
            char* temp = new char[length() + other.length() + 1];
            strcpy(temp, str);
            strcat(temp, other.str);
            delete[] str;
            str = temp;
        }
        return *this;
    }




    bool operator==(const String& other) const {
        return (strcmp(str, other.str) == 0);
    }

    bool operator!=(const String& other) const {
        return !(*this == other);
    }

    void print() const {
        if (str) {
            cout << str << endl;
        } else {
            cout << "(Empty String)" << endl;
        }
    }
};

int main() {

    String s1("Hello");
    String s2("World");
    String s3 = s1 + s2;
    cout << "s1: ";
    s1.print();
    cout << "s2: ";
    s2.print();
    cout << "s3: ";
    s3.print();

}
