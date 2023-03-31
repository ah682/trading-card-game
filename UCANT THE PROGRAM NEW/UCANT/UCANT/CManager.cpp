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

unique_ptr<CCounter> randomNumber = make_unique<CCounter>(); // ?\

shared_ptr<CEasyTarget> TEST = make_shared<CEasyTarget>(); // ?



void CManager::UsePlagiarismHearingCard(vector<shared_ptr<CCard>>& cardsDrawn, vector <shared_ptr<CPlagiarismHearing>>& plagiarism, vector <shared_ptr<CTable>>& tableAttacked, int randomCard, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, string attackedName, string attackerName, int randomChoice, vector<shared_ptr<CEasyTarget>>& easyTarget)
{

	cout << "Using Plagiarism Hearing Card" << endl;

	if (cardsDrawn[randomCard]->mType == G_PLAGIARISM_HEARING && cardsDrawn[randomCard]->mResilience != G_DEAD_CARD)
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
		TEST->attackEasyTarget(CARD_POWER, easyTarget);
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
					cout << "Card Attacked: " << elementneeded->mType << " " << elementneeded->mFirstname << " " << elementneeded->mLastname << " " << elementneeded->mPower << " " << elementneeded->mResilience << " " << elementneeded->mBoost << " by player " << professorAttacker.mProfName << endl;
				}
				if (cardResilience <= 0) {
					elementneeded->mResilience = "-0";
					cout << "Card Killed: " << elementneeded->mType << " " << elementneeded->mFirstname << " " << elementneeded->mLastname << " " << elementneeded->mPower << " " << elementneeded->mResilience << " " << elementneeded->mBoost << " by player " << professorAttacker.mProfName << endl;
					elementneeded->mResilience = G_DEAD_CARD;
					tableAttacked.pop_back();
				}
			}

			if (randomChoice == 2) {
				professorAttacked.mProfPrestige -= CARD_POWER;
			}
			if (professorAttacked.mProfPrestige < 0)
			{
				professorAttacked.mProfPrestige = 0;
			}
		}
		cout << professorAttacked.mProfName << " prestige is now " << professorAttacked.mProfPrestige << endl;
	}
}

void CManager::UseCourseAccreditationCard(vector<shared_ptr<CCard>>& cardsDrawn, vector <shared_ptr<CCourseAccreditation>>& accreditation, vector<shared_ptr<CTable>>& tableAttacked, int randomCard, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, string attackedName, string attackerName, vector<shared_ptr<CEasyTarget>>& easyTarget)
{
	const int CARD_POWER = 1;
	int cardResilience = 0;

	cout << "Using Course Accreditation Card" << endl;

	if (cardsDrawn[randomCard]->mType == G_COURSE_ACCREDITATION && cardsDrawn[randomCard]->mResilience != G_DEAD_CARD)
	{
		// Convert the shared_ptr<CCard> to a shared_ptr<CDrawCourseAccreditationCard>
		shared_ptr<CCourseAccreditation> pAccreditationElement = static_pointer_cast<CCourseAccreditation>(cardsDrawn[randomCard]);

		// Add the converted element to the accreditation vector
		accreditation.push_back(pAccreditationElement);
	}

	professorAttacked.mProfName = attackedName;
	professorAttacker.mProfName = attackerName;

	for (int i = 0; i < accreditation.size(); i++)
	{
		if (!tableAttacked.empty()) {
			for (int j = 0; j < tableAttacked.size() - 1; j++)
			{
				TEST->attackEasyTarget(CARD_POWER, easyTarget);
				cardResilience = stoi(tableAttacked[j]->mResilience);
				cardResilience -= CARD_POWER;
				string cardResilienceString = to_string(cardResilience);
				tableAttacked[j]->mResilience = cardResilienceString;
				cout << "Card Attacked: " << tableAttacked[j]->mType << " " << tableAttacked[j]->mFirstname << " " << tableAttacked[j]->mLastname << " " << tableAttacked[j]->mPower << " " << tableAttacked[j]->mResilience << " " << tableAttacked[j]->mBoost << " by player " << professorAttacker.mProfName << endl;

				if (cardResilience <= 0) {
					tableAttacked[j]->mResilience = "0";
					cout << "Card Killed: " << tableAttacked[j]->mType << " " << tableAttacked[j]->mFirstname << " " << tableAttacked[j]->mLastname << " " << tableAttacked[j]->mPower << " " << tableAttacked[j]->mResilience << " " << tableAttacked[j]->mBoost << " by player " << professorAttacker.mProfName << endl;
					tableAttacked[j]->mResilience = G_DEAD_CARD;
					tableAttacked.erase(tableAttacked.begin() + j);
				}
			}

			professorAttacked.mProfPrestige -= CARD_POWER;

			if (professorAttacked.mProfPrestige < 0)
			{
				professorAttacked.mProfPrestige = 0;
			}
		}

	}
	cout << professorAttacked.mProfName << " prestige is now " << professorAttacked.mProfPrestige << endl;
}

