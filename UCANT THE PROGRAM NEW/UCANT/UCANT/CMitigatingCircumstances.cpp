// Adam James Anthony Hall
#include "CMitigatingCircumstances.h"

/**

This function is a method of the CMitigatingCircumstances class.
It takes in two integer parameters: damage and mDamageReduction.
The method adds the mDamageReduction value to the damage value and returns the sum.
This method is used to grant damage reduction and returns the left-over damage if required.
@param damage an integer value representing the amount of damage.
@param mDamageReduction an integer value representing the amount of damage reduction.
@return an integer value representing the sum of damage and damage reduction.
*/
int CMitigatingCircumstances::useCardSpecialAbility(int damage, int mDamageReduction) // Grant Damage Reduction returns left over dmaage if required
{
	damage += mDamageReduction;
	return damage;
}

/**

This function uses a vector of shared pointers to CCards drawn from a deck, a shared pointer to CMitigatingCircumstances damage reduction object, a vector of shared pointers to CTable objects representing attackers,
a vector of shared pointers to CMitigatingCircumstances objects and a random integer to select a card from the deck. It first prints the type of card being used and then checks if the random integer is within the range of the cardsDrawn vector.
If it is, it checks if the card's type is a mitigating circumstance card and adds it to the mitigatingCircumstances vector if so. It then proceeds to loop through the mitigatingCircumstances vector and for each mitigating circumstance,
generates a random index within the range of the tableAttacker vector. If the index is within the range and mitigatingCircumstances and tableAttacker vectors are not empty, the function calculates the damage reduction granted by the damageReduction object
and subtracts it from the attacker's resilience. It then prints out the card's details along with the amount of damage reduced. If the tableAttacker vector is empty, the function prints out a message indicating so.
If the mitigatingCircumstances vector is empty, the function proceeds to clear it.
*/
void CMitigatingCircumstances::useCard(vector<shared_ptr<CCard>> cardsDrawn, shared_ptr<CMitigatingCircumstances> damageReduction, vector<shared_ptr<CTable>>& tableAttacker, vector<shared_ptr<CMitigatingCircumstances>> mitigatingCircumstances, int randomCard)
{
	unique_ptr<CMitigatingCircumstances> printCardType = make_unique<CMitigatingCircumstances>();
	unique_ptr<CCounter> randomNumber = make_unique<CCounter>();
	printCardType->printCardUse();
	if (randomCard < cardsDrawn.size())
	{
		if (cardsDrawn[randomCard]->mType == G_MITIGATING_CIRCUMSTANCES)
		{
			// Convert the shared_ptr<CCard> to a shared_ptr<CDrawCourseAccreditationCard>
			shared_ptr<CMitigatingCircumstances> pMitigatingCircumstancesElements = static_pointer_cast<CMitigatingCircumstances>(cardsDrawn[randomCard]);

			// Add the converted element to the accreditation vector
			mitigatingCircumstances.push_back(pMitigatingCircumstancesElements);
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
							damageReduction->mDamageReductionGetterInt = damageReduction->getMDamageReduction();
							int damageReductionGranted = damageReduction->useCardSpecialAbility(tableAttackerResillienceInt, damageReduction->mDamageReductionGetterInt);
							string damageReductionString = to_string(damageReductionGranted);
							tableAttacker[randomIndex]->mResilience = damageReductionString;
							cout << "Damaged Reduced of card" << tableAttacker[randomIndex]->mType << tableAttacker[randomIndex]->mFirstName << tableAttacker[randomIndex]->mLastName << tableAttacker[randomIndex]->mPower << tableAttacker[randomIndex]->mResilience << tableAttacker[randomIndex]->mBoost << endl;
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

	}
	mitigatingCircumstances.clear();
}


int CMitigatingCircumstances::getMDamageReduction() { // Getter method for the mDamageReductionInt variable.
	return mDamageReductionInt;
}

void CMitigatingCircumstances::printCardUse()
{

}