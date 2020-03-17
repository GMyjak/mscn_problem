#include "pch.h"
#include "CRandom.h"
#include <vector>



CRandom::CRandom()
{
	i_seed = time(NULL);
}

CRandom::CRandom(int iSeed)
{
	i_seed = iSeed;
}

CRandom::~CRandom()
{

}

void CRandom::vSetSeed(int iNewSeed)
{
	i_seed = iNewSeed;
}

int CRandom::iGetSeed()
{
	return i_seed;
}

int CRandom::iGetNextInt()
{
	int i_ret_value = 0;

	for (int ii = 0; ii < I_NUMBER_OF_BYTES; ii++)
	{
		i_seed = (i_seed * I_MULTIPLIER + I_INCREMENT) % I_MODULUS;

		i_ret_value *= 2;
		i_ret_value += i_seed % 2;
	}

	return i_ret_value;
}

int CRandom::iGetNextInt(int iMinValue, int iMaxValue)
{
	if (iMinValue >= iMaxValue)
	{
		return NULL;
	}

	int i_size_of_interval = iMaxValue - iMinValue + 1;

	return (abs(iGetNextInt()) % i_size_of_interval + iMinValue);
}

double CRandom::dGetNextDouble()
{
	double d_ret_value = (double)iGetNextInt() / I_SIZEOF_INT;

	return d_ret_value;
}

double CRandom::dGetNextDouble(double dMinValue, double dMaxValue)
{
	if (dMinValue >= dMaxValue)
	{
		return NULL;
	}

	double d_size_of_interval = dMaxValue - dMinValue;

	return abs(dGetNextDouble()) * d_size_of_interval + dMinValue;
}

//TODO doesn't work
/*int CRandom::iGetPeriod()
{
	int i_counter = -1;
	int i_first_repeat_index;
	bool b_num_repeat = false;
	vector<int> vi_numbers;

	while (!b_num_repeat)
	{
		int i_current_value = iGetNextInt();

		for (int ii = 0; ii < vi_numbers.size(); ii++)
		{
			if (i_current_value == vi_numbers[ii])
			{
				b_num_repeat = true;
				i_first_repeat_index = ii;
			}
		}

		vi_numbers.push_back(i_current_value);
		i_counter++;
	}

	return i_counter - i_first_repeat_index;
}*/
