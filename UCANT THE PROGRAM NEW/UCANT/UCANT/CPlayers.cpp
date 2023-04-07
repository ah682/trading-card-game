// Adam James Anthony Hall

// Initialize necessary header files
#include "CPlayers.h"

/**

The ProfessorSacked function checks the prestige of four professors and
prints a message indicating whether any of them have been sacked due to
having a prestige of zero or less.
@param plagiarist A reference to the SProfessor struct for the first professor.
@param piffle A reference to the SProfessor struct for the second professor.
@param pointless A reference to the SProfessor struct for the third professor.
@param perdition A reference to the SProfessor struct for the fourth professor.
*/
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