#pragma once

#include <crtdbg.h>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <sstream>

#include "CCard.h"
#include "CPlayers.h"
#include "CStudent.h"
#include "CTable.h"
#include "CCounter.h"

class GameState
{
public:
    void startRound(int round);
    void gameStart();
    void gameOver(CPlayers::SProfessor winner, CPlayers::SProfessor loser);
    void cardsDuel(vector<CCard*>& table, vector<CCard*>& tableAttacker, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, string name, string nametwo, vector<CCard*> cardDrawn, int randomCard);
    void cardsDuelCards();
    void fillDeck(ifstream& inFile, vector<CCard*>& cards, vector<CStudent*>& cardsStudent);
    void drawCard(vector<CCard*>& cards, vector<CCard*>& drawnCards, int& deckCounter, int& i, CPlayers::SProfessor name, vector<bool*>& usedCards);
    void tableCard(vector <CCard*>& table, vector<CCard*>& cardsDrawn, CPlayers::SProfessor name, string professor, int randomCard);
    void plagiarismHearing(vector<CCard*>& cardsDrawn, vector <CCard*>& plagiarism, vector<CCard*>& tableAttacked, int randomCard, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, string attackedName, string attackerName, int randomChoice);
    void courseAccreditation(vector<CCard*>& cardsDrawn, vector <CCard*>& accreditation, vector<CCard*>& tableAttacked, int randomCard, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, string attackedName, string attackerName);
};

