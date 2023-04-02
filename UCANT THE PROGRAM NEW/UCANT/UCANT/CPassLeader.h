// Adam James Anthony Hall
#pragma once
#include "CCard.h"
class CPassLeader :
	public CCard
{
public:
	void printCardUse() override;
	void printCardDeath() override;
};

