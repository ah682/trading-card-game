// Adam James Anthony Hall
#pragma once

// Initialize necessary header files
#include "CCard.h"
#include "CManager.h"
#include "CEasyTarget.h"

class CFeedbackForum :
	public CCard
{
	public:
		void useCard(vector<shared_ptr<CCard>> cardsDrawn, vector<shared_ptr<CFeedbackForum>>& feedbackforum, vector<shared_ptr<CTable>>& tableAttacked, int randomCard, CPlayers::SProfessor& professorAttacked, CPlayers::SProfessor& professorAttacker, string attackedName, string attackerName, int randomChoice, vector<shared_ptr<CTable>>& tableAttacker, vector<shared_ptr<CEasyTarget>>& easyTarget);
		void printCardUse() override;
		void printCardDeath(shared_ptr<CCard> elementneeded);
};

