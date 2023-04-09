// Adam James Anthony Hall
#pragma once
#include "CCard.h"
#include "CTable.h"
#include "CManager.h"
#include "CEasyTarget.h"

class CIndustrialPlacement :
	public CCard
{
public:
	void useCard(vector<shared_ptr<CCard>> cardsDrawn, vector<shared_ptr<CIndustrialPlacement>>& industrialPlacement, int randomCard, CPlayers& professorAttacked, CPlayers& professorAttacker, string attackerName, vector<shared_ptr<CTable>>& tableAttacker, vector<shared_ptr<CTable>>& tableAttacked, vector<shared_ptr<CEasyTarget>>& easyTarget); // Method to use the card and pass necessary data such as card vector, table vector, professor information, etc.
	void printCardUse() override; // Method to print the usage of the card
	void activateCardDeath(int randomIndex, vector<shared_ptr<CTable>>& tableAttacked); // Method to activate the death effect of the card
	void attackProfessor(CPlayers& professorAttacked, int cardPowerAttackerInt, int randomCard, vector<shared_ptr<CCard>> cardsDrawn); // Method to attack a professor with the card
};

