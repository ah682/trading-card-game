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
	void useCard(vector<shared_ptr<CCard>> cardsDrawn, vector<shared_ptr<CIndustrialPlacement>>& industrialPlacement, int randomCard, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, string attackerName, vector<shared_ptr<CTable>>& tableAttacker, vector<shared_ptr<CTable>>& tableAttacked, vector<shared_ptr<CEasyTarget>>& easyTarget);
	void printCardUse() override;
	void printCardDeath(int randomIndex, vector<shared_ptr<CTable>>& tableAttacked);
};

