// Adam James Anthony Hall

// Initialize necessary header files
#include <memory>

#include "CManager.h"
#include "CPlayers.h"
#include "CTable.h"
#include "CCounter.h"
#include "CStudent.h"
#include "CCourseAccreditation.h"
#include "CPlagiarismHearing.h"
#include "CFeedbackForum.h"

using namespace std;

unique_ptr<CCounter> randomNumber = make_unique<CCounter>();

// Initilalise size of dead card as -9999 string value
const string DEAD_CARD = "-9999";

// Initilalise size of decks as 48 integers
const int DECK_SIZE = 48;

void CManager::UsePlagiarismHearingCard(vector<shared_ptr<CCard>>& cardsDrawn, vector <shared_ptr<CPlagiarismHearing>>& plagiarism, vector <shared_ptr<CTable>>& tableAttacked, int randomCard, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, string attackedName, string attackerName, int randomChoice)
{
	if (cardsDrawn[randomCard]->mType == "2" && cardsDrawn[randomCard]->mResilience != DEAD_CARD)
	{
		// Convert the shared_ptr<CCard> to a shared_ptr<CDrawCourseAccreditationCard>
		shared_ptr<CPlagiarismHearing> pPlagiarismElement = static_pointer_cast<CPlagiarismHearing>(cardsDrawn[randomCard]);

		// Add the converted element to the accreditation vector
		plagiarism.push_back(pPlagiarismElement);
	}

	professorAttacked.mProfName = attackedName;
	professorAttacker.mProfName = attackerName;

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
					cout << "Card Killed: " << elementneeded->mType << " " << elementneeded->mFirstname << " " << elementneeded->mLastname << " " << elementneeded->mPower << " " << elementneeded->mResilience << " " << elementneeded->mBoost << " by player " << professorAttacker.mProfName << endl;
					elementneeded->mResilience = DEAD_CARD;
					tableAttacked.erase(tableAttacked.end() - 1);
				}
			}

			if (randomChoice == 2) {
				professorAttacked.mProfPrestige -= CARD_POWER;
			}
			if (professorAttacked.mProfPrestige < 0)
			{
				professorAttacked.mProfPrestige = 0;
			}
			cout << professorAttacked.mProfName << " prestige is now " << professorAttacked.mProfPrestige << endl;
		}
	}
}

void CManager::UseCourseAccreditationCard(vector<shared_ptr<CCard>>& cardsDrawn, vector <shared_ptr<CCourseAccreditation>>& accreditation, vector<shared_ptr<CTable>>& tableAttacked, int randomCard, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, string attackedName, string attackerName)
{
	const int CARD_POWER = 1;
	int cardResilience = 0;

	if (cardsDrawn[randomCard]->mType == "3" && cardsDrawn[randomCard]->mResilience != DEAD_CARD)
	{
		// Convert the shared_ptr<CCard> to a shared_ptr<CDrawCourseAccreditationCard>
		shared_ptr<CCourseAccreditation> accreditationElement = static_pointer_cast<CCourseAccreditation>(cardsDrawn[randomCard]);

		// Add the converted element to the accreditation vector
		accreditation.push_back(accreditationElement);
	}

	professorAttacked.mProfName = attackedName;
	professorAttacker.mProfName = attackerName;

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
				cout << "Card Killed: " << tableAttacked[j]->mType << " " << tableAttacked[j]->mFirstname << " " << tableAttacked[j]->mLastname << " " << tableAttacked[j]->mPower << " " << tableAttacked[j]->mResilience << " " << tableAttacked[j]->mBoost << " by player " << professorAttacker.mProfName << endl;
				tableAttacked[j]->mResilience = DEAD_CARD;
				tableAttacked.erase(tableAttacked.begin() + j);
			}
		}

		professorAttacked.mProfPrestige -= CARD_POWER;

		if (professorAttacked.mProfPrestige < 0)
		{
			professorAttacked.mProfPrestige = 0;
		}
		cout << professorAttacked.mProfName << " prestige is now " << professorAttacked.mProfPrestige << endl;

	}
}

