#include <iostream>
using namespace std;

string remuve_symbol(char* str, int index);
string remove_character(char* str, char ch);
void insert_character(char input_string[], int position, char ch);
void SymbolNumStrCheck(char* str);





int main() {
//===============================================================
//    1


//    char input_str[] = "Deleting a letter from a string";
//    int index_remove;
//
//    cout << "Enter index to remove: ";
//    cin >> index_remove;
//
//    string result = remuve_symbol(input_str, index_remove);
//    cout << "Result: " << result << endl;
//
//===============================================================

//2
//
//    char input_str[] = "Deleting a letter from a string";
//    char character_to_remove;
//
//    cout << "Enter character to remove: ";
//    cin >> character_to_remove;
//
//    string result = remove_character(input_str, character_to_remove);
//    cout << "Result: " << result << endl;


//===============================================================

//3
//
//    int insert_position;
//    char character_to_insert;
//    char input_string[100] = "hello add symbol";
//    cout << "hello,enter position :" << endl;
//    cin >> insert_position;
//    cout << "hello,enter symbol :" << endl;
//    cin >> character_to_insert;
//
//
//    insert_character(input_string, insert_position, character_to_insert);
//    cout << "Result: " << input_string << endl;


//===============================================================

//4
//
//const int MAX_LENGTH = 1000;
//char string[MAX_LENGTH];
//cout << "Enter list: ";
//cin.getline(string, MAX_LENGTH);
//char oklic = '!';
//
//    for (int i = 0; string[i] != '\0'; ++i) {
//        if (string[i] == '.'){
//            string[i] = oklic;
//        }
//    }
//    cout<<  string << endl;


//===============================================================
//5

//const int MAX_LENGTH = 1000;
//char string[MAX_LENGTH];
//char symbol;
//cout << "Enter list: ";
//cin.getline(string, MAX_LENGTH);
//
//cout << "Enter symbol :";
//cin >> symbol;
//
//    int numSimbol = 0;
//    for (int i = 0; string[i] != '\0'; ++i) {
//        if (string[i] == symbol){
//            numSimbol++;
//        }
//    }
//    cout<<  numSimbol << endl;
//



//===============================================================


//6
//    char symbol[30] = "12 34 def daf jumaisymba !";
//
//    SymbolNumStrCheck(symbol);

}






// FUNCTION













//==============================================

//1
//string remuve_symbol(char* str, int index) {
//    if (index < 0) {
//        return str;
//    } else {
//        string result;
//        for (int i = 0; str[i] != '\0'; ++i) {
//            if (i != index) {
//                result += str[i];
//            }
//        }
//        return result;
//    }
//}
//==============================================
//2
//string remove_character(char* str, char ch) {
//    string result;
//    for (int i = 0; str[i] != '\0'; ++i) {
//        if (str[i] != ch) {
//            result += str[i];
//        }
//    }
//    return result;
//}
//=============================================
//3
//
//void insert_character(char input_string[], int position, char ch) {
//    int length = 0;
//    while (input_string[length] != '\0') {
//        length++;
//    }
//    if (position < 0 || position > length) {
//        cout << "Позиція вставки виходить за межі рядка." << endl;
//        return;
//    }
//    for (int i = length; i >= position; i--) {
//        input_string[i + 1] = input_string[i];
//    }
//
//
//    input_string[position] = ch;
//}

//===============================================================

//6
//void SymbolNumStrCheck(char* str) {
//    char* strPtr = nullptr;
//    int num = 0;
//    int strs = 0;
//    int symbol = 0;
//
//    for (strPtr = str; *strPtr; strPtr++) {
//        if (*strPtr >= 48 && *strPtr <= 57) {
//            num += 1;
//        }
//        else if (*strPtr >= 65 && *strPtr <= 90) {
//            strs += 1;
//
//        }
//        else if (*strPtr >= 97 && *strPtr <= 122) {
//            strs += 1;
//        }
//        else {
//            symbol += 1;
//        }
//    }
//
//    cout << num << endl;
//    cout << strs << endl;
//    cout << symbol << endl;
//
//}
//===============================================================
