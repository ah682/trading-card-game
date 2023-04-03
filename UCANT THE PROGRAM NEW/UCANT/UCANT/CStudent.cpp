// Adam James Anthony Hall

// Initialize necessary header files
#include "CStudent.h"
#include "CCard.h"

void CStudent::printCardUse()
{
	cout << "Using Student Card" << endl;
}

void CStudent::printCardDeath(int randomIndex, vector<shared_ptr<CTable>>& tableAttacked)
{
	cout << "You have been expelled from the university." << endl;
}