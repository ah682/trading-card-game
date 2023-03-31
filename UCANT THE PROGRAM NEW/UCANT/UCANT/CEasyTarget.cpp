// Adam James Anthony Hall
#include "CStudent.h"
#include "CEasyTarget.h"
#include "CCard.h"
#include "CCounter.h"
#include "CManager.h"

unique_ptr<CCounter> TEST = make_unique<CCounter>(); // ?

int CEasyTarget::attackEasyTarget(int damage, vector <shared_ptr<CEasyTarget>>& attacked)
{
	if (attacked.size() > 0)
	{
		int randomIndex = TEST->Random(attacked.size() - 1);
		int  attackedResilience = stoi(attacked[randomIndex]->mResilience);
		attackedResilience -= damage;

		if (attackedResilience > 0)
		{
			string attackedResilienceString = to_string(attackedResilience);
			cout << "Easy Target who was Attacked Resilience: " << attacked[randomIndex]->mResilience << endl;
		}
		if (attackedResilience <= 0)
		{
			attacked[randomIndex]->mResilience = "0";
			cout << "Easy Target Killed" << endl;
			attacked[randomIndex]->mResilience = G_DEAD_CARD;
			attacked.erase(attacked.begin() + randomIndex);

		}
	}
	if (attacked.size() <= 0)
	{
		cout << "No Easy Targets left" << endl;
	}
	return damage;
}