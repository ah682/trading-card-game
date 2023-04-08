// Adam James Anthony Hall

// Initialize necessary header files
#include "CPlagiarismHearing.h"


void CPlagiarismHearing::printCardUse()
{
	
}

/**

This function is a part of the CPlagiarismHearing class and is responsible for activating the death of a card on the table attacked by the player.
It takes two parameters as input: a pointer to an object of type CCard, which is the enemy table card to be defeated, and a reference to a vector of shared pointers
to objects of type CTable, which is the table attacked by the player. The function prints out the details of the defeated card and pops it from the tableAttacked vector.
This function overloads the activateCardDeath function from the CCard class.
*/
void CPlagiarismHearing::activateCardDeath(CCard* enemyTable, vector <shared_ptr<CTable>>& tableAttacked) //Function overloading
{
	cout <<  enemyTable->mFirstname << " " << enemyTable->mLastname << " is defeated" << endl;
	tableAttacked.pop_back();
}

/**

This function is used to attack a professor by subtracting the power of the attacking card from the prestige of the professor.
The function takes in a reference to the struct containing information about the professor being attacked, an integer representing the power of the attacking card,
a vector containing shared pointers to the cards drawn by the player, and an integer representing the index of the attacking card in the vector.
The function prints out the name of the attacking card and the name of the professor being attacked, along with the updated prestige of the professor after the attack.
*/
void CPlagiarismHearing::attackProfessor(CPlayers::SProfessor& professorAttacked, int cardPower, vector<shared_ptr<CCard>>& cardsDrawn, int randomCard)
{
	professorAttacked.mProfPrestige -= cardPower;
	cout << cardsDrawn[randomCard]->mFirstname << " " << cardsDrawn[randomCard]->mLastname << " attacks " << professorAttacked.mProfName << ". " << professorAttacked.mProfName << " prestige is now " << professorAttacked.mProfPrestige << endl;
}

/**

Uses a card to either attack a professor or a table enemy.
If the card is of type "Plagiarism Hearing", it adds it to the plagiarism vector.
Then it activates the card's special ability to attack either the last table enemy or the professor
based on the value of randomChoice. If the attacked entity's resilience becomes 0, it is removed from the table.
@param cardsDrawn vector of shared pointers to the cards drawn by the player
@param plagiarism vector of shared pointers to the plagiarism cards in the player's possession
@param tableAttacked vector of shared pointers to the enemies on the table
@param randomCard the index of the card to be used from cardsDrawn
@param professorAttacked the professor being attacked
@param professorAttacker the professor doing the attacking
@param attackedName the name of the professor being attacked
@param attackerName the name of the professor doing the attacking
@param randomChoice integer value indicating whether the attack should be on the professor or the table enemy
@param easyTarget vector of shared pointers to easy target cards in the player's possession
*/
void CPlagiarismHearing::useCard(vector<shared_ptr<CCard>>& cardsDrawn, vector <shared_ptr<CPlagiarismHearing>>& plagiarism, vector <shared_ptr<CTable>>& tableAttacked, int randomCard, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, string attackedName, string attackerName, int randomChoice, vector<shared_ptr<CEasyTarget>>& easyTarget)
{
	unique_ptr<CPlagiarismHearing> printCardType = make_unique<CPlagiarismHearing>();
	shared_ptr<CEasyTarget> activateEasyTarget = make_shared<CEasyTarget>();
	printCardType->printCardUse();

	if (cardsDrawn[randomCard]->mType == G_PLAGIARISM_HEARING)
	{
		// Convert the shared_ptr<CCard> to a shared_ptr<CDrawCourseAccreditationCard>
		shared_ptr<CPlagiarismHearing> pPlagiarismElement = static_pointer_cast<CPlagiarismHearing>(cardsDrawn[randomCard]);

		// Add the converted element to the accreditation vector
		plagiarism.push_back(pPlagiarismElement);
	}

	professorAttacked.mProfName = attackedName;
	professorAttacker.mProfName = attackerName;

	const int CARD_POWER = 3;
	int cardResilience = 0;

	for (int i = 0; i < plagiarism.size(); i++)
	{
		activateEasyTarget->useCardSpecialAbility(CARD_POWER, easyTarget);
		if (!tableAttacked.empty()) {
			CCard* enemyTable = tableAttacked.back().get();
			if (!enemyTable->mResilience.empty()) {
				cardResilience = stoi(enemyTable->mResilience);
			}

			if (randomChoice == 1)
			{
				if (cardResilience > 0) {
					cardResilience -= CARD_POWER;
					string cardResilienceString = to_string(cardResilience);
					tableAttacked[tableAttacked.size() - 1]->mResilience = cardResilienceString;
					cout << cardsDrawn[randomCard]->mFirstname << " " << cardsDrawn[randomCard]->mLastname << " attacks: " << enemyTable->mFirstname << " " << enemyTable->mLastname << ". " << " " << enemyTable->mFirstname << " " << enemyTable->mLastname << "'s resilience is now " << enemyTable->mResilience << endl;
				}
				if (cardResilience <= 0) {
					printCardType->activateCardDeath(enemyTable, tableAttacked);
				}
			}

			if (randomChoice == 2) {
				printCardType->attackProfessor(professorAttacked, CARD_POWER, cardsDrawn, randomCard);
			}
			if (professorAttacked.mProfPrestige < 0)
			{
				professorAttacked.mProfPrestige = 0;
			}
		}
	}
	plagiarism .clear();
}
