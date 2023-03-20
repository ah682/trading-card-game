#pragma once

#include "CCard.h"
#include <crtdbg.h>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <sstream>

class CCounter
{
public:
	int i = 0;
	int deckCounter = 2;
	int num_cardsPlagiarist = 0;
	int num_cardsPiffle = 0;
	int randomCardPiffle = 0;
	int randomCardPlagiarist = 0;
	int seed = 0;
	int resilienceIncreasePiffle = 0;
	int resilienceIncreasePlagiarist = 0;
	string linePiffle = "";
	string linePlagiarist = "";
	ifstream filePlagiarist;
	ifstream filePiffle;
};

