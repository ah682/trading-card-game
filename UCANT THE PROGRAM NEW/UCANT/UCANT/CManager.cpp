// Adam James Anthony Hall
#include "CManager.h"
#include "CPlayers.h"
#include "CTable.h"
#include "CCounter.h"
#include "CCourseAccreditation.h"
#include "CPlagiarismHearing.h"
#include "CFeedbackForum.h"

CCounter counter;

void CManager::plagiarismHearing(vector<shared_ptr<CCard>>& cardsDrawn, vector <shared_ptr<CPlagiarismHearing>>& plagiarism, vector < shared_ptr <CTable>>& tableAttacked, int randomCard, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, string attackedName, string attackerName, int randomChoice)
{
	if (cardsDrawn[randomCard]->type == "2" && cardsDrawn[randomCard]->resilience != "-99")
	{
		// Convert the shared_ptr<CCard> to a shared_ptr<CCourseAccreditation>
		shared_ptr<CPlagiarismHearing> plagiarismElement = static_pointer_cast<CPlagiarismHearing>(cardsDrawn[randomCard]);

		// Add the converted element to the accreditation vector
		plagiarism.push_back(plagiarismElement);
	}

	professorAttacked.profName = attackedName;
	professorAttacker.profName = attackerName;

	int cardPower = 3;
	int cardResilience = 0;

	for (int i = 0; i < plagiarism.size(); i++)
	{
		if (!tableAttacked.empty()) {
			CCard* elementneeded = tableAttacked.back().get();
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
					elementneeded->resilience = "-0";
					cout << "Card Killed: " << elementneeded->type << " " << elementneeded->firstname << " " << elementneeded->lastname << " " << elementneeded->power << " " << elementneeded->resilience << " " << elementneeded->boost << " by player " << professorAttacker.profName << endl;
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

void CManager::courseAccreditation(vector<shared_ptr<CCard>>& cardsDrawn, vector <shared_ptr<CCourseAccreditation>>& accreditation, vector<shared_ptr<CTable>>& tableAttacked, int randomCard, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, string attackedName, string attackerName)
{
	int cardPower = 1;
	int cardResilience = 0;

	if (cardsDrawn[randomCard]->type == "3" && cardsDrawn[randomCard]->resilience != "-99")
	{
		// Convert the shared_ptr<CCard> to a shared_ptr<CCourseAccreditation>
		shared_ptr<CCourseAccreditation> accreditationElement = static_pointer_cast<CCourseAccreditation>(cardsDrawn[randomCard]);

		// Add the converted element to the accreditation vector
		accreditation.push_back(accreditationElement);
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
				tableAttacked[j]->resilience = "0";
				cout << "Card Killed: " << tableAttacked[j]->type << " " << tableAttacked[j]->firstname << " " << tableAttacked[j]->lastname << " " << tableAttacked[j]->power << " " << tableAttacked[j]->resilience << " " << tableAttacked[j]->boost << " by player " << professorAttacker.profName << endl;
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

void CManager::tableCard(vector<shared_ptr<CTable>>& table, vector<shared_ptr<CCard>>& cardsDrawn, CPlayers::SProfessor name, string professor, int randomCard)
{
	name.profName = professor;
	if ((cardsDrawn[randomCard]->type == "1" || cardsDrawn[randomCard]->type == "5") && cardsDrawn[randomCard]->resilience != "-99")
	{
		// Convert the shared_ptr<CCard> to a shared_ptr<CCourseAccreditation>
		shared_ptr<CTable> tableElement = static_pointer_cast<CTable>(cardsDrawn[randomCard]);

		// Add the converted element to the accreditation vector
		table.push_back(tableElement);
	}

	// Shows cards placed on table
	cout << name.profName << " cards on table: " << endl;
	for (int i = 0; i < table.size(); i++)
	{
		cout << table[i]->type << " " << table[i]->firstname << " " << table[i]->lastname << " " << table[i]->power << " " << table[i]->resilience << " " << table[i]->boost << endl;
		if (i > table.size() - table.size() + 1)
		{
			break;
		}
	}
}
void CManager::gameStart()
{
	cout << "Welcome to U-Can't. Let the winnowing begin..." << endl;
}

void CManager::gameOver(CPlayers::SProfessor piffle, CPlayers::SProfessor plagiarist)
{


	if (piffle.profPrestige > plagiarist.profPrestige)
	{
		if (plagiarist.profPrestige < 0)
		{
			plagiarist.profPrestige = 0;
		}
		cout << plagiarist.profName << " prestige is " << plagiarist.profPrestige << " " << piffle.profName << " prestige is " << piffle.profPrestige << endl
			<< piffle.profName << " wins" << endl << endl;

		cout << "Game Over" << endl;
	}
	else if (plagiarist.profPrestige > piffle.profPrestige)
	{
		if (piffle.profPrestige < 0)
		{
			piffle.profPrestige = 0;
		}
		cout << piffle.profName << " prestige is " << piffle.profPrestige << " " << plagiarist.profName << " prestige is " << plagiarist.profPrestige << endl
			<< plagiarist.profName << " wins" << endl << endl;

		cout << "Game Over" << endl;
	}
}

void CManager::startRound(int round)
{
	cout << "Round: " << round << endl;
}

void CManager::fillDeck(ifstream& inFile, vector<shared_ptr<CCard>>& cards, vector<shared_ptr<CStudent>>& cardsStudent)
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

void CManager::drawCard(vector<shared_ptr<CCard>>& cards, vector<shared_ptr<CCard>>& drawnCards, int& deckCounter, int& i, CPlayers::SProfessor name, vector<shared_ptr<bool>>& usedCards)
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
void CManager::cardsDuel(vector<shared_ptr<CTable>>& tableAttacked, vector<shared_ptr<CTable>>& tableAttacker, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, string name, string nametwo, vector<shared_ptr<CCard>> cardDrawn, int randomCard, int& typeFiveCounter)
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


		if (tableAttacked[i]->resilience != "")
		{
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
			if (cardResilience > 0)
			{
				cardResilience -= cardPower;
				if (tableAttacker[j]->type == "5")
				{
					typeFiveCounter++;
				}
				string cardResilienceString = to_string(cardResilience);
				tableAttacked[i]->resilience = cardResilienceString;
			}
			if (cardResilience <= 0) {
				tableAttacked[i]->resilience = "0";
				cout << "Card Killed: " << tableAttacked[i]->type << " " << tableAttacked[i]->firstname << " " << tableAttacked[i]->lastname << " " << tableAttacked[i]->power << " " << tableAttacked[i]->resilience << " " << tableAttacked[i]->power << " by player " << professorAttacker.profName << endl;
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

void CManager::cardsDuelCards()
{

}

void CManager::feedbackForum(vector<shared_ptr<CCard>> cardsDrawn, vector<shared_ptr<CFeedbackForum>>& feedbackforum, vector<shared_ptr<CTable>>& tableAttacked, int randomCard, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, string attackedName, string attackerName, int randomChoice, vector<shared_ptr<CTable>>& tableAttacker)
{
	if (cardsDrawn[randomCard]->type == "4" && cardsDrawn[randomCard]->resilience != "-99")
	{
		// Convert the shared_ptr<CCard> to a shared_ptr<CCourseAccreditation>
		shared_ptr<CFeedbackForum> feedbackElement = static_pointer_cast<CFeedbackForum>(cardsDrawn[randomCard]);

		// Add the converted element to the accreditation vector
		feedbackforum.push_back(feedbackElement);

	}

	professorAttacked.profName = attackedName;
	professorAttacker.profName = attackerName;

	int cardPower = 2;
	int cardResilience = 0;

	for (int i = 0; i < feedbackforum.size(); i++)
	{
		if (randomChoice == 1)
		{
			int randomIndex = counter.Random(tableAttacked.size() - 1);

			if (!tableAttacked.empty())
			{
				shared_ptr<CCard> elementneeded = tableAttacked[randomIndex];
				if (!elementneeded->resilience.empty())
				{
					cardResilience = stoi(elementneeded->resilience);
				}


				if (cardResilience > 0)
				{
					cardResilience -= cardPower;
					string cardResilienceString = to_string(cardResilience);
					tableAttacked[randomIndex]->resilience = cardResilienceString;
				}
				if (cardResilience <= 0)
				{
					elementneeded->resilience = "0";
					cout << "Card Killed: " << elementneeded->type << " " << elementneeded->firstname << " " << elementneeded->lastname << " " << elementneeded->power << " " << elementneeded->resilience << " " << elementneeded->boost << " by player " << professorAttacker.profName << endl;
					elementneeded->resilience = "-99";
					tableAttacked.erase(tableAttacked.end() - 1);
				}
				professorAttacked.profPrestige -= cardPower;
			}

			if (randomChoice == 2)
			{

				int randomIndex = counter.Random(tableAttacker.size() - 1);
				if (!tableAttacker.empty())
				{
					shared_ptr<CCard> elementneeded = tableAttacker[randomIndex];
					if (!elementneeded->resilience.empty())
					{
						cardResilience = stoi(elementneeded->resilience);
					}
				}
				cardResilience += cardPower;
				string cardResilienceString = to_string(cardResilience);
				tableAttacker[randomIndex]->resilience = cardResilienceString;
				professorAttacker.profPrestige += cardPower;
				cout << professorAttacker.profName << " " << " has recieved healing of " << cardPower << " points" << endl;
				cout << tableAttacker[tableAttacker.size() - 1]->firstname << " " << " has recieved healing of " << cardPower << " points" << endl;
			}


			if (professorAttacked.profPrestige < 0)
			{
				professorAttacked.profPrestige = 0;
			}
			cout << professorAttacked.profName << " Prestige is now " << professorAttacked.profPrestige << endl;
		}
	}
}