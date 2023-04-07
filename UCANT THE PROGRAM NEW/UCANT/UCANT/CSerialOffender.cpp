// Adam James Anthony Hall
#include "CSerialOffender.h"

/**
 * This function uses the Serial Offender card on the specified targets. It also handles the card's special abilities
 * including attacking additional entities and activating the Easy Target card's special ability.
 *
 * @param tableAttacked the vector of tables that the card can attack
 * @param tableAttacker the vector of tables that the card belongs to
 * @param professorAttacked the professor that the card can attack
 * @param professorAttacker the professor that the card belongs to
 * @param cardsDrawn the vector of cards drawn by the player
 * @param serialOffender the vector of Serial Offender cards that the player has
 * @param randomCard the index of the card in the cardsDrawn vector that the player wants to use
 * @param easyTarget the vector of Easy Target cards that the player has
 */
void CSerialOffender::useCard(vector<shared_ptr<CTable>>& tableAttacked, vector<shared_ptr<CTable>>& tableAttacker, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, vector<shared_ptr<CCard>> cardsDrawn, vector<shared_ptr<CSerialOffender>>& serialOffender, int randomCard, vector<shared_ptr<CEasyTarget>>& easyTarget)
{
	unique_ptr<CSerialOffender> printCardTypeSerialOffender = make_unique<CSerialOffender>();
	unique_ptr<CEasyTarget> printCardTypeEasyTarget = make_unique<CEasyTarget>();
	unique_ptr<CCounter> randomNumber = make_unique<CCounter>(); 
	shared_ptr<CEasyTarget> activateEasyTarget = make_shared<CEasyTarget>(); 

	printCardTypeSerialOffender->printCardUse();


	int cardPowerAttackerInt = 0;
	int cardResilienceAttackerInt = 0;
	int cardPowerAttackedInt = 0;
	int cardResilienceAttackedInt = 0;
	int additionalCardResilienceAttackedInt = 0;
	int additionalCardResilienceAttackedIntEasyTarget = 0;

	if (cardsDrawn[randomCard]->mType == G_SERIAL_OFFENDER)
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

				activateEasyTarget->useCardSpecialAbility(cardPowerAttackerInt, easyTarget);

				if (cardResilienceAttackedInt > 0) {
					printCardTypeSerialOffender->attackEntity(cardResilienceAttackedInt, cardPowerAttackerInt, randomIndex, tableAttacked);
					int leftOverDamage = cardPowerAttackerInt - cardResilienceAttackedInt;
					do
					{
						int additionalRandomIndex = randomNumber->Random(tableAttacked.size() - 1);
						int additionalEasyTargetRandomIndex = randomNumber->Random(easyTarget.size() - 1);

						if (additionalRandomIndex < 0 || additionalEasyTargetRandomIndex < 0) {
							// break out of the loop if either of the random indices is invalid
							break;
						}

						if (additionalRandomIndex >= 0 && additionalRandomIndex < tableAttacked.size())
						{
							additionalCardResilienceAttackedInt = stoi(tableAttacked[additionalRandomIndex]->mResilience); //-2 dont think this is an issue [table attacked random index value]
						}
						else
						{
							break;
						}
						if (additionalEasyTargetRandomIndex >= 0 && additionalEasyTargetRandomIndex < easyTarget.size())
						{
							additionalCardResilienceAttackedIntEasyTarget = stoi(easyTarget[additionalEasyTargetRandomIndex]->mResilience); //This is -858993460 [easy target random index] i assume this is the issue
						}
						else
						{
							break;
						}
						int additionalCardPowerAttackerInt = stoi(tableAttacked[randomIndex]->mPower);
						if (additionalCardResilienceAttackedIntEasyTarget > 0 && easyTarget.size() >= 0)
						{
							printCardTypeEasyTarget->attackEntity(additionalCardResilienceAttackedIntEasyTarget, leftOverDamage, randomIndex, additionalEasyTargetRandomIndex, easyTarget);
							if (additionalCardResilienceAttackedIntEasyTarget <= 0)
							{
								printCardTypeEasyTarget->activateCardDeath(additionalEasyTargetRandomIndex, easyTarget);
							}
						}
						if (additionalCardResilienceAttackedInt > 0 && easyTarget.size() <= 0)
						{
							printCardTypeSerialOffender->attackEntity(additionalCardResilienceAttackedInt, cardPowerAttackerInt, additionalRandomIndex, randomIndex, tableAttacked, leftOverDamage, additionalCardResilienceAttackedInt);
							if (additionalCardResilienceAttackedInt <= 0)
							{
								printCardTypeSerialOffender->activateCardDeath(additionalRandomIndex, tableAttacked);
							}
						}


					} while (leftOverDamage > 0);

				}
				if (cardResilienceAttackedInt <= 0) {
					printCardTypeSerialOffender->activateCardDeath(randomIndex, tableAttacked);
				}
			}

			if (tableAttacked.empty()) {
				printCardTypeSerialOffender->attackProfessor(cardPowerAttackerInt, professorAttacked, cardsDrawn, randomCard);
			}

			if (professorAttacked.mProfPrestige < 0)
			{
				professorAttacked.mProfPrestige = 0;
			}


		}
	}
	if (serialOffender.empty())
	{
		
	}
	serialOffender.clear();
}
void CSerialOffender::printCardUse()
{
	
}

