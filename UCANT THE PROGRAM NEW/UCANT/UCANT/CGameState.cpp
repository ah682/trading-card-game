#include "CGameState.h"
#include "CPlayers.h"
#include "CTable.h"
void GameState::plagiarismHearing(vector<CCard*>& cardsDrawn, vector <CCard*>& plagiarism, vector<CCard*>& tableAttacked, int randomCard, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, string attackedName, string attackerName, int randomChoice)
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
            CCard* elementneeded = tableAttacked[tableAttacked.size() - 1];
            if (!elementneeded->resilience.empty()) {
                cardResilience = stoi(elementneeded->resilience);
            }

            if (randomChoice == 1)
            {
                if (cardResilience > 0) {
                    cardResilience -= cardPower;
                    string cardResilienceString = to_string(cardResilience);
                    tableAttacked[tableAttacked.size() - 1]->resilience = cardResilienceString;
                }
                if (cardResilience <= 0) {
                    cout << "CARD KILLED Name:" << elementneeded->firstname << " by player " << professorAttacker.profName << endl;
                    elementneeded->resilience = "-99";
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
            cout << professorAttacked.profName << " Prestige is now " << professorAttacked.profPrestige << endl;
        }
    }
}

void GameState::courseAccreditation(vector<CCard*>& cardsDrawn, vector <CCard*>& accreditation, vector<CCard*>& tableAttacked, int randomCard, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, string attackedName, string attackerName)
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
                cout << "CARD KILLED Name:" << tableAttacked[j]->firstname << " by player " << professorAttacker.profName << endl;
                tableAttacked[j]->resilience = "-99";
                tableAttacked.erase(tableAttacked.begin() + j);
            }
        }

        professorAttacked.profPrestige -= cardPower;

        if (professorAttacked.profPrestige < 0)
        {
            professorAttacked.profPrestige = 0;
        }
        cout << professorAttacked.profName << " Prestige is now " << professorAttacked.profPrestige << endl;

    }
}

void GameState::tableCard(vector<CCard*>& table, vector<CCard*>& cardsDrawn, CPlayers::SProfessor name, string professor, int randomCard)
{
    name.profName = professor;
    if ((cardsDrawn[randomCard]->type == "1" || cardsDrawn[randomCard]->type == "5") && cardsDrawn[randomCard]->resilience != "-99")
    {
        table.push_back(cardsDrawn[randomCard]);
    }

    // Shows cards placed on table
    cout << name.profName << " cards on table " << endl;
    for (int i = 0; i < table.size(); i++) {
        cout << table[i]->type << " " << table[i]->firstname << " " << table[i]->lastname << " " << table[i]->power << " " << table[i]->resilience << " " << table[i]->boost << endl;
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

void GameState::gameOver(CPlayers::SProfessor piffle, CPlayers::SProfessor plagiarist)
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

void GameState::fillDeck(ifstream& inFile, vector<CCard*>& cards, vector<CStudent*>& cardsStudent)
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

void GameState::drawCard(vector<CCard*>& cards, vector<CCard*>& drawnCards, int& deckCounter, int& i, CPlayers::SProfessor name, vector<bool*>& usedCards)
{
    for (int j = i; j < deckCounter; j++)
    {
        if (i == 48)
        {
            break;
        }
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
void GameState::cardsDuel(vector<CCard*>& tableAttacked, vector<CCard*>& tableAttacker, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, string name, string nametwo, vector<CCard*> cardDrawn, int randomCard, int &typeFiveCounter)
{
    professorAttacked.profName = name;
    professorAttacker.profName = nametwo;

    int cardPower = 0;
    int cardResilience = 0;
    int attackerCardResilience = 0;
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
        if (tableAttacker[j]->type == "5")
        {
            attackerCardResilience = stoi(tableAttacker[j]->resilience);
            attackerCardResilience += typeFiveCounter;
            string attackerCardResilienceString = to_string(attackerCardResilience);
            tableAttacker[j]->resilience = attackerCardResilienceString;
        }

        if (tableAttacked.size() > 0)
        {
            if (cardResilience > 0) {
                cardResilience -= cardPower;
                if (tableAttacker[j]->type == "5")
                {
                    typeFiveCounter++;
                }
                string cardResilienceString = to_string(cardResilience);
                tableAttacked[i]->resilience = cardResilienceString;
            }
            if (cardResilience <= 0) {
                cout << "CARD KILLED Name:" << tableAttacked[i]->firstname << " by player " << professorAttacker.profName << endl;
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
    cout << professorAttacked.profName << " Prestige is now " << professorAttacked.profPrestige << endl;
}

void GameState::cardsDuelCards()
{

}

void GameState::feedbackForum(vector<CCard*>& cardsDrawn, vector <CCard*>& feedbackforum, vector<CCard*>& tableAttacked, int randomCard, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, string attackedName, string attackerName, int randomChoice, vector<CCard*>& tableAttacker)
{
    if (cardsDrawn[randomCard]->type == "4" && cardsDrawn[randomCard]->resilience != "-99")
    {
        feedbackforum.push_back(cardsDrawn[randomCard]);
    }

    professorAttacked.profName = attackedName;
    professorAttacker.profName = attackerName;

    int cardPower = 2;
    int cardResilience = 0;

    for (int i = 0; i < feedbackforum.size(); i++)
    {
        if (randomChoice == 1)
        {
        if (!tableAttacked.empty()) {
            CCard* elementneeded = tableAttacked[tableAttacked.size() - 1];
            if (!elementneeded->resilience.empty()) {
                cardResilience = stoi(elementneeded->resilience);
            }

            
                if (cardResilience > 0) {
                    cardResilience -= cardPower;
                    string cardResilienceString = to_string(cardResilience);
                    tableAttacked[tableAttacked.size() - 1]->resilience = cardResilienceString;
                }
                if (cardResilience <= 0) {
                    cout << "CARD KILLED Name:" << elementneeded->firstname << " by player " << professorAttacker.profName << endl;
                    elementneeded->resilience = "-99";
                    tableAttacked.erase(tableAttacked.end() - 1);
                }
                professorAttacked.profPrestige -= cardPower;
        }

        if (randomChoice == 2) {

                if (!tableAttacker.empty()) {
                    CCard* elementneeded = tableAttacker[tableAttacker.size() - 1];
                    if (!elementneeded->resilience.empty()) {
                        cardResilience = stoi(elementneeded->resilience);
                    }
                }
                cardResilience += cardPower;
                string cardResilienceString = to_string(cardResilience);
                tableAttacker[tableAttacker.size() - 1]->resilience = cardResilienceString;

                professorAttacker.profPrestige += cardPower;
        }
            
            
            if (professorAttacked.profPrestige < 0)
            {
                professorAttacked.profPrestige = 0;
            }
            cout << professorAttacked.profName << " Prestige is now " << professorAttacked.profPrestige << endl;
        }
    }
}