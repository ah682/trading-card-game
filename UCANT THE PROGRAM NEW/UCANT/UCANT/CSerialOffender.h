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
	void activateCardDeath(int randomIndex, vector<shared_ptr<CTable>>& tableAttacked); //overload
	void attackProfessor(int cardPowerAttackerInt, CPlayers::SProfessor& professorAttacked, vector<shared_ptr<CCard>> cardsDrawn, int randomCard);
	void attackEntity(int& cardResilienceAttackedInt, int& cardPowerAttackerInt, int randomIndex, vector<shared_ptr<CTable>>& tableAttacked); //not left over damage for serial offender
	void attackEntity(int& cardResilienceAttackedInt, int& cardPowerAttackerInt, int additionalRandomIndex, int randomIndex, vector<shared_ptr<CTable>>& tableAttacked, int& leftOverDamage, int& additionalCardResilienceAttackedInt); //left over damage for serialoffender
};

