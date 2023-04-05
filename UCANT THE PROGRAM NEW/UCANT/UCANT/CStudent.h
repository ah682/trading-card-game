// Adam James Anthony Hall
#pragma once

// Initialize necessary header files
#include "CCard.h"
#include "CTable.h"
#include "CPlayers.h"


class CStudent :
	public CCard
{
public:
	void printCardUse() override;
	void activateCardDeath(int randomIndex, vector<shared_ptr<CTable>>& tableAttacked);
	void attackEntity(int &cardResilienceAttackedInt, int &cardPowerAttackerInt, int randomIndex, int randomCard, vector<shared_ptr<CTable>>& tableAttacked, vector<shared_ptr<CCard>> cardsDrawn);
	void attackProfessor(CPlayers::SProfessor& professorAttacked, vector<shared_ptr<CCard>> cardsDrawn, int randomCard, int& cardPowerAttackedInt);
};


