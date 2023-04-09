// Adam James Anthony Hall
#pragma once

// Initialize necessary header files
#include "CCard.h"
#include "CEasyTarget.h"
#include "CManager.h"

/*
 * The CPlagiarismHearing class inherits from the CCard class.
 * It has several public member functions, including:
 * - useCard: which takes several arguments including vectors of shared pointers to CCard, CPlagiarismHearing and CTable objects,
 *   an int for a random card, references to SProfessor objects for the attacker and attacked,
 *   strings for the attacker and attacked names, an int for a random choice and a vector of shared pointers to CEasyTarget objects.
 * - printCardUse: which overrides the printCardUse function from the base class.
 * - activateCardDeath: which takes a pointer to a CCard object for the enemy table and a vector of shared pointers to CTable objects for the table attacked as arguments and activates the card's death effect.
 * - attackProfessor: which takes a reference to an SProfessor object for the professor attacked, an int for the card power,
 *   a vector of shared pointers to CCard objects and an int for a random card as arguments and attacks the professor.
 */
class CPlagiarismHearing :
	public CCard
{
	public:
		void useCard(vector<shared_ptr<CCard>>& cardsDrawn, vector <shared_ptr<CPlagiarismHearing>>& plagiarism, vector <shared_ptr<CTable>>& tableAttacked, int randomCard, CPlayers& professorAttacked, CPlayers& professorAttacker, string attackedName, string attackerName, int randomChoice, vector<shared_ptr<CEasyTarget>>& easyTarget); // Use card function
		void printCardUse() override; // Override the printCardUse function from the base class
		void activateCardDeath(CCard* enmemyTable, vector <shared_ptr<CTable>>& tableAttacked); // Activate the card's death effect
		void attackProfessor(CPlayers& professorAttacked, int cardPower, vector<shared_ptr<CCard>>& cardsDrawn, int randomCard); // Attack the professor
};

