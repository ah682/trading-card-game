// Adam James Anthony Hall
#include "CPassLeader.h"


//Gives buff
void::CPassLeader::useCard(vector<shared_ptr<CCard>> cardsDrawn, vector<shared_ptr<CPassLeader>>& passLeader, int randomCard, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, string attackerName, vector<shared_ptr<CTable>>& tableAttacker)
{
	unique_ptr<CPassLeader> printCardType = make_unique<CPassLeader>();
	printCardType->printCardUse();
	if (randomCard < cardsDrawn.size())
	{
		if (cardsDrawn[randomCard]->mType == G_PASS_LEADER)
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
	if (passLeader.empty())
	{
		cout << "There is no pass leader cards to use" << endl;
	}
}
void::CPassLeader::printCardUse()
{
	cout << "Using Pass Leader Card" << endl;
}

void::CPassLeader::activateCardDeath()
{
	cout << "You have been killed by the Pass Leader card." << endl;
}
