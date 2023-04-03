// Adam James Anthony Hall
#pragma once
#include "CCard.h"
#include "CManager.h"
#include "CEasyTarget.h"
class CResearchFunding :
	public CCard
{
public:
	void useCard(vector<shared_ptr<CCard>> cardsDrawn, vector<shared_ptr<CResearchFunding>> researchFunding, int randomCard, CPlayers::SProfessor& professorAttacker, string attackerName, vector<shared_ptr<CTable>>& tableAttacker);
	void printCardUse() override;
	void printCardDeath();
};

