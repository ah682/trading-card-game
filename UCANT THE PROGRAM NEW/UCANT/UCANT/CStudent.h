// Adam James Anthony Hall
#pragma once

// Initialize necessary header files
#include "CCard.h"

class CStudent :
	public CCard
{
public:
	void printCardUse() override;
	void printCardDeath() override;
};


