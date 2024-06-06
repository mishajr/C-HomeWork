#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

bool compare_courses(const pair<string, int> &a, const pair<string, int> &b) {
    return a.second > b.second;
}

class CourseManagementSystem {
    multimap<string, string> course_students;
    map<string, multiset<int>> student_grades;
    unordered_set<string> unique_students;

    vector<string> menu_options = {
            "Save to file",
            "Add student to course",
            "Update student grade",
            "Remove student from course",
            "Print all courses and students",
            "Print unique students",
            "Print students by grades",
            "Load from file",
            "Append to file",
            "Print file content",
            "Search student",
            "Calculate average grade",
            "Filter students by course",
            "Print courses sorted by student count",
            "Exit"
    };

public:
    void load_from_file(const string &filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return;
        }

        string course, student;
        int grade;
        while (file >> course >> student >> grade) {
            add_student_to_course(course, student, grade, false);
        }

        file.close();
        print_courses();
    }

    void add_student_to_course(const string &course, const string &student, int grade, bool writeToFile = true) {
        course_students.emplace(course, student);
        student_grades[student].insert(grade);
        unique_students.insert(student);

        if (writeToFile) {
            append_to_file("courses.txt", course, student, grade);
        }
    }

    void update_student_grade(const string &student, int old_grade, int new_grade) {
        auto &grades = student_grades[student];
        auto it = grades.find(old_grade);
        if (it != grades.end()) {
            grades.erase(it);
            grades.insert(new_grade);
        }
    }

    void remove_student_from_course(const string &course, const string &student) {
        auto range = course_students.equal_range(course);
        for (auto it = range.first; it != range.second; ) {
            if (it->second == student) {
                it = course_students.erase(it);
            } else {
                ++it;
            }
        }

        if (student_grades[student].empty()) {
            student_grades.erase(student);
            unique_students.erase(student);
        }
    }

    void print_courses() const {
        for (const auto &entry : course_students) {
            cout << "Course: " << entry.first << ", Student: " << entry.second << endl;
        }
    }

    void print_unique_students() const {
        for (const auto &student : unique_students) {
            cout << "Student: " << student << endl;
        }
    }

    void print_students_by_grades() const {
        for (const auto &entry : student_grades) {
            cout << "Student: " << entry.first << ", Grades: ";
            for (const auto &grade : entry.second) {
                cout << grade << " ";
            }
            cout << endl;
        }
    }

    void save_to_file(const string &filename) const {
        ofstream file(filename);
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return;
        }

        for (const auto &entry : course_students) {
            const string &course = entry.first;
            const string &student = entry.second;
            for (const auto &grade : student_grades.at(student)) {
                file << course << " " << student << " " << grade << endl;
            }
        }

        file.close();
    }

    void append_to_file(const string &filename, const string &course, const string &student, int grade) const {
        ofstream file(filename, ios::app);
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return;
        }

        file << course << " " << student << " " << grade << endl;
        file.close();
    }

    void search_student(const string &student) const {
        auto it = student_grades.find(student);
        if (it != student_grades.end()) {
            cout << "Student: " << student << endl;
            cout << "Courses: ";
            for (const auto &course : course_students) {
                if (course.second == student) {
                    cout << course.first << " ";
                }
            }
            cout << ", Grades: ";
            for (const auto &grade : it->second) {
                cout << grade << " ";
            }
            cout << endl;
        } else {
            cout << "Student not found!" << endl;
        }
    }

    void calculate_average_grade(const string &student) const {
        auto it = student_grades.find(student);
        if (it != student_grades.end() && !it->second.empty()) {
            double average = accumulate(it->second.begin(), it->second.end(), 0.0) / it->second.size();
            cout << "Student: " << student << endl;
            cout << "Average Grade: " << average << endl;
        } else {
            cout << "Student not found or no grades available!" << endl;
        }
    }

    void filter_students_by_course(const string &course) const {
        cout << "Course: " << course <<endl;
        cout << "Students: " << endl;
        auto range = course_students.equal_range(course);
        for (auto it = range.first; it != range.second; ++it) {
            cout << it->second << " ";
        }
        cout << endl;
    }



    void print_courses_sorted_by_student_count() const {
        map<string, int> course_count;
        for (const auto &entry : course_students) {
            course_count[entry.first]++;
        }

        vector<pair<string, int>> sorted_courses(course_count.begin(), course_count.end());
        sort(sorted_courses.begin(), sorted_courses.end(), compare_courses);

        for (const auto &course : sorted_courses) {
            cout << "Course: " << course.first << endl;
            cout << "Number of Students: " << course.second << endl;
        }
    }

    void print_file_content(const string &filename) const {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error opening file!" << endl;
            return;
        }

        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }

        file.close();
    }

    void menu() {
        int current_selection = 0;
        string input;
        string course, student, filename;
        int grade, old_grade, new_grade;



        auto print_menu = [&]() {

            cout << "-------Course Management System Menu--------" << endl;
            for (int i = 0; i < menu_options.size(); ++i) {
                if (i == current_selection) {
                    cout << "-> ";
                } else {
                    cout << "   ";
                }
                cout << menu_options[i] << endl;
            }
            cout << "--------------------------------------------" << endl;
            cout << "Enter 'n' for next, 'b' for back, 'e' for enter: " << endl;
        };

        do {
            print_menu();
            cin >> input;

            if (input == "n") {
                current_selection = (current_selection + 1) % menu_options.size();
            } else if (input == "b") {
                current_selection = (current_selection - 1 + menu_options.size()) % menu_options.size();
            } else if (input == "e") {
                switch (current_selection) {
                    case 0:
                        cout << "Enter filename: " << endl;
                        cin >> filename;
                        save_to_file(filename);
                        break;
                    case 1:
                        cout << "Enter course name: " << endl;
                        cin >> course;
                        cout << "Enter student name: " << endl;
                        cin >> student;
                        cout << "Enter grade: " << endl;
                        cin >> grade;
                        add_student_to_course(course, student, grade);
                        break;
                    case 2:
                        cout << "Enter student name: " << endl;
                        cin >> student;
                        cout << "Enter old grade: " << endl;
                        cin >> old_grade;
                        cout << "Enter new grade: " << endl;
                        cin >> new_grade;
                        update_student_grade(student, old_grade, new_grade);
                        break;
                    case 3:
                        cout << "Enter course name: " << endl;
                        cin >> course;
                        cout << "Enter student name: " << endl;
                        cin >> student;
                        remove_student_from_course(course, student);
                        break;
                    case 4:
                        print_courses();
                        break;
                    case 5:
                        print_unique_students();
                        break;
                    case 6:
                        print_students_by_grades();
                        break;
                    case 7:
                        cout << "Enter filename: " << endl;
                        cin >> filename;
                        load_from_file(filename);
                        break;
                    case 8:
                        cout << "Enter filename: " << endl;
                        cin >> filename;
                        cout << "Enter course name: " << endl;
                        cin >> course;
                        cout << "Enter student name: " << endl;
                        cin >> student;
                        cout << "Enter grade: " << endl;
                        cin >> grade;
                        append_to_file(filename, course, student, grade);
                        break;
                    case 9:
                        cout << "Enter filename: " << endl;
                        cin >> filename;
                        print_file_content(filename);
                        break;
                    case 10:
                        cout << "Enter student name: " << endl;
                        cin >> student;
                        search_student(student);
                        break;
                    case 11:
                        cout << "Enter student name: " << endl;
                        cin >> student;
                        calculate_average_grade(student);
                        break;
                    case 12:
                        cout << "Enter course name: " << endl;
                        cin >> course;
                        filter_students_by_course(course);
                        break;
                    case 13:
                        print_courses_sorted_by_student_count();
                        break;
                    case 14:
                        cout << "Exiting..." << endl;
                        break;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                }
            }
        } while (current_selection != 14 || input != "e");
    }
};

int main() {
    CourseManagementSystem cms;
    cms.menu();
}