void CManager::PrintTable(vector<shared_ptr<CTable>>& table, vector<shared_ptr<CCard>>& cardsDrawn, CPlayers::SProfessor playerName, string professor, int randomCard)
{
	cout << "Printing Table" << endl;
	playerName.mProfName = professor;
	if (((((cardsDrawn[randomCard]->mType == G_STUDENT || cardsDrawn[randomCard]->mType == G_INDUSTRIAL_PLACEMENT) || cardsDrawn[randomCard]->mType == G_PASS_LEADER) || cardsDrawn[randomCard]->mType == G_EASY_TARGET) || cardsDrawn[randomCard]->mType == G_FEEDBACK_FORUM) && cardsDrawn[randomCard]->mResilience != G_DEAD_CARD)
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

void CManager::StartRound(int& round)
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
			if (cardsStudent[i]->mType == G_STUDENT)
			{
				ss >> cardsStudent[i]->mType >> cardsStudent[i]->mFirstname >> cardsStudent[i]->mLastname >> cardsStudent[i]->mPower >> cardsStudent[i]->mResilience >> cardsStudent[i]->mBoost;
			}
		}

	}
}

void CManager::DrawCard(vector<shared_ptr<CCard>>& cards, vector<shared_ptr<CCard>>& drawnCards, int& deckCounter, int& i, CPlayers::SProfessor playerName, vector<shared_ptr<bool>>& usedCards)
{
	cout << "Drawing Cards" << endl;

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
void CManager::UseStudentCard(vector<shared_ptr<CTable>>& tableAttacked, vector<shared_ptr<CTable>>& tableAttacker, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, string name, string nametwo, vector<shared_ptr<CCard>> cardsDrawn, vector<shared_ptr<CStudent>>& ordinaryStudent, int randomCard, vector<shared_ptr<CEasyTarget>> &easyTarget)
{
	cout << "Using Ordinary Student Card" << endl;

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

				TEST->attackEasyTarget(cardPowerAttackerInt, easyTarget);

				if (cardResilienceAttackedInt > 0) {

					cardResilienceAttackedInt -= cardPowerAttackerInt;
					string cardResilienceStringDueled = to_string(cardResilienceAttackedInt);
					tableAttacked[randomIndex]->mResilience = cardResilienceStringDueled;
				}
				if (cardResilienceAttackedInt <= 0) {
					tableAttacked[randomIndex]->mResilience = "0";
					cout << "Card Killed: " << tableAttacked[randomIndex]->mType << " " << tableAttacked[randomIndex]->mFirstname << " " << tableAttacked[randomIndex]->mLastname << " " << tableAttacked[randomIndex]->mPower << " " << tableAttacked[randomIndex]->mResilience << " " << tableAttacked[randomIndex]->mBoost << " by player " << professorAttacker.mProfName << endl;
					tableAttacked[randomIndex]->mResilience = G_DEAD_CARD;
					tableAttacked.erase(tableAttacked.begin() + randomIndex);
				}
			}

			if (tableAttacked.empty()) {
				professorAttacked.mProfPrestige -= cardPowerAttackerInt;
			}

			if (professorAttacked.mProfPrestige < 0)
			{
				professorAttacked.mProfPrestige = 0;
			}


		}
		cout << professorAttacked.mProfName << " prestige is now " << professorAttacked.mProfPrestige << endl;
	}
	if (ordinaryStudent.empty())
	{
		cout << "No student cards to use" << endl;
	}

}

