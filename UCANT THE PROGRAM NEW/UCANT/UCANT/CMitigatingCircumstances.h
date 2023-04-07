// Adam James Anthony Hall
#pragma once
#include "CCard.h"
#include "CManager.h"
#include "CEasyTarget.h"
class CMitigatingCircumstances :
	public CCard
{
public:
	int mDamageReductionGetterInt = 0;
	int useCardSpecialAbility(int damage, int mDamageReduction); // Grant Damage Reduction returns left over dmaage if required
	void useCard(vector<shared_ptr<CCard>> cardsDrawn, shared_ptr<CMitigatingCircumstances> damageReduction, vector<shared_ptr<CTable>>& tableAttacker, vector<shared_ptr<CMitigatingCircumstances>> mitigatingCircumstances, int randomCard);
	void printCardUse() override;
	int getMDamageReduction(); // Getter method for the mDamageReductionInt variable.
private:
	int mDamageReductionInt = 1;
};

