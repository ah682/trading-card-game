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
	cout << tableAttacked[randomIndex]->mType << " " << tableAttacked[randomIndex]->mFirstname << " " << tableAttacked[randomIndex]->mLastname << " " << tableAttacked[randomIndex]->mPower << " " << tableAttacked[randomIndex]->mResilience << " " << tableAttacked[randomIndex]->mBoost << " is defeated" << endl;
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
	cout << cardsDrawn[randomCard]->mFirstname << " " << cardsDrawn[randomCard]->mLastname << " attacks " << tableAttacked[randomIndex]->mFirstname << " " << tableAttacked[randomIndex]->mLastname << " " << tableAttacked[randomIndex]->mPower << " " << tableAttacked[randomIndex]->mResilience << " " << tableAttacked[randomIndex]->mBoost << " " << tableAttacked[randomIndex]->mFirstname << " " << tableAttacked[randomIndex]->mLastname << " resilience is now " << tableAttacked[randomIndex]->mResilience << endl;
}

/**
This function takes a reference to a struct object of type CPlayers::SProfessor representing the professor attacked,
a vector of shared pointers to CCard objects representing the drawn cards, an integer representing the index of the
drawn card used for attack, and a reference to an integer representing the power of the attacking card. It decreases
the prestige of the professor attacked by the attacking card's power, and prints out a message indicating the attack and
the updated prestige of the professor attacked.
*/
void CStudent::attackProfessor(CPlayers::SProfessor& professorAttacked, vector<shared_ptr<CCard>> cardsDrawn, int randomCard, int& cardPowerAttackerInt)
{
	professorAttacked.mProfPrestige -= cardPowerAttackerInt;
	cout << cardsDrawn[randomCard]->mFirstname << " " << cardsDrawn[randomCard]->mLastname << " attacks " << professorAttacked.mProfName << ". " << professorAttacked.mProfName << " prestige is now " << professorAttacked.mProfPrestige << endl;
}