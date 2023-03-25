// Adam James Anthony Hall

// Initialize necessary header files
#include "CStudent.h"
#include "CCard.h"

int CStudent::grantDamageReduction(int mDamageReduction, int damage)
{
	damage = -mDamageReduction;
	return damage;
}