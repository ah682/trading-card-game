// Adam James Anthony Hall
#pragma once
#include "CCard.h"
#include "CCounter.h"
class CEasyTarget :
	public CCard
{
public:
	int useCardSpecialAbility(int damage, vector <shared_ptr<CEasyTarget>>& attacked);
	void printCardUse() override;
	void activateCardDeath(int additionalEasyTargetRandomIndex, vector<shared_ptr<CEasyTarget>>& easyTarget); //overload
	void attackEntity(int& additionalCardResilienceAttackedIntEasyTarget, int& leftOverDamage, int randomIndex, int additionalEasyTargetRandomIndex, vector<shared_ptr<CEasyTarget>>& easyTarget);

};

