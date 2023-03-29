#include "CMitigatingCircumstances.h"

int CMitigatingCircumstances::grantDamageReduction(int damage, int mDamageReduction)
{
	damage += mDamageReduction;
	return damage;
}