void CManager::UseFeedbackForumCard(vector<shared_ptr<CCard>> cardsDrawn, vector<shared_ptr<CFeedbackForum>>& feedbackforum, vector<shared_ptr<CTable>>& tableAttacked, int randomCard, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, string attackedName, string attackerName, int randomChoice, vector<shared_ptr<CTable>>& tableAttacker, vector<shared_ptr<CEasyTarget>>& easyTarget)
{

	cout << "Using FeedBackForum Card" << endl;

	if (cardsDrawn[randomCard]->mType == G_FEEDBACK_FORUM && cardsDrawn[randomCard]->mResilience != G_DEAD_CARD)
	{
		// Convert the shared_ptr<CCard> to a shared_ptr<CDrawCourseAccreditationCard>
		shared_ptr<CFeedbackForum> pFeedbackElement = static_pointer_cast<CFeedbackForum>(cardsDrawn[randomCard]);

		// Add the converted element to the accreditation vector
		feedbackforum.push_back(pFeedbackElement);

	}

	professorAttacked.mProfName = attackedName;
	professorAttacker.mProfName = attackerName;

	const int CARD_POWER = 2;
	int cardResilience = 0;

	for (int i = 0; i < feedbackforum.size(); i++)
	{
		TEST->attackEasyTarget(CARD_POWER, easyTarget );
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
					elementneeded->mResilience = G_DEAD_CARD;
					tableAttacked.erase(tableAttacked.begin() + randomIndex);
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

		}
		cout << professorAttacked.mProfName << " prestige is now " << professorAttacked.mProfPrestige << endl;
	}
}

void CManager::UsePassLeaderCard(vector<shared_ptr<CCard>> cardsDrawn, vector<shared_ptr<CPassLeader>>& passLeader, int randomCard, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, string attackerName, vector<shared_ptr<CTable>>& tableAttacker)
{
	cout << "Using PassLeader Card" << endl;
	if (randomCard < cardsDrawn.size())
	{
		if (cardsDrawn[randomCard]->mType == G_PASS_LEADER && (cardsDrawn[randomCard]->mType != G_DEAD_CARD))
		{
			// Convert the shared_ptr<CCard> to a shared_ptr<CDrawCourseAccreditationCard>
			shared_ptr<CPassLeader> pPassLeaderElement = static_pointer_cast<CPassLeader>(cardsDrawn[randomCard]);

			// Add the converted element to the pass leader vector
			passLeader.push_back(pPassLeaderElement);
		}
	}
	else
	{
		std::cout << "randomCard is out of range" << endl;
	}

	professorAttacker.mProfName = attackerName;

	int passLeaderCounter = 0;

	for (int i = 0; i < passLeader.size(); i++)
	{
		passLeaderCounter++;
	}

	for (int i = 0; i < passLeader.size(); i++)
	{
		if (!tableAttacker.empty() && i < tableAttacker.size() && tableAttacker[i]->mType == G_PASS_LEADER)
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
		if (!tableAttacker.empty() && i < tableAttacker.size() && tableAttacker[i]->mType == G_PASS_LEADER)
		{
			cout << professorAttacker.mProfName << "'s " << tableAttacker[i]->mFirstname << " " << tableAttacker[i]->mLastname << "  " << tableAttacker[i]->mPower << " " << tableAttacker[i]->mResilience << " " << tableAttacker[i]->mBoost << " has recieved power increase of " << passLeaderCounter << " points" << endl;
		}
	}
}

void CManager::UseResearchFundingCard(vector<shared_ptr<CCard>> cardsDrawn, vector<shared_ptr<CResearchFunding>> researchFunding, int randomCard, CPlayers::SProfessor& professorAttacker, string attackerName, vector<shared_ptr<CTable>>& tableAttacker)
{
	cout << "Using ResearchFunding Card" << endl;

	if (cardsDrawn[randomCard]->mType == G_RESEARCH_FUNDING)
	{
		// Convert the shared_ptr<CCard> to a shared_ptr<CDrawCourseAccreditationCard>
		shared_ptr<CResearchFunding> pResearchFundingElement = static_pointer_cast<CResearchFunding>(cardsDrawn[randomCard]);

		// Add the converted element to the accreditation vector
		researchFunding.push_back(pResearchFundingElement);

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
					cout << tableAttacker[randomIndex]->mType << " " << tableAttacker[randomIndex]->mFirstname << " " << tableAttacker[randomIndex]->mLastname << " " << tableAttacker[randomIndex]->mPower << " " << tableAttacker[randomIndex]->mResilience << " " << tableAttacker[randomIndex]->mBoost << "has recieved a power increase of " << cardPowerAdditionInteger << endl;

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
		cout << "There is no research funding cards to use" << endl;
	}
}

