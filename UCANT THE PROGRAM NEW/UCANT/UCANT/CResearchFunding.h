// Adam James Anthony Hall
#pragma once
#include "CCard.h"
class CResearchFunding :
	public CCard
{
public:
	void printCardUse() override;
	void printCardDeath() override;
};

