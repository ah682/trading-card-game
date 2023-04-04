// Adam James Anthony Hall
#pragma once
#include "CCard.h"
#include "CTable.h"
#include "CManager.h"
#include "CEasyTarget.h"


class CSerialOffender :
	public CCard
{
	public:
	void useCard(vector<shared_ptr<CTable>>& tableAttacked, vector<shared_ptr<CTable>>& tableAttacker, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, vector<shared_ptr<CCard>> cardsDrawn, vector<shared_ptr<CSerialOffender>>& serialOffender, int randomCard, vector<shared_ptr<CEasyTarget>>& easyTarget);
	void printCardUse() override;
	//Bottom
	void activateCardDeath(int randomIndex, vector<shared_ptr<CTable>>& tableAttacked); //overload
};

