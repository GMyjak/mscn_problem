#pragma once
#include <random>
#include <time.h>

using namespace std;

class CRandomV2
{
private:
	mt19937 c_generator;
	int i_seed;

public:
	CRandomV2();
	CRandomV2(int iSeed);
	~CRandomV2();

	int iGetNextInt(int iMin, int iMax);
	double dGetNextDouble(double dMin, double dMax);

	int iGetSeed();
	void vSetSeed(int iSeed);
};

