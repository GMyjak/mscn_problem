#include <iostream>
#include <ctime>
#include <cmath>

#define I_MODULUS 7829
#define I_MULTIPLIER 379
#define I_INCREMENT 2310

#define I_NUMBER_OF_BYTES 32
#define I_SIZEOF_INT 2147483647

using namespace std;

class CRandom
{
private:
	int i_seed;

public:
	CRandom();
	CRandom(int iSeed);
	~CRandom();

	void vSetSeed(int iNewSeed);
	int iGetSeed();

	int iGetNextInt();												//Returns random int32
	int iGetNextInt(int iMinValue, int iMaxValue);					//Returns random constrained int32
	double dGetNextDouble();										//Returns random double from 0 to 1
	double dGetNextDouble(double dMinValue, double dMaxValue);		//Returns random constrained double

	//int iGetPeriod();
};