void CManager::PrintTable(vector<shared_ptr<CTable>>& table, vector<shared_ptr<CCard>>& cardsDrawn, CPlayers::SProfessor playerName, string professor, int randomCard)
{
	playerName.mProfName = professor;
	if (((cardsDrawn[randomCard]->mType == "1" || cardsDrawn[randomCard]->mType == "5") || cardsDrawn[randomCard]->mType == "6") && cardsDrawn[randomCard]->mResilience != DEAD_CARD)
	{
		// Convert the shared_ptr<CCard> to a shared_ptr<CDrawCourseAccreditationCard>
		shared_ptr<CTable> tableElement = static_pointer_cast<CTable>(cardsDrawn[randomCard]);

		// Add the converted element to the accreditation vector
		table.push_back(tableElement);
	}

	// Shows cards placed on table
	cout << playerName.mProfName << " cards on table: " << endl;
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


	if (piffle.mProfPrestige > plagiarist.mProfPrestige)
	{
		if (plagiarist.mProfPrestige < 0)
		{
			plagiarist.mProfPrestige = 0;
		}
		cout << plagiarist.mProfName << " prestige is " << plagiarist.mProfPrestige << " " << piffle.mProfName << " prestige is " << piffle.mProfPrestige << endl
			<< piffle.mProfName << " wins" << endl << endl;

		cout << "Game Over" << endl;
	}
	else if (plagiarist.mProfPrestige > piffle.mProfPrestige)
	{
		if (piffle.mProfPrestige < 0)
		{
			piffle.mProfPrestige = 0;
		}
		cout << piffle.mProfName << " prestige is " << piffle.mProfPrestige << " " << plagiarist.mProfName << " prestige is " << plagiarist.mProfPrestige << endl
			<< plagiarist.mProfName << " wins!" << endl << endl;

		cout << "Game Over" << endl;
	}
}

void CManager::StartRound(int &round)
{
	cout << "Round: " << round << endl;
	round++;
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

void CManager::DrawCard(vector<shared_ptr<CCard>>& cards, vector<shared_ptr<CCard>>& drawnCards, int& deckCounter, int& i, CPlayers::SProfessor playerName, vector<shared_ptr<bool>>& usedCards)
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
			cout << playerName.mProfName << " has drawn " << drawnCards.back()->mType << " " << drawnCards.back()->mFirstname << " " << drawnCards.back()->mLastname << " " << drawnCards.back()->mPower << " " << drawnCards.back()->mResilience << " " << drawnCards.back()->mBoost << endl;
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
void CManager::UseStudentCard(vector<shared_ptr<CTable>>& tableAttacked, vector<shared_ptr<CTable>>& tableAttacker, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, string name, string nametwo, vector<shared_ptr<CCard>> cardDrawn, int randomCard, int& typeFiveCounter)
{
	professorAttacked.mProfName = name;
	professorAttacker.mProfName = nametwo;

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
				cout << "Card Killed: " << tableAttacked[i]->mType << " " << tableAttacked[i]->mFirstname << " " << tableAttacked[i]->mLastname << " " << tableAttacked[i]->mPower << " " << tableAttacked[i]->mResilience << " " << tableAttacked[i]->mBoost << " by player " << professorAttacker.mProfName << endl;
				tableAttacked[i]->mResilience = DEAD_CARD;
				tableAttacked.erase(tableAttacked.begin() + i);
			}
		}
		if (tableAttacked.size() <= 0) {
			professorAttacked.mProfPrestige -= cardPower;
		}
		j--;

	}

	if (professorAttacked.mProfPrestige < 0)
	{
		professorAttacked.mProfPrestige = 0;
	}
	cout << professorAttacked.mProfName << " prestige is now " << professorAttacked.mProfPrestige << endl;
}

void CManager::UseFeedbackForumCard(vector<shared_ptr<CCard>> cardsDrawn, vector<shared_ptr<CFeedbackForum>>& feedbackforum, vector<shared_ptr<CTable>>& tableAttacked, int randomCard, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, string attackedName, string attackerName, int randomChoice, vector<shared_ptr<CTable>>& tableAttacker)
{
	if (cardsDrawn[randomCard]->mType == "4" && cardsDrawn[randomCard]->mResilience != DEAD_CARD)
	{
		// Convert the shared_ptr<CCard> to a shared_ptr<CDrawCourseAccreditationCard>
		shared_ptr<CFeedbackForum> feedbackElement = static_pointer_cast<CFeedbackForum>(cardsDrawn[randomCard]);

		// Add the converted element to the accreditation vector
		feedbackforum.push_back(feedbackElement);

	}

	professorAttacked.mProfName = attackedName;
	professorAttacker.mProfName = attackerName;

	const int CARD_POWER = 2;
	int cardResilience = 0;

	for (int i = 0; i < feedbackforum.size(); i++)
	{
		if (randomChoice == 1)
		{
			int randomIndex = randomNumber->Random(tableAttacked.size() - 1);

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
					cout << "Card Killed: " << elementneeded->mType << " " << elementneeded->mFirstname << " " << elementneeded->mLastname << " " << elementneeded->mPower << " " << elementneeded->mResilience << " " << elementneeded->mBoost << " by player " << professorAttacker.mProfName << endl;
					elementneeded->mResilience = DEAD_CARD;
					tableAttacked.erase(tableAttacked.end() - 1);
				}
				professorAttacked.mProfPrestige -= CARD_POWER;
			}

			if (randomChoice == 2)
			{

				int randomIndex = randomNumber->Random(tableAttacker.size() - 1);
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
				professorAttacker.mProfPrestige += CARD_POWER;
				cout << professorAttacker.mProfName << " " << " has recieved healing of " << CARD_POWER << " points" << endl;
				cout << tableAttacker[tableAttacker.size() - 1]->mFirstname << " " << " has recieved healing of " << CARD_POWER << " points" << endl;
			}


			if (professorAttacked.mProfPrestige < 0)
			{
				professorAttacked.mProfPrestige = 0;
			}
			cout << professorAttacked.mProfName << " prestige is now " << professorAttacked.mProfPrestige << endl;
		}
	}
}

