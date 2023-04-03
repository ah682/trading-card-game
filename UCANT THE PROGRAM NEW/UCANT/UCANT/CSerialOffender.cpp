// Adam James Anthony Hall
#include "CSerialOffender.h"

void CSerialOffender::printCardUse()
{
	cout << "Using Serial Offender Card" << endl;
}

//Bottom
void CSerialOffender::printCardDeath(int randomIndex, vector<shared_ptr<CTable>>& tableAttacked) //overload
{
	cout << tableAttacked[randomIndex]->mFirstname << " " << tableAttacked[randomIndex]->mLastname << " is defeated" << endl;
}
