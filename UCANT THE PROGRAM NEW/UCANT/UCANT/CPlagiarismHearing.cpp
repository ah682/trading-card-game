// Adam James Anthony Hall

// Initialize necessary header files
#include "CPlagiarismHearing.h"

void CPlagiarismHearing::printCardUse()
{
	cout << "Using Plagiarism Hearing Card" << endl;
}

void CPlagiarismHearing::printCardDeath(CCard* elementneeded) //Function overloading
{
	cout << elementneeded->mType << " " << elementneeded->mFirstname << " " << elementneeded->mLastname << " " << elementneeded->mPower << " " << elementneeded->mResilience << " " << elementneeded->mBoost << " is defeated" << endl;

}
