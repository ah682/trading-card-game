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
int randomRange(int min, int max);

struct SProfessor
{
    string profName;
    int profPrestige = 30;
};

class CCard
{
public:
    string type;
    string firstname;
    string lastname;
    string power;
    string resilience;
    string boost;
};

class GameState
{
public:
    void startRound(int round);
    void gameStart();
    void gameOver(SProfessor winner, SProfessor loser);
    void cardsDuel(SProfessor &professor, string name, int cardPower, vector<CCard> cardDrawn, int randomCard);
    void fillDeck(ifstream &inFile, vector<CCard> &cards);
    void drawCard(vector<CCard> &cards, vector<CCard> &drawnCards, int &deckCounter, int &i, SProfessor name, vector<bool>& usedCards);
};

void GameState::gameStart()
{
    cout << "Welcome to U-Can't. Let the winnowing begin..." << endl;
}

void GameState::gameOver(SProfessor piffle, SProfessor plagiarist)
{

        
    if (piffle.profPrestige > plagiarist.profPrestige)
    {
            cout << "Game Over" << endl
            << plagiarist.profName << " prestige is " << plagiarist.profPrestige << " " << piffle.profName << " prestige is " << piffle.profPrestige << endl
            << piffle.profName << " wins";
    }
    else if (plagiarist.profPrestige > piffle.profPrestige)
    {
        cout << "Game Over" << endl
            << piffle .profName << " prestige is " << piffle.profPrestige << " " << plagiarist.profName << " prestige is " << plagiarist.profPrestige << endl
            << plagiarist.profName << " wins";
    }
    else if (piffle.profPrestige == plagiarist.profPrestige)
    {
        cout << "Game Over" << endl
            << piffle.profName << " prestige is " << piffle.profPrestige << " " << plagiarist.profName << " prestige is " << plagiarist.profPrestige << endl
            << " DRAW!";
    }
}

void GameState::startRound(int round)
{
    cout << "Round: " << round << endl;
}

void GameState::fillDeck(ifstream &inFile, vector<CCard> &cards)
{
    inFile.clear();
    inFile.seekg(0);

    string line;
    for (int i = 0; i < cards.size(); i++)
    {
        getline(inFile, line);
        stringstream ss(line);
        ss >> cards[i].type;
        if (cards[i].type == "1")
        {
            ss >> cards[i].firstname >> cards[i].lastname >> cards[i].power >> cards[i].resilience >> cards[i].boost;
        }
    }
}

void GameState::drawCard(vector<CCard> &cards, vector<CCard> &drawnCards, int &deckCounter, int &i, SProfessor name, vector<bool>& usedCards)
{
    int awesomeCounter = 0;
    for (int j = i; j < deckCounter; j++)
    {
        if (cards[j].type == "1" && usedCards[j] == false)
        {
            drawnCards.push_back(cards[j]);
            usedCards[j] = true;
            cout << "Player " << name.profName << " has drawn " << drawnCards.back().type << " " << drawnCards.back().firstname << " " << drawnCards.back().lastname << " " << drawnCards.back().power << " " << drawnCards.back().resilience << " " << drawnCards.back().boost << endl;
            
        }
        else
        {
            i++;
            deckCounter++;
            usedCards[j] = true;
        }
    }
}

void GameState::cardsDuel(SProfessor &professor, string name, int cardPower, vector<CCard> cardDrawn, int randomCard)
{
    professor.profName = name;
    professor.profPrestige -= cardPower;

    cout << cardDrawn[randomCard].type << " " << cardDrawn[randomCard].firstname << " " << cardDrawn[randomCard].lastname << " " << cardDrawn[randomCard].power << " " << cardDrawn[randomCard].resilience << " " << cardDrawn[randomCard].boost << " attacks ";
    cout << professor.profName << " Prestige is now " << professor.profPrestige << endl;
}

