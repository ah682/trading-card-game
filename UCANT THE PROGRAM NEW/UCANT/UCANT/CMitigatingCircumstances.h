// Adam James Anthony Hall
#pragma once
#include "CCard.h"
#include "CManager.h"
#include "CEasyTarget.h"
/*
The CMitigatingCircumstances class is derived from the CCard class and represents a type of card in the game. This class contains methods to use the card, print its usage, and grant damage reduction.

Public member functions:

useCardSpecialAbility: returns the left over damage after granting damage reduction.
useCard: takes several arguments including vectors of shared pointers to CCard, CMitigatingCircumstances, and CTable objects, as well as a shared pointer to a CMitigatingCircumstances object and an int for a random card.
printCardUse: overrides the printCardUse function from the base class.
getMDamageReduction: getter method for the mDamageReductionInt variable.
Private member variable:

mDamageReductionInt: stores the damage reduction value.
*/
class CMitigatingCircumstances :
	public CCard // CMitigatingCircumstances is derived from CCard using public inheritance
{
public:
	int mDamageReductionGetterInt = 0; // Variable to store the damage reduction value
	int useCardSpecialAbility(int damage, int mDamageReduction); // Grant Damage Reduction returns left over dmaage if required
	void useCard(vector<shared_ptr<CCard>> cardsDrawn, shared_ptr<CMitigatingCircumstances> damageReduction, vector<shared_ptr<CTable>>& tableAttacker, vector<shared_ptr<CMitigatingCircumstances>> mitigatingCircumstances, int randomCard); // Use card function
	void printCardUse() override; // Print card use function
	int getMDamageReduction(); // Getter method for the mDamageReductionInt variable.
private:
	int mDamageReductionInt = 1; // Variable to store the damage reduction value
};

