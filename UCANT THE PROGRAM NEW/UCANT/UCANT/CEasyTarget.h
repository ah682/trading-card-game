// Adam James Anthony Hall
#pragma once
#include "CCard.h"
#include "CCounter.h"
#include "CPlayers.h"
#include "CTable.h"

/*
 * The CEasyTarget class is derived from the CCard class and represents a type of card in the game.
 * This class contains methods to use the card's special ability, print its usage, activate its death effect,
 * and attack an entity on the table.
 */
class CEasyTarget :
	public CCard // CEasyTarget is derived from CCard using public inheritance
{
public:
	int useCardSpecialAbility(int damage, vector <shared_ptr<CEasyTarget>>& attacked); // Returns damage if required
	void printCardUse() override; // Overrides the printCardUse method from the base class
	void activateCardDeath(int additionalEasyTargetRandomIndex, vector<shared_ptr<CEasyTarget>>& easyTarget); // Overloaded method to activate the card's death effect
	void attackEntity(int& additionalCardResilienceAttackedIntEasyTarget, int& leftOverDamage, int randomIndex, int additionalEasyTargetRandomIndex, vector<shared_ptr<CEasyTarget>>& easyTarget); // Method to attack an entity on the table
	void UseCard(vector<shared_ptr<CCard>> cardsDrawn, vector<shared_ptr<CEasyTarget>> easyTarget, int randomCard, CPlayers& professorAttacker, string attackerName, vector<shared_ptr<CTable>>& tableAttacker); // Uses an easy target card
};

