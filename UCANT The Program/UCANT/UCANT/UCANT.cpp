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

void graveYard();

void readCardData();

struct SProfessor
{
    string profName;
    int profPresrtige = 30;
};

class CCard {
public:
    string type;
    string firstname;
    string lastname;
    string power;
    string resilience;
    string boost;
};

class Round {
public:
    void startRound(int round);
};

class GameStart {
public:
    void gameStart();
};


class GameOver {
public:
    void gameOver();
};

void GameStart::gameStart() {
    cout << "Welcome to U-Can't. Let the winnowing begin..." << endl;
}

void GameOver::gameOver() {
    cout << "Game Over!" << endl << "player " << " " << "wins";
}

void startRound(int round)
{
    void drawCard();
    cout << "Round: " << round << endl;
}

void drawCard();

int main() {
    // Genereates seed for Nick WORKS
    int seed = readSeedFile("seed.txt");
    srand(2334823854999);
    cout << "Seed Number: " << seed << endl;

    // Generates random number for me WORKS
    int testrand = Random(48);
    cout << "Random Number Spawned with Random Function " << testrand << endl;

    GameStart();

    ifstream filePlagiarist("plagiarist.txt");
    int num_cardsPlagiarist = 0;
    string linePlagiarist;

    // Count the number of cards in the plagiarist file
    while (getline(filePlagiarist, linePlagiarist)) {
        num_cardsPlagiarist++;
    }

    // Allocate memory for the cards
    vector<CCard> cardsPlagiarist(num_cardsPlagiarist);

    // Read in the card data into object for plagiaraist
    filePlagiarist.clear();
    filePlagiarist.seekg(0);
    for (int i = 0; i < cardsPlagiarist.size(); i++) {
        getline(filePlagiarist, linePlagiarist);
        stringstream ssPlag(linePlagiarist);
        ssPlag >> cardsPlagiarist[i].type;
        if (cardsPlagiarist[i].type == "1") {
            ssPlag >> cardsPlagiarist[i].firstname >> cardsPlagiarist[i].lastname >> cardsPlagiarist[i].power >> cardsPlagiarist[i].resilience >> cardsPlagiarist[i].boost;
        }
        else {
            cardsPlagiarist[i].type = "";
            cardsPlagiarist[i].firstname = "";
            cardsPlagiarist[i].lastname = "";
            cardsPlagiarist[i].power = "";
            cardsPlagiarist[i].resilience = "";
            cardsPlagiarist[i].boost = "";
        }
    }

    // Create a new vector for non-empty cards
    vector<CCard> nonEmptyCardsPlagiarist;
    for (int i = 0; i < cardsPlagiarist.size(); i++) {
        if (cardsPlagiarist[i].type != "") {
            nonEmptyCardsPlagiarist.push_back(cardsPlagiarist[i]);
        }
    }

    // Replace the original vector with the non-empty vector
    cardsPlagiarist = nonEmptyCardsPlagiarist;

    // Example usage: print out random cards of plagiarist
    bool usedCardsPlagiarist[48] = {false};
    for (int i = 0; i < cardsPlagiarist.size(); i++) {
        int randomCardPlagiarist = Random(48);
        do
        {
            randomCardPlagiarist = Random(48);
        } while (usedCardsPlagiarist[randomCardPlagiarist] == true);
        cout << cardsPlagiarist[randomCardPlagiarist].type << " " << cardsPlagiarist[randomCardPlagiarist].firstname << " " << cardsPlagiarist[randomCardPlagiarist].lastname << " " << cardsPlagiarist[randomCardPlagiarist].power << " " << cardsPlagiarist[randomCardPlagiarist].resilience << " " << cardsPlagiarist[randomCardPlagiarist].boost << endl;
        usedCardsPlagiarist[randomCardPlagiarist] = true;
    } 


    ifstream filePiffle("piffle-paper.txt");
    int num_cardsPiffle = 0;
    string linePiffle;

    // Count the number of cards in the plagiarist file file
    while (getline(filePiffle, linePiffle)) {
        num_cardsPiffle++;
    }

    cout << "NUM CARDS PIFFLE" << num_cardsPiffle << endl;

    cout << endl << endl << endl << endl << endl << endl;
    // Allocate memory for the cards
    vector<CCard> cardsPiffle(num_cardsPiffle);

    // Read in the card data for plagiaraist
    filePiffle.clear();
    filePiffle.seekg(0);
    for (int i = 0; i < cardsPiffle.size(); i++) {
        getline(filePiffle, linePiffle);
        stringstream ssPif(linePiffle);
        ssPif >> cardsPiffle[i].type;
        if (cardsPiffle[i].type == "1") {
           ssPif >> cardsPiffle[i].firstname >> cardsPiffle[i].lastname >> cardsPiffle[i].power >> cardsPiffle[i].resilience >> cardsPiffle[i].boost;
        }
        else {
            cardsPiffle[i].type = "";
            cardsPiffle[i].firstname = "";
            cardsPiffle[i].lastname = "";
            cardsPiffle[i].power = "";
            cardsPiffle[i].resilience = "";
            cardsPiffle[i].boost = "";
        }
    }

    

    // Example usage: print out random cards of piffle paper
    bool usedCardsPiffle[48] = { false };
    for (int i = 0; i < cardsPiffle.size(); i++) {
        int randomCardPiffle = Random(48);
        do
        {
            randomCardPiffle = Random(48);
        } while (usedCardsPiffle[randomCardPiffle] == true);
        cout << cardsPiffle[randomCardPiffle].type << " " << cardsPiffle[randomCardPiffle].firstname << " " << cardsPiffle[randomCardPiffle].lastname << " " << cardsPiffle[randomCardPiffle].power << " " << cardsPiffle[randomCardPiffle].resilience << " " << cardsPiffle[randomCardPiffle].boost << endl;
        usedCardsPiffle[randomCardPiffle] = true;
    }


    // Draws random card for piffle and checks if works with cout
    cout << endl << endl << endl << endl << endl;
    cout << "DRAWN CARDS Piffle" << endl << endl << endl << endl << endl;
    vector<CCard> cardsPiffleDrawn;
    bool usedCardsPiffleDrawn[48] = { false };
    for (int i = 0; i < 2; i++) {
        int randomCardPiffle = Random(48);
        do
        {
            randomCardPiffle = Random(48);
        } while (usedCardsPiffleDrawn[randomCardPiffle] == true);

        cardsPiffleDrawn.push_back(cardsPiffle[randomCardPiffle]);
        // Checks if works
        cout << cardsPiffleDrawn[i].type << " " << cardsPiffleDrawn[i].firstname << " " << cardsPiffleDrawn[i].power << " " << cardsPiffleDrawn[i].resilience << " " << cardsPiffleDrawn[i].boost << endl;
        usedCardsPiffleDrawn[randomCardPiffle] = true;
    }


    // Draws random card for plagarist and checks if works with cout
    cout << endl << endl << endl << endl << endl;
    cout << "DRAWN CARDS Plagiarist" << endl << endl << endl << endl << endl;
    vector<CCard> cardsPlagiaristDrawn;
    bool usedCardsPlagiaristDrawn[48] = { false };
    for (int i = 0; i < 2; i++) {
        int randomCardPlagiarist = Random(48);
        do
        {
            randomCardPlagiarist = Random(48);
        } while (usedCardsPlagiaristDrawn[randomCardPlagiarist] == true);

        cardsPlagiaristDrawn.push_back(cardsPlagiarist[randomCardPlagiarist]);
        // Checks if works
        cout << "Player has drawn " << cardsPlagiaristDrawn[i].type << " " << cardsPlagiaristDrawn[i].firstname << " " << cardsPlagiaristDrawn[i].lastname << " " << cardsPlagiaristDrawn[i].power << " " << cardsPlagiaristDrawn[i].resilience << " " << cardsPlagiaristDrawn[i].boost << endl;
        usedCardsPlagiaristDrawn[randomCardPlagiarist] = true;
    }

    // Piffle Chooses a card card
    int randomCardPiffle = Random(2);
    cout << " Player chooses " << cardsPiffleDrawn[randomCardPiffle].type << " " << cardsPiffleDrawn[randomCardPiffle].firstname << " " << cardsPiffleDrawn[randomCardPiffle].lastname << " " << cardsPiffleDrawn[randomCardPiffle].power << " " << cardsPiffleDrawn[randomCardPiffle].resilience << " " << cardsPiffleDrawn[randomCardPiffle].boost << endl;
    usedCardsPiffleDrawn[randomCardPiffle] = true;

    // Plagiarist Chooses a card card
    int randomCardPlagiarist = Random(2);
    cout << " Player chooses " << cardsPlagiaristDrawn[randomCardPlagiarist].type << " " << cardsPlagiaristDrawn[randomCardPlagiarist].firstname << " " << cardsPlagiaristDrawn[randomCardPlagiarist].lastname << " " << cardsPlagiaristDrawn[randomCardPlagiarist].power << " " << cardsPlagiaristDrawn[randomCardPlagiarist].resilience << " " << cardsPlagiaristDrawn[randomCardPlagiarist].boost << endl;
    usedCardsPlagiaristDrawn[randomCardPlagiarist] = true;

    //Convert card stats to integers for use
    int piffleintpower = stoi(cardsPiffleDrawn[randomCardPiffle].power);

    // Make cards duel
    //Create Piffle Player
    SProfessor Piffle;
    Piffle.profName = "Piffle";
    Piffle.profPresrtige -= piffleintpower;

    cout << Piffle.profName << Piffle.profPresrtige << endl;

    //Convert card stats to integers for use
    int plagiaristintpower = stoi(cardsPlagiaristDrawn[randomCardPlagiarist].power);

    // Make cards duel
    //Create Plagiarist Player
    SProfessor Plagiarist;
    Plagiarist.profName = "Plagiarist";
    Plagiarist.profPresrtige -= plagiaristintpower;

    cout << Plagiarist.profName << Plagiarist.profPresrtige << endl;





    // Free the memory even though its pointless right now
    // Free the memory even though its pointless right now
    

    _CrtDumpMemoryLeaks(); // Memory Leak Detection

    // Game Finished
    GameOver* message = new GameOver;
    message->gameOver();

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

void readCardData(ifstream file, int num_cards, CCard* cards, string line) // FOR LATER
{
    // Read in the card data
    file.clear();
    file.seekg(0);
    for (int i = 0; i < num_cards; i++) {
        getline(file, line);
        stringstream ss(line);
        ss >> cards[i].type >> cards[i].firstname >> cards[i].lastname >> cards[i].power >> cards[i].resilience >> cards[i].boost;
    }

    // Example usage: print out the data
    for (int i = 0; i < num_cards; i++) {
        std::cout << cards[i].type << " " << cards[i].firstname << " " << cards[i].lastname << " " << cards[i].power << " " << cards[i].resilience << " " << cards[i].boost << endl;
    }
}
