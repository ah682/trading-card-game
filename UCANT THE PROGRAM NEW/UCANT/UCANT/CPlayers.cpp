// Adam James Anthony Hall

// Initialize necessary header files
#include "CPlayers.h"

void CPlayers::ProfessorSacked(CPlayers::SProfessor& plagiarist, CPlayers::SProfessor& piffle, CPlayers::SProfessor& pointless, CPlayers::SProfessor& perdition)
{
	if (plagiarist.mProfPrestige <= 0)
	{
		cout << endl << "Prof " << plagiarist.mProfName << " has no prestige and is sacked!" << endl;
	}
	else if (piffle.mProfPrestige <= 0)
	{
		cout << endl << "Prof " << piffle.mProfName << " has no prestige and is sacked!" << endl;
	}
	else if (pointless.mProfPrestige <= 0)
	{
		cout << endl << "Prof " << pointless.mProfName << " has no prestige and is sacked!" << endl;
	}
	else if (perdition.mProfPrestige <= 0)
	{
		cout << endl << "Prof " << perdition.mProfName << " has no prestige and is sacked!" << endl;
	}
	else
	{

	}
	
}