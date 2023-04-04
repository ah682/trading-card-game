// Adam James Anthony Hall
#include "CIndustrialPlacement.h"

void CIndustrialPlacement::useCard(vector<shared_ptr<CCard>> cardsDrawn, vector<shared_ptr<CIndustrialPlacement>>& industrialPlacement, int randomCard, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, string attackerName, vector<shared_ptr<CTable>>& tableAttacker, vector<shared_ptr<CTable>>& tableAttacked, vector<shared_ptr<CEasyTarget>>& easyTarget)
{
	unique_ptr<CIndustrialPlacement> printCardType = make_unique<CIndustrialPlacement>();
	unique_ptr<CCounter> randomNumber = make_unique<CCounter>(); // ?
	shared_ptr<CEasyTarget> activateEasyTarget = make_shared<CEasyTarget>(); // ?

	printCardType->printCardUse();

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
					activateEasyTarget->attackEasyTarget(cardPowerAttackerInt, easyTarget);
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
					cout << cardsDrawn[randomCard]->mFirstname << " " << cardsDrawn[randomCard]->mLastname << " attacks " << tableAttacked[randomIndex]->mType << " " << tableAttacked[randomIndex]->mFirstname << " " << tableAttacked[randomIndex]->mLastname << " " << tableAttacked[randomIndex]->mPower << " " << tableAttacked[randomIndex]->mResilience << " " << tableAttacked[randomIndex]->mBoost << " " << tableAttacked[randomIndex]->mFirstname << " " << tableAttacked[randomIndex]->mLastname << " resilience is now " << tableAttacked[randomIndex]->mResilience << endl;
				}
				if (cardResilienceAttackedInt <= 0) {
					tableAttacked[randomIndex]->mResilience = "0";
					printCardType->activateCardDeath(randomIndex, tableAttacked);
					tableAttacked[randomIndex]->mResilience = G_DEAD_CARD;
					tableAttacked.erase(tableAttacked.begin() + randomIndex);
				}
			}

			if (tableAttacked.empty()) {
				professorAttacked.mProfPrestige -= cardPowerAttackerInt;
				cardResilienceAttackerInt += increaseResilience;
				string cardResilienceStringAttacker = to_string(cardResilienceAttackerInt);
				cardsDrawn[randomCard]->mResilience = cardResilienceStringAttacker;
				cout << cardsDrawn[randomCard]->mFirstname << " " << cardsDrawn[randomCard]->mLastname << " attacks " << professorAttacked.mProfName << " prestige is now " << professorAttacked.mProfPrestige << endl;
			}

			if (professorAttacked.mProfPrestige < 0)
			{
				professorAttacked.mProfPrestige = 0;
			}

		}
	}
	if (industrialPlacement.empty())
	{
		cout << "No Industrial Placement cards to use" << endl;
	}
}

void CIndustrialPlacement::printCardUse()
{
	cout << "Using Industrial Placement Card" << endl;
}

void CIndustrialPlacement::activateCardDeath(int randomIndex, vector<shared_ptr<CTable>>& tableAttacked)
{
	cout << tableAttacked[randomIndex]->mType << " " << tableAttacked[randomIndex]->mFirstname << " " << tableAttacked[randomIndex]->mLastname << " " << tableAttacked[randomIndex]->mPower << " " << tableAttacked[randomIndex]->mResilience << " " << tableAttacked[randomIndex]->mBoost << " is defeated" << endl;
}
