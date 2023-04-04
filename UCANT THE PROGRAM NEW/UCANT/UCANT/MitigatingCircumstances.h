// Adam James Anthony Hall
#pragma once
#include "CCard.h"
class MitigatingCircumstances :
	public CCard
{
	public:
		void printCardUse() override;
		void activateCardDeath();
};

