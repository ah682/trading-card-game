// Adam James Anthony Hall
#pragma once

// Initialize necessary header files
#include "CCard.h"

class CFeedbackForum :
	public CCard
{
	public:
		void printCardUse() override;
		void printCardDeath() override;
};

