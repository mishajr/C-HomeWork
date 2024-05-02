#include <iostream>
#include <cstring>

using namespace std;


class String {
protected:
    char* str;
    int length;

public:
    String() {
        length = 0;
        str = new char[1];
        str[0] = '\0';
    }

    String(const char* s) {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }

    String(const String& other) {
        length = other.length;
        str = new char[length + 1];
        strcpy(str, other.str);
    }

    String& operator=(const String& other) {
        if (this != &other) {
            delete[] str;
            length = other.length;
            str = new char[length + 1];
            strcpy(str, other.str);
        }
        return *this;
    }

    int getLength() const {
        return length;
    }

    void clear() {
        delete[] str;
        length = 0;
        str = new char[1];
        str[0] = '\0';
    }

    ~String() {
        delete[] str;
    }

    String operator+(const String& other) const {
        String newString;
        newString.length = length + other.length;
        newString.str = new char[newString.length + 1];
        strcpy(newString.str, str);
        strcat(newString.str, other.str);
        return newString;
    }

    String& operator+=(const String& other) {
        char* temp = new char[length + other.length + 1];
        strcpy(temp, str);
        strcat(temp, other.str);
        delete[] str;
        str = temp;
        length += other.length;
        return *this;
    }

    bool operator==(const String& other) const {
        return (length == other.length) && (strcmp(str, other.str) == 0);
    }

    bool operator!=(const String& other) const {
        return !(*this == other);
    }

    friend ostream& operator<<(ostream& out, const String& s) {
        out << s.str;
        return out;
    }
};


class BitString : public String {
public:
    BitString() : String() {}

    BitString(const char* s) {
        int len = strlen(s);
        bool isValid = true;
        for (int i = 0; i < len; ++i) {
            if (s[i] != '0' && s[i] != '1') {
                isValid = false;
                break;
            }
        }

        if (isValid) {
            length = len;
            str = new char[length + 1];
            strcpy(str, s);
        } else {
            length = 0;
            str = new char[1];
            str[0] = '\0';
        }
    }

    BitString(const BitString& other) : String(other) {}

    BitString& operator=(const BitString& other) {
        String::operator=(other);
        return *this;
    }

    void negate() {
        for (int i = 0; i < length; ++i) {
            if (str[i] == '0') {
                str[i] = '1';
            } else {
                str[i] = '0';
            }
        }
    }

    BitString operator+(const BitString& other) const {
        BitString result;
        result.length = length + other.length;
        result.str = new char[result.length + 1];
        strcpy(result.str, str);
        strcat(result.str, other.str);
        return result;
    }

    BitString& operator+=(const BitString& other) {
        *this = *this + other;
        return *this;
    }

    bool operator==(const BitString& other) const {
        return String::operator==(other);
    }

    bool operator!=(const BitString& other) const {
        return String::operator!=(other);
    }
};

int main() {
    String s1("Hello");
    String s2(" World");

    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;

    String s3 = s1 + s2;
    cout << "s3 (s1 + s2): " << s3 << endl;

    if (s1 == s2) {
        cout << "s1 is equal to s2" << endl;
    } else {
        cout << "s1 is not equal to s2" << endl;
    }

    BitString bs1("1010");
    BitString bs2("1101");

    cout << "bs1: " << bs1 << endl;
    cout << "bs2: " << bs2 << endl;

    BitString bs3 = bs1 + bs2;
    cout << "bs3 (bs1 + bs2): " << bs3 << endl;

    bs1.negate();
    cout << "Negated bs1: " << bs1 << endl;

    if (bs1 != bs2) {
        cout << "bs1 is not equal to bs2" << endl;
    } else {
        cout << "bs1 is equal to bs2" << endl;
    }

}
