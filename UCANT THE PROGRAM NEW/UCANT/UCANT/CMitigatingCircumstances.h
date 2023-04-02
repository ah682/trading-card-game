// Adam James Anthony Hall
#pragma once
#include "CCard.h"
class CMitigatingCircumstances :
	public CCard
{
public:
	int mDamageReduction = 1;
	int grantDamageReduction(int damage, int mDamageReduction); //Grant Damage Reduction
	void printCardUse() override;
	void printCardDeath() override;
};

