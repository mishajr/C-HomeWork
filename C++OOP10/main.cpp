#include <iostream>
#include <string>

using namespace std;

class Animal {
protected:
    string name;

public:
    Animal(const string& animalName) : name(animalName) {}

    void makeSound() const {
        cout << "Animal sound" << endl;
    }

    void displayInfo() const {
        cout << "Animal: " << name << endl;
    }
};

class Dog : public Animal {
private:
    string breed;

public:
    Dog(const string& dogName, const string& dogBreed)
            : Animal(dogName), breed(dogBreed) {}

    void makeSound() const {
        cout << "Woof! Woof!" << endl;


    }

    void displayInfo() const {



        cout << "Dog: " << name << " (Breed: " << breed << ")" << endl;
    }
};

class Cat : public Animal {

private:

    bool hasTail;


public:
    Cat(const string& catName, bool catHasTail)
            : Animal(catName), hasTail(catHasTail) {}

    void makeSound() const {

        cout << "Meow! Meow!" << endl;
    }

    void displayInfo() const {
        cout << "Cat: " << name;
        if (hasTail)
            cout << " Has Tail)";
        else
            cout << " (Tailless)";

        cout << endl;

    }
};

class Parrot : public Animal {
private:

    string favoritePhrase;

public:
    Parrot(const string& parrotName, const string& phrase)
            : Animal(parrotName), favoritePhrase(phrase) {}

    void makeSound() const {

        cout << "Plly wants a cracker!" << endl;
    }


    void displayInfo() const {
        cout << "Parrot: " << name << " (favorite Phrase: \"" << favoritePhrase << "\")" << endl;
    }
};

int main() {

    Dog myDog("Buddy", "Golden Retriever");
    Cat myCat("Whiskers", true);
    Parrot myParrot("Polly", "Hello world!");

    myDog.makeSound();

    myDog.displayInfo();

    myCat.makeSound();
    myCat.displayInfo();

    

    myParrot.makeSound();
    myParrot.displayInfo();


}
