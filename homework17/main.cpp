#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//
//void compareFiles(const string& file1_path, const string& file2_path) {
//    ifstream file1(file1_path);
//    ifstream file2(file2_path);
//
//    string line1, line2;
//    int line_number = 1;
//
//    while (getline(file1, line1) && getline(file2, line2)) {
//        if (line1 != line2) {
//            cout << "Difference found at line " << line_number << ":" << endl;
//            cout << "File 1: " << line1 << endl;
//            cout << "File 2: " << line2 << endl;
//            break;
//        }
//        line_number++;
//    }
//
//
//    if (getline(file1, line1)) {
//        cout << "File 1 has additional lines starting from line " << line_number << ":" << endl;
//        cout << "File 1: " << line1 << endl;
//    }
//    if (getline(file2, line2)) {
//        cout << "File 2 has additional lines starting from line " << line_number << ":" << endl;
//        cout << "File 2: " << line2 << endl;
//    }
//    else {
//        cout << "Files are identical." << endl;
//    }
//}

//====================================================================

//
//bool isVowel(char c) {
//    c = tolower(c);
//    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
//}
//
//void calculateStatistics(const string& file_path) {
//    ifstream input_file(file_path);
//    if (!input_file.is_open()) {
//        cerr << "Unable to open file: " << file_path << endl;
//        return;
//    }
//
//    int char_count = 0;
//    int line_count = 0;
//    int vowel_count = 0;
//    int consonant_count = 0;
//    int digit_count = 0;
//
//    string line;
//    while (getline(input_file, line)) {
//        char_count += line.size();
//        line_count++;
//
//        for (char c : line) {
//            if (isalpha(c)) {
//                if (isVowel(c))
//                    vowel_count++;
//                else
//                    consonant_count++;
//            } else if (isdigit(c)) {
//                digit_count++;
//            }
//        }
//    }
//
//    ofstream output_file("statistics.txt");
//    if (output_file.is_open()) {
//        output_file << "Characters count: " << char_count << endl;
//        output_file << "Lines count: " << line_count << endl;
//        output_file << "Vowels count: " << vowel_count << endl;
//        output_file << "Consonants count: " << consonant_count << endl;
//        output_file << "Digits count: " << digit_count << endl;
//        output_file.close();
//        cout << "Statistics saved to 'statistics.txt'." << endl;
//    } else {
//        cerr << "Unable to create output file." << endl;
//    }
//}
//======================================================================

//string caesar_cipher(const string& text, int shift) {
//    string encrypted_text = "";
//    for (char c : text) {
//        if (isalpha(c)) {
//            char base = (isupper(c)) ? 'A' : 'a';
//            char new_char = ((c - base + shift) % 26) + base;
//            encrypted_text += new_char;
//        } else {
//            encrypted_text += c;
//        }
//    }
//    return encrypted_text;
//}

int main() {

//==========================================================
//завдання 1
//1
//    string file1_path = "file1.txt";
//    ofstream fout1;
//    string str1;
//
//    cout << "Enter text " << endl;
//    fout1.open(file1_path,fstream ::app);
//
//    getline(cin, str1);
//    fout1 << str1;
//    fout1.close();
//
//


//    2
//    string file2_path = "file2.txt";
//    ofstream fout2;
//    string str2;

//    cout << "Enter text " << endl;
//    fout1.open(file2_path,fstream ::app);
//
//    getline(cin, str2);
//    fout1 << str2;
//    fout1.close();
//
//    compareFiles(file1_path, file2_path);
//=======================================================================
//Завдяння 2
//    string file_path = "text.txt";
//    ofstream fout;
//    string str;
//
//    cout << "Enter text " << endl;
//    fout.open(file_path,fstream ::app);
//
//    getline(cin, str);
//    fout << str;
//    fout.close();
//    calculateStatistics(file1_path);
//


//=======================================================================
//
//    string file_path3 = "input.txt";
//    ofstream fout3;
//    string str3;
//
//    cout << "Enter text " << endl;
//    fout3.open(file_path3,fstream ::app);
//
//    getline(cin, str3);
//    fout3 << str3;
//    fout3.close();
//
//    ifstream input_file("input.txt");
//    if (!input_file) {
//        cerr << "Failed to open input.txt" << endl;
//
//    }
//
//    string original_text;
//    getline(input_file, original_text);
//    input_file.close();
//
//    string encrypted_text = caesar_cipher(original_text, 3);
//
//    ofstream output_file("output.txt");
//    if (!output_file) {
//        cerr << "Failed to create output.txt" << endl;
//        return 1;
//    }
//
//    output_file << encrypted_text;
//    output_file.close();
//
//    cout << "Text encrypted and written to output.txt" << endl;
//

//деякі з функцій в string caesar_cipher знайшов в інтернеті,isalpha i isupper






}
