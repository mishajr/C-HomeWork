#include <iostream>
#include <fstream>

#include <string>



using namespace std;











class Company {



public:

    string name;

    string owner;

    string phone;

    string address;

    string activity;

    Company() {}

    Company(string n, string o, string p, string a, string r): name(n), owner(o), phone(p), address(a), activity(r) {}

};

class Directory {

    static const int MAX_COMPANIES = 100;

    Company companies[MAX_COMPANIES];

    int companyCount;

    const string filename = "directory.txt";


    void loadFromFile() {
        
        ifstream file(filename);
        
        if (file.is_open()) {
            
            companyCount = 0;
            
            string name, owner, phone, address, activity;
            
            while (getline(file, name) && companyCount < MAX_COMPANIES) {
                
                getline(file, owner);
                
                getline(file, phone);
                
                getline(file, address);
                
                getline(file, activity);
                
                companies[companyCount++] = Company(name, owner, phone, address, activity);
                
            }
            
            file.close();
            
        }
    }

    void saveToFile() {
        
        ofstream file(filename);
        
        if (file.is_open()) {
            
            for (int i = 0; i < companyCount; ++i) {
                
                file << companies[i].name << endl;
                
                file << companies[i].owner << endl;
                
                
                file << companies[i].phone << endl;
                
                file << companies[i].address << endl;
                
                file << companies[i].activity << endl;
                
            }
            
            file.close();
            
        }
    }

public:

    Directory() : companyCount(0) {
        
        loadFromFile();
        
    }

    ~Directory() {
        
        saveToFile();
        
    }

    void addCompany(const Company& company) {
        
        if (companyCount < MAX_COMPANIES) {
            
            companies[companyCount++] = company;
            
            saveToFile();
            
        } else {
            
            cout << "Directory is full. Cannot add more companies." << endl;
            
        }
    }

    void displayAll() const {
        
        for (int i = 0; i < companyCount; ++i) {
            
            cout << "Name: " << companies[i].name << endl;
            
            cout << "Owner: " << companies[i].owner << endl;
            
            cout << "Phone: " << companies[i].phone << endl;
            
            cout << "Address: " << companies[i].address << endl;
            
            cout << "Activity: " << companies[i].activity << endl;
            
            cout << "---------------------------------" << endl;
            
        }
    }

    void searchByName(const string& name) const {
        
        bool found = false;
        
        for (int i = 0; i < companyCount; ++i) {
            
            if (companies[i].name == name) {
                
                cout << "Company found: " << companies[i].name << ", Owner: " << companies[i].owner << ", Phone: " << companies[i].phone << ", Address: " << companies[i].address << ", Activity: " << companies[i].activity << endl;
                found = true;
                
            }
        }
        if (!found) {
            
            cout << "No company found with name: " << name << endl;
            
        }
    }

    void searchByOwner(const string& owner) const {
        
        bool found = false;
        
        for (int i = 0; i < companyCount; ++i) {
            
            if (companies[i].owner == owner) {
                
                cout << "Company found: " << companies[i].name << ", Owner: " << companies[i].owner << ", Phone: " << companies[i].phone << ", Address: " << companies[i].address << ", Activity: " << companies[i].activity << endl;
                found = true;
                
            }
        }
        if (!found) {
            
            cout << "No company found with owner: " << owner << endl;
            
        }
    }

    void searchByPhone(const string& phone) const {
        
        bool found = false;
        
        for (int i = 0; i < companyCount; ++i) {
            
            if (companies[i].phone == phone) {
                
                cout << "Company found: " << companies[i].name << ", Owner: " << companies[i].owner << ", Phone: " << companies[i].phone << ", Address: " << companies[i].address << ", Activity: " << companies[i].activity << endl;
                found = true;
                
            }
        }
        if (!found) {
            
            cout << "No company found with phone: " << phone << endl;
            
        }
    }

    void searchByActivity(const string& activity) const {
        
        bool found = false;
        
        for (int i = 0; i < companyCount; ++i) {
            
            if (companies[i].activity == activity) {
                
                cout << "Company found: " << companies[i].name << ", Owner: " << companies[i].owner << ", Phone: " << companies[i].phone << ", Address: " << companies[i].address << ", Activity: " << companies[i].activity << endl;
                found = true;
                
            }
        }
        if (!found) {
            
            cout << "No company found with activity: " << activity << endl;
            
        }
        
    }
};

void displayMenu() {
    
    cout << "----------Directory Menu:--------------" << endl;
    
    cout << "1. Add Company" << endl;
    
    cout << "2. Display All Companies" << endl;
    
    cout << "3. Search By Name" << endl;
    
    cout << "4. Search By Owner" << endl;
    
    cout << "5. Search By Phone" << endl;
    
    cout << "6. Search By Activity" << endl;
    
    cout << "7. Exit" << endl;
    
    cout << "Enter your choice: ";
    
}

void handleUserChoice(int choice, Directory& directory) {
    switch (choice) {
        case 1: {
            
            string name, owner, phone, address, activity;
            
            cout << "Enter company name: ";
            getline(cin, name);
            
            cout << "Enter owner name: ";
            getline(cin, owner);
            
            cout << "Enter phone number: ";
            getline(cin, phone);
            
            cout << "Enter address: ";
            getline(cin, address);
            
            cout << "Enter activity: ";
            getline(cin, activity);

            
            directory.addCompany(Company(name, owner, phone, address, activity));

            
            break;
        }
        case 2:
            directory.displayAll();
            break;
        case 3: {
            string name;
            cout << "Enter company name: ";
            
            getline(cin, name);
            
            directory.searchByName(name);
            
            break;
        }
        case 4: {
            string owner;
            cout << "Enter owner name: ";
            
            getline(cin, owner);
            
            directory.searchByOwner(owner);
            
            break;
        }
        case 5: {
            string phone;
            cout << "Enter phone number: ";
            
            getline(cin, phone);
            
            directory.searchByPhone(phone);
            
            break;
        }
        case 6: {
            string activity;
            
            cout << "Enter activity: ";
            
            getline(cin, activity);
            directory.searchByActivity(activity);
            
            break;
        }
        case 7:
            cout << "Exiting program." << endl;
            
            break;
        default:
            
            cout << "Invalid choice. Please try again." << endl;
    }
}

int main() {
    Directory directory;
    
    int choice;

    
    do {
        
        displayMenu();
        
        cin >> choice;
        cin.ignore();

        handleUserChoice(choice, directory);
        
    } while (choice != 7);
}