void CManager::UseMitigatingCircumstancesCard(vector<shared_ptr<CCard>> cardsDrawn, shared_ptr<CMitigatingCircumstances> damageReduction, vector<shared_ptr<CTable>>& tableAttacker, vector<shared_ptr<CMitigatingCircumstances>> mitigatingCircumstances, int randomCard)
{
	cout << "Using MitigatingCircumstances Card" << endl;
	if (randomCard < cardsDrawn.size())
	{
		if (cardsDrawn[randomCard]->mType == G_MITIGATING_CIRCUMSTANCES && (cardsDrawn[randomCard]->mType != G_DEAD_CARD))
		{
			// Convert the shared_ptr<CCard> to a shared_ptr<CDrawCourseAccreditationCard>
			shared_ptr<CMitigatingCircumstances> pMitigatingCircumstancesElement = static_pointer_cast<CMitigatingCircumstances>(cardsDrawn[randomCard]);

			// Add the converted element to the accreditation vector
			mitigatingCircumstances.push_back(pMitigatingCircumstancesElement);
		}
	}
	else
	{
		cout << "randomCard is out of range" << endl;
	}

	for (int i = 0; i < mitigatingCircumstances.size(); i++)
	{
		int randomIndex = randomNumber->Random(tableAttacker.size() - 1);
		if (randomIndex < tableAttacker.size())
		{
			if (!mitigatingCircumstances.empty())
			{
				if (!tableAttacker.empty())
				{
					if (randomIndex < tableAttacker.size())
					{
						int randomIndex = randomNumber->Random(tableAttacker.size() - 1);
						int tableAttackerResillienceInt = stoi(tableAttacker[randomIndex]->mResilience);
						if (damageReduction != nullptr) {
							int damageReductionGranted = damageReduction->grantDamageReduction(tableAttackerResillienceInt, damageReduction->mDamageReduction);
							string damageReductionString = to_string(damageReductionGranted);
							tableAttacker[randomIndex]->mResilience = damageReductionString;
							cout << "Damaged Reduced of card" << tableAttacker[randomIndex]->mType << tableAttacker[randomIndex]->mFirstname << tableAttacker[randomIndex]->mLastname << tableAttacker[randomIndex]->mPower << tableAttacker[randomIndex]->mResilience << tableAttacker[randomIndex]->mBoost << endl;
							// rest of the code
						}
						else {
							// skip the function or handle the null pointer case
						}

					}
					else
					{

					}
				}
			}

			if (tableAttacker.empty())
			{
				cout << "Table attacker is empty!" << endl;
			}
		}
	}
	if (mitigatingCircumstances.empty())
	{
		cout << "There is no mitigating circumstance cards to use" << endl;
	}
}
// Card Type 9 – Student – When students are activating, if there is an Easy Target in the enemy cohort, they MUST target them rather than choosing a random target.
void CManager::UseEasyTargetCard(vector<shared_ptr<CCard>> cardsDrawn, vector<shared_ptr<CEasyTarget>> easyTarget, int randomCard, CPlayers::SProfessor& professorAttacker, string attackerName, vector<shared_ptr<CTable>>& tableAttacker)
{
	cout << "Using EasyTarget Card" << endl;
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

	}
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

	}
}

