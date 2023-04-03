// Adam James Anthony Hall
#pragma once
#include "CCard.h"
#include "CTable.h"

class CSerialOffender :
	public CCard
{
	public:
	void printCardUse() override;
	//Bottom
	void printCardDeath(int randomIndex, vector<shared_ptr<CTable>>& tableAttacked); //overload
};

