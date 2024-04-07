#define SIZE 10
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
struct Games{
 int id;
 char name[50];
 char director[50];
 char genre[50];
 int year;
 float rating;
 char descriptione[500];


};


void Show(const Games& game);
void ShowAll(Games game[], int size);


void SearchByName(const Games game[], int size, const char* name);
void SearchByDirector(const Games game[], int size, const char* director);
void SearchByGenre(const Games game[], int size, const char* genre);
void SearchByYear(const Games game[], int size, const int year);


void ThemostPopular(const Games game[], int size);
void ChangeData(Games game[], int size, int id);
void SaveToFile(const Games game[],int size, const char* fileName);
void LoudToFile( Games game[], int &size, const char* fileName);





int main()
{
    int choice;
    Games Game[SIZE] = {
            {1, "Halo Infinite","343 Industries", "First person shooter", 2021, 8.7, "In terms of plot, Halo Infinite is a continuation of Halo 5: Guardians. In this part, the artificial intelligence Cortana, a program that helped the main character with advice and hacked computer security, and allied AIs (artificial intelligence - editor's note) rebel against their creators - the United Nations Space Command."},
            {2, "Ghostrunner","One More Level, Slipgate Ironworks, 3D Realms","Shooter", 2020, 8.1, "The online game takes place in the future, after a global cataclysm. The last habitat of humanity is the tower city. The Architect built it and, to protect it, created a special detachment of soldiers - ghostrunners, that is, ghost runners."},
            {3, "God of War", "Santa Monica Studio", "Action", 2018, 9.4, "God of War is the fourth installment in the main God of War series. This and previous parts of the game were created by Sony's own studio."},
            {4, "Deathloop", "Arkane Studios", "Adventure", 2022, 8.8, "Deathloop is a first-person shooter. The game begins in an alternate 1963 on Blackreef Island, where a time anomaly has occurred."},
            {5, "Hitman 3", "IO Interactive", "Stealth", 2020, 8.7, "In the story, the game is designed as the conclusion of the trilogy begun in Hitman and Hitman 2. In Hitman 3, Agent 47 and his colleague Diana Burnwood team up with a friend and professional assassin named Lucas Gray. They want to destroy the secret organization Providence. To do this, the player completes many assassination contracts around the world."},

            {6, "GTA5","Rockstar Games", "3rd person view", 2014, 8.7, "Grand Theft Auto V is a continuation of the beloved and popular GTA action game. In the 5th part we will return to San Andreas and the familiar Los Santos. This time we are given 3 main characters: Michael - an ex-bank robber, forced to return to the criminal world due to financial difficulties; Trevor Phillips - another..."},
            {7, "Assassin’s Creed 2","Ubisoft","Single Play", 2010, 7.6, "Assassin's Creed 2 is a continuation of the popular adventure series Assassin's Creed, developed by Ubisoft. The game's plot takes place in Renaissance Italy at the end of the 15th century. The main character is Ezio Auditore, a young Italian aristocrat, who becomes a member of a mysterious brotherhood..."},
            {8, "Portal", "Valve", "Future", 2007, 7.7, "Portal is a single-player, 1st-person, sci-fi puzzle-adventure platformer set in an Aperture research lab. The main character Chell will have to go through a series of test rooms using logic and a portal gun, capable of creating spatial vortexes by moving herself or objects through walls.\n"
                                                          "\n"
                                                          "At the end of each room you need to get to the exit in the form of a circular elevator, which leads to the next test.\n "
                                                          "Each new room will be more difficult and dangerous."},
            {9, "Hogwarts Legacy", "Avalanche Software, Portkey Games", "Fantasy", 2023, 8.4, "Hogwarts Legacy is an exciting open world action RPG based on the Harry Potter books."},
            {10, "Fallout", "Black Isle Studios", "Complex", 1997, 9.8, "Fallout 1 (“Fallout: A Post Nuclear Role Playing Game”) is a single-player role-playing game with an isometric camera in the setting of a dark post-apocalyptic future about a native of Vault 13 who must save his settlement from death, the first game in the Fallout series. 2161 The world has experienced a nuclear war."},

    };

    do {
        cout << "---- MENU GAME SEARCH ----" << endl;
        cout << "[1] - Search by name     |" << endl;
        cout << "[2] - Search by director |" << endl;
        cout << "[3] - Search by genre    |" << endl;
        cout << "[4] - Search by year     |" << endl;
        cout << "[5] - The most popular   |" << endl;
        cout << "[6] - Show all           |" << endl;
        cout << "[7] - Change data        |" << endl;
        cout << "[8] - Write to file      |" << endl;
        cout << "[9] - Load from file     |" << endl;
        cout << "[0] - Exit               |"<< endl;
        cout << "---- MENU GAME SEARCH ----" << endl;

        cin >> choice;
        cin.ignore();




        switch (choice)
        {

            case 1: {
                char name[50];
                cout << "Enter name of game --> " ;
                cin.getline(name, 50);

                SearchByName(Game, SIZE, name);

                break;
            }
            case 2:{
                char director[50];
                cout << "Enter director of game --> " ;
                cin.getline(director, 50);
                SearchByDirector(Game, SIZE, director);
                break;
            }
            case  3: {
                char genre[50];
                cout << "Enter genre of game --> " ;
                cin.getline(genre, 50);
                SearchByGenre(Game, SIZE, genre);
                break;
            }
            case 4:{
                int year;
                cout << "Enter year of game --> " ;
                cin >> year;
                SearchByYear(Game, SIZE, year);
                break;
            }
            case 5: {
                ThemostPopular(Game, SIZE);
                break;
            }
            case 6:{

                ShowAll(Game, SIZE);
                break;

            }
            case 7: {
                cout << "Enter id --> ";

                int id;
                cin >> id;
                ChangeData(Game, SIZE, id);
                break;
            }
            case 8: {
                char fileName[50];
                cout << "Enter name for your file --> ";
                cin.getline(fileName, 50);
                SaveToFile(Game, SIZE, fileName);
                break;
            }
            case 9: {
                int size ;
                char fileName[50];
                cout << "Enter name for your file --> ";
                cin.getline(fileName, 50);
                LoudToFile(Game, size, fileName);

                break;
            }
            case 0:{
                cout << "Game search is disabled...." << endl;
                return 0;

            }
            default:
                cout << "invalid" << endl;
                break;
        }

    } while (true);


}



