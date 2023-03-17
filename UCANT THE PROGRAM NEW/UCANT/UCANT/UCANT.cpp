// UCANT.cpp

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

class CStudent : public CCard
{
public:

};

class GameState
{
public:
    void startRound(int round);
    void gameStart();
    void gameOver(SProfessor winner, SProfessor loser);
    void cardsDuel(vector<CCard*>& table, vector<CCard*>& tableAttacker, SProfessor &professor, string name, vector<CCard*> cardDrawn, int randomCard);
    void cardsDuelCards();
    void fillDeck(ifstream &inFile, vector<CCard*> &cards, vector<CStudent*> &cardsStudent);
    void drawCard(vector<CCard*> &cards, vector<CCard*> &drawnCards, int &deckCounter, int &i, SProfessor name, vector<bool*>& usedCards);
    void tableCard(vector <CCard*> &table, vector<CCard*> &cardsDrawn, SProfessor name, string professor, int randomCard);
};


void GameState::tableCard(vector<CCard*> &table, vector<CCard*> &cardsDrawn, SProfessor name, string professor, int randomCard)
{
    name.profName = professor;
    if (cardsDrawn[randomCard]->type == "1")
    {
        table.push_back(cardsDrawn[randomCard]);
    }

    // Shows cards placed on table
    cout << name.profName << " cards on table " << endl;
    for (int i = 0; i < table.size(); i++) {
        cout << table[i]->type << " " << table[i]->firstname << " " << table[i]->lastname << " " << table[i]->power << " " << table[i]->power << " " << table[i]->resilience << table[i]->boost << endl;
        if (i > table.size() - table.size() + 1)
        {
            break;
        }
    }
}
void GameState::gameStart()
{
    cout << "Welcome to U-Can't. Let the winnowing begin..." << endl;
}

void GameState::gameOver(SProfessor piffle, SProfessor plagiarist)
{


    if (piffle.profPrestige > plagiarist.profPrestige)
    {
        cout << "Game Over" << endl;
        if (plagiarist.profPrestige < 0)
        {
            plagiarist.profPrestige = 0;
        }
        cout << plagiarist.profName << " prestige is " << plagiarist.profPrestige << " " << piffle.profName << " prestige is " << piffle.profPrestige << endl
            << piffle.profName << " wins";
    }
    else if (plagiarist.profPrestige > piffle.profPrestige)
    {
        cout << "Game Over" << endl;
        if (piffle.profPrestige < 0)
        {
            piffle.profPrestige = 0;
        }
        cout << piffle.profName << " prestige is " << piffle.profPrestige << " " << plagiarist.profName << " prestige is " << plagiarist.profPrestige << endl
            << plagiarist.profName << " wins";
    }
}

void GameState::startRound(int round)
{
    cout << "Round: " << round << endl;
}

void GameState::fillDeck(ifstream &inFile, vector<CCard*> &cards, vector<CStudent*> &cardsStudent)
{
    inFile.clear();
    inFile.seekg(0);

    string line;
    for (int i = 0; i < cards.size(); i++)
    {
        if (getline(inFile, line)) {
            stringstream ss(line);
            ss >> cards[i]->type >> cards[i]->firstname >> cards[i]->lastname >> cards[i]->power >> cards[i]->resilience >> cards[i]->boost;
            if (cardsStudent[i]->type == "1")
            {
                ss >> cardsStudent[i]->type >> cardsStudent[i]->firstname >> cardsStudent[i]->lastname >> cardsStudent[i]->power >> cardsStudent[i]->resilience >> cardsStudent[i]->boost;
            }
        }
        
    }
}

void GameState::drawCard(vector<CCard*>& cards, vector<CCard*>& drawnCards, int& deckCounter, int& i, SProfessor name, vector<bool*>& usedCards)
{
    int awesomeCounter = 0;
    for (int j = i; j < cards.size(); j++)
    {
        if (*usedCards[j] == false)
        {
            drawnCards.push_back(cards[j]);
            *usedCards[j] = true;
            cout << "Player " << name.profName << " has drawn " << drawnCards.back()->type << " " << drawnCards.back()->firstname << " " << drawnCards.back()->lastname << " " << drawnCards.back()->power << " " << drawnCards.back()->resilience << " " << drawnCards.back()->boost << endl;
        }
        else
        {
            i++;
            deckCounter++;
            *usedCards[j] = true;
        }
    }
}

