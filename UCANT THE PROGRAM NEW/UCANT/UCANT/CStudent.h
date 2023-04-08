// Adam James Anthony Hall
#pragma once
// Initialize necessary header files
#include "CCard.h"
#include "CTable.h"
#include "CPlayers.h"
#include "CCounter.h"
#include "CEasyTarget.h"


/*
 * The CStudent class inherits from the CCard class.
 * It has several public member functions, including:
 * - printCardUse: which overrides the printCardUse function from the base class.
 * - activateCardDeath: which takes an int for a random index and a vector of shared pointers to CTable objects for the table attacked as arguments and activates the card's death effect.
 * - attackEntity: which takes several arguments including references to ints for the card resilience and power of the attacker,
 *   ints for a random index and card, a vector of shared pointers to CTable objects for the table attacked,
 *   and a vector of shared pointers to CCard objects for the cards drawn.
 * - attackProfessor: which takes a reference to an SProfessor object for the professor attacked,
 *   a vector of shared pointers to CCard objects for the cards drawn, an int for a random card
 *   and a reference to an int for the card power attacked as arguments and attacks the professor.
 */
class CStudent :
	public CCard // Inherit from the CCard class
{
public:
	void printCardUse() override; // Override the printCardUse function from the base class
	void activateCardDeath(int randomIndex, vector<shared_ptr<CTable>>& tableAttacked); // Activate the card's death effect
	void attackEntity(int &cardResilienceAttackedInt, int &cardPowerAttackerInt, int randomIndex, int randomCard, vector<shared_ptr<CTable>>& tableAttacked, vector<shared_ptr<CCard>> cardsDrawn); // Attack the entity
	void attackProfessor(CPlayers::SProfessor& professorAttacked, vector<shared_ptr<CCard>> cardsDrawn, int randomCard, int& cardPowerAttackedInt); // Attack the professor
	void UseCard(vector<shared_ptr<CTable>>& tableAttacked, vector<shared_ptr<CTable>>& tableAttacker, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, vector<shared_ptr<CCard>> cardsDrawn, vector<shared_ptr<CStudent>>& ordinaryStudent, int randomCard, vector<shared_ptr<CEasyTarget>>& easyTarget); // Uses a student card
	void AddStudents(vector<shared_ptr<CStudent>>& pCardsStudents);
};


