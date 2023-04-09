// Adam James Anthony Hall
#include "CIndustrialPlacement.h"

/**

This function takes in various parameters, including vectors of cards drawn, industrial placements, tables,
and easy targets, as well as the names of the attacking and attacked players, and their respective professors.
The function then uses the cards and their attributes to attack tables and professors, reducing their resilience
and potentially removing them from play. The function also handles the special abilities of certain cards, such
as the "easy target" card. The code includes several variables and conditions to control the flow of the game and
ensure proper execution.
*/
void CIndustrialPlacement::useCard(vector<shared_ptr<CCard>> cardsDrawn, vector<shared_ptr<CIndustrialPlacement>>& industrialPlacement, int randomCard, CPlayers& professorAttacked, CPlayers& professorAttacker, string attackerName, vector<shared_ptr<CTable>>& tableAttacker, vector<shared_ptr<CTable>>& tableAttacked, vector<shared_ptr<CEasyTarget>>& easyTarget)
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

	if (cardsDrawn[randomCard]->mType == G_STUDENT)
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
					activateEasyTarget->useCardSpecialAbility(cardPowerAttackerInt, easyTarget);
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
					cout << cardsDrawn[randomCard]->mFirstname << " " << cardsDrawn[randomCard]->mLastname << " attacks " << tableAttacked[randomIndex]->mFirstname << " " << tableAttacked[randomIndex]->mLastname << ". " << tableAttacked[randomIndex]->mFirstname << " " << tableAttacked[randomIndex]->mLastname << "'s resilience is now " << tableAttacked[randomIndex]->mResilience << endl;
				}
				if (cardResilienceAttackedInt <= 0) {
					printCardType->activateCardDeath(randomIndex, tableAttacked);
					tableAttacked.erase(tableAttacked.begin() + randomIndex);
				}
			}

			if (tableAttacked.empty()) {

				cardResilienceAttackerInt += increaseResilience;
				string cardResilienceStringAttacker = to_string(cardResilienceAttackerInt);
				cardsDrawn[randomCard]->mResilience = cardResilienceStringAttacker;
				printCardType->attackProfessor(professorAttacked, cardPowerAttackerInt, randomCard, cardsDrawn);
			}

			if (professorAttacked.mProfPrestige < 0)
			{
				professorAttacked.mProfPrestige = 0;
			}

		}
	}
	if (industrialPlacement.empty())
	{

	}
	industrialPlacement.clear();
}

void CIndustrialPlacement::printCardUse()
{

}

/**

Activates the card death of a table from the given vector of tables at the given random index.
Outputs the details of the defeated table to the console.
@param randomIndex The random index of the table to be defeated.
@param tableAttacked The vector of tables that contains the table to be defeated.
*/
void CIndustrialPlacement::activateCardDeath(int randomIndex, vector<shared_ptr<CTable>>& tableAttacked)
{
	cout << tableAttacked[randomIndex]->mFirstname << " " << tableAttacked[randomIndex]->mLastname << " is defeated" << endl;
}

/**

Description: Function to attack a professor with a card.
Parameters:
professorAttacked: reference to the professor being attacked
cardPowerAttackerInt: integer value of the attacking card's power
randomCard: index of the attacking card in the drawn cards vector
cardsDrawn: vector containing all the cards drawn by the player
Returns: void
*/
void CIndustrialPlacement::attackProfessor(CPlayers& professorAttacked, int cardPowerAttackerInt, int randomCard, vector<shared_ptr<CCard>> cardsDrawn)
{
	professorAttacked.mProfPrestige -= cardPowerAttackerInt;
	cout << cardsDrawn[randomCard]->mFirstname << " " << cardsDrawn[randomCard]->mLastname << " attacks " << professorAttacked.mProfName << ". " << professorAttacked.mProfName << " prestige is now " << professorAttacked.mProfPrestige << endl;
}
