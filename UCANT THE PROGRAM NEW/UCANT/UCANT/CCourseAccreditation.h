// Adam James Anthony Hall
#pragma once

// Initialize necessary header files
#include "CCard.h"
#include "CTable.h"
#include "CManager.h"
#include "CEasyTarget.h"

/*
 * The CCourseAccreditation class is derived from the CCard class and represents a type of card in the game.
 * This class contains methods to use the card, print its usage, activate its death effect, attack a professor,
 * and attack an entity on the table.
 */
class CCourseAccreditation :
	public CCard // This class inherits from CCard

{
	public:
	void useCard(vector<shared_ptr<CCard>>& cardsDrawn, vector <shared_ptr<CCourseAccreditation>>& accreditation, vector<shared_ptr<CTable>>& tableAttacked, int randomCard, CPlayers& professorAttacked, CPlayers& professorAttacker, string attackedName, string attackerName, vector<shared_ptr<CEasyTarget>>& easyTarget); // Method to use the card and pass necessary data such as card vector, table vector, professor information, etc.
	void printCardUse() override; // Method to print the usage of the card
	void activateCardDeath(int j, vector<shared_ptr<CTable>>& tableAttacked); // Overloaded function method to activate the death effect of the card
	void attackProfessor(int cardPower, int randomCard, CPlayers& professorAttacked, vector<shared_ptr<CCard>>& cardsDrawn); // Method to attack a professor with the card
	void attackEntity(string& cardResilienceString, vector<shared_ptr<CTable>>& tableAttacked, vector<shared_ptr<CCard>>& cardsDrawn, int j, int randomCard); // Method to attack an entity on the table with the card
};

