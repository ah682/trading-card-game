// UCANT.cpp : This file contains the 'main' function. Program execution begins and ends there.

// Memory Leak Detection
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <sstream>

using namespace std;

time_t readSeedFile(string filename);

int Random(int max);

void startRound(int round);

void graveYard();

void gameOver();

void readCardData();

struct SProfessor
{
    string profName;
    int profPresrtige = 30;
};

class CCard {
public:
    string type;
    string name;
    string power;
    string resilience;
    string boost;
};

int main() {
    // Genereates seed for Nick WORKS
    int seed = readSeedFile("seed.txt");
    srand(seed);
    cout << "Seed Number: " << seed << endl;

    // Generates random number for me WORKS
    int testrand = Random(49);
    cout << "Random Number Spawned with Random Function " << testrand << endl;

    ifstream filePlagiarist("plagiarist.txt");
    int num_cardsPlagiarist = 0;
    string linePlagiarist;

    // Count the number of cards in the plagiarist file
    while (getline(filePlagiarist, linePlagiarist)) {
        num_cardsPlagiarist++;
    }

    // Allocate memory for the cards
    CCard* cardsPlagiarist = new CCard[num_cardsPlagiarist];

    // Read in the card data into object for plagiaraist
    filePlagiarist.clear();
    filePlagiarist.seekg(0);
    for (int i = 0; i < num_cardsPlagiarist; i++) {
        getline(filePlagiarist, linePlagiarist);
        stringstream ssPlag(linePlagiarist);
        ssPlag >> cardsPlagiarist[i].type >> cardsPlagiarist[i].name >> cardsPlagiarist[i].power >> cardsPlagiarist[i].resilience >> cardsPlagiarist[i].boost;
    }

    // Example usage: print out random cards of plagiarist
    bool usedCardsPlagiarist[48] = {false};
    for (int i = 0; i < num_cardsPlagiarist; i++) {
        int randomCardPlagiarist = Random(48);
        do
        {
            randomCardPlagiarist = Random(48);
        } while (usedCardsPlagiarist[randomCardPlagiarist] == true);
        cout << cardsPlagiarist[randomCardPlagiarist].type << " " << cardsPlagiarist[randomCardPlagiarist].name << " " << cardsPlagiarist[randomCardPlagiarist].power << " " << cardsPlagiarist[randomCardPlagiarist].resilience << " " << cardsPlagiarist[randomCardPlagiarist].boost << endl;
        usedCardsPlagiarist[randomCardPlagiarist] = true;
    } 


    ifstream filePiffle("piffle-paper.txt");
    int num_cardsPiffle = 0;
    string linePiffle;

    // Count the number of cards in the plagiarist file file
    while (getline(filePiffle, linePiffle)) {
        num_cardsPiffle++;
    }

    cout << endl << endl << endl << endl << endl << endl;
    // Allocate memory for the cards
    CCard* cardsPiffle = new CCard[num_cardsPiffle];

    // Read in the card data for plagiaraist
    filePiffle.clear();
    filePiffle.seekg(0);
    for (int i = 0; i < num_cardsPiffle; i++) {
        getline(filePiffle, linePiffle);
        stringstream ssPif(linePiffle);
        ssPif >> cardsPiffle[i].type >> cardsPiffle[i].name >> cardsPiffle[i].power >> cardsPiffle[i].resilience >> cardsPiffle[i].boost;
    }

    // Example usage: print out random cards of piffle paper
    bool usedCardsPiffle[48] = { false };
    for (int i = 0; i < num_cardsPiffle; i++) {
        int randomCardPiffle = Random(48);
        do
        {
            randomCardPiffle = Random(48);
        } while (usedCardsPiffle[randomCardPiffle] == true);
        cout << cardsPiffle[randomCardPiffle].type << " " << cardsPiffle[randomCardPiffle].name << " " << cardsPiffle[randomCardPiffle].power << " " << cardsPiffle[randomCardPiffle].resilience << " " << cardsPiffle[randomCardPiffle].boost << endl;
        usedCardsPiffle[randomCardPiffle] = true;
    }

    //Play Game
    

    // Free the memory even though its pointless right now
    delete[] cardsPlagiarist;
    // Free the memory even though its pointless right now
    delete[] cardsPiffle;

    _CrtDumpMemoryLeaks(); // Memory Leak Detection

    // Game Finished
    gameOver();

    return 0;
}

int Random(int max)
{
    return int(float(rand()) / (RAND_MAX + 1) * float(max));
}



time_t readSeedFile(string filename) {
    time_t seed_value = 0;

    // Read from the file
    ifstream file_stream(filename);
    if (file_stream.is_open()) {
        string line;
        if (getline(file_stream, line)) {
            seed_value = stoi(line);
        }
        file_stream.close();
    }
    else {
        std::cout << "Unable to open file " << filename << '\n';
    }

    return seed_value;
}
void gameOver()
{
    cout << "Game Over!" << endl << "player " << " " << "wins";
}

void readCardData(ifstream file, int num_cards, CCard* cards, string line) // FOR LATER
{
    // Read in the card data
    file.clear();
    file.seekg(0);
    for (int i = 0; i < num_cards; i++) {
        getline(file, line);
        stringstream ss(line);
        ss >> cards[i].type >> cards[i].name >> cards[i].power >> cards[i].resilience >> cards[i].boost;
    }

    // Example usage: print out the data
    for (int i = 0; i < num_cards; i++) {
        std::cout << cards[i].type << " " << cards[i].name << " " << cards[i].power << " " << cards[i].resilience << " " << cards[i].boost << endl;
    }
}
