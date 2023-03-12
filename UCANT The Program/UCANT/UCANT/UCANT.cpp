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
    int profPrestige = 30;
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

class GameState {
public:
    void startRound(int round);
    void gameStart();
    void gameOver();
    void cardsDuel();
    void fillDeck(ifstream& inFile, vector<CCard>& cards);
    void drawCard(vector<CCard>& cards, vector<CCard>& drawnCards);
};

void GameState::gameStart() {
    cout << "Welcome to U-Can't. Let the winnowing begin..." << endl;
}

void GameState::gameOver() {
    cout << "Game Over!" << endl << "player " << " " << "wins";
}

void GameState::startRound(int round)
{
    cout << "Round: " << round << endl;
}

void GameState::fillDeck(ifstream& inFile, vector<CCard>& cards) {
    inFile.clear();
    inFile.seekg(0);

    string line;
    for (int i = 0; i < cards.size(); i++) {
        getline(inFile, line);
        stringstream ss(line);
        ss >> cards[i].type;
        if (cards[i].type == "1") {
            ss >> cards[i].firstname >> cards[i].lastname >> cards[i].power >> cards[i].resilience >> cards[i].boost;
        }
    }
}

void GameState::drawCard(vector<CCard>& cards, vector<CCard>& drawnCards)
{
    bool usedCards[48] = { false };
    int deckCounter = 2;
    for (int i = 0; i < 2; i++) {
        if (cards[i].type == "1") {
            drawnCards.push_back(cards[i]);
            // Checks if works
            cout << "Player has drawn " << drawnCards.back().type << " " << drawnCards.back().firstname << " " << drawnCards.back().lastname << " " << drawnCards.back().power << " " << drawnCards.back().resilience << " " << drawnCards.back().boost << endl;
            usedCards[i] = true;
        }
    }
    deckCounter += 2;
}

void GameState::cardsDuel()
{

}

int main() {
    // Genereates seed for Nick WORKS
    int seed = readSeedFile("seed.txt");
    srand(seed);
    cout << "Seed Number: " << seed << endl;

    // Generates random number for me WORKS
    int testrand = Random(48);
    cout << "Random Number Spawned with Random Function " << testrand << endl;

    GameState message;
    message.gameStart();

    ifstream filePlagiarist("plagiarist.txt");
    int num_cardsPlagiarist = 0;
    string linePlagiarist;

    // Count the number of cards in the plagiarist file
    while (getline(filePlagiarist, linePlagiarist)) {
        num_cardsPlagiarist++;
    }

    // Allocate memory for the cards
    vector<CCard> cardsPlagiarist(num_cardsPlagiarist);
    message.fillDeck(filePlagiarist, cardsPlagiarist);

    ifstream filePiffle("piffle-paper.txt");
    int num_cardsPiffle = 0;
    string linePiffle;

    // Count the number of cards in the plagiarist file
    while (getline(filePiffle, linePiffle)) {
        num_cardsPiffle++;
    }

    cout << "NUM CARDS PIFFLE" << num_cardsPiffle << endl;

    cout << endl << endl << endl << endl << endl << endl;
    // Allocate memory for the cards
    vector<CCard> cardsPiffle(num_cardsPiffle);
    message.fillDeck(filePiffle, cardsPiffle);

    
    // Draws random card for piffle and checks if works with cout
    cout << endl << endl << endl << endl << endl;
    cout << "DRAWN CARDS Piffle" << endl << endl << endl << endl << endl;
    vector<CCard> cardsPiffleDrawn;
    message.drawCard(cardsPiffle, cardsPiffleDrawn);

    // Draws random card for plagarist and checks if works with cout
    cout << endl << endl << endl << endl << endl;
    cout << "DRAWN CARDS Plagiarist" << endl << endl << endl << endl << endl;
    vector<CCard> cardsPlagiaristDrawn;
    message.drawCard(cardsPlagiarist, cardsPlagiaristDrawn);

    // Piffle Chooses a card card THIS IS SUPPOSE TO BE RANDOM
    int randomCardPiffle = Random(2);
    cout << " Piffle chooses " << cardsPiffleDrawn[randomCardPiffle].type << " " << cardsPiffleDrawn[randomCardPiffle].firstname << " " << cardsPiffleDrawn[randomCardPiffle].lastname << " " << cardsPiffleDrawn[randomCardPiffle].power << " " << cardsPiffleDrawn[randomCardPiffle].resilience << " " << cardsPiffleDrawn[randomCardPiffle].boost << endl;

    // Plagiarist Chooses a card card THIS IS SUPPOSE TO BE RANDOM
    int randomCardPlagiarist = Random(2);
    cout << "Plagiarist draws " << cardsPlagiaristDrawn[randomCardPlagiarist].type << " " << cardsPlagiaristDrawn[randomCardPlagiarist].firstname << " " << cardsPlagiaristDrawn[randomCardPlagiarist].lastname << " " << cardsPlagiaristDrawn[randomCardPlagiarist].power << " " << cardsPlagiaristDrawn[randomCardPlagiarist].resilience << " " << cardsPlagiaristDrawn[randomCardPlagiarist].boost << endl;

    //Convert card stats to integers to attack professor
    int piffleintpower = stoi(cardsPiffleDrawn[randomCardPiffle].power);

    // Make cards duel
    //Create Piffle Player
    SProfessor Piffle;
    Piffle.profName = "Piffle";
    Piffle.profPrestige -= piffleintpower;

    cout << cardsPlagiaristDrawn[randomCardPlagiarist].type << " " << cardsPlagiaristDrawn[randomCardPlagiarist].firstname << " " << cardsPlagiaristDrawn[randomCardPlagiarist].lastname << " " << cardsPlagiaristDrawn[randomCardPlagiarist].power << " " << cardsPlagiaristDrawn[randomCardPlagiarist].resilience << " " << cardsPlagiaristDrawn[randomCardPlagiarist].boost << " attacks ";
    cout << Piffle.profName << " Prestige is now " << Piffle.profPrestige << endl;

    //Convert card stats to integers for use
    int plagiaristintpower = stoi(cardsPlagiaristDrawn[randomCardPlagiarist].power);

    // Make cards duel
    //Create Plagiarist Player
    SProfessor Plagiarist;
    Plagiarist.profName = "Plagiarist";
    Plagiarist.profPrestige -= plagiaristintpower;
    
    cout << cardsPiffleDrawn[randomCardPiffle].type << " " << cardsPiffleDrawn[randomCardPiffle].firstname << " " << cardsPiffleDrawn[randomCardPiffle].lastname << " " << cardsPiffleDrawn[randomCardPiffle].power << " " << cardsPiffleDrawn[randomCardPiffle].resilience << " " << cardsPiffleDrawn[randomCardPiffle].boost << " attacks ";
    cout << Plagiarist.profName << " Prestige is now " << Plagiarist.profPrestige << endl;

    // Game Finished
    message.gameOver();

    // Memory Leak Detection
    _CrtDumpMemoryLeaks();

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
