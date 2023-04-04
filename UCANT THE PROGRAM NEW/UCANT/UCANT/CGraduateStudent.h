// Adam James Anthony Hall
#pragma once
#include "CCard.h"
#include "CTable.h"
#include "CManager.h"
#include "CEasyTarget.h"
class CGraduateStudent :
	public CCard
{
	public:
		void useCard(vector<shared_ptr<CTable>>& tableAttacked, vector<shared_ptr<CTable>>& tableAttacker, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, vector<shared_ptr<CCard>> cardsDrawn, vector<shared_ptr<CGraduateStudent>>& graduateStudent, int randomCard, vector<shared_ptr<CEasyTarget>>& easyTarget);
		void printCardUse() override;
		void activateCardDeath(int randomIndex, vector<shared_ptr<CTable>>& tableAttacked);
		void attackProfessor(CPlayers::SProfessor& professorAttacked, int cardPowerAttackerInt, vector<shared_ptr<CCard>> cardsDrawn, int randomCard);
		void attackEntity(int& cardResilienceAttackedInt, int& cardPowerAttackerInt, string& cardResilienceStringDueled, vector<shared_ptr<CTable>>& tableAttacked, int randomIndex, int randomCard, vector<shared_ptr<CCard>>& cardsDrawn);
};

