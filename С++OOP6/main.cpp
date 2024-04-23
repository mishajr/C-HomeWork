#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

int main() {
//1)
    string str1 = "hello world";
    string str = "hello world";

cout << str << endl;
//2)
cout << str.size() << endl;
//3)
cout << str[0] << endl;
//4)
str.replace(6,8,"planet");
cout << str << endl;
//5)
str += ", How are you?";
cout << str << endl;
//6)
bool TF = str == str1;
cout << TF << endl;
//7)
    str.substr(6, 6);
    cout << str << endl;
//    8)
    size_t pos = str.find("planet");
    cout << pos << endl;

//    9)
    string text = "hello planet, How are you?";
    string substring = "planet";

    text.find(substring);
    cout << text << endl;


//10)
    str.insert(pos, "hello ");
    cout << str << endl;
//11)

    reverse(str.begin(), str.end());
    cout << str << endl;

//12)
    string phrase = "hello planet, How are you?";
    string pattern = "l";
    size_t count = 0;
    size_t pos2 = phrase.find(pattern);
    while (pos2 != string::npos) {
        ++count;
        pos2 = phrase.find(pattern, pos2 + 1);
    }
    cout << count << endl;
//13)


    transform(str.begin(), str.end(), str.begin(), ::toupper);
    cout << str << endl;
//14)


    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    cout << str << endl;

//15)


    vector<string> words;
    stringstream ss(str);
    string word;
    while (ss >> word) {
        words.push_back(word);
    }

    cout << endl;
    for (const auto& w : words) {
        cout << w << " "  << "   "<< endl;
    }
    cout << endl;


//16)
    string str12 = "hello planet, How are you?";
    string from = "hello";
    string to = "crazy";
    size_t start_pos = 0;
    while ((start_pos = str12.find(from, start_pos)) != string::npos) {
        str12.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    cout << str12 << endl;

//17)

    string str65 = "HelleH";
    string reversed = str65;
    reverse(reversed.begin(), reversed.end());
    str65 == reversed ? cout << "palindrom :" << str65  << endl : cout << " ne palindrom :" << str65  << endl;

    cout<< endl;




//18)


    sort(str12.begin(), str12.end());
    cout << str12 << endl;
    cout<< endl;

//19)

    string str546 = "To DAY 2024-04-22";
    cout<< str546<<  endl;


    for (char& c : str546) {

        if (isdigit(c)) {
            c = 'X';
        }
    }

    cout << str546 << endl;
    cout<< endl;

//20)


    string combined = str12 + " " + str65;
    cout << combined << endl;
    cout<< endl;



}



