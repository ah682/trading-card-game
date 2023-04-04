// Adam James Anthony Hall
#pragma once

// Initialize necessary header files
#include "CCard.h"
#include "CTable.h"
#include "CManager.h"
#include "CEasyTarget.h"
class CCourseAccreditation :
	public CCard
{
	public:
	void useCard(vector<shared_ptr<CCard>>& cardsDrawn, vector <shared_ptr<CCourseAccreditation>>& accreditation, vector<shared_ptr<CTable>>& tableAttacked, int randomCard, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, string attackedName, string attackerName, vector<shared_ptr<CEasyTarget>>& easyTarget);
	void printCardUse() override;
	void activateCardDeath(int j, vector<shared_ptr<CTable>>& tableAttacked); //Overloaded function
	void attackProfessor(int cardPower, int randomCard, CPlayers::SProfessor& professorAttacked, vector<shared_ptr<CCard>>& cardsDrawn);
	void attackEntity(string& cardResilienceString, vector<shared_ptr<CTable>>& tableAttacked, vector<shared_ptr<CCard>>& cardsDrawn, int j, int randomCard);
};

