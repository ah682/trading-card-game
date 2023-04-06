// Adam James Anthony Hall
#include "CSerialOffender.h"

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
}
void CSerialOffender::printCardUse()
{
	
}

//Bottom
void CSerialOffender::activateCardDeath(int randomIndex, vector<shared_ptr<CTable>>& tableAttacked) //overload
{
	cout << tableAttacked[randomIndex]->mFirstname << " " << tableAttacked[randomIndex]->mLastname << " is defeated" << endl;
	tableAttacked.erase(tableAttacked.begin() + randomIndex);

}

void CSerialOffender::attackProfessor(int cardPowerAttackerInt, CPlayers::SProfessor& professorAttacked, vector<shared_ptr<CCard>> cardsDrawn, int randomCard)
{
	professorAttacked.mProfPrestige -= cardPowerAttackerInt;
	cout << cardsDrawn[randomCard]->mFirstname << " " << cardsDrawn[randomCard]->mLastname << " attacks " << professorAttacked.mProfName << ". " << professorAttacked.mProfName << " prestige is now " << professorAttacked.mProfPrestige << endl;
}

// Regular Entity
void CSerialOffender::attackEntity(int &cardResilienceAttackedInt, int &cardPowerAttackerInt, int randomIndex, vector<shared_ptr<CTable>>& tableAttacked) //not left over damage for serialoffender
{
	cardResilienceAttackedInt -= cardPowerAttackerInt;
	string cardResilienceStringDueled = to_string(cardResilienceAttackedInt);
	tableAttacked[randomIndex]->mResilience = cardResilienceStringDueled;

}

// Additional Entity
void CSerialOffender::attackEntity(int& cardResilienceAttackedInt, int& cardPowerAttackerInt, int additionalRandomIndex, int randomIndex, vector<shared_ptr<CTable>>& tableAttacked, int &leftOverDamage, int &additionalCardResilienceAttackedInt) //left over damage for serialoffender
{
	additionalCardResilienceAttackedInt -= leftOverDamage;
	cout << "Left over damage attacks" << tableAttacked[additionalRandomIndex]->mFirstname << tableAttacked[additionalRandomIndex]->mLastname;
	string additionalCardResilienceAttackedString = to_string(additionalCardResilienceAttackedInt);
	tableAttacked[randomIndex]->mResilience = additionalCardResilienceAttackedString;
	leftOverDamage -= additionalCardResilienceAttackedInt;

}