int main()
{
    // Genereates seed from read file
    int seed = readSeedFile("seed.txt");
    srand(seed);
    cout << "Seed Number: " << seed << endl;

    // Initialize data before commencing U-Can't

    GameState message;
    message.gameStart();

    ifstream filePlagiarist("plagiarist.txt");
    int num_cardsPlagiarist = 0;
    string linePlagiarist;

    ifstream filePiffle("piffle-paper.txt");
    int num_cardsPiffle = 0;
    string linePiffle;

    SProfessor Plagiarist;
    SProfessor Piffle;

    // Count the number of cards in the plagiarist file
    while (getline(filePlagiarist, linePlagiarist))
    {
        num_cardsPlagiarist++;
    }

    // Count the number of cards in the piffle file
    while (getline(filePiffle, linePiffle))
    {
        num_cardsPiffle++;
    }

    // Allocate memory for the cards
    vector<CCard> cardsPlagiarist(num_cardsPlagiarist);
    message.fillDeck(filePlagiarist, cardsPlagiarist);

    // Allocate memory for the cards
    vector<CCard> cardsPiffle(num_cardsPiffle);
    message.fillDeck(filePiffle, cardsPiffle);

    // Allocate memory for the cards
    vector<CCard> cardsPlagiaristDrawn;
    vector<CCard> cardsPiffleDrawn;

    // Allocate
    int deckCounter = 2;
    int i = 0;

    // Allocate
    vector<bool> checkUsedCardPlagiarist(48, false);
    vector<bool> checkUsedCardPiffle(48, false);

    // MAKE LOOP UNTIL PRESTIGE HITS 0
    do
    {
        // Allocate memory for the cards
        cout << "DRAWN CARDS Plagiarist" << endl;
        // Draws random card for plagarist and checks if works with cout
        message.drawCard(cardsPlagiarist, cardsPlagiaristDrawn, deckCounter, i, Plagiarist, checkUsedCardPlagiarist);

        cout << "DRAWN CARDS Piffle" << endl;
        message.drawCard(cardsPiffle, cardsPiffleDrawn, deckCounter, i, Piffle, checkUsedCardPiffle);

        // Piffle Chooses a card card THIS IS SUPPOSE TO BE RANDOM
        int randomCardPiffle = randomRange(cardsPiffleDrawn.size() - 2, cardsPiffleDrawn.size() - 1);

        cout << "Piffle chooses " << cardsPiffleDrawn[randomCardPiffle].type << " " << cardsPiffleDrawn[randomCardPiffle].firstname << " " << cardsPiffleDrawn[randomCardPiffle].lastname << " " << cardsPiffleDrawn[randomCardPiffle].power << " " << cardsPiffleDrawn[randomCardPiffle].resilience << " " << cardsPiffleDrawn[randomCardPiffle].boost << endl;
        // Plagiarist Chooses a card card THIS IS SUPPOSE TO BE RANDOM
        int randomCardPlagiarist = randomRange(cardsPlagiaristDrawn.size() - 2, cardsPlagiaristDrawn.size() - 1);
        cout << "Plagiarist chooses " << cardsPlagiaristDrawn[randomCardPlagiarist].type << " " << cardsPlagiaristDrawn[randomCardPlagiarist].firstname << " " << cardsPlagiaristDrawn[randomCardPlagiarist].lastname << " " << cardsPlagiaristDrawn[randomCardPlagiarist].power << " " << cardsPlagiaristDrawn[randomCardPlagiarist].resilience << " " << cardsPlagiaristDrawn[randomCardPlagiarist].boost << endl;

        // Convert card stats to integers to attack professor
        int piffleintpower = stoi(cardsPiffleDrawn[randomCardPiffle].power);

        // Make cards duel
        // Create Piffle Player
        message.cardsDuel(Piffle, "Piffle", piffleintpower, cardsPlagiaristDrawn, randomCardPlagiarist);


        // Convert card stats to integers for use
        int plagiaristintpower = stoi(cardsPlagiaristDrawn[randomCardPlagiarist].power);

        if (Plagiarist.profPrestige <= 0 || Piffle.profPrestige <= 0) {
            // Exit the loop when one of the players loses all their prestige
            break;
        }

        // Make cards duel
        // Create Plagiarist Player
        message.cardsDuel(Plagiarist, "Plagiarist", plagiaristintpower, cardsPiffleDrawn, randomCardPiffle);

        if (Plagiarist.profPrestige <= 0 || Piffle.profPrestige <= 0) {
            // Exit the loop when one of the players loses all their prestige
            break;
        }

    } while (Plagiarist.profPrestige > 0 && Piffle.profPrestige > 0);


    // Checks who is winner
    message.gameOver(Piffle, Plagiarist);
    

    // Memory Leak Detection
    _CrtDumpMemoryLeaks();

    return 0;
}

int Random(int max)
{
    return int(float(rand()) / (RAND_MAX + 1) * float(max));
}

int randomRange(int min, int max)
{
    return min + int(float(rand()) / (RAND_MAX + 1) * float(max - min + 1));
}

time_t readSeedFile(string filename)
{
    time_t seed_value = 0;

    // Read from the file
    ifstream file_stream(filename);
    if (file_stream.is_open())
    {
        string line;
        if (getline(file_stream, line))
        {
            seed_value = stoi(line);
        }
        file_stream.close();
    }
    else
    {
        std::cout << "Unable to open file " << filename << '\n';
    }

    return seed_value;
}
