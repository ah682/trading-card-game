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

#include "CGameState.h"
#include "CCard.h"
#include "CStudent.h"
#include "CTable.h"
#include "CCourseAccreditation.h"
#include "CPlagiarismHearing.h"
#include "CCounter.h"

using namespace std;

const time_t readSeedFile(string filename);
int Random(int max);
int randomRange(int min, int max);


int main()
{
    CCounter* Counter = new CCounter();
    // Genereates seed from read file
    Counter->seed = readSeedFile("seed.txt");
    srand(Counter->seed);
    cout << "Seed Number: " << Counter->seed << endl;

    // Initialize data before commencing U-Can't

    GameState message;
    message.gameStart();

    const int deckSize = 48;

    Counter->filePlagiarist.open("plagiarist.txt");

    Counter->filePiffle.open("piffle-paper.txt");

    CPlayers::SProfessor* Plagiarist = new CPlayers::SProfessor;
    CPlayers::SProfessor* Piffle = new CPlayers::SProfessor;

    // Count the number of cards in the plagiarist file
    while (getline(Counter->filePlagiarist, Counter->linePlagiarist))
    {
        Counter->num_cardsPlagiarist++ + deckSize;
    }

    // Count the number of cards in the piffle file
    while (getline(Counter->filePiffle, Counter->linePiffle))
    {
        Counter->num_cardsPiffle++ + deckSize;
    }


    // Allocate memory for the cards
    vector<CCard*> cardsPiffle(Counter->num_cardsPiffle, nullptr);

    for (int i = 0; i < Counter->num_cardsPiffle; i++) {
        CCard* cardTest1 = new CCard(); // Allocate memory for the card object
        cardsPiffle[i] = cardTest1; // Assign the pointer to point to the newly allocated memory
    }

    // Allocate memory for the cards
    vector<CCard*> cardsPlagiarist(Counter->num_cardsPlagiarist, nullptr);

    for (int i = 0; i < Counter->num_cardsPlagiarist; i++) {
        CCard* cardTest2 = new CCard(); // Allocate memory for the card object
        cardsPlagiarist[i] = cardTest2; // Assign the pointer to point to the newly allocated memory
    }

    // Allocate memory for the cards
    vector<CStudent*> cardsPlagiaristStudents(Counter->num_cardsPlagiarist, nullptr);

    for (int i = 0; i < Counter->num_cardsPlagiarist; i++) {
        CStudent* cardTest6 = new CStudent(); // Allocate memory for the card object
        cardsPlagiaristStudents[i] = cardTest6; // Assign the pointer to point to the newly allocated memory
    }

    // Allocate memory for the cards
    vector<CStudent*> cardsPiffleStudents(Counter->num_cardsPiffle, nullptr);

    for (int i = 0; i < Counter->num_cardsPiffle; i++) {
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

    vector<CCard*> plagiarismHearingPlagiarist; 
    vector<CCard*> plagiarismHearingPiffle; 

    vector<CCard*> courseAccreditationPlagiarist; 
    vector<CCard*> courseAccreditationPiffle; 

    message.fillDeck(Counter->filePlagiarist, cardsPlagiarist, cardsPlagiaristStudents);
    message.fillDeck(Counter->filePiffle, cardsPiffle, cardsPiffleStudents);
    

    // Allocate
    vector<bool*> checkUsedCardPlagiarist(deckSize, nullptr);

    for (int i = 0; i < deckSize; i++) {
        bool* cardTest3 = new bool(false); // Allocate memory for the card object
        checkUsedCardPlagiarist[i] = cardTest3; // Assign the pointer to point to the newly allocated memory
    }

    vector<bool*> checkUsedCardPiffle(deckSize, nullptr);

    for (int i = 0; i < deckSize; i++) {
        bool* cardTest4 = new bool(false); // Allocate memory for the card object
        checkUsedCardPiffle[i] = cardTest4; // Assign the pointer to point to the newly allocated memory
    }

    // MAKE LOOP UNTIL PRESTIGE HITS 0
    do
    {
        // Allocate memory for the cards
        
        // Draws random card for plagiarist and checks if works with cout
        if (Counter->i < deckSize)
        {
            cout << "DRAWN CARDS Plagiarist" << endl;
            message.drawCard(cardsPlagiarist, cardsPlagiaristDrawn, Counter->deckCounter, Counter->i, *Plagiarist, checkUsedCardPlagiarist);

            cout << "DRAWN CARDS Piffle" << endl;

            message.drawCard(cardsPiffle, cardsPiffleDrawn, Counter->deckCounter, Counter->i, *Piffle, checkUsedCardPiffle);


            // Piffle Chooses a card card THIS IS SUPPOSE TO BE RANDOM
            Counter->randomCardPiffle = randomRange(cardsPiffleDrawn.size() - 2, cardsPiffleDrawn.size() - 1);

            cout << "Piffle chooses " << cardsPiffleDrawn[Counter->randomCardPiffle]->type << " " << cardsPiffleDrawn[Counter->randomCardPiffle]->firstname << " " << cardsPiffleDrawn[Counter->randomCardPiffle]->lastname << " " << cardsPiffleDrawn[Counter->randomCardPiffle]->power << " " << cardsPiffleDrawn[Counter->randomCardPiffle]->resilience << " " << cardsPiffleDrawn[Counter->randomCardPiffle]->boost << endl;
            // Plagiarist Chooses a card card THIS IS SUPPOSE TO BE RANDOM
            Counter->randomCardPlagiarist = randomRange(cardsPlagiaristDrawn.size() - 2, cardsPlagiaristDrawn.size() - 1);
            cout << "Plagiarist chooses " << cardsPlagiaristDrawn[Counter->randomCardPlagiarist]->type << " " << cardsPlagiaristDrawn[Counter->randomCardPlagiarist]->firstname << " " << cardsPlagiaristDrawn[Counter->randomCardPlagiarist]->lastname << " " << cardsPlagiaristDrawn[Counter->randomCardPlagiarist]->power << " " << cardsPlagiaristDrawn[Counter->randomCardPlagiarist]->resilience << " " << cardsPlagiaristDrawn[Counter->randomCardPlagiarist]->boost << endl;
        }

        //Prints table on cards for specific player
        message.tableCard(tablePiffle, cardsPiffleDrawn, *Piffle, "Piffle", Counter->randomCardPiffle);
        message.tableCard(tablePlagiarist, cardsPlagiaristDrawn, *Plagiarist, "Plagiarist", Counter->randomCardPlagiarist);

        // Make cards duel
        // Create Piffle Player piffle gets attacked
        message.cardsDuel(tablePiffle, tablePlagiarist, *Piffle, *Plagiarist, "Piffle", "Plagiarist", cardsPlagiaristDrawn, Counter->randomCardPlagiarist);


        int randomRangeOneorTwo = randomRange(1, 2);
        //Piffle Gets Attacked
        message.plagiarismHearing(cardsPlagiaristDrawn, plagiarismHearingPlagiarist, tablePiffle, Counter->randomCardPlagiarist, *Piffle, *Plagiarist, "Piffle", "Plagiarist", randomRangeOneorTwo);
        message.courseAccreditation(cardsPlagiaristDrawn, courseAccreditationPlagiarist, tablePiffle, Counter->randomCardPlagiarist, *Piffle, *Plagiarist, "Piffle", "Plagiarist");


        if (Plagiarist->profPrestige <= 0 || Piffle->profPrestige <= 0) {
            // Exit the loop when one of the players loses all their prestige
            break;
        }

        // Make cards duel
        // Create Plagiarist Player plagiarist gets attacked
        message.cardsDuel(tablePlagiarist, tablePiffle, *Plagiarist, *Piffle, "Plagiarist", "Piffle", cardsPiffleDrawn, Counter->randomCardPiffle);

        randomRangeOneorTwo = randomRange(1, 2);    
        //Plagiarist Gets Attacked
        message.plagiarismHearing(cardsPiffleDrawn, plagiarismHearingPiffle, tablePlagiarist, Counter->randomCardPiffle, *Plagiarist, *Piffle, "Plagiarist", "Piffle", randomRangeOneorTwo);
        message.courseAccreditation(cardsPiffleDrawn, courseAccreditationPiffle, tablePlagiarist, Counter->randomCardPiffle, *Plagiarist, *Piffle, "Plagiarist", "Piffle");

        if (Plagiarist->profPrestige <= 0 || Piffle->profPrestige <= 0) {
            // Exit the loop when one of the players loses all their prestige
            break;
        }

    } while (Plagiarist->profPrestige > 0 && Piffle->profPrestige > 0);

    // Checks who is winner
    message.gameOver(*Piffle, *Plagiarist);

    // Close files
    Counter->filePlagiarist.close();
    Counter->filePiffle.close();

    // De-allocate memory
    delete Counter;
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

const time_t readSeedFile(string filename)
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