// Create Card Type 10 function GraduateStudent
void CManager::UseSerialOffenderCard(vector<shared_ptr<CTable>>& tableAttacked, vector<shared_ptr<CTable>>& tableAttacker, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, string name, string nametwo, vector<shared_ptr<CCard>> cardsDrawn, vector<shared_ptr<CSerialOffender>>& serialOffender, int randomCard, vector<shared_ptr<CEasyTarget>>& easyTarget)
{
	cout << "Using Ordinary Student Card" << endl;

	int cardPowerAttackerInt = 0;
	int cardResilienceAttackerInt = 0;
	int cardPowerAttackedInt = 0;
	int cardResilienceAttackedInt = 0;

	if (cardsDrawn[randomCard]->mType == G_SERIAL_OFFENDER && cardsDrawn[randomCard]->mResilience != G_DEAD_CARD)
	{
		// Convert the shared_ptr<CCard> to a shared_ptr<CDrawCourseAccreditationCard>
		shared_ptr<CSerialOffender> pSerialOffenderElement = static_pointer_cast<CSerialOffender>(cardsDrawn[randomCard]);

		// Add the converted element to the accreditation vector
		serialOffender.push_back(pSerialOffenderElement);
	}

	professorAttacked.mProfName;
	professorAttacker.mProfName;

	if (!serialOffender.empty())
	{

		for (int i = 0; i < serialOffender.size(); i++)
		{

			string cardPowerAttacker = serialOffender[i]->mPower;
			string cardResilienceAttacker = serialOffender[i]->mResilience;

			if (!tableAttacked.empty()) {
				int randomIndex = randomNumber->Random(tableAttacked.size() - 1);

				string cardPowerAttacked = tableAttacked[randomIndex]->mPower;
				string cardResilienceAttacked = tableAttacked[randomIndex]->mResilience;

				cardPowerAttackerInt = stoi(cardPowerAttacker);
				cardResilienceAttackerInt = stoi(cardResilienceAttacker);
				cardPowerAttackedInt = stoi(cardPowerAttacked);
				cardResilienceAttackedInt = stoi(cardResilienceAttacked);

				TEST->attackEasyTarget(cardPowerAttackerInt, easyTarget);

				if (cardResilienceAttackedInt > 0) {

					cardResilienceAttackedInt -= cardPowerAttackerInt;
					string cardResilienceStringDueled = to_string(cardResilienceAttackedInt);
					tableAttacked[randomIndex]->mResilience = cardResilienceStringDueled;
					int leftOverDamage = cardPowerAttackerInt - cardResilienceAttackedInt;
					do
					{
						int additionalRandomIndex = randomNumber->Random(tableAttacked.size() - 1);
						int additionalEasyTargetRandomIndex = randomNumber->Random(serialOffender.size() - 1);
						int additionalCardResilienceAttackedInt = stoi(tableAttacked[additionalRandomIndex]->mResilience);
						int additionalCardResilienceAttackedIntEasyTarget = stoi(easyTarget[additionalEasyTargetRandomIndex]->mResilience);
						int additionalCardPowerAttackerInt = stoi(tableAttacked[randomIndex]->mPower);
						if (additionalCardResilienceAttackedIntEasyTarget > 0 && easyTarget.size() > 0)
						{
							additionalCardResilienceAttackedIntEasyTarget -= leftOverDamage;
							string additionalCardResilienceAttackedStringEasyTarget = to_string(additionalCardResilienceAttackedIntEasyTarget);
							easyTarget[randomIndex]->mResilience = additionalCardResilienceAttackedIntEasyTarget;
							if (additionalCardResilienceAttackedIntEasyTarget <= 0)
							{
								easyTarget.erase(easyTarget.begin() + additionalEasyTargetRandomIndex);
							}
						}
						if (additionalCardResilienceAttackedInt > 0 && easyTarget.size() <= 0)
						{
							additionalCardResilienceAttackedInt -= leftOverDamage;
							string additionalCardResilienceAttackedString = to_string(additionalCardResilienceAttackedInt);
							tableAttacked[randomIndex]->mResilience = additionalCardResilienceAttackedString;
							leftOverDamage -= additionalCardResilienceAttackedInt;
							if (additionalCardResilienceAttackedInt <= 0)
							{
								tableAttacked.erase(tableAttacked.begin() + additionalRandomIndex);
							}
						}


					} while (leftOverDamage > 0);

				}
				if (cardResilienceAttackedInt <= 0) {
					tableAttacked[randomIndex]->mResilience = "0";
					cout << "Card Killed: " << tableAttacked[randomIndex]->mType << " " << tableAttacked[randomIndex]->mFirstname << " " << tableAttacked[randomIndex]->mLastname << " " << tableAttacked[randomIndex]->mPower << " " << tableAttacked[randomIndex]->mResilience << " " << tableAttacked[randomIndex]->mBoost << " by player " << professorAttacker.mProfName << endl;
					tableAttacked[randomIndex]->mResilience = G_DEAD_CARD;
					tableAttacked.erase(tableAttacked.begin() + randomIndex);
				}
			}

			if (tableAttacked.empty()) {
				professorAttacked.mProfPrestige -= cardPowerAttackerInt;
			}

			if (professorAttacked.mProfPrestige < 0)
			{
				professorAttacked.mProfPrestige = 0;
			}


		}
		cout << professorAttacked.mProfName << " prestige is now " << professorAttacked.mProfPrestige << endl;
	}
	if (serialOffender.empty())
	{
		cout << "No serial offender cards to use" << endl;
	}
}


