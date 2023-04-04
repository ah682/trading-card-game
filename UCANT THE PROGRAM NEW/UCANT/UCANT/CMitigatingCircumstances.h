// Adam James Anthony Hall
#pragma once
#include "CCard.h"
#include "CManager.h"
#include "CEasyTarget.h"
class CMitigatingCircumstances :
	public CCard
{
public:
	int mDamageReduction = 1;
	int useCardSpecialAbility(int damage, int mDamageReduction); //Grant Damage Reduction
	void useCard(vector<shared_ptr<CCard>> cardsDrawn, shared_ptr<CMitigatingCircumstances> damageReduction, vector<shared_ptr<CTable>>& tableAttacker, vector<shared_ptr<CMitigatingCircumstances>> mitigatingCircumstances, int randomCard);
	void printCardUse() override;
};

