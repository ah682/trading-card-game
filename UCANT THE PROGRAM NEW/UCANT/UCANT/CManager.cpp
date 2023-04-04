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
#include "CSerialOffender.h"
#include "CMitigatingCircumstances.h"
#include "CIndustrialPlacement.h"
#include "CEasyTarget.h"
#include "CGraduateStudent.h"

// Tells the compiler to use the standard namespace
using namespace std;

void CManager::PrintTable(vector<shared_ptr<CTable>>& table, vector<shared_ptr<CCard>>& cardsDrawn, CPlayers::SProfessor playerName, string professor, int randomCard)
{
	cout << "Printing Table" << endl;
	playerName.mProfName = professor;
	if (((((((cardsDrawn[randomCard]->mType == G_STUDENT || cardsDrawn[randomCard]->mType == G_INDUSTRIAL_PLACEMENT) || cardsDrawn[randomCard]->mType == G_PASS_LEADER) || cardsDrawn[randomCard]->mType == G_EASY_TARGET) || cardsDrawn[randomCard]->mType == G_FEEDBACK_FORUM) || cardsDrawn[randomCard]->mType == G_SERIAL_OFFENDER) || cardsDrawn[randomCard]->mType == G_GRADUATE_STUDENT) && cardsDrawn[randomCard]->mResilience != G_DEAD_CARD)
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
		cout << plagiarist.mProfName << " prestige is " << plagiarist.mProfPrestige << " " << piffle.mProfName << " prestige is " << piffle.mProfPrestige << endl << plagiarist.mProfName << " has no prestige and is a sacked!" << endl << piffle.mProfName << " wins" << endl;

		cout << "Game Over" << endl;
	}
	else if (plagiarist.mProfPrestige > piffle.mProfPrestige)
	{
		if (piffle.mProfPrestige < 0)
		{
			piffle.mProfPrestige = 0;
		}
		cout << piffle.mProfName << " prestige is " << piffle.mProfPrestige << " " << plagiarist.mProfName << " prestige is " << plagiarist.mProfPrestige << endl << piffle.mProfName << " has no prestige and is a sacked!" << endl << plagiarist.mProfName << " wins" << endl;

		cout << "Game Over" << endl;
	}
}

void CManager::StartRound(int& round)
{
	cout << "Round: " << round << endl << "=========" << endl;
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
			if (cardsStudent[i]->mType == G_STUDENT)
			{
				ss >> cardsStudent[i]->mType >> cardsStudent[i]->mFirstname >> cardsStudent[i]->mLastname >> cardsStudent[i]->mPower >> cardsStudent[i]->mResilience >> cardsStudent[i]->mBoost;
			}
		}

	}
}

void CManager::DrawCard(vector<shared_ptr<CCard>>& cards, vector<shared_ptr<CCard>>& drawnCards, int& deckCounter, int& i, CPlayers::SProfessor playerName, vector<shared_ptr<bool>>& usedCards)
{
	cout << "Drawing Card" << endl;

	for (int j = i; j < deckCounter; j++)
	{
		if (i == G_DECK_SIZE)
		{
			break;
		}
		if (*usedCards[j] == false)
		{
			drawnCards.push_back(cards[j]);
			*usedCards[j] = true;
			cout << playerName.mProfName << " draws " << drawnCards[j]->mType << " " << drawnCards[j]->mFirstname << " " << drawnCards[j]->mLastname << " " << drawnCards[j]->mPower << " " << drawnCards[j]->mResilience << " " << drawnCards[j]->mBoost << endl;
			cout << playerName.mProfName << " plays " << drawnCards[j]->mFirstname << " " << drawnCards[j]->mLastname << " " << drawnCards[j]->mPower << " " << drawnCards[j]->mResilience << " " << drawnCards[j]->mBoost << endl;
		}
		else
		{
			i++;
			deckCounter++;
			*usedCards[j] = true;
		}
	}
}

void CManager::pushToHand(vector<shared_ptr<CCard>>& drawnCards, vector<shared_ptr<CCard>>& hand, int& i, CPlayers::SProfessor playerName)
{
	cout << "Pushing Cards to Hand" << endl;
	for (int j = i; j < drawnCards.size(); j++)
	{
		if (i == G_DECK_SIZE)
		{
			break;
		}
		if (hand.size() < 2)
		{
			hand.push_back(drawnCards[j]);
			cout << playerName.mProfName << " has pushed " << hand[j]->mType << " " << hand[j]->mFirstname << " " << hand[j]->mLastname << " " << hand[j]->mPower << " " << hand[j]->mResilience << " " << hand[j]->mBoost << " to hand" << endl;
		}
	}
} 