void CManager::UsePassLeaderCard(vector<shared_ptr<CCard>> cardsDrawn, vector<shared_ptr<CPassLeader>>& passLeader, int randomCard, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, string attackerName, vector<shared_ptr<CTable>>& tableAttacker)
{
	
	if (cardsDrawn[randomCard]->mType == "6" && (cardsDrawn[randomCard]->mType != DEAD_CARD))
	{
		// Convert the shared_ptr<CCard> to a shared_ptr<CDrawCourseAccreditationCard>
		shared_ptr<CPassLeader> passLeaderElement = static_pointer_cast<CPassLeader>(cardsDrawn[randomCard]);

		// Add the converted element to the pass leader vector
		passLeader.push_back(passLeaderElement);

	}

	professorAttacker.mProfName = attackerName;

	int passLeaderCounter = 0;

	for (int i = 0; i < passLeader.size(); i++)
	{
		passLeaderCounter++;
	}	

	for (int i = 0; i < passLeader.size(); i++)
	{
		if (!tableAttacker.empty() && tableAttacker[i]->mType == "6")
		{
        int cardPower = 0;
		cardPower = stoi(tableAttacker[i]->mPower);
		cardPower += passLeaderCounter;
		string cardPowerString = to_string(cardPower);
		tableAttacker[i]->mPower = cardPowerString;
		}
	}

	for (int i = 0; i < passLeader.size(); i++)
	{
		if (!tableAttacker.empty() && tableAttacker[i]->mType == "6")
		{
		cout << professorAttacker.mProfName << "'s " << tableAttacker[i]->mFirstname << " " << tableAttacker[i]->mLastname << "  " << tableAttacker[i]->mPower << " " << tableAttacker[i]->mResilience << " " << tableAttacker[i]->mBoost << " has recieved power increase of " << passLeaderCounter << " points" << endl;
		}
	}
}

void CManager::UseResearchFundingCard(vector<shared_ptr<CCard>> cardsDrawn, vector<shared_ptr<CResearchFunding>> researchFunding, int randomCard, CPlayers::SProfessor& professorAttacker, string attackerName, vector<shared_ptr<CTable>>& tableAttacker)
{
	if (cardsDrawn[randomCard]->mType == "7")
	{
		// Convert the shared_ptr<CCard> to a shared_ptr<CDrawCourseAccreditationCard>
		shared_ptr<CResearchFunding> researchFundingElement = static_pointer_cast<CResearchFunding>(cardsDrawn[randomCard]);

		// Add the converted element to the accreditation vector
		researchFunding.push_back(researchFundingElement);

	}

	professorAttacker.mProfName = attackerName;

	 int cardPowerAdditionInteger = 2;
	 int cardPower;

	 for (int i = 0; i < researchFunding.size(); i++)
	 {
		 int randomIndex = randomNumber->Random(tableAttacker.size() - 1);
		 if (randomIndex < tableAttacker.size())
		 {
			 if (!researchFunding.empty())
			 {

				 if (!tableAttacker.empty())
				 {

					shared_ptr<CCard> elementneeded = tableAttacker[randomIndex]; 
					cardPower = stoi(elementneeded->mPower);
					cardPower += cardPowerAdditionInteger;
					string cardPowerString = to_string(cardPower);
					tableAttacker[randomIndex]->mPower = cardPowerString;
					 
				 }

			 }

			 if (tableAttacker.empty())
			 {
				 professorAttacker.mProfPrestige += cardPowerAdditionInteger;
				 cout << professorAttacker.mProfName << " prestige is now " << professorAttacker.mProfPrestige << endl;

			 }
		 }
	 }
	 if (researchFunding.empty())
	 {

	 }
}

void CManager::UseMitigatingCircumstancesCard(shared_ptr<CStudent> damageReduction)
{
	int ok = damageReduction->grantDamageReduction();
}
