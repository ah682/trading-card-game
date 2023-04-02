// Adam James Anthony Hall
#pragma once
#include "CCard.h"
class CGraduateStudent :
	public CCard
{
	public:
		void printCardUse() override;
		void printCardDeath() override;
};

