// Adam James Anthony Hall
#pragma once

// Initialize necessary header files
#include "CCard.h"
#include "CEasyTarget.h"

class CStudent :
	public CCard
{
public:
	int mDamageReduction = 1;
	int grantDamageReduction(int mDamageReduction, int damage);
	int attackEasyTarget(int damage, vector <shared_ptr<CEasyTarget>> attacked);
};


