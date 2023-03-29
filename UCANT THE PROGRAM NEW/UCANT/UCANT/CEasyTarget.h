#pragma once
#include "CCard.h"
class CEasyTarget :
    public CCard
{
    int attackEasyTarget(int damage, vector <shared_ptr<CEasyTarget>> attacked);
};