//Prof name is the one getting attacked
void GameState::cardsDuel(vector<CCard*>& tableAttacked, vector<CCard*>& tableAttacker, SProfessor& professor, string name, vector<CCard*> cardDrawn, int randomCard)
{
    professor.profName = name;
    int cardPower = 0;
    int cardResilience = 0;
    int j = tableAttacker.size() - 1;

    for (int i = tableAttacked.size() - 1; i >= 0 && j >= 0; i--)
    {
        cardPower = stoi(tableAttacker[j]->power);

        if (tableAttacked[i]->resilience != "") {
            cardResilience = stoi(tableAttacked[i]->resilience);
        }

        if (tableAttacked.size() > 0)
        {
            if (cardResilience > 0) {
                cardResilience -= cardPower;
                string cardResilienceString = to_string(cardResilience);
                tableAttacked[i]->resilience = cardResilienceString;
            }
            if (cardResilience <= 0) {
                cout << "CARD KILLED Name:" << tableAttacked[i]->firstname << " by player x" << endl;
                tableAttacked.erase(tableAttacked.begin() + i);
            }
        }
        if (tableAttacked.size() <= 0) {
            professor.profPrestige -= cardPower;
        }
        j--;
    }

    cout << professor.profName << " Prestige is now " << professor.profPrestige << endl;
}

