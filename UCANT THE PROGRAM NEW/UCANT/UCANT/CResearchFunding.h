// Adam James Anthony Hall
#pragma once
#include "CCard.h"
#include "CManager.h"
#include "CEasyTarget.h"

/*
 * The CResearchFunding class inherits from the CCard class.
 * It has several public member functions, including:
 * - useCard: which takes several arguments including vectors of shared pointers to CCard and CResearchFunding objects,
 *   an int for a random card, a reference to an SProfessor object for the attacker,
 *   a string for the attacker name and a vector of shared pointers to CTable objects for the table attacker.
 * - printCardUse: which overrides the printCardUse function from the base class.
 * - activateCardDeath: which activates the card's death effect.
 */
class CResearchFunding :
	public CCard
{
public:
	void useCard(vector<shared_ptr<CCard>> cardsDrawn, vector<shared_ptr<CResearchFunding>> researchFunding, int randomCard, CPlayers::SProfessor& professorAttacker, string attackerName, vector<shared_ptr<CTable>>& tableAttacker); // Use the card
	void printCardUse() override; // Override the printCardUse function from the base class
	void activateCardDeath(); // Activate the card's death effect
};