/**
Activates the card death ability of the Serial Offender on a random table in the vector of tables.
Removes the defeated table from the vector.
@param randomIndex The index of the table to be attacked.
@param tableAttacked The vector of tables to choose from.
*/
void CSerialOffender::activateCardDeath(int randomIndex, vector<shared_ptr<CTable>>& tableAttacked) //overload
{
	cout << tableAttacked[randomIndex]->mFirstname << " " << tableAttacked[randomIndex]->mLastname << " is defeated" << endl;
	tableAttacked.erase(tableAttacked.begin() + randomIndex);

}

/*

Function: attackProfessor
This function is used to attack a professor with a card. It subtracts the card power from the
professor's prestige and prints out a message indicating the attack.
Parameters:
cardPowerAttackerInt: an integer representing the power of the attacking card
professorAttacked: a reference to the professor object being attacked
cardsDrawn: a vector of shared pointers to cards that have been drawn
randomCard: an integer representing the index of the attacking card in the cardsDrawn vector
*/
void CSerialOffender::attackProfessor(int cardPowerAttackerInt, CPlayers::SProfessor& professorAttacked, vector<shared_ptr<CCard>> cardsDrawn, int randomCard)
{
	professorAttacked.mProfPrestige -= cardPowerAttackerInt;
	cout << cardsDrawn[randomCard]->mFirstname << " " << cardsDrawn[randomCard]->mLastname << " attacks " << professorAttacked.mProfName << ". " << professorAttacked.mProfName << " prestige is now " << professorAttacked.mProfPrestige << endl;
}

/**
 * Regular Entity
 * Attacks an entity on a table with a card
 * @param cardResilienceAttackedInt the resilience value of the attacked entity
 * @param cardPowerAttackerInt the power value of the attacking card
 * @param randomIndex the index of the attacked entity in the table
 * @param tableAttacked the table containing the attacked entity
 */
void CSerialOffender::attackEntity(int &cardResilienceAttackedInt, int &cardPowerAttackerInt, int randomIndex, vector<shared_ptr<CTable>>& tableAttacked) //not left over damage for serialoffender
{
	cardResilienceAttackedInt -= cardPowerAttackerInt;
	string cardResilienceStringDueled = to_string(cardResilienceAttackedInt);
	tableAttacked[randomIndex]->mResilience = cardResilienceStringDueled;

}

/** 
 * Additional Entity
 * Attacks an entity on a table with a card, taking into account any left over damage from a previous attack
 * @param cardResilienceAttackedInt the resilience value of the attacked entity
 * @param cardPowerAttackerInt the power value of the attacking card
 * @param additionalRandomIndex the index of the additional attacked entity in the table
 * @param randomIndex the index of the main attacked entity in the table
 * @param tableAttacked the table containing the attacked entities
 * @param leftOverDamage any left over damage from a previous attack
 * @param additionalCardResilienceAttackedInt the resilience value of the additional attacked entity
 */
void CSerialOffender::attackEntity(int& cardResilienceAttackedInt, int& cardPowerAttackerInt, int additionalRandomIndex, int randomIndex, vector<shared_ptr<CTable>>& tableAttacked, int &leftOverDamage, int &additionalCardResilienceAttackedInt) //left over damage for serialoffender
{
	additionalCardResilienceAttackedInt -= leftOverDamage;
	cout << "Left over damage attacks" << tableAttacked[additionalRandomIndex]->mFirstname << tableAttacked[additionalRandomIndex]->mLastname;
	string additionalCardResilienceAttackedString = to_string(additionalCardResilienceAttackedInt);
	tableAttacked[randomIndex]->mResilience = additionalCardResilienceAttackedString;
	leftOverDamage -= additionalCardResilienceAttackedInt;

}