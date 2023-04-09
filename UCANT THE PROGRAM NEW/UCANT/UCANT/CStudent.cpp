// Adam James Anthony Hall

// Initialize necessary header files
#include "CStudent.h"
#include "CCard.h"

void CStudent::printCardUse()
{
	
}

/**

This function activates a card's death effect on a table entity by printing out the entity's information and removing it from the table vector.
@param randomIndex The index of the table entity being attacked.
@param tableAttacked The vector of shared pointers to the table entities.
*/
void CStudent::activateCardDeath(int randomIndex, vector<shared_ptr<CTable>>& tableAttacked)
{
	cout << tableAttacked[randomIndex]->mType << " " << tableAttacked[randomIndex]->mFirstname << " " << tableAttacked[randomIndex]->mLastname << " is defeated" << endl;
	tableAttacked.erase(tableAttacked.begin() + randomIndex);
}

/*
This function is used to simulate an attack between a card and an entity, such as a monster or another player's card.
It takes in the attacker's card's power and the attacked entity's resilience as integers and the attacked entity's index in the tableAttacked vector as a randomIndex parameter.
It also takes in a randomCard parameter for selecting the attacking card from the cardsDrawn vector.
The function subtracts the attacker's card's power from the attacked entity's resilience and updates the entity's resilience in the tableAttacked vector.
Then it prints out a message indicating the attack details, including the attacker's card's name, the entity's name and its power, resilience and boost values before and after the attack.
*/
void CStudent::attackEntity(int &cardResilienceAttackedInt, int &cardPowerAttackerInt, int randomIndex, int randomCard, vector<shared_ptr<CTable>>& tableAttacked, vector<shared_ptr<CCard>> cardsDrawn)
{
	cardResilienceAttackedInt -= cardPowerAttackerInt;
	string cardResilienceStringDueled = to_string(cardResilienceAttackedInt);
	tableAttacked[randomIndex]->mResilience = cardResilienceStringDueled;
	cout << cardsDrawn[randomCard]->mFirstname << " " << cardsDrawn[randomCard]->mLastname << " attacks " << tableAttacked[randomIndex]->mFirstname << " " << tableAttacked[randomIndex]->mLastname << ". " << tableAttacked[randomIndex]->mFirstname << " " << tableAttacked[randomIndex]->mLastname << "'s resilience is now " << tableAttacked[randomIndex]->mResilience << endl;
}

/**
This function takes a reference to a struct object of type CPlayers::SProfessor representing the professor attacked,
a vector of shared pointers to CCard objects representing the drawn cards, an integer representing the index of the
drawn card used for attack, and a reference to an integer representing the power of the attacking card. It decreases
the prestige of the professor attacked by the attacking card's power, and prints out a message indicating the attack and
the updated prestige of the professor attacked.
*/
void CStudent::attackProfessor(CPlayers& professorAttacked, vector<shared_ptr<CCard>> cardsDrawn, int randomCard, int& cardPowerAttackerInt)
{
	professorAttacked.mProfPrestige -= cardPowerAttackerInt;
	cout << cardsDrawn[randomCard]->mFirstname << " " << cardsDrawn[randomCard]->mLastname << " attacks " << professorAttacked.mProfName << ". " << professorAttacked.mProfName << " prestige is now " << professorAttacked.mProfPrestige << endl;
}

/**

This function uses a student card to attack either a table or a professor. If a table is attacked, the function selects a random table from the tableAttacked vector and subtracts the card's power from the table's resilience. If a professor is attacked, the function subtracts the card's power from the professor's prestige. If the table's resilience or the professor's prestige reaches zero or below, they are removed from the game. The function also activates any special abilities of the card, and adds any drawn student cards to the ordinaryStudent vector.
@param tableAttacked - a vector of shared_ptr<CTable> representing the tables being attacked
@param tableAttacker - a vector of shared_ptr<CTable> representing the tables belonging to the attacker
@param professorAttacked - a struct representing the professor being attacked
@param professorAttacker - a struct representing the professor who owns the attacking card
@param cardsDrawn - a vector of shared_ptr<CCard> representing the cards drawn during the turn
@param ordinaryStudent - a vector of shared_ptr<CStudent> representing the drawn student cards
@param randomCard - an integer representing the index of the card being used
@param easyTarget - a vector of shared_ptr<CEasyTarget> representing the cards that can be used on tables directly
@return void
*/
void CStudent::UseCard(vector<shared_ptr<CTable>>& tableAttacked, vector<shared_ptr<CTable>>& tableAttacker, CPlayers& professorAttacked, CPlayers& professorAttacker, vector<shared_ptr<CCard>> cardsDrawn, vector<shared_ptr<CStudent>>& ordinaryStudent, int randomCard, vector<shared_ptr<CEasyTarget>>& easyTarget)
{
	unique_ptr<CCounter> randomNumber = make_unique<CCounter>();
	shared_ptr<CEasyTarget> activateEasyTarget = make_shared<CEasyTarget>();
	shared_ptr<CStudent> printCardType = make_shared<CStudent>();

	activateEasyTarget->printCardUse();

	int cardPowerAttackerInt = 0;
	int cardResilienceAttackerInt = 0;
	int cardPowerAttackedInt = 0;
	int cardResilienceAttackedInt = 0;

	if (cardsDrawn[randomCard]->mType == G_STUDENT)
	{
		// Convert the shared_ptr<CCard> to a shared_ptr<CDrawCourseAccreditationCard>
		shared_ptr<CStudent> pStudentElement = static_pointer_cast<CStudent>(cardsDrawn[randomCard]);

		// Add the converted element to the accreditation vector
		ordinaryStudent.push_back(pStudentElement);
	}

	professorAttacked.mProfName;
	professorAttacker.mProfName;

	if (!ordinaryStudent.empty())
	{

		for (int i = 0; i < ordinaryStudent.size(); i++)
		{

			string cardPowerAttacker = ordinaryStudent[i]->mPower;
			string cardResilienceAttacker = ordinaryStudent[i]->mResilience;

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
					printCardType->attackEntity(cardResilienceAttackedInt, cardPowerAttackerInt, randomIndex, randomCard, tableAttacked, cardsDrawn);
				}
				if (cardResilienceAttackedInt <= 0) {
					printCardType->activateCardDeath(randomIndex, tableAttacked);
				}
			}

			if (tableAttacked.empty()) {
				printCardType->attackProfessor(professorAttacked, cardsDrawn, randomCard, cardPowerAttackedInt);
			}

			if (professorAttacked.mProfPrestige < 0)
			{
				professorAttacked.mProfPrestige = 0;
			}


		}
	}
	if (ordinaryStudent.empty())
	{

	}
	ordinaryStudent.clear();

}

void CStudent::AddStudents(vector<shared_ptr<CStudent>>& pCardsStudents)
{
	for (int i = 0; i < pCardsStudents.size(); i++)
	{
		auto student = make_shared<CStudent>();
		pCardsStudents[i] = student;
	}
}