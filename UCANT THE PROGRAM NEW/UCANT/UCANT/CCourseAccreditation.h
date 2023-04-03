// Adam James Anthony Hall
#pragma once

// Initialize necessary header files
#include "CCard.h"
#include "CTable.h"
class CCourseAccreditation :
	public CCard
{
	public:
	void printCardUse() override;
	void printCardDeath(int j, vector<shared_ptr<CTable>>& tableAttacked); //Overloaded function
};