void CManager::UseIndustrialPlacementCard(vector<shared_ptr<CCard>> cardsDrawn, vector<shared_ptr<CIndustrialPlacement>>& industrialPlacement, int randomCard, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, string attackerName, vector<shared_ptr<CTable>>& tableAttacker, vector<shared_ptr<CTable>>& tableAttacked, vector<shared_ptr<CEasyTarget>>& easyTarget)
{
	cout << "Using IndustrialPlacement Card" << endl;
	int cardPowerAttackerInt = 0;
	int cardResilienceAttackerInt = 0;
	int cardPowerAttackedInt = 0;
	int cardResilienceAttackedInt = 0;
	int increaseResilience = 1;

	if (cardsDrawn[randomCard]->mType == G_STUDENT && cardsDrawn[randomCard]->mResilience != G_DEAD_CARD)
	{
		// Convert the shared_ptr<CCard> to a shared_ptr<CDrawCourseAccreditationCard>
		shared_ptr<CIndustrialPlacement> pStudentElement = static_pointer_cast<CIndustrialPlacement>(cardsDrawn[randomCard]);

		// Add the converted element to the accreditation vector
		industrialPlacement.push_back(pStudentElement);
	}

	professorAttacked.mProfName;
	professorAttacker.mProfName;

	if (!industrialPlacement.empty())
	{

		for (int i = 0; i < industrialPlacement.size(); i++)
		{
			
			string cardPowerAttacker = industrialPlacement[i]->mPower;
			string cardResilienceAttacker = industrialPlacement[i]->mResilience;
			

			if (!tableAttacked.empty()) {
				int randomIndex = randomNumber->Random(tableAttacked.size() - 1);

				string cardPowerAttacked = tableAttacked[randomIndex]->mPower;
				string cardResilienceAttacked = tableAttacked[randomIndex]->mResilience;

				cardPowerAttackerInt = stoi(cardPowerAttacker);
				cardResilienceAttackerInt = stoi(cardResilienceAttacker);
				cardPowerAttackedInt = stoi(cardPowerAttacked);
				cardResilienceAttackedInt = stoi(cardResilienceAttacked);



				if (cardResilienceAttackedInt > 0) {
					TEST->attackEasyTarget(cardPowerAttackerInt, easyTarget);
					if (easyTarget.size() > 0)
					{
						cardResilienceAttackerInt += increaseResilience;
					}
					cardResilienceAttackedInt -= cardPowerAttackerInt;
					string cardResilienceStringDueled = to_string(cardResilienceAttackedInt);
					tableAttacked[randomIndex]->mResilience = cardResilienceStringDueled;
					cardResilienceAttackerInt += increaseResilience;
					string cardResilienceStringAttacker = to_string(cardResilienceAttackerInt);
					cardsDrawn[randomCard]->mResilience = cardResilienceStringAttacker;
					cout << "Card Attacked: " << tableAttacked[randomIndex]->mType << " " << tableAttacked[randomIndex]->mFirstname << " " << tableAttacked[randomIndex]->mLastname << " " << tableAttacked[randomIndex]->mPower << " " << tableAttacked[randomIndex]->mResilience << " " << tableAttacked[randomIndex]->mBoost << " by player " << professorAttacker.mProfName << endl;
				}
				if (cardResilienceAttackedInt <= 0) {
					tableAttacked[randomIndex]->mResilience = "0";
					cout << "Card Killed: " << tableAttacked[randomIndex]->mType << " " << tableAttacked[randomIndex]->mFirstname << " " << tableAttacked[randomIndex]->mLastname << " " << tableAttacked[randomIndex]->mPower << " " << tableAttacked[randomIndex]->mResilience << " " << tableAttacked[randomIndex]->mBoost << " by player " << professorAttacker.mProfName << endl;
					tableAttacked[randomIndex]->mResilience = G_DEAD_CARD;
					tableAttacked.erase(tableAttacked.begin() + randomIndex);
				}
			}

			if (tableAttacked.empty()) {
				professorAttacked.mProfPrestige -= cardPowerAttackerInt;
				cardResilienceAttackerInt += increaseResilience;
				string cardResilienceStringAttacker = to_string(cardResilienceAttackerInt);
				cardsDrawn[randomCard]->mResilience = cardResilienceStringAttacker;
			}

			if (professorAttacked.mProfPrestige < 0)
			{
				professorAttacked.mProfPrestige = 0;
			}

		}
		cout << professorAttacked.mProfName << " prestige is now " << professorAttacked.mProfPrestige << endl;
	}
	if (industrialPlacement.empty())
	{
		cout << "No Industrial Placement cards to use" << endl;
	}
}



