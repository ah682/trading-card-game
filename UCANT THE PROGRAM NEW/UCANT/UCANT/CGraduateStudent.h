// Adam James Anthony Hall
#pragma once
#include "CCard.h"
#include "CTable.h"
class CGraduateStudent :
	public CCard
{
	public:
		void printCardUse() override;
		void printCardDeath(int randomIndex, vector<shared_ptr<CTable>>& tableAttacked);
};

