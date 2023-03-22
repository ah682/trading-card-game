// Adam James Anthony Hall
#include "CManager.h"
#include "CPlayers.h"
#include "CTable.h"
#include "CCounter.h"
#include "CCourseAccreditation.h"
#include "CPlagiarismHearing.h"
#include "CFeedbackForum.h"

CCounter randomNumber; //??????

void CManager::PlagiarismHearing(vector<shared_ptr<CCard>>& cardsDrawn, vector <shared_ptr<CPlagiarismHearing>>& plagiarism, vector < shared_ptr <CTable>>& tableAttacked, int randomCard, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, string attackedName, string attackerName, int randomChoice)
{
	if (cardsDrawn[randomCard]->mType == "2" && cardsDrawn[randomCard]->mResilience != "-99")
	{
		// Convert the shared_ptr<CCard> to a shared_ptr<CCourseAccreditation>
		shared_ptr<CPlagiarismHearing> pPlagiarismElement = static_pointer_cast<CPlagiarismHearing>(cardsDrawn[randomCard]);

		// Add the converted element to the accreditation vector
		plagiarism.push_back(pPlagiarismElement);
	}

	professorAttacked.profName = attackedName;
	professorAttacker.profName = attackerName;

	const int CARD_POWER = 3;
	int cardResilience = 0;

	for (int i = 0; i < plagiarism.size(); i++)
	{
		if (!tableAttacked.empty()) {
			CCard* elementneeded = tableAttacked.back().get();
			if (!elementneeded->mResilience.empty()) {
				cardResilience = stoi(elementneeded->mResilience);
			}

			if (randomChoice == 1)
			{
				if (cardResilience > 0) {
					cardResilience -= CARD_POWER;
					string cardResilienceString = to_string(cardResilience);
					tableAttacked[tableAttacked.size() - 1]->mResilience = cardResilienceString;
				}
				if (cardResilience <= 0) {
					elementneeded->mResilience = "-0";
					cout << "Card Killed: " << elementneeded->mType << " " << elementneeded->mFirstname << " " << elementneeded->mLastname << " " << elementneeded->mPower << " " << elementneeded->mResilience << " " << elementneeded->mBoost << " by player " << professorAttacker.profName << endl;
					elementneeded->mResilience = "-99";
					tableAttacked.erase(tableAttacked.end() - 1);
				}
			}

			if (randomChoice == 2) {
				professorAttacked.profPrestige -= CARD_POWER;
			}
			if (professorAttacked.profPrestige < 0)
			{
				professorAttacked.profPrestige = 0;
			}
			cout << professorAttacked.profName << " Prestige is now " << professorAttacked.profPrestige << endl;
		}
	}
}

void CManager::CourseAccreditation(vector<shared_ptr<CCard>>& cardsDrawn, vector <shared_ptr<CCourseAccreditation>>& accreditation, vector<shared_ptr<CTable>>& tableAttacked, int randomCard, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, string attackedName, string attackerName)
{
	const int CARD_POWER = 1;
	int cardResilience = 0;

	if (cardsDrawn[randomCard]->mType == "3" && cardsDrawn[randomCard]->mResilience != "-99")
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
			cardResilience = stoi(tableAttacked[j]->mResilience);
			cardResilience -= CARD_POWER;
			string cardResilienceString = to_string(cardResilience);
			tableAttacked[j]->mResilience = cardResilienceString;

			if (cardResilience <= 0) {
				tableAttacked[j]->mResilience = "0";
				cout << "Card Killed: " << tableAttacked[j]->mType << " " << tableAttacked[j]->mFirstname << " " << tableAttacked[j]->mLastname << " " << tableAttacked[j]->mPower << " " << tableAttacked[j]->mResilience << " " << tableAttacked[j]->mBoost << " by player " << professorAttacker.profName << endl;
				tableAttacked[j]->mResilience = "-99";
				tableAttacked.erase(tableAttacked.begin() + j);
			}
		}

		professorAttacked.profPrestige -= CARD_POWER;

		if (professorAttacked.profPrestige < 0)
		{
			professorAttacked.profPrestige = 0;
		}
		cout << professorAttacked.profName << " Prestige is now " << professorAttacked.profPrestige << endl;

	}
}

void CManager::TableCard(vector<shared_ptr<CTable>>& table, vector<shared_ptr<CCard>>& cardsDrawn, CPlayers::SProfessor name, string professor, int randomCard)
{
	name.profName = professor;
	if ((cardsDrawn[randomCard]->mType == "1" || cardsDrawn[randomCard]->mType == "5") && cardsDrawn[randomCard]->mResilience != "-99")
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
		cout << table[i]->mType << " " << table[i]->mFirstname << " " << table[i]->mLastname << " " << table[i]->mPower << " " << table[i]->mResilience << " " << table[i]->mBoost << endl;
		if (i > table.size() - table.size() + 1)
		{
			break;
		}
	}
}
void CManager::GameStart()
{
	cout << "Welcome to U-Can't. Let the winnowing begin..." << endl;
}

void CManager::GameOver(CPlayers::SProfessor piffle, CPlayers::SProfessor plagiarist)
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

void CManager::StartRound(int round)
{
	cout << "Round: " << round << endl;
}

void CManager::FillDeck(ifstream& inFile, vector<shared_ptr<CCard>>& cards, vector<shared_ptr<CStudent>>& cardsStudent)
{
	inFile.clear();
	inFile.seekg(0);

	string line;
	for (int i = 0; i < cards.size(); i++)
	{
		if (getline(inFile, line)) {
			stringstream ss(line);
			ss >> cards[i]->mType >> cards[i]->mFirstname >> cards[i]->mLastname >> cards[i]->mPower >> cards[i]->mResilience >> cards[i]->mBoost;
			if (cardsStudent[i]->mType == "1")
			{
				ss >> cardsStudent[i]->mType >> cardsStudent[i]->mFirstname >> cardsStudent[i]->mLastname >> cardsStudent[i]->mPower >> cardsStudent[i]->mResilience >> cardsStudent[i]->mBoost;
			}
		}

	}
}