//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++




void Show(const Games& game) {


    cout << "\n";
    cout << "|\n";
    cout << "V\n";
    cout << "\n";

    cout << "Name :" << game.name << endl;
    cout << "Director :" << game.director << endl;
    cout << "Genre :" << game.genre << endl;
    cout << "Year :" << game.year << endl;
    cout << "Rating :" << game.rating << endl;
    cout << "Descriptione :" << game.descriptione << endl;
    cout << "------------------------------------" << endl;

}
void ShowAll(Games game[], int size) {

    for (int i = 0; i < size; ++i) {
        cout << "id :" << game[i].id <<endl;
        cout << "Name :" << game[i].name << endl;
        cout << "Director :" << game[i].director << endl;
        cout << "Genre :" << game[i].genre << endl;
        cout << "Year :" << game[i].year << endl;
        cout << "Rating :" << game[i].rating << endl;
        cout << "Descriptione :" << game[i].descriptione << endl;
        cout << "------------------------------------" << endl;

    }

}





void SearchByName(const Games game[], int size, const char* name) {

    bool found = false;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(game[i].name,name) == 0) {
            Show(game[i]);
            found = true;
        }
    }
    if (!found) {
        cout << " Game not found"<< endl;
    }



}


void SearchByDirector(const Games game[], int size, const char* director) {

    bool found = false;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(game[i].director,director) == 0) {

            found = true;
            Show(game[i]);
            break;
        }
    }
    if (!found) {
        cout << " Game not found" << endl;
    }



}



void SearchByGenre(const Games game[], int size, const char* genre) {

    bool found = false;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(game[i].genre,genre) == 0) {

            found = true;
            Show(game[i]);
            break;
        }
    }
    if (!found) {
        cout << " Game not found" << endl;
    }



}



void SearchByYear(const Games game[], int size, const int year) {

    bool found = false;
    for (int i = 0; i < size; i++)
    {
        if (game[i].year == year) {
            if (game[i].id != 3) {
                found = true;
                Show(game[i]);
                break;
            }

        }
    }
    if (!found) {
        cout << " Game not found" << endl;
    }



}







void ThemostPopular(const Games game[], int size) {

    int index = -1;
    int maxRating = game[0].rating;

    for (int i = 0; i < size; i++)
    {
        if (game[i].rating > maxRating) {
            maxRating = game[i].rating;
            index = i;
        }
    }
    if (index != -1) {
        Show(game[index]);
    }
    else {
        cout << "Game not fount" << endl;
    }
}


void ChangeData(Games game[], int size, int id) {
    bool found = false;
    for (int i = 0; i < size; i++)
    {
        if (game[i].id == id) {
            Show(game[i]);
            cout << "Enter  Name : ";
            cin >> game[i].name;
            cout << "Enter  Director : ";
            cin >> game[i].director;
            cout << "Enter  Genre : ";
            cin >> game[i].genre;
            cout << "Enter  Year : ";
            cin >> game[i].year;
            cout << "Enter  Rating : ";
            cin >> game[i].rating;
            cout << "Enter  Descriptione : ";
            cin >> game[i].descriptione;
            found = true;
            cin.ignore();
            cout << "--------------------" << endl;
            Show(game[i]);

            break;
        }
    }
}


void SaveToFile(const Games game[],int size, const char* fileName) {
    ofstream file(fileName);
    if (file.is_open()) {
        for (int i = 0; i < size; i++)
        {
            file << game[i].id << endl;
            file << game[i].name << endl;
            file << game[i].director << endl;
            file << game[i].genre << endl;
            file << game[i].year << endl;
            file << game[i].rating << endl;
            file << game[i].descriptione << endl;

        }
    }
    else {
        cerr << "Error open";
        return;
    }
}


void LoudToFile( Games game[], int &size, const char* fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "Error opening";
        return;
    }
    else {
        size = 0;
        while (!file.eof()) {
            file >> game[size].id;
            file.ignore();
            file.getline(game[size].name, 50);
            file.getline(game[size].director, 50);
            file.getline(game[size].genre, 50);
            file >> game[size].year;
            file >> game[size].rating;
            file.ignore();
            file.getline(game[size].descriptione, 100);
            size++;
        }
        ShowAll(game,size);
        file.close();
    }
}

















