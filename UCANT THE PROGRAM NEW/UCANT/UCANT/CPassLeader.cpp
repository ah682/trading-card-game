// Adam James Anthony Hall
#include "CPassLeader.h"


/**

This function receives a vector of shared pointers to cards, a vector of shared pointers to CPassLeader objects,
an integer representing the index of a randomly drawn card, two structures representing professors, a string representing
the name of the attacker, and a vector of shared pointers to CTable objects. It checks if the card at the given index is a
CPassLeader card and adds it to the passLeader vector if it is. Then, it counts the number of CPassLeader cards in the passLeader
vector and increases the power of each CPassLeader card on the attacker's table by the number of CPassLeader cards in the passLeader
vector. Finally, it prints a message indicating the power increase for each affected CPassLeader card.
*/
void::CPassLeader::useCard(vector<shared_ptr<CCard>> cardsDrawn, vector<shared_ptr<CPassLeader>>& passLeader, int randomCard, CPlayers& professorAttacked, CPlayers& professorAttacker, string attackerName, vector<shared_ptr<CTable>>& tableAttacker)
{
	unique_ptr<CPassLeader> printCardType = make_unique<CPassLeader>();
	printCardType->printCardUse();
	if (randomCard < cardsDrawn.size())
	{
		if (cardsDrawn[randomCard]->mType == G_PASS_LEADER)
		{
			// Convert the shared_ptr<CCard> to a shared_ptr<CDrawCourseAccreditationCard>
			shared_ptr<CPassLeader> pPassLeaderElements = static_pointer_cast<CPassLeader>(cardsDrawn[randomCard]);

			// Add the converted element to the pass leader vector
			passLeader.push_back(pPassLeaderElements);
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
			cout << professorAttacker.mProfName << "'s " << tableAttacker[i]->mFirstName << " " << tableAttacker[i]->mLastName << "  " << tableAttacker[i]->mPower << " " << tableAttacker[i]->mResilience << " " << tableAttacker[i]->mBoost << " has recieved power increase of " << passLeaderCounter << " points" << endl;
		}
	}
	if (passLeader.empty())
	{

	}
	passLeader.clear();
}
void::CPassLeader::printCardUse()
{

}

void::CPassLeader::activateCardDeath()
{
	cout << "You have been killed by the Pass Leader card." << endl;
}
