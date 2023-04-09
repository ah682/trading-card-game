// Adam James Anthony Hall
#pragma once
#include "CCard.h"
#include "CTable.h"
#include "CManager.h"
#include "CEasyTarget.h"

/*
 * The CGraduateStudent class inherits from the CCard class.
 * It has several public member functions, including:
 * - useCard: which takes several arguments including vectors of shared pointers to CTable, CCard, CGraduateStudent and CEasyTarget objects,
 *   as well as references to SProfessor objects and an int for a random card.
 * - printCardUse: which overrides the printCardUse function from the base class.
 * - activateCardDeath: which takes an int for a random index and a vector of shared pointers to CTable objects.
 * - attackProfessor: which takes a reference to an SProfessor object, an int for the card power of the attacker,
 *   a vector of shared pointers to CCard objects and an int for a random card.
 * - attackEntity: which takes several arguments including references to ints for the card resilience and power of the attacker,
 *   a reference to a string for the card resilience string dueled, a vector of shared pointers to CTable objects,
 *   an int for a random index and card, and a vector of shared pointers to CCard objects.
 */
class CGraduateStudent :
	public CCard
{
	public:
		void useCard(vector<shared_ptr<CTable>>& tableAttacked, vector<shared_ptr<CTable>>& tableAttacker, CPlayers& professorAttacked, CPlayers& professorAttacker, vector<shared_ptr<CCard>> cardsDrawn, vector<shared_ptr<CGraduateStudent>>& graduateStudent, int randomCard, vector<shared_ptr<CEasyTarget>>& easyTarget); // Method to use the card
		void printCardUse() override; // Method to print the usage of the card
		void activateCardDeath(int randomIndex, vector<shared_ptr<CTable>>& tableAttacked); // Method to activate the death effect of the card
		void attackProfessor(CPlayers& professorAttacked, int cardPowerAttackerInt, vector<shared_ptr<CCard>> cardsDrawn, int randomCard); // Method to attack a professor
		void attackEntity(int& cardResilienceAttackedInt, int& cardPowerAttackerInt, string& cardResilienceStringDueled, vector<shared_ptr<CTable>>& tableAttacked, int randomIndex, int randomCard, vector<shared_ptr<CCard>>& cardsDrawn); // Method to attack an entity on the table
};

