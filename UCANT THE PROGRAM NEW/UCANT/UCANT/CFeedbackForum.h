// Adam James Anthony Hall
#pragma once

// Initialize necessary header files
#include "CCard.h"
#include "CManager.h"
#include "CEasyTarget.h"

/*
 * The CFeedbackForum class is derived from the CCard class and represents a type of card in the game.
 * This class contains methods to use the card, print its usage, and activate its death effect.
 */
class CFeedbackForum :
	public CCard // This class inherits from CCard
{
	public:
		void useCard(vector<shared_ptr<CCard>> cardsDrawn, vector<shared_ptr<CFeedbackForum>>& feedbackforum, vector<shared_ptr<CTable>>& tableAttacked, int randomCard, CPlayers& professorAttacked, CPlayers& professorAttacker, string attackedName, string attackerName, int randomChoice, vector<shared_ptr<CTable>>& tableAttacker, vector<shared_ptr<CEasyTarget>>& easyTarget); // Method to use the card and pass necessary data such as card vector, table vector, professor information, etc.
		void printCardUse() override; // Method to print the usage of the card
		void activateCardDeath(shared_ptr<CCard> elementneeded, vector<shared_ptr<CTable>>& tableAttacked, int randomIndex); // Method to activate the death effect of the card
};

