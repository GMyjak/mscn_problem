#include "pch.h"
#include "CRandomV2.h"


CRandomV2::CRandomV2()
{
	i_seed = time(NULL);
	c_generator = mt19937(i_seed);
}

CRandomV2::CRandomV2(int iSeed)
{
	i_seed = iSeed;
	c_generator = mt19937(i_seed);
}


CRandomV2::~CRandomV2()
{
}

int CRandomV2::iGetNextInt(int iMin, int iMax)
{
	if (iMin > iMax)
	{
		return NULL;
	}

	return uniform_int_distribution<int>{iMin, iMax}(c_generator);
}

double CRandomV2::dGetNextDouble(double dMin, double dMax)
{
	if (dMin > dMax)
	{
		return NULL;
	}

	return uniform_real_distribution<double>{dMin, dMax}(c_generator);
}

int CRandomV2::iGetSeed()
{
	return i_seed;
}

void CRandomV2::vSetSeed(int iSeed)
{
	i_seed = iSeed;
	c_generator = mt19937(i_seed);
}