void CManager::DrawCard(vector<shared_ptr<CCard>>& cards, vector<shared_ptr<CCard>>& drawnCards, int& deckCounter, int& i, CPlayers::SProfessor name, vector<shared_ptr<bool>>& usedCards)
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
			cout << "Player " << name.profName << " has drawn " << drawnCards.back()->mType << " " << drawnCards.back()->mFirstname << " " << drawnCards.back()->mLastname << " " << drawnCards.back()->mPower << " " << drawnCards.back()->mResilience << " " << drawnCards.back()->mBoost << endl;
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
void CManager::CardsDuel(vector<shared_ptr<CTable>>& tableAttacked, vector<shared_ptr<CTable>>& tableAttacker, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, string name, string nametwo, vector<shared_ptr<CCard>> cardDrawn, int randomCard, int& typeFiveCounter)
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
		cardPower = stoi(tableAttacker[j]->mPower);


		if (tableAttacked[i]->mResilience != "")
		{
			cardResilience = stoi(tableAttacked[i]->mResilience);
		}
		if (tableAttacker[j]->mType == "5")
		{
			attackerCardResilience = stoi(tableAttacker[j]->mResilience);
			attackerCardResilience += typeFiveCounter;
			string attackerCardResilienceString = to_string(attackerCardResilience);
			tableAttacker[j]->mResilience = attackerCardResilienceString;
		}

		if (tableAttacked.size() > 0)
		{
			if (cardResilience > 0)
			{
				cardResilience -= cardPower;
				if (tableAttacker[j]->mType == "5")
				{
					typeFiveCounter++;
				}
				string cardResilienceString = to_string(cardResilience);
				tableAttacked[i]->mResilience = cardResilienceString;
			}
			if (cardResilience <= 0) {
				tableAttacked[i]->mResilience = "0";
				cout << "Card Killed: " << tableAttacked[i]->mType << " " << tableAttacked[i]->mFirstname << " " << tableAttacked[i]->mLastname << " " << tableAttacked[i]->mPower << " " << tableAttacked[i]->mResilience << " " << tableAttacked[i]->mBoost << " by player " << professorAttacker.profName << endl;
				tableAttacked[i]->mResilience = "-99";
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

void CManager::FeedbackForum(vector<shared_ptr<CCard>> cardsDrawn, vector<shared_ptr<CFeedbackForum>>& feedbackforum, vector<shared_ptr<CTable>>& tableAttacked, int randomCard, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, string attackedName, string attackerName, int randomChoice, vector<shared_ptr<CTable>>& tableAttacker)
{
	if (cardsDrawn[randomCard]->mType == "4" && cardsDrawn[randomCard]->mResilience != "-99")
	{
		// Convert the shared_ptr<CCard> to a shared_ptr<CCourseAccreditation>
		shared_ptr<CFeedbackForum> feedbackElement = static_pointer_cast<CFeedbackForum>(cardsDrawn[randomCard]);

		// Add the converted element to the accreditation vector
		feedbackforum.push_back(feedbackElement);

	}

	professorAttacked.profName = attackedName;
	professorAttacker.profName = attackerName;

	const int CARD_POWER = 2;
	int cardResilience = 0;

	for (int i = 0; i < feedbackforum.size(); i++)
	{
		if (randomChoice == 1)
		{
			int randomIndex = randomNumber.Random(tableAttacked.size() - 1);

			if (!tableAttacked.empty())
			{
				shared_ptr<CCard> elementneeded = tableAttacked[randomIndex];
				if (!elementneeded->mResilience.empty())
				{
					cardResilience = stoi(elementneeded->mResilience);
				}


				if (cardResilience > 0)
				{
					cardResilience -= CARD_POWER;
					string cardResilienceString = to_string(cardResilience);
					tableAttacked[randomIndex]->mResilience = cardResilienceString;
				}
				if (cardResilience <= 0)
				{
					elementneeded->mResilience = "0";
					cout << "Card Killed: " << elementneeded->mType << " " << elementneeded->mFirstname << " " << elementneeded->mLastname << " " << elementneeded->mPower << " " << elementneeded->mResilience << " " << elementneeded->mBoost << " by player " << professorAttacker.profName << endl;
					elementneeded->mResilience = "-99";
					tableAttacked.erase(tableAttacked.end() - 1);
				}
				professorAttacked.profPrestige -= CARD_POWER;
			}

			if (randomChoice == 2)
			{

				int randomIndex = randomNumber.Random(tableAttacker.size() - 1);
				if (!tableAttacker.empty())
				{
					shared_ptr<CCard> elementneeded = tableAttacker[randomIndex];
					if (!elementneeded->mResilience.empty())
					{
						cardResilience = stoi(elementneeded->mResilience);
					}
				}
				cardResilience += CARD_POWER;
				string cardResilienceString = to_string(cardResilience);
				tableAttacker[randomIndex]->mResilience = cardResilienceString;
				professorAttacker.profPrestige += CARD_POWER;
				cout << professorAttacker.profName << " " << " has recieved healing of " << CARD_POWER << " points" << endl;
				cout << tableAttacker[tableAttacker.size() - 1]->mFirstname << " " << " has recieved healing of " << CARD_POWER << " points" << endl;
			}


			if (professorAttacked.profPrestige < 0)
			{
				professorAttacked.profPrestige = 0;
			}
			cout << professorAttacked.profName << " Prestige is now " << professorAttacked.profPrestige << endl;
		}
	}
}