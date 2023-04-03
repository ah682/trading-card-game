// Adam James Anthony Hall
#include "CSerialOffender.h"

void CSerialOffender::useCard(vector<shared_ptr<CTable>>& tableAttacked, vector<shared_ptr<CTable>>& tableAttacker, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, string name, string nametwo, vector<shared_ptr<CCard>> cardsDrawn, vector<shared_ptr<CSerialOffender>>& serialOffender, int randomCard, vector<shared_ptr<CEasyTarget>>& easyTarget)
{
	unique_ptr<CSerialOffender> printCardTypeSerialOffender = make_unique<CSerialOffender>();
	unique_ptr<CEasyTarget> printCardTypeEasyTarget = make_unique<CEasyTarget>();
	unique_ptr<CCounter> randomNumber = make_unique<CCounter>(); // ?
	shared_ptr<CEasyTarget> activateEasyTarget = make_shared<CEasyTarget>(); // ?

	printCardTypeSerialOffender->printCardUse();


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

				activateEasyTarget->attackEasyTarget(cardPowerAttackerInt, easyTarget);

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
							cout << "Left over damage attacks" << easyTarget[additionalEasyTargetRandomIndex]->mFirstname << easyTarget[additionalEasyTargetRandomIndex]->mLastname;
							string additionalCardResilienceAttackedStringEasyTarget = to_string(additionalCardResilienceAttackedIntEasyTarget);
							easyTarget[randomIndex]->mResilience = additionalCardResilienceAttackedIntEasyTarget;
							if (additionalCardResilienceAttackedIntEasyTarget <= 0)
							{
								printCardTypeEasyTarget->printCardDeath(additionalEasyTargetRandomIndex, easyTarget);
								easyTarget.erase(easyTarget.begin() + additionalEasyTargetRandomIndex);
							}
						}
						if (additionalCardResilienceAttackedInt > 0 && easyTarget.size() <= 0)
						{
							additionalCardResilienceAttackedInt -= leftOverDamage;
							cout << "Left over damage attacks" << tableAttacked[additionalRandomIndex]->mFirstname << tableAttacked[additionalRandomIndex]->mLastname;
							string additionalCardResilienceAttackedString = to_string(additionalCardResilienceAttackedInt);
							tableAttacked[randomIndex]->mResilience = additionalCardResilienceAttackedString;
							leftOverDamage -= additionalCardResilienceAttackedInt;
							if (additionalCardResilienceAttackedInt <= 0)
							{
								printCardTypeSerialOffender->printCardDeath(additionalRandomIndex, tableAttacked);
								tableAttacked.erase(tableAttacked.begin() + additionalRandomIndex);
							}
						}


					} while (leftOverDamage > 0);

				}
				if (cardResilienceAttackedInt <= 0) {
					tableAttacked[randomIndex]->mResilience = "0";
					printCardTypeSerialOffender->printCardDeath(randomIndex, tableAttacked);
					tableAttacked[randomIndex]->mResilience = G_DEAD_CARD;
					tableAttacked.erase(tableAttacked.begin() + randomIndex);
				}
			}

			if (tableAttacked.empty()) {
				professorAttacked.mProfPrestige -= cardPowerAttackerInt;
				cout << cardsDrawn[randomCard]->mFirstname << " " << cardsDrawn[randomCard]->mLastname << " attacks " << professorAttacked.mProfName << " prestige is now " << professorAttacked.mProfPrestige << endl;
			}

			if (professorAttacked.mProfPrestige < 0)
			{
				professorAttacked.mProfPrestige = 0;
			}


		}
	}
	if (serialOffender.empty())
	{
		cout << "No serial offender cards to use" << endl;
	}
}
void CSerialOffender::printCardUse()
{
	cout << "Using Serial Offender Card" << endl;
}

//Bottom
void CSerialOffender::printCardDeath(int randomIndex, vector<shared_ptr<CTable>>& tableAttacked) //overload
{
	cout << tableAttacked[randomIndex]->mFirstname << " " << tableAttacked[randomIndex]->mLastname << " is defeated" << endl;
}
