// Adam James Anthony Hall
#pragma once
#include <crtdbg.h>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <sstream>

using namespace std;

class CCard
{
public:
	string type;
	string firstname;
	string lastname;
	string power;
	string resilience;
	string boost;
	virtual ~CCard() {}
};

