// Adam James Anthony Hall
#include "CStudent.h"
#include "CEasyTarget.h"
#include "CCard.h"
#include "CCounter.h"
#include "CManager.h"



int CEasyTarget::attackEasyTarget(int damage, vector <shared_ptr<CEasyTarget>>& attacked)
{
	unique_ptr<CCounter> pickRandom = make_unique<CCounter>();
	unique_ptr<CEasyTarget> cardType = make_unique<CEasyTarget>();

	if (attacked.size() > 0)
	{
		int randomIndex = pickRandom->Random(attacked.size() - 1);
		int  attackedResilience = stoi(attacked[randomIndex]->mResilience);
		attackedResilience -= damage;

		if (attackedResilience > 0)
		{
			string attackedResilienceString = to_string(attackedResilience);
			cout << "Easy Target who was Attacked Resilience: " << attacked[randomIndex]->mResilience << endl;
		}
		if (attackedResilience <= 0)
		{
			
			cardType->activateCardDeath(randomIndex, attacked);
		}
	}
	if (attacked.size() <= 0)
	{
		cout << "No Easy Targets left" << endl;
	}
	return damage;
}

void CEasyTarget::printCardUse()
{
	cout << "Using Easy Target Card" << endl;
}

void CEasyTarget::activateCardDeath(int additionalEasyTargetRandomIndex, vector<shared_ptr<CEasyTarget>>& attacked)
{
	cout << attacked[additionalEasyTargetRandomIndex]->mFirstname << attacked[additionalEasyTargetRandomIndex]->mLastname << " is defeated" << endl;
	

	attacked[additionalEasyTargetRandomIndex]->mResilience = "0";
	cout << "Easy Target Killed" << endl;
	attacked[additionalEasyTargetRandomIndex]->mResilience = G_DEAD_CARD;
	attacked.erase(attacked.begin() + additionalEasyTargetRandomIndex);
	
}