void GameState::cardsDuelCards()
{

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

    int num_cardsPlagiarist = 0;
    int num_cardsPiffle = 0;

    ifstream filePlagiarist("plagiarist.txt");
    string linePlagiarist;

    ifstream filePiffle("piffle-paper.txt");
    string linePiffle;

    SProfessor Plagiarist;
    SProfessor Piffle;

    // Count the number of cards in the plagiarist file
    while (getline(filePlagiarist, linePlagiarist))
    {
        num_cardsPlagiarist++ + 200;
    }

    // Count the number of cards in the piffle file
    while (getline(filePiffle, linePiffle))
    {
        num_cardsPiffle++ + 200;
    }


    // Allocate memory for the cards
    vector<CCard*> cardsPiffle(num_cardsPiffle, nullptr);

    for (int i = 0; i < num_cardsPiffle; i++) {
        CCard* cardTest1 = new CCard(); // Allocate memory for the card object
        cardsPiffle[i] = cardTest1; // Assign the pointer to point to the newly allocated memory
    }

    // Allocate memory for the cards
    vector<CCard*> cardsPlagiarist(num_cardsPlagiarist, nullptr);

    for (int i = 0; i < num_cardsPlagiarist; i++) {
        CCard* cardTest2 = new CCard(); // Allocate memory for the card object
        cardsPlagiarist[i] = cardTest2; // Assign the pointer to point to the newly allocated memory
    }

    // Allocate memory for the cards
    vector<CStudent*> cardsPlagiaristStudents(num_cardsPlagiarist, nullptr);

    for (int i = 0; i < num_cardsPlagiarist; i++) {
        CStudent* cardTest6 = new CStudent(); // Allocate memory for the card object
        cardsPlagiaristStudents[i] = cardTest6; // Assign the pointer to point to the newly allocated memory
    }

    // Allocate memory for the cards
    vector<CStudent*> cardsPiffleStudents(num_cardsPiffle, nullptr);

    for (int i = 0; i < num_cardsPiffle; i++) {
        CStudent* cardTest7 = new CStudent(); // Allocate memory for the card object
        cardsPiffleStudents[i] = cardTest7; // Assign the pointer to point to the newly allocated memory
    }

    // Allocate memory for the cards
    vector<CCard*> cardsPlagiaristDrawn;
    vector<CCard*> cardsPiffleDrawn;

    vector<CStudent*> cardsPlagiaristStudentsDrawn;
    vector<CStudent*> cardsPiffleStudentsDrawn;

    vector<CCard*> tablePlagiarist;
    vector<CCard*> tablePiffle;

    vector<CCard*> graveyardPlagiarist; //USE LATER
    vector<CCard*> graveyardPiffle; //USE LATER

    message.fillDeck(filePlagiarist, cardsPlagiarist, cardsPlagiaristStudents);
    message.fillDeck(filePiffle, cardsPiffle, cardsPiffleStudents);

    // Allocate
    int deckCounter = 2;
    int i = 0;

    // Allocate
    vector<bool*> checkUsedCardPlagiarist(200, nullptr);

    for (int i = 0; i < 200; i++) {
        bool* cardTest3 = new bool(false); // Allocate memory for the card object
        checkUsedCardPlagiarist[i] = cardTest3; // Assign the pointer to point to the newly allocated memory
    }

    vector<bool*> checkUsedCardPiffle(200, nullptr);

    for (int i = 0; i < 200; i++) {
        bool* cardTest4 = new bool(false); // Allocate memory for the card object
        checkUsedCardPiffle[i] = cardTest4; // Assign the pointer to point to the newly allocated memory
    }

    // MAKE LOOP UNTIL PRESTIGE HITS 0
    do
    {
        // Allocate memory for the cards
        cout << "DRAWN CARDS Plagiarist" << endl;
        // Draws random card for plagiarist and checks if works with cout
        message.drawCard(cardsPlagiarist, cardsPlagiaristDrawn, deckCounter, i, Plagiarist, checkUsedCardPlagiarist);

        cout << "DRAWN CARDS Piffle" << endl;
        message.drawCard(cardsPiffle, cardsPiffleDrawn, deckCounter, i, Piffle, checkUsedCardPiffle);

        // Piffle Chooses a card card THIS IS SUPPOSE TO BE RANDOM
        int randomCardPiffle = randomRange(cardsPiffleDrawn.size() - 2, cardsPiffleDrawn.size() - 1);

        cout << "Piffle chooses " << cardsPiffleDrawn[randomCardPiffle]->type << " " << cardsPiffleDrawn[randomCardPiffle]->firstname << " " << cardsPiffleDrawn[randomCardPiffle]->lastname << " " << cardsPiffleDrawn[randomCardPiffle]->power << " " << cardsPiffleDrawn[randomCardPiffle]->resilience << " " << cardsPiffleDrawn[randomCardPiffle]->boost << endl;
        // Plagiarist Chooses a card card THIS IS SUPPOSE TO BE RANDOM
        int randomCardPlagiarist = randomRange(cardsPlagiaristDrawn.size() - 2, cardsPlagiaristDrawn.size() - 1);
        cout << "Plagiarist chooses " << cardsPlagiaristDrawn[randomCardPlagiarist]->type << " " << cardsPlagiaristDrawn[randomCardPlagiarist]->firstname << " " << cardsPlagiaristDrawn[randomCardPlagiarist]->lastname << " " << cardsPlagiaristDrawn[randomCardPlagiarist]->power << " " << cardsPlagiaristDrawn[randomCardPlagiarist]->resilience << " " << cardsPlagiaristDrawn[randomCardPlagiarist]->boost << endl;

        //Prints table on cards for specific player
        message.tableCard(tablePiffle, cardsPiffleDrawn, Piffle, "Piffle", randomCardPiffle);
        message.tableCard(tablePlagiarist, cardsPlagiaristDrawn, Plagiarist, "Plagiarist", randomCardPlagiarist);

        // Convert card stats to integers to attack professor
     //   int piffleintpower = stoi(cardsPiffleDrawn[randomCardPiffle]->power);

       // int piffleintresilience = 0;
       // if (cardsPiffleDrawn[randomCardPiffle]->resilience != "") {
       //     piffleintresilience = stoi(cardsPiffleDrawn[randomCardPiffle]->resilience);
       // }
        // Convert card stats to integers for use
        //int plagiaristintpower = stoi(cardsPlagiaristDrawn[randomCardPlagiarist]->power);
        // Convert card stats to integers for use
        //int plagiaristintresilience = 0;
        //if (cardsPlagiaristDrawn[randomCardPlagiarist]->resilience != "") {
        //    plagiaristintresilience = stoi(cardsPlagiaristDrawn[randomCardPlagiarist]->resilience);
        //}

        // Make cards duel
        // Create Piffle Player piffle gets attacked
        message.cardsDuel(tablePiffle, tablePlagiarist, Piffle, "Piffle", cardsPlagiaristDrawn, randomCardPlagiarist);

        if (Plagiarist.profPrestige <= 0 || Piffle.profPrestige <= 0) {
            // Exit the loop when one of the players loses all their prestige
            break;
        }

        // Make cards duel
        // Create Plagiarist Player plagiarist gets attacked
        message.cardsDuel(tablePlagiarist, tablePiffle, Plagiarist, "Plagiarist", cardsPiffleDrawn, randomCardPiffle);

        if (Plagiarist.profPrestige <= 0 || Piffle.profPrestige <= 0) {
            // Exit the loop when one of the players loses all their prestige
            break;
        }

    } while (Plagiarist.profPrestige > 0 && Piffle.profPrestige > 0);

    // Checks who is winner
    message.gameOver(Piffle, Plagiarist);

    // Close files
    filePlagiarist.close();
    filePiffle.close();

    // De-allocate memory
    
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
