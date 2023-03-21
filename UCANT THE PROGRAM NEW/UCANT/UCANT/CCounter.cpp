// Adam James Anthony Hall
#include "CCard.h"
#include "CCounter.h"
#include <crtdbg.h>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
#include <sstream>

int CCounter::Random(int max)
{
    return int(float(rand()) / (RAND_MAX + 1) * float(max));
}

int CCounter::randomRange(int min, int max)
{
    return min + int(float(rand()) / (RAND_MAX + 1) * float(max - min + 1));
}