//Prof name is the one getting attacked
void CManager::UseStudentCard(vector<shared_ptr<CTable>>& tableAttacked, vector<shared_ptr<CTable>>& tableAttacker, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, vector<shared_ptr<CCard>> cardsDrawn, vector<shared_ptr<CStudent>>& ordinaryStudent, int randomCard, vector<shared_ptr<CEasyTarget>> &easyTarget)
{
	unique_ptr<CCounter> randomNumber = make_unique<CCounter>(); 
	shared_ptr<CEasyTarget> activateEasyTarget = make_shared<CEasyTarget>(); 
	shared_ptr<CStudent> printCardType = make_shared<CStudent>();

	activateEasyTarget->printCardUse();

	int cardPowerAttackerInt = 0;
	int cardResilienceAttackerInt = 0;
	int cardPowerAttackedInt = 0;
	int cardResilienceAttackedInt = 0;

	if (cardsDrawn[randomCard]->mType == G_STUDENT && cardsDrawn[randomCard]->mResilience != G_DEAD_CARD)
	{
		// Convert the shared_ptr<CCard> to a shared_ptr<CDrawCourseAccreditationCard>
		shared_ptr<CStudent> pStudentElement = static_pointer_cast<CStudent>(cardsDrawn[randomCard]);

		// Add the converted element to the accreditation vector
		ordinaryStudent.push_back(pStudentElement);
	}

	professorAttacked.mProfName;
	professorAttacker.mProfName;

	if (!ordinaryStudent.empty())
	{

		for (int i = 0; i < ordinaryStudent.size(); i++)
		{
			
			string cardPowerAttacker = ordinaryStudent[i]->mPower;
			string cardResilienceAttacker = ordinaryStudent[i]->mResilience;

			if (!tableAttacked.empty()) {
				int randomIndex = randomNumber->Random(tableAttacked.size() - 1);

				string cardPowerAttacked = tableAttacked[randomIndex]->mPower;
				string cardResilienceAttacked = tableAttacked[randomIndex]->mResilience;

				cardPowerAttackerInt = stoi(cardPowerAttacker);
				cardResilienceAttackerInt = stoi(cardResilienceAttacker);
				cardPowerAttackedInt = stoi(cardPowerAttacked);
				cardResilienceAttackedInt = stoi(cardResilienceAttacked);

				activateEasyTarget->useCardSpecialAbility(cardPowerAttackerInt, easyTarget);

				if (cardResilienceAttackedInt > 0) {

					cardResilienceAttackedInt -= cardPowerAttackerInt;
					string cardResilienceStringDueled = to_string(cardResilienceAttackedInt);
					tableAttacked[randomIndex]->mResilience = cardResilienceStringDueled;
					cout << cardsDrawn[randomCard]->mFirstname << " " << cardsDrawn[randomCard]->mLastname << " attacks : " << tableAttacked[randomIndex]->mType << " " << tableAttacked[randomIndex]->mFirstname << " " << tableAttacked[randomIndex]->mLastname << " " << tableAttacked[randomIndex]->mPower << " " << tableAttacked[randomIndex]->mResilience << " " << tableAttacked[randomIndex]->mBoost << " " << tableAttacked[randomIndex]->mFirstname << " " << tableAttacked[randomIndex]->mLastname << " resilience is now " << tableAttacked[randomIndex]->mResilience << endl;
				}
				if (cardResilienceAttackedInt <= 0) {
					printCardType->activateCardDeath(randomIndex, tableAttacked);
				}
			}

			if (tableAttacked.empty()) {
				professorAttacked.mProfPrestige -= cardPowerAttackerInt;
				cout << cardsDrawn[randomCard]->mFirstname << " " << cardsDrawn[randomCard]->mLastname << " attacks  " << professorAttacked.mProfName << " prestige is now " << professorAttacked.mProfPrestige << endl;
			}

			if (professorAttacked.mProfPrestige < 0)
			{
				professorAttacked.mProfPrestige = 0;
			}


		}
	}
	if (ordinaryStudent.empty())
	{
		cout << "No student cards to use" << endl;
	}

}

// Card Type 9 – Student – When students are activating, if there is an Easy Target in the enemy cohort, they MUST target them rather than choosing a random target.
void CManager::UseEasyTargetCard(vector<shared_ptr<CCard>> cardsDrawn, vector<shared_ptr<CEasyTarget>> easyTarget, int randomCard, CPlayers::SProfessor& professorAttacker, string attackerName, vector<shared_ptr<CTable>>& tableAttacker)
{
	unique_ptr<CEasyTarget> printCardType = make_unique<CEasyTarget>();
	unique_ptr<CCounter> randomNumber = make_unique<CCounter>(); // ?
	printCardType->printCardUse();
	if (randomCard < cardsDrawn.size())
	{
		if (cardsDrawn[randomCard]->mType == G_EASY_TARGET && (cardsDrawn[randomCard]->mType != G_DEAD_CARD))
		{
			// Convert the shared_ptr<CCard> to a shared_ptr<CDrawCourseAccreditationCard>
			shared_ptr<CEasyTarget> pEasyTargetElement = static_pointer_cast<CEasyTarget>(cardsDrawn[randomCard]);
			// Add the converted element to the accreditation vector
			easyTarget.push_back(pEasyTargetElement);
		}
	}
	else
	{


		professorAttacker.mProfName = attackerName;
		for (int i = 0; i < easyTarget.size(); i++)
		{
			int randomIndex = randomNumber->Random(tableAttacker.size() - 1);
			if (randomIndex < tableAttacker.size())
			{
				if (!easyTarget.empty())
				{
					if (!tableAttacker.empty())
					{
						if (randomIndex < tableAttacker.size())
						{
						}
						else
						{

						}
					}
				}
				if (tableAttacker.empty())
				{

				}
			}
		}
		if (easyTarget.empty())
		{
			cout << "Easy Target card is empty" << endl;
		}
	}
}

