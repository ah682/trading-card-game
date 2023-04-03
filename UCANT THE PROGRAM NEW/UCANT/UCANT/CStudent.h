// Adam James Anthony Hall
#pragma once

// Initialize necessary header files
#include "CCard.h"
#include "CTable.h"

class CStudent :
	public CCard
{
public:
	void printCardUse() override;
	void printCardDeath(int randomIndex, vector<shared_ptr<CTable>>& tableAttacked);
};


