// Adam James Anthony Hall
#pragma once
#include "CCard.h"
#include "CTable.h"
#include "CManager.h"
#include "CEasyTarget.h"

/*
 * The CSerialOffender class inherits from the CCard class.
 * It has several public member functions, including:
 * - useCard: which takes several arguments including vectors of shared pointers to CTable, CCard and CSerialOffender objects,
 *   references to SProfessor objects for the attacker and attacked, an int for a random card and a vector of shared pointers to CEasyTarget objects.
 * - printCardUse: which overrides the printCardUse function from the base class.
 * - activateCardDeath: which takes an int for a random index and a vector of shared pointers to CTable objects for the table attacked as arguments and activates the card's death effect.
 * - attackProfessor: which takes an int for the card power of the attacker, a reference to an SProfessor object for the professor attacked,
 *   a vector of shared pointers to CCard objects and an int for a random card as arguments and attacks the professor.
 * - attackEntity: which is overloaded and can take several different sets of arguments including references to ints for the card resilience and power of the attacker,
 *   ints for random indices, a vector of shared pointers to CTable objects for the table attacked,
 *   and references to ints for left over damage and additional card resilience attacked.
 */
class CSerialOffender :
	public CCard
{
	public:
	void useCard(vector<shared_ptr<CTable>>& tableAttacked, vector<shared_ptr<CTable>>& tableAttacker, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, vector<shared_ptr<CCard>> cardsDrawn, vector<shared_ptr<CSerialOffender>>& serialOffender, int randomCard, vector<shared_ptr<CEasyTarget>>& easyTarget); // Method to use the card
	void printCardUse() override; // Method to print the usage of the card
	void activateCardDeath(int randomIndex, vector<shared_ptr<CTable>>& tableAttacked); // Method to activate the death effect of the card
	void attackProfessor(int cardPowerAttackerInt, CPlayers::SProfessor& professorAttacked, vector<shared_ptr<CCard>> cardsDrawn, int randomCard); // Method to attack a professor
	// Function overloading - two versions of the attackEntity function with different parameters
	void attackEntity(int& cardResilienceAttackedInt, int& cardPowerAttackerInt, int randomIndex, vector<shared_ptr<CTable>>& tableAttacked); // First version of the attackEntity function
	void attackEntity(int& cardResilienceAttackedInt, int& cardPowerAttackerInt, int additionalRandomIndex, int randomIndex, vector<shared_ptr<CTable>>& tableAttacked, int& leftOverDamage, int& additionalCardResilienceAttackedInt); // Second version of the attackEntity function with additional parameters
};

