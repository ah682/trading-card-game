// Adam James Anthony Hall
#include "CStudent.h"
#include "CEasyTarget.h"
#include "CCard.h"
#include "CCounter.h"
#include "CStudent.h"
#include "CManager.h"



/**
Attacks an easy target.

@param damage The amount of damage to inflict.

@param attacked A vector of shared pointers to the easy targets that can be attacked.

@return The damage inflicted, if required.
*/
int CEasyTarget::useCardSpecialAbility(int damage, vector <shared_ptr<CEasyTarget>>& attacked) // Returns damage if required
{
	unique_ptr<CCounter> pickRandom = make_unique<CCounter>();
	unique_ptr<CEasyTarget> cardType = make_unique<CEasyTarget>();

	if (attacked.size() > 0)
	{
		int randomIndex = pickRandom->Random(attacked.size() - 1);
		int attackedResilience = stoi(attacked[randomIndex]->mResilience);
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
	if (attacked.size() <= 0 || attacked.empty())
	{
		//If there is no easy targets left do nothing
	}
	return damage;
}

void CEasyTarget::printCardUse()
{
	
}

/**
This function activates the death of an Easy Target card when its resilience reaches 0 or below.
It outputs a message indicating which Easy Target card was defeated and removes the card from the 'attacked' vector.
@param additionalEasyTargetRandomIndex An integer representing the index of the Easy Target card that reached 0 or below resilience.
@param attacked A vector of shared pointers to Easy Target cards representing the cards that were attacked.
*/
void CEasyTarget::activateCardDeath(int additionalEasyTargetRandomIndex, vector<shared_ptr<CEasyTarget>>& attacked) // overload
{
	cout << attacked[additionalEasyTargetRandomIndex]->mFirstname << attacked[additionalEasyTargetRandomIndex]->mLastname << " is defeated" << endl;
	cout << "Easy Target Killed" << endl;
	attacked.erase(attacked.begin() + additionalEasyTargetRandomIndex);
	
}

/**

This method is responsible for using Card Type 9 - Student. When students are activating, if there is an Easy Target in the enemy cohort, they MUST target them rather than choosing a random target.

@param cardsDrawn A vector containing shared pointers to all cards drawn

@param easyTarget A vector containing shared pointers to all Easy Target cards in play

@param randomCard An integer representing the index of the card chosen at random

@param professorAttacker A struct representing the attacking professor

@param attackerName A string representing the name of the attacking professor

@param tableAttacker A vector containing shared pointers to all tables in the attacking professor's cohort
*/
void CEasyTarget::UseCard(vector<shared_ptr<CCard>> cardsDrawn, vector<shared_ptr<CEasyTarget>> easyTarget, int randomCard, CPlayers& professorAttacker, string attackerName, vector<shared_ptr<CTable>>& tableAttacker)
{
	unique_ptr<CEasyTarget> printCardType = make_unique<CEasyTarget>();
	unique_ptr<CCounter> randomNumber = make_unique<CCounter>();
	printCardType->printCardUse();
	if (randomCard < cardsDrawn.size())
	{
		if (cardsDrawn[randomCard]->mType == G_EASY_TARGET)
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

/**

Attacks an easy target entity with additional left over damage.
@param additionalCardResilienceAttackedIntEasyTarget an integer representing the additional damage.
@param leftOverDamage an integer representing the amount of left over damage.
@param randomIndex an integer representing the index of the attacked entity in the vector of easy targets.
@param additionalEasyTargetRandomIndex an integer representing the index of the attacked entity in the vector of easy targets.
@param easyTarget a vector of shared pointers representing the collection of easy targets.
@return void
*/
void CEasyTarget::attackEntity(int& additionalCardResilienceAttackedIntEasyTarget, int& leftOverDamage, int randomIndex, int additionalEasyTargetRandomIndex, vector<shared_ptr<CEasyTarget>>& easyTarget)
{
	additionalCardResilienceAttackedIntEasyTarget -= leftOverDamage;
	cout << "Left over damage attacks" << easyTarget[additionalEasyTargetRandomIndex]->mFirstname << easyTarget[additionalEasyTargetRandomIndex]->mLastname;
	string additionalCardResilienceAttackedStringEasyTarget = to_string(additionalCardResilienceAttackedIntEasyTarget);
	easyTarget[randomIndex]->mResilience = additionalCardResilienceAttackedIntEasyTarget;
}