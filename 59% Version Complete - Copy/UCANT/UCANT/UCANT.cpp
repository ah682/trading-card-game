// UCan't The Winnowing
// Created by: Damnian Phillips

// Memory Leak Detection
#define _CRTDBG_MAP_ALLOC
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <sstream>
#include <crtdbg.h>
#include <iostream>
#include <cstdlib>

using namespace std;

const int G_MAX_CARDS = 48;
const int G_CHOICE_ONE = 1;
const int G_CHOICE_TWO = 2;

time_t  seedValueFromFile(string filePath);
int Random(int max);
int Random(int min, int max);

struct SProfessor
{
    string profName;
    int profPrestige = 30;
};

class CCard
{
public:
    // Defines structore of a card
    string type;
    string namef;
    string namel;
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
    void cardsDuel(vector<CCard*>& table, vector<CCard*>& tableAttacker, SProfessor &professorAttacked, SProfessor& professorAttacker, string name, string nametwo, vector<CCard*> cardDrawn, int randomCard);
    void cardsDuelCards();
    void fillDeck(ifstream &inFile, vector<CCard*> &cards, vector<CStudent*> &cardsStudent);
    void drawCard(vector<CCard*> &cards, vector<CCard*> &drawnCards, int &deckCounter, int &i, SProfessor name, vector<bool*>& usedCards);
    void tableCard(vector <CCard*> &table, vector<CCard*> &cardsDrawn, SProfessor name, string professor, int randomCard);
    void plagiarismHearing(vector<CCard*>& cardsDrawn, vector <CCard*> &plagiarism, vector<CCard*>& tableAttacked, int randomCard, SProfessor& professorAttacked, SProfessor& professorAttacker, string attackedName, string attackerName, int randomChoice);
    void courseAccreditation(vector<CCard*>& cardsDrawn, vector <CCard*>& accreditation, vector<CCard*>& tableAttacked, int randomCard, SProfessor& professorAttacked, SProfessor& professorAttacker, string attackedName, string attackerName);
};

void GameState::plagiarismHearing(vector<CCard*>& cardsDrawn, vector <CCard*> &plagiarism, vector<CCard*>& tableAttacked, int randomCard, SProfessor& professorAttacked, SProfessor& professorAttacker, string attackedName, string attackerName, int randomChoice)
{
    if (cardsDrawn[randomCard]->type == "2" && cardsDrawn[randomCard]->resilience != "-99")
    {
        plagiarism.push_back(cardsDrawn[randomCard]);
    }

    professorAttacked.profName = attackedName;
    professorAttacker.profName = attackerName;
    
    int cardPower = 3;
    int cardResilience = 0;

    for (int i = 0; i < plagiarism.size(); i++)
    {
        if (!tableAttacked.empty()) {
            CCard* tableAttackede = tableAttacked[tableAttacked.size() - 1];
            if (!tableAttackede->resilience.empty()) {
                cardResilience = stoi(tableAttackede->resilience);
            }

            if (randomChoice == 1)
            {
                if (cardResilience > 0) {
                    cardResilience -= cardPower;
                    string cardResilienceString = to_string(cardResilience);
                    tableAttacked[tableAttacked.size() - 1]->resilience = cardResilienceString;
                }
                if (cardResilience <= 0) {
                    cout << "CARD KILLED Name:" << tableAttackede->namef << " by player " << professorAttacker.profName << '\n';
                    tableAttackede->resilience = "-99";
                    tableAttacked.erase(tableAttacked.end() - 1);
                }
            }
            
            if (randomChoice == 2) {
                professorAttacked.profPrestige -= cardPower;
            }
            if (professorAttacked.profPrestige < 0)
            {
                professorAttacked.profPrestige = 0;
            }
            cout << professorAttacked.profName << " Prestige is now " << professorAttacked.profPrestige << '\n';
        }
    }
}

void GameState::courseAccreditation(vector<CCard*>& cardsDrawn, vector <CCard*>& accreditation, vector<CCard*>& tableAttacked, int randomCard, SProfessor& professorAttacked, SProfessor& professorAttacker, string attackedName, string attackerName)
{
    int cardPower = 1;
    int cardResilience = 0;

    if (cardsDrawn[randomCard]->type == "3" && cardsDrawn[randomCard]->resilience != "-99")
    {
        accreditation.push_back(cardsDrawn[randomCard]);
    }

    professorAttacked.profName = attackedName;
    professorAttacker.profName = attackerName;

    for (int i = 0; i < accreditation.size(); i++)
    {
        for (int j = 0; j < tableAttacked.size() - 1; j++)
        {
           cardResilience = stoi(tableAttacked[j]->resilience);
           cardResilience -= cardPower;
           string cardResilienceString = to_string(cardResilience);
           tableAttacked[j]->resilience = cardResilienceString;

           if (cardResilience <= 0) {
               cout << "CARD KILLED Name:" << tableAttacked[j]->namef << " by player " << professorAttacker.profName << '\n';
               tableAttacked[j]->resilience = "-99";
               tableAttacked.erase(tableAttacked.begin() + j);
           }
        }

        professorAttacked.profPrestige -= cardPower;

        if (professorAttacked.profPrestige < 0)
        {
          professorAttacked.profPrestige = 0;
        }
        cout << professorAttacked.profName << " Prestige is now " << professorAttacked.profPrestige << '\n';
        
    }
}

void GameState::tableCard(vector<CCard*> &table, vector<CCard*> &cardsDrawn, SProfessor name, string professor, int randomCard)
{
    name.profName = professor;
    if (cardsDrawn[randomCard]->type == "1" && cardsDrawn[randomCard]->resilience != "-99")
    {
        table.push_back(cardsDrawn[randomCard]);
    }
    
    // Shows cards placed on table
    cout << name.profName << " cards on table " << endl;
    for (int i = 0; i < table.size(); i++) {
        cout << table[i]->type << " " << table[i]->namef << " " << table[i]->namel << " " << table[i]->power << " " << table[i]->power << " " << table[i]->resilience << table[i]->boost << '\n';
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

void GameState::gameOver(SProfessor pifflepaper, SProfessor plagiarist)
{


    if (pifflepaper.profPrestige > plagiarist.profPrestige)
    {
        cout << "Game Over" << endl;
        if (plagiarist.profPrestige < 0)
        {
            plagiarist.profPrestige = 0;
        }
        cout << plagiarist.profName << " prestige is " << plagiarist.profPrestige << " " << pifflepaper.profName << " prestige is " << pifflepaper.profPrestige << '\n'
            << pifflepaper.profName << " wins";
    }
    else if (plagiarist.profPrestige > pifflepaper.profPrestige)
    {
        cout << "Game Over" << '\n';
        if (pifflepaper.profPrestige < 0)
        {
            pifflepaper.profPrestige = 0;
        }
        cout << pifflepaper.profName << " prestige is " << pifflepaper.profPrestige << " " << plagiarist.profName << " prestige is " << plagiarist.profPrestige << '\n'
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
            ss >> cards[i]->type >> cards[i]->namef >> cards[i]->namel >> cards[i]->power >> cards[i]->resilience >> cards[i]->boost;
            if (cardsStudent[i]->type == "1")
            {
                ss >> cardsStudent[i]->type >> cardsStudent[i]->namef >> cardsStudent[i]->namel >> cardsStudent[i]->power >> cardsStudent[i]->resilience >> cardsStudent[i]->boost;
            }
        }
        
    }
}

void GameState::drawCard(vector<CCard*>& cards, vector<CCard*>& drawnCards, int& deckCounter, int& i, SProfessor name, vector<bool*>& usedCards)
{
    int awesomeCounter = 0;
    for (int j = i; j < deckCounter; j++)
    {
        if (i == G_MAX_CARDS)
        {
            break;
        }
        if (*usedCards[j] == false)
        {
            drawnCards.push_back(cards[j]);
            *usedCards[j] = true;
            cout << "Player " << name.profName << " has drawn " << drawnCards.back()->type << " " << drawnCards.back()->namef << " " << drawnCards.back()->namel << " " << drawnCards.back()->power << " " << drawnCards.back()->resilience << " " << drawnCards.back()->boost << '\n';
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
void GameState::cardsDuel(vector<CCard*>& tableAttacked, vector<CCard*>& tableAttacker, SProfessor& professorAttacked, SProfessor& professorAttacker, string name, string nametwo, vector<CCard*> cardDrawn, int randomCard)
{
    professorAttacked.profName = name;
    professorAttacker.profName = nametwo;

    int cardPower = 0;
    int cardResilience = 0;
    int minuses = 0;

    if (cardResilience < 0)
    {
        minuses = cardResilience;
    }

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
                cout << "CARD KILLED Name:" << tableAttacked[i]->namef << " by player " << professorAttacker.profName << '\n';
                tableAttacked[i]->resilience = "-99";
                tableAttacked.erase(tableAttacked.begin() + i);
            }
        }
        if (tableAttacked.size() <= 0) {
            professorAttacked.profPrestige -= cardPower;
        }
        j--;
    }

    if (professorAttacked.profPrestige < 0)
    {
        professorAttacked.profPrestige = 0;
    }
    cout << professorAttacked.profName << " Prestige is now " << professorAttacked.profPrestige << '\n';
}

void GameState::cardsDuelCards()
{

}

int main()
{
    // Genereates seed from seeding file and sets it by srand
    int seed = seedValueFromFile("seed.txt");
    srand(seed);

    // Initialises data before commencing combat of UCan't
    GameState message;
    message.gameStart();

    // Counts number of cards for each professor
    int numCardsPlagiarist = 0;
    int numCardsPifflePaper = 0;

    // Open the files
    ifstream fPlagiarist("plagiarist.txt");
    string lineCountPlagiarist;
    ifstream fPifflePaper("piffle-paper.txt");
    string lineCountPifflePaper;

    // Object type of SProfessor for the two professors
    SProfessor Plagiarist;
    SProfessor PifflePaper;

    // Count the number of cards in the plagiarist file
    while (getline(fPlagiarist, lineCountPlagiarist))
    {
        numCardsPlagiarist++ + 200;
    }

    // Count the number of cards in the piffle file
    while (getline(fPifflePaper, lineCountPifflePaper))
    {
        numCardsPifflePaper++ + 200;
    }


    // Allocate memory for the cards
    vector<CCard*> cardsPiffle(numCardsPifflePaper, nullptr);

    for (int i = 0; i < numCardsPifflePaper; i++) {
        CCard* cardTest1 = new CCard(); // Allocate memory for the card object
        cardsPiffle[i] = cardTest1; // Assign the pointer to point to the newly allocated memory
    }

    // Allocate memory for the cards
    vector<CCard*> cardsPlagiarist(numCardsPlagiarist, nullptr);

    for (int i = 0; i < numCardsPlagiarist; i++) {
        CCard* cardTest2 = new CCard(); // Allocate memory for the card object
        cardsPlagiarist[i] = cardTest2; // Assign the pointer to point to the newly allocated memory
    }

    // Allocate memory for the cards
    vector<CStudent*> cardsPlagiaristStudents(numCardsPlagiarist, nullptr);

    for (int i = 0; i < numCardsPlagiarist; i++) {
        CStudent* cardTest6 = new CStudent(); // Allocate memory for the card object
        cardsPlagiaristStudents[i] = cardTest6; // Assign the pointer to point to the newly allocated memory
    }

    // Allocate memory for the cards
    vector<CStudent*> cardsPiffleStudents(numCardsPifflePaper, nullptr);

    for (int i = 0; i < numCardsPifflePaper; i++) {
        CStudent* cardTest7 = new CStudent(); // Allocate memory for the card object
        cardsPiffleStudents[i] = cardTest7; // Assign the pointer to point to the newly allocated memory
    }

    // Allocate memory for the cards
    vector<CCard*> cardsPlagiaristDrawn;
    vector<CCard*> cardsPifflePaperDrawn;
    vector<CStudent*> cardsPlagiaristStudentsDrawn;
    vector<CStudent*> cardsPiffleStudentsDrawn;
    vector<CCard*> tablePlagiarist;
    vector<CCard*> tablePifflePaper;
    vector<CCard*> plagiarismHearingPlagiarist; 
    vector<CCard*> plagiarismHearingPifflePaper; 
    vector<CCard*> courseAccreditationPlagiarist;
    vector<CCard*> courseAccreditationPifflePaper;

    // Fills Piffle-Papers and Plagiarist decks with cards
    message.fillDeck(fPlagiarist, cardsPlagiarist, cardsPlagiaristStudents);
    message.fillDeck(fPifflePaper, cardsPiffle, cardsPiffleStudents);

    // Iterators for the deck specifically with round increasing
    int deckIteration = 2;
    int i = 0;

    // Allocate
    vector<bool*> checkUsedCardPlagiarist(G_MAX_CARDS, nullptr);

    for (int i = 0; i < G_MAX_CARDS; i++) {
        bool* cardTest3 = new bool(false); // Allocate memory for the card object
        checkUsedCardPlagiarist[i] = cardTest3; // Assign the pointer to point to the newly allocated memory
    }

    vector<bool*> checkUsedCardPiffle(G_MAX_CARDS, nullptr);

    for (int i = 0; i < G_MAX_CARDS; i++) {
        bool* cardTest4 = new bool(false); // Allocate memory for the card object
        checkUsedCardPiffle[i] = cardTest4; // Assign the pointer to point to the newly allocated memory
    }

    // do while loop until prestige of one player game <= 0
    do
    {
        int randomCardPiffle = 0;
        int randomCardPlagiarist = 0;
        // Allocate memory for the cards
        
        // Draws random card for plagiarist and checks if works with cout
        if (i < G_MAX_CARDS)
        {
            cout << "DRAWN CARDS Plagiarist" << '\n';
            message.drawCard(cardsPlagiarist, cardsPlagiaristDrawn, deckIteration, i, Plagiarist, checkUsedCardPlagiarist);

            cout << "DRAWN CARDS Piffle-Paper" << '\n';

            message.drawCard(cardsPiffle, cardsPifflePaperDrawn, deckIteration, i, PifflePaper, checkUsedCardPiffle);


            // Piffle Chooses a card card THIS IS SUPPOSE TO BE RANDOM
            randomCardPiffle = Random(cardsPifflePaperDrawn.size() - 2, cardsPifflePaperDrawn.size() - 1);

            cout << "Piffle-Paper chooses " << cardsPifflePaperDrawn[randomCardPiffle]->type << " " << cardsPifflePaperDrawn[randomCardPiffle]->namef << " " << cardsPifflePaperDrawn[randomCardPiffle]->namel << " " << cardsPifflePaperDrawn[randomCardPiffle]->power << " " << cardsPifflePaperDrawn[randomCardPiffle]->resilience << " " << cardsPifflePaperDrawn[randomCardPiffle]->boost << endl;
            // Plagiarist Chooses a card card THIS IS SUPPOSE TO BE RANDOM
            randomCardPlagiarist = Random(cardsPlagiaristDrawn.size() - 2, cardsPlagiaristDrawn.size() - 1);
            cout << "Plagiarist chooses " << cardsPlagiaristDrawn[randomCardPlagiarist]->type << " " << cardsPlagiaristDrawn[randomCardPlagiarist]->namef << " " << cardsPlagiaristDrawn[randomCardPlagiarist]->namel << " " << cardsPlagiaristDrawn[randomCardPlagiarist]->power << " " << cardsPlagiaristDrawn[randomCardPlagiarist]->resilience << " " << cardsPlagiaristDrawn[randomCardPlagiarist]->boost << endl;
        }

        //Prints table on cards for Piffle-Paper
        message.tableCard(tablePifflePaper, cardsPifflePaperDrawn, PifflePaper, "Piffle-Paper", randomCardPiffle);
        //Prints table on cards for Plagiarist
        message.tableCard(tablePlagiarist, cardsPlagiaristDrawn, Plagiarist, "Plagiarist", randomCardPlagiarist);

        
        // Piffle-Paper's minions gets attacked by Plagiarist's minions
        message.cardsDuel(tablePifflePaper, tablePlagiarist, PifflePaper, Plagiarist, "Piffle-Paper", "Plagiarist", cardsPlagiaristDrawn, randomCardPlagiarist);


        int randomRangeOneorTwo = Random(G_CHOICE_ONE, G_CHOICE_TWO);
        //Piffle Gets Attacked
        message.plagiarismHearing(cardsPlagiaristDrawn, plagiarismHearingPlagiarist, tablePifflePaper, randomCardPlagiarist, PifflePaper, Plagiarist, "Piffle-Paper", "Plagiarist", randomRangeOneorTwo);
        message.courseAccreditation(cardsPlagiaristDrawn, courseAccreditationPlagiarist, tablePifflePaper, randomCardPlagiarist, PifflePaper, Plagiarist, "Piffle-Paper", "Plagiarist");

        // Make cards duel
        // Create Plagiarist Player plagiarist gets attacked
        message.cardsDuel(tablePlagiarist, tablePifflePaper, Plagiarist, PifflePaper, "Plagiarist", "Piffle-Paper", cardsPifflePaperDrawn, randomCardPiffle);

        randomRangeOneorTwo = Random(G_CHOICE_ONE, G_CHOICE_TWO);    
        //Plagiarist Gets Attacked
        message.plagiarismHearing(cardsPifflePaperDrawn, plagiarismHearingPifflePaper, tablePlagiarist, randomCardPiffle, Plagiarist, PifflePaper, "Plagiarist", "Piffle-Paper", randomRangeOneorTwo);
        message.courseAccreditation(cardsPifflePaperDrawn, courseAccreditationPifflePaper, tablePlagiarist, randomCardPiffle, Plagiarist, PifflePaper, "Plagiarist", "Piffle-Paper");

        if (Plagiarist.profPrestige <= 0 || PifflePaper.profPrestige <= 0) {
            // Exit the loop when one of the players loses all their prestige
            break;
        }

    } while (Plagiarist.profPrestige > 0 && PifflePaper.profPrestige > 0);

    // Checks who is winner
    message.gameOver(PifflePaper, Plagiarist);

    // Close files
    fPlagiarist.close();
    fPifflePaper.close();

    // Detects Memory Leaks Before Compiler returns 0, just before code is running
    _CrtDumpMemoryLeaks();

    return 0;
}


// Random number generator
int Random(int max)
{
    return int(float(rand()) / (RAND_MAX + 1) * float(max));
}

// Random number generator within range
int Random(int min, int max)
{
    return min + int(float(rand()) / (RAND_MAX + 1) * float(max - min + 1));
}

// Function to seed a value from a file
time_t seedValueFromFile(string filePath)
{
    time_t seedValue = 0; // Initialize seed value to 0
    string fileLine;
    ifstream fileStream(filePath); // Open file stream

    // Check if file stream is open
    if (fileStream.is_open())
    {
        // Read first line from file
        if (getline(fileStream, fileLine))
        {
            seedValue = stoi(fileLine); // Convert line to integer and store as seed value
        }
        fileStream.close(); // Close file stream
    }
    else
    {
        // Print error message if unable to open file
        std::cout << "Unable to open file this card file " << filePath << '\n';
    }

    return seedValue; // Return seed value
}
