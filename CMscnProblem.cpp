#include "pch.h"
#include "CMscnProblem.h"

using namespace std;

CMscnProblem::CMscnProblem()
{

}


CMscnProblem::~CMscnProblem()
{

}


int CMscnProblem::iGetSolutionSize()
{
	return (i_provider_number * i_factory_number + i_factory_number * i_warehouse_number + i_warehouse_number * i_shop_number);
}

bool CMscnProblem::bSetProviderNumber(int iNumber)
{
	if (iNumber < 0)
	{
		return false;
	}

	i_provider_number = iNumber;

	prod_cost_provider_factory.bSetSizeX(iNumber);
	resource_amount_provider_factory.bSetSizeX(iNumber);
	resource_amount_provider_factory_min.bSetSizeX(iNumber);
	resource_amount_provider_factory_max.bSetSizeX(iNumber);
	single_cost_provider.bSetSize(iNumber);
	prod_power_provider.bSetSize(iNumber);

	return true;
}

bool CMscnProblem::bSetFactoryNumber(int iNumber)
{
	if (iNumber < 0)
	{
		return false;
	}
	
	i_factory_number = iNumber;

	prod_cost_provider_factory.bSetSizeY(iNumber);
	prod_cost_factory_warehouse.bSetSizeX(iNumber);
	resource_amount_provider_factory.bSetSizeY(iNumber);
	resource_amount_factory_warehouse.bSetSizeX(iNumber);
	single_cost_factory.bSetSize(iNumber);
	prod_power_factory.bSetSize(iNumber);

	resource_amount_provider_factory_min.bSetSizeY(iNumber);
	resource_amount_provider_factory_max.bSetSizeY(iNumber);
	resource_amount_factory_warehouse_min.bSetSizeX(iNumber);
	resource_amount_factory_warehouse_max.bSetSizeX(iNumber);

	return true;
}

bool CMscnProblem::bSetWarehouseNumber(int iNumber)
{
	if (iNumber < 0)
	{
		return false;
	}
	
	i_warehouse_number = iNumber;

	prod_cost_factory_warehouse.bSetSizeY(iNumber);
	prod_cost_warehouse_shop.bSetSizeX(iNumber);
	resource_amount_factory_warehouse.bSetSizeY(iNumber);
	resource_amount_warehouse_shop.bSetSizeX(iNumber);
	single_cost_warehouse.bSetSize(iNumber);
	prod_power_warehouse.bSetSize(iNumber);

	resource_amount_factory_warehouse_min.bSetSizeY(iNumber);
	resource_amount_factory_warehouse_max.bSetSizeY(iNumber);
	resource_amount_warehouse_shop_min.bSetSizeX(iNumber);
	resource_amount_warehouse_shop_max.bSetSizeX(iNumber);

	return true;
}

bool CMscnProblem::bSetShopNumber(int iNumber)
{
	if (iNumber < 0)
	{
		return false;
	}
	
	i_shop_number = iNumber;

	prod_cost_warehouse_shop.bSetSizeY(iNumber);
	resource_amount_warehouse_shop.bSetSizeY(iNumber);
	profit_per_shop.bSetSize(iNumber);
	prod_demand_shop.bSetSize(iNumber);

	resource_amount_warehouse_shop_min.bSetSizeY(iNumber);
	resource_amount_warehouse_shop_max.bSetSizeY(iNumber);

	return true;
}

bool CMscnProblem::bSetCdValueAt(int iOffsetX, int iOffsetY, double dValue)
{
	if (dValue < 0) 
	{
		return false;
	}
	return prod_cost_provider_factory.bSetValueAt(iOffsetX, iOffsetY, dValue);
}

bool CMscnProblem::bSetCfValueAt(int iOffsetX, int iOffsetY, double dValue)
{
	if (dValue < 0)
	{
		return false;
	}
	return prod_cost_factory_warehouse.bSetValueAt(iOffsetX, iOffsetY, dValue);
}

bool CMscnProblem::bSetCmValueAt(int iOffsetX, int iOffsetY, double dValue)
{
	if (dValue < 0)
	{
		return false;
	}
	return prod_cost_warehouse_shop.bSetValueAt(iOffsetX, iOffsetY, dValue);
}


bool CMscnProblem::bSetUdValueAt(int iOffset, double dValue)
{
	if (dValue < 0)
	{
		return false;
	}
	return single_cost_provider.bSetValueAt(iOffset, dValue);
}

bool CMscnProblem::bSetUfValueAt(int iOffset, double dValue)
{
	if (dValue < 0)
	{
		return false;
	}
	return single_cost_factory.bSetValueAt(iOffset, dValue);
}

bool CMscnProblem::bSetUmValueAt(int iOffset, double dValue)
{
	if (dValue < 0)
	{
		return false;
	}
	return single_cost_warehouse.bSetValueAt(iOffset, dValue);
}

bool CMscnProblem::bSetPValueAt(int iOffset, double dValue)
{
	if (dValue < 0)
	{
		return false;
	}
	return profit_per_shop.bSetValueAt(iOffset, dValue);
}


bool CMscnProblem::bSetSdValueAt(int iOffset, double dValue)
{
	if (dValue < 0)
	{
		return false;
	}
	return prod_power_provider.bSetValueAt(iOffset, dValue);
}

bool CMscnProblem::bSetSfValueAt(int iOffset, double dValue)
{
	if (dValue < 0)
	{
		return false;
	}
	return prod_power_factory.bSetValueAt(iOffset, dValue);
}

bool CMscnProblem::bSetSmValueAt(int iOffset, double dValue)
{
	if (dValue < 0)
	{
		return false;
	}
	return prod_power_warehouse.bSetValueAt(iOffset, dValue);
}

bool CMscnProblem::bSetSsValueAt(int iOffset, double dValue)
{
	if (dValue < 0)
	{
		return false;
	}
	return prod_demand_shop.bSetValueAt(iOffset, dValue);
}


bool CMscnProblem::bSetXdMinValueAt(int iOffsetX, int iOffsetY, double dValue)
{
	if (dValue < 0)
	{
		return false;
	}
	return resource_amount_provider_factory_min.bSetValueAt(iOffsetX, iOffsetY, dValue);
}

bool CMscnProblem::bSetXdMaxValueAt(int iOffsetX, int iOffsetY, double dValue)
{
	if (dValue < 0)
	{
		return false;
	}
	return resource_amount_provider_factory_max.bSetValueAt(iOffsetX, iOffsetY, dValue);
}

bool CMscnProblem::bSetXfMinValueAt(int iOffsetX, int iOffsetY, double dValue)
{
	if (dValue < 0)
	{
		return false;
	}
	return resource_amount_factory_warehouse_min.bSetValueAt(iOffsetX, iOffsetY, dValue);
}

bool CMscnProblem::bSetXfMaxValueAt(int iOffsetX, int iOffsetY, double dValue)
{
	if (dValue < 0)
	{
		return false;
	}
	return resource_amount_factory_warehouse_max.bSetValueAt(iOffsetX, iOffsetY, dValue);
}

bool CMscnProblem::bSetXmMinValueAt(int iOffsetX, int iOffsetY, double dValue)
{
	if (dValue < 0)
	{
		return false;
	}
	return resource_amount_warehouse_shop_min.bSetValueAt(iOffsetX, iOffsetY, dValue);
}

bool CMscnProblem::bSetXmMaxValueAt(int iOffsetX, int iOffsetY, double dValue)
{
	if (dValue < 0)
	{
		return false;
	}
	return resource_amount_warehouse_shop_max.bSetValueAt(iOffsetX, iOffsetY, dValue);
}

bool CMscnProblem::bSetXdValueAt(int iOffsetX, int iOffsetY, double dValue)
{
	if (dValue < 0)
	{
		return false;
	}
	return resource_amount_provider_factory.bSetValueAt(iOffsetX, iOffsetY, dValue);
}

bool CMscnProblem::bSetXfValueAt(int iOffsetX, int iOffsetY, double dValue)
{
	if (dValue < 0)
	{
		return false;
	}
	return resource_amount_factory_warehouse.bSetValueAt(iOffsetX, iOffsetY, dValue);
}

bool CMscnProblem::bSetXmValueAt(int iOffsetX, int iOffsetY, double dValue)
{
	if (dValue < 0)
	{
		return false;
	}
	return resource_amount_warehouse_shop.bSetValueAt(iOffsetX, iOffsetY, dValue);
}

double CMscnProblem::dGetXdMinAt(int iOffset, int* iErrFlag)
{
	if (iOffset < 0 || iOffset >= i_provider_number * i_factory_number)
	{
		*iErrFlag = E_INDEX_OUT_OF_BOUNDS;
		return NULL;
	}
	return resource_amount_provider_factory_min.getValueAtArray(iOffset);
}

double CMscnProblem::dGetXdMaxAt(int iOffset, int* iErrFlag)
{
	if (iOffset < 0 || iOffset >= i_provider_number * i_factory_number)
	{
		*iErrFlag = E_INDEX_OUT_OF_BOUNDS;
		return NULL;
	}
	return resource_amount_provider_factory_max.getValueAtArray(iOffset);
}

double CMscnProblem::dGetXfMinAt(int iOffset, int* iErrFlag)
{
	if (iOffset < 0 || iOffset >= i_factory_number * i_warehouse_number)
	{
		*iErrFlag = E_INDEX_OUT_OF_BOUNDS;
		return NULL;
	}
	return resource_amount_factory_warehouse_min.getValueAtArray(iOffset);
}

double CMscnProblem::dGetXfMaxAt(int iOffset, int* iErrFlag)
{
	if (iOffset < 0 || iOffset >= i_factory_number * i_warehouse_number)
	{
		*iErrFlag = E_INDEX_OUT_OF_BOUNDS;
		return NULL;
	}
	return resource_amount_factory_warehouse_max.getValueAtArray(iOffset);
}

double CMscnProblem::dGetXmMinAt(int iOffset, int* iErrFlag)
{
	if (iOffset < 0 || iOffset >= i_warehouse_number * i_shop_number)
	{
		*iErrFlag = E_INDEX_OUT_OF_BOUNDS;
		return NULL;
	}
	return resource_amount_warehouse_shop_min.getValueAtArray(iOffset);
}

double CMscnProblem::dGetXmMaxAt(int iOffset, int* iErrFlag)
{
	if (iOffset < 0 || iOffset >= i_warehouse_number * i_shop_number)
	{
		*iErrFlag = E_INDEX_OUT_OF_BOUNDS;
		return NULL;
	}
	return resource_amount_warehouse_shop_max.getValueAtArray(iOffset);
}

int CMscnProblem::iGetProviderNumber()
{
	return i_provider_number;
}

int CMscnProblem::iGetFactoryNumber()
{
	return i_factory_number;
}

int CMscnProblem::iGetWarehouseNumber()
{
	return i_warehouse_number;
}

int CMscnProblem::iGetShopNumber()
{
	return i_shop_number;
}





double CMscnProblem::dGetQuality(vector<double> &vdSolution, int* iErrFlag)
{
	bLoadSolutionFromVector(vdSolution, iErrFlag);
	if (*iErrFlag != E_NO_ERROR)
	{
		return NULL;
	}

	if (!bCheckDataFormat())
	{
		*iErrFlag = E_INCORRECT_DATA_FORMAT;
		return NULL;
	}
	if (!bCheckDataValues())
	{
		*iErrFlag = E_NEGATIVE_DATA_VALUES;
		return NULL;
	}
	if (!bCheckSolutionLegalValues())
	{
		*iErrFlag = E_NEGATIVE_SOLUTION_VALUES;
		return NULL;
	}

	*iErrFlag = E_NO_ERROR;

	double d_sum_kt = 0;
	double d_sum_ku = 0;
	double d_sum_p = 0;

	//Obliczanie KT
	for (int iip = 0; iip < i_provider_number; iip++)
	{
		for (int iif = 0; iif < i_factory_number; iif++)
		{
			d_sum_kt += (prod_cost_provider_factory.getValueAt(iip, iif) * resource_amount_provider_factory.getValueAt(iip, iif));
		}
	}

	for (int iif = 0; iif < i_factory_number; iif++)
	{
		for (int iiw = 0; iiw < i_warehouse_number; iiw++)
		{
			d_sum_kt += (prod_cost_factory_warehouse.getValueAt(iif, iiw) * resource_amount_factory_warehouse.getValueAt(iif, iiw));
		}
	}

	for (int iiw = 0; iiw < i_warehouse_number; iiw++)
	{
		for (int iis = 0; iis < i_shop_number; iis++)
		{
			//Hidden spaghetti message
			d_sum_kt += (prod_cost_warehouse_shop.getValueAt(iiw, iis) * resource_amount_warehouse_shop.getValueAt(iiw, iis));
		}
	}

	//Obliczanie KU
	for (int iip = 0; iip < i_provider_number; iip++)
	{
		double d_sum_aux = 0;
		
		for (int iif = 0; iif < i_factory_number; iif++)
		{
			d_sum_aux += resource_amount_provider_factory.getValueAt(iip, iif);
		}

		if (d_sum_aux > 0)
		{
			d_sum_ku += single_cost_provider.getValueAt(iip);
		}
	}

	for (int iif = 0; iif < i_factory_number; iif++)
	{
		double d_sum_aux = 0;
		
		for (int iiw = 0; iiw < i_warehouse_number; iiw++)
		{
			d_sum_aux += resource_amount_factory_warehouse.getValueAt(iif, iiw);
		}

		if (d_sum_aux > 0)
		{
			d_sum_ku += single_cost_factory.getValueAt(iif);
		}
	}

	for (int iiw = 0; iiw < i_warehouse_number; iiw++)
	{
		double d_sum_aux = 0;
		
		for (int iis = 0; iis < i_shop_number; iis++)
		{
			d_sum_aux += resource_amount_warehouse_shop.getValueAt(iiw, iis);
		}

		if (d_sum_aux > 0)
		{
			d_sum_ku += single_cost_warehouse.getValueAt(iiw);
		}
	}

	//Obliczanie P
	for (int iiw = 0; iiw < i_warehouse_number; iiw++)
	{
		for (int iis = 0; iis < i_shop_number; iis++)
		{
			d_sum_p += (profit_per_shop.getValueAt(iis) * resource_amount_warehouse_shop.getValueAt(iiw, iis));
		}
	}

	return (d_sum_p - d_sum_kt - d_sum_ku);
}

bool CMscnProblem::bConstraintsSatisfied(vector<double> &vdSolution, int* iErrFlag)
{
	bLoadSolutionFromVector(vdSolution, iErrFlag);
	if (*iErrFlag != E_NO_ERROR)
	{
		return NULL;
	}

	if (!bCheckDataFormat())
	{
		*iErrFlag = E_INCORRECT_DATA_FORMAT;
		return NULL;
	}
	if (!bCheckDataValues())
	{
		*iErrFlag = E_NEGATIVE_DATA_VALUES;
		return NULL;
	}

	*iErrFlag = E_NO_ERROR;

	return bCheckSolutionConstraints();
}

bool CMscnProblem::bCheckDataFormat()
{
	bool b_ret_flag = true;

	b_ret_flag = b_ret_flag && prod_cost_provider_factory.bIsOfSize(i_provider_number, i_factory_number);
	b_ret_flag = b_ret_flag && prod_cost_factory_warehouse.bIsOfSize(i_factory_number, i_warehouse_number);
	b_ret_flag = b_ret_flag && prod_cost_warehouse_shop.bIsOfSize(i_warehouse_number, i_shop_number);
	b_ret_flag = b_ret_flag && single_cost_provider.bIsOfSize(i_provider_number);
	b_ret_flag = b_ret_flag && single_cost_factory.bIsOfSize(i_factory_number);
	b_ret_flag = b_ret_flag && single_cost_warehouse.bIsOfSize(i_warehouse_number);
	b_ret_flag = b_ret_flag && profit_per_shop.bIsOfSize(i_shop_number);
	b_ret_flag = b_ret_flag && prod_power_provider.bIsOfSize(i_provider_number);
	b_ret_flag = b_ret_flag && prod_power_factory.bIsOfSize(i_factory_number);
	b_ret_flag = b_ret_flag && prod_power_warehouse.bIsOfSize(i_warehouse_number);
	b_ret_flag = b_ret_flag && prod_demand_shop.bIsOfSize(i_shop_number);
	b_ret_flag = b_ret_flag && resource_amount_provider_factory.bIsOfSize(i_provider_number, i_factory_number);
	b_ret_flag = b_ret_flag && resource_amount_factory_warehouse.bIsOfSize(i_factory_number, i_warehouse_number);
	b_ret_flag = b_ret_flag && resource_amount_warehouse_shop.bIsOfSize(i_warehouse_number, i_shop_number);
	b_ret_flag = b_ret_flag && resource_amount_provider_factory_min.bIsOfSize(i_provider_number, i_factory_number);
	b_ret_flag = b_ret_flag && resource_amount_provider_factory_max.bIsOfSize(i_provider_number, i_factory_number);
	b_ret_flag = b_ret_flag && resource_amount_factory_warehouse_min.bIsOfSize(i_factory_number, i_warehouse_number);
	b_ret_flag = b_ret_flag && resource_amount_factory_warehouse_max.bIsOfSize(i_factory_number, i_warehouse_number);
	b_ret_flag = b_ret_flag && resource_amount_warehouse_shop_min.bIsOfSize(i_warehouse_number, i_shop_number);
	b_ret_flag = b_ret_flag && resource_amount_warehouse_shop_max.bIsOfSize(i_warehouse_number, i_shop_number);

	return b_ret_flag;
}

bool CMscnProblem::bCheckDataValues()
{
	bool b_ret_flag = true;

	b_ret_flag = b_ret_flag && !prod_cost_provider_factory.bContainsNegativeValues();
	b_ret_flag = b_ret_flag && !prod_cost_factory_warehouse.bContainsNegativeValues();
	b_ret_flag = b_ret_flag && !prod_cost_warehouse_shop.bContainsNegativeValues();
	b_ret_flag = b_ret_flag && !single_cost_provider.bContainsNegativeValues();
	b_ret_flag = b_ret_flag && !single_cost_factory.bContainsNegativeValues();
	b_ret_flag = b_ret_flag && !single_cost_warehouse.bContainsNegativeValues();
	b_ret_flag = b_ret_flag && !profit_per_shop.bContainsNegativeValues();
	b_ret_flag = b_ret_flag && !prod_power_provider.bContainsNegativeValues();
	b_ret_flag = b_ret_flag && !prod_power_factory.bContainsNegativeValues();
	b_ret_flag = b_ret_flag && !prod_power_warehouse.bContainsNegativeValues();
	b_ret_flag = b_ret_flag && !prod_demand_shop.bContainsNegativeValues();
	b_ret_flag = b_ret_flag && !resource_amount_provider_factory_min.bContainsNegativeValues();
	b_ret_flag = b_ret_flag && !resource_amount_provider_factory_max.bContainsNegativeValues();
	b_ret_flag = b_ret_flag && !resource_amount_factory_warehouse_min.bContainsNegativeValues();
	b_ret_flag = b_ret_flag && !resource_amount_factory_warehouse_max.bContainsNegativeValues();
	b_ret_flag = b_ret_flag && !resource_amount_warehouse_shop_min.bContainsNegativeValues();
	b_ret_flag = b_ret_flag && !resource_amount_warehouse_shop_max.bContainsNegativeValues();

	return b_ret_flag;
}

bool CMscnProblem::bCheckSolutionConstraints()
{
	for (int iip = 0; iip < i_provider_number; iip++)
	{
		double d_sum = 0;
		for (int iif = 0; iif < i_factory_number; iif++)
		{
			d_sum += resource_amount_provider_factory.getValueAt(iip, iif);
		}

		if (d_sum > prod_power_provider.getValueAt(iip))
		{
			return false;
		}
	}

	for (int iif = 0; iif < i_factory_number; iif++)
	{
		double d_sum = 0;
		for (int iiw = 0; iiw < i_warehouse_number; iiw++)
		{
			d_sum += resource_amount_factory_warehouse.getValueAt(iif, iiw);
		}

		if (d_sum > prod_power_factory.getValueAt(iif))
		{
			return false;
		}
	}

	for (int iiw = 0; iiw < i_warehouse_number; iiw++)
	{
		double d_sum = 0;
		for (int iis = 0; iis < i_shop_number; iis++)
		{
			d_sum += resource_amount_warehouse_shop.getValueAt(iiw, iis);
		}

		if (d_sum > prod_power_warehouse.getValueAt(iiw))
		{
			return false;
		}
	}

	for (int iis = 0; iis < i_shop_number; iis++)
	{
		double d_sum = 0;
		for (int iiw = 0; iiw < i_warehouse_number; iiw++)
		{
			d_sum += resource_amount_warehouse_shop.getValueAt(iiw, iis);
		}

		if (d_sum > prod_demand_shop.getValueAt(iis))
		{
			return false;
		}
	}

	for (int iif = 0; iif < i_factory_number; iif++)
	{
		double d_sum_left = 0;
		double d_sum_right = 0;

		for (int iip = 0; iip < i_provider_number; iip++)
		{
			d_sum_left += resource_amount_provider_factory.getValueAt(iip, iif);
		}

		for (int iiw = 0; iiw < i_warehouse_number; iiw++)
		{
			d_sum_right += resource_amount_factory_warehouse.getValueAt(iif, iiw);
		}

		if (d_sum_left < d_sum_right)
		{
			return false;
		}
	}

	for (int iiw = 0; iiw < i_warehouse_number; iiw++)
	{
		double d_sum_left = 0;
		double d_sum_right = 0;

		for (int iif = 0; iif < i_factory_number; iif++)
		{
			d_sum_left += resource_amount_factory_warehouse.getValueAt(iif, iiw);
		}

		for (int iis = 0; iis < i_shop_number; iis++)
		{
			d_sum_left += resource_amount_warehouse_shop.getValueAt(iiw, iis);
		}

		if (d_sum_left < d_sum_right)
		{
			return false;
		}
	}

	return true;
}

bool CMscnProblem::bCheckSolutionLegalValues()
{
	bool b_ret_flag = true;

	b_ret_flag = b_ret_flag && !resource_amount_provider_factory.bContainsNegativeValues();
	b_ret_flag = b_ret_flag && !resource_amount_factory_warehouse.bContainsNegativeValues();
	b_ret_flag = b_ret_flag && !resource_amount_warehouse_shop.bContainsNegativeValues();

	return b_ret_flag;
}

bool CMscnProblem::bLoadSolutionFromVector(vector<double> &vdSolution, int* iErrFlag)
{
	if (vdSolution.size() != iGetSolutionSize())
	{
		*iErrFlag = E_INDEX_OUT_OF_BOUNDS;
		return false;
	}
	
	bool b_ret_flag = true;
	int i_offset = 0;

	for (int iip = 0; iip < i_provider_number; iip++)
	{
		for (int iif = 0; iif < i_factory_number; iif++)
		{
			b_ret_flag = b_ret_flag && resource_amount_provider_factory.bSetValueAt(iip, iif, vdSolution[i_offset]);
			i_offset++;
		}
	}

	for (int iif = 0; iif < i_factory_number; iif++)
	{
		for (int iiw = 0; iiw < i_warehouse_number; iiw++)
		{
			b_ret_flag = b_ret_flag && resource_amount_factory_warehouse.bSetValueAt(iif, iiw, vdSolution[i_offset]);
			i_offset++;
		}
	}

	for (int iiw = 0; iiw < i_warehouse_number; iiw++)
	{
		for (int iis = 0; iis < i_shop_number; iis++)
		{
			b_ret_flag = b_ret_flag && resource_amount_warehouse_shop.bSetValueAt(iiw, iis, vdSolution[i_offset]);
			i_offset++;
		}
	}

	if (!b_ret_flag)
	{
		*iErrFlag = E_INCORRECT_DATA_FORMAT;
		return false;
	}

	*iErrFlag = E_NO_ERROR;
	return true;
}

void CMscnProblem::vTest()
{
	cout << "CD" << endl;
	prod_cost_provider_factory.vPrintMatrix();
	cout << "CF" << endl;
	prod_cost_factory_warehouse.vPrintMatrix();
	cout << "CM" << endl;
	prod_cost_warehouse_shop.vPrintMatrix();

	cout << "UD" << endl;
	single_cost_provider.vPrintTable();
	cout << "UF" << endl;
	single_cost_factory.vPrintTable();
	cout << "UM" << endl;
	single_cost_warehouse.vPrintTable();
	cout << "P" << endl;
	profit_per_shop.vPrintTable();

	cout << "SD" << endl;
	prod_power_provider.vPrintTable();
	cout << "SF" << endl;
	prod_power_factory.vPrintTable();
	cout << "SM" << endl;
	prod_power_warehouse.vPrintTable();
	cout << "SS" << endl;
	prod_demand_shop.vPrintTable();

	//resource_amount_provider_factory.vPrintMatrix();
	//resource_amount_factory_warehouse.vPrintMatrix();
	//resource_amount_warehouse_shop.vPrintMatrix();

	//resource_amount_provider_factory_min.vPrintMatrix();
	//resource_amount_provider_factory_max.vPrintMatrix();
	//resource_amount_factory_warehouse_min.vPrintMatrix();
	//resource_amount_factory_warehouse_max.vPrintMatrix();
	//resource_amount_warehouse_shop_min.vPrintMatrix();
	//resource_amount_warehouse_shop_max.vPrintMatrix();
}

bool CMscnProblem::bSaveSolutionToFile(string sFileName, int* iErrFlag)
{
	if (!bCheckDataFormat())
	{
		*iErrFlag = E_INCORRECT_DATA_FORMAT;
		return NULL;
	}
	if (!bCheckDataValues())
	{
		*iErrFlag = E_NEGATIVE_DATA_VALUES;
		return NULL;
	}

	FILE *pf_file = NULL;
	pf_file = fopen(sFileName.c_str(), "w");

	if (pf_file == NULL)
	{
		*iErrFlag = E_FILE_OUTPUT;
		return NULL;
	}

	string s_text = "D " + to_string(i_provider_number) + "\n\n";
	fprintf(pf_file, s_text.c_str());
	s_text = "F " + to_string(i_factory_number) + "\n\n";
	fprintf(pf_file, s_text.c_str());
	s_text = "M " + to_string(i_warehouse_number) + "\n\n";
	fprintf(pf_file, s_text.c_str());
	s_text = "S " + to_string(i_shop_number) + "\n\n";
	fprintf(pf_file, s_text.c_str());

	s_text = "xd\n\n" + resource_amount_provider_factory.sToString() + "\n";
	fprintf(pf_file, s_text.c_str());
	s_text = "xf\n\n" + resource_amount_provider_factory.sToString() + "\n";
	fprintf(pf_file, s_text.c_str());
	s_text = "xm\n\n" + resource_amount_provider_factory.sToString() + "\n";
	fprintf(pf_file, s_text.c_str());

	fclose(pf_file);

	*iErrFlag = E_NO_ERROR;
	return true;
}

bool CMscnProblem::bSaveProblemToFile(string sFileName, int* iErrFlag)
{
	if (!bCheckDataFormat())
	{
		*iErrFlag = E_INCORRECT_DATA_FORMAT;
		return false;
	}
	if (!bCheckDataValues())
	{
		*iErrFlag = E_NEGATIVE_DATA_VALUES;
		return false;
	}

	FILE *pf_file = NULL;
	pf_file = fopen(sFileName.c_str(), "w");

	if (pf_file == NULL)
	{
		*iErrFlag = E_FILE_OUTPUT;
		return false;
	}

	string s_text = "D " + to_string(i_provider_number) + "\n\n";
	fprintf(pf_file, s_text.c_str());
	s_text = "F " + to_string(i_factory_number) + "\n\n";
	fprintf(pf_file, s_text.c_str());
	s_text = "M " + to_string(i_warehouse_number) + "\n\n";
	fprintf(pf_file, s_text.c_str());
	s_text = "S " + to_string(i_shop_number) + "\n\n";
	fprintf(pf_file, s_text.c_str());

	s_text = "sd\n\n" + prod_power_provider.sToString() + "\n";
	fprintf(pf_file, s_text.c_str());
	s_text = "sm\n\n" + prod_power_factory.sToString() + "\n";
	fprintf(pf_file, s_text.c_str());
	s_text = "sf\n\n" + prod_power_warehouse.sToString() + "\n";
	fprintf(pf_file, s_text.c_str());
	s_text = "ss\n\n" + prod_demand_shop.sToString() + "\n";
	fprintf(pf_file, s_text.c_str());
	s_text = "cd\n\n" + prod_cost_provider_factory.sToString() + "\n";
	fprintf(pf_file, s_text.c_str());
	s_text = "cf\n\n" + prod_cost_factory_warehouse.sToString() + "\n";
	fprintf(pf_file, s_text.c_str());
	s_text = "cm\n\n" + prod_cost_warehouse_shop.sToString() + "\n";
	fprintf(pf_file, s_text.c_str());
	s_text = "ud\n\n" + single_cost_provider.sToString() + "\n";
	fprintf(pf_file, s_text.c_str());
	s_text = "uf\n\n" + single_cost_factory.sToString() + "\n";
	fprintf(pf_file, s_text.c_str());
	s_text = "um\n\n" + single_cost_warehouse.sToString() + "\n";
	fprintf(pf_file, s_text.c_str());
	s_text = "p\n\n" + profit_per_shop.sToString() + "\n";
	fprintf(pf_file, s_text.c_str());
	s_text = "xdmin\n\n" + resource_amount_provider_factory_min.sToString() + "\n";
	fprintf(pf_file, s_text.c_str());
	s_text = "xdmax\n\n" + resource_amount_provider_factory_max.sToString() + "\n";
	fprintf(pf_file, s_text.c_str());
	s_text = "xfmin\n\n" + resource_amount_factory_warehouse_min.sToString() + "\n";
	fprintf(pf_file, s_text.c_str());
	s_text = "xfmax\n\n" + resource_amount_factory_warehouse_max.sToString() + "\n";
	fprintf(pf_file, s_text.c_str());
	s_text = "xmmin\n\n" + resource_amount_warehouse_shop_min.sToString() + "\n";
	fprintf(pf_file, s_text.c_str());
	s_text = "xmmax\n\n" + resource_amount_warehouse_shop_max.sToString() + "\n";
	fprintf(pf_file, s_text.c_str());

	fclose(pf_file);

	*iErrFlag = E_NO_ERROR;
	return true;
}

bool CMscnProblem::bLoadSolutionFromFile(string sFileName, int* iErrFlag)
{
	FILE *pf_file = NULL;
	pf_file = fopen(sFileName.c_str(), "r");

	if (pf_file == NULL)
	{
		*iErrFlag = E_FILE_INPUT;
		return false;
	}
	
	
	bool b_ret_flag = true;
	
	int i_val;
	double d_val;
	char s_markup[10];

	fscanf(pf_file, "%s", s_markup);
	fscanf(pf_file, "%i", &i_val);
	b_ret_flag = b_ret_flag && bSetProviderNumber(i_val);

	fscanf(pf_file, "%s", s_markup);
	fscanf(pf_file, "%i", &i_val);
	b_ret_flag = b_ret_flag && bSetFactoryNumber(i_val);

	fscanf(pf_file, "%s", s_markup);
	fscanf(pf_file, "%i", &i_val);
	b_ret_flag = b_ret_flag && bSetWarehouseNumber(i_val);

	fscanf(pf_file, "%s", s_markup);
	fscanf(pf_file, "%i", &i_val);
	b_ret_flag = b_ret_flag && bSetShopNumber(i_val);

	fscanf(pf_file, "%s", s_markup);
	for (int iip = 0; iip < i_provider_number; iip++)
	{
		for (int iif = 0; iif < i_factory_number; iif++)
		{
			fscanf(pf_file, "%lf", &d_val);
			b_ret_flag = b_ret_flag && bSetXdValueAt(iip, iif, d_val);
		}
	}

	fscanf(pf_file, "%s", s_markup);
	for (int iif = 0; iif < i_factory_number; iif++)
	{
		for (int iiw = 0; iiw < i_warehouse_number; iiw++)
		{
			fscanf(pf_file, "%lf", &d_val);
			b_ret_flag = b_ret_flag && bSetXfValueAt(iif, iiw, d_val);
		}
	}

	fscanf(pf_file, "%s", s_markup);
	for (int iiw = 0; iiw < i_warehouse_number; iiw++)
	{
		for (int iis = 0; iis < i_shop_number; iis++)
		{
			fscanf(pf_file, "%lf", &d_val);
			b_ret_flag = b_ret_flag && bSetXmValueAt(iiw, iis, d_val);
		}
	}

	fclose(pf_file);

	if (!b_ret_flag)
	{
		*iErrFlag = E_FILE_INPUT;
		return false;
	}

	*iErrFlag = E_NO_ERROR;
	return true;
}

bool CMscnProblem::bLoadProblemFromFile(string sFileName, int* iErrFlag)
{
	FILE *pf_file = NULL;
	pf_file = fopen(sFileName.c_str(), "r");

	if (pf_file == NULL)
	{
		*iErrFlag = E_FILE_INPUT;
		return false;
	}


	bool b_ret_flag = true;

	int i_val;
	double d_val;
	char s_markup[10];

	fscanf(pf_file, "%s", s_markup);
	fscanf(pf_file, "%i", &i_val);
	b_ret_flag = b_ret_flag && bSetProviderNumber(i_val);

	fscanf(pf_file, "%s", s_markup);
	fscanf(pf_file, "%i", &i_val);
	b_ret_flag = b_ret_flag && bSetFactoryNumber(i_val);

	fscanf(pf_file, "%s", s_markup);
	fscanf(pf_file, "%i", &i_val);
	b_ret_flag = b_ret_flag && bSetWarehouseNumber(i_val);

	fscanf(pf_file, "%s", s_markup);
	fscanf(pf_file, "%i", &i_val);
	b_ret_flag = b_ret_flag && bSetShopNumber(i_val);

	
	fscanf(pf_file, "%s", s_markup);
	for (int iip = 0; iip < i_provider_number; iip++)
	{
		fscanf(pf_file, "%lf", &d_val);
		b_ret_flag = b_ret_flag && bSetSdValueAt(iip, d_val);
	}

	fscanf(pf_file, "%s", s_markup);
	for (int iif = 0; iif < i_factory_number; iif++)
	{
		fscanf(pf_file, "%lf", &d_val);
		b_ret_flag = b_ret_flag && bSetSfValueAt(iif, d_val);
	}

	fscanf(pf_file, "%s", s_markup);
	for (int iiw = 0; iiw < i_warehouse_number; iiw++)
	{
		fscanf(pf_file, "%lf", &d_val);
		b_ret_flag = b_ret_flag && bSetSmValueAt(iiw, d_val);
	}

	fscanf(pf_file, "%s", s_markup);
	for (int iis = 0; iis < i_shop_number; iis++)
	{
		fscanf(pf_file, "%lf", &d_val);
		b_ret_flag = b_ret_flag && bSetSsValueAt(iis, d_val);
	}

	fscanf(pf_file, "%s", s_markup);
	for (int iip = 0; iip < i_provider_number; iip++)
	{
		for (int iif = 0; iif < i_factory_number; iif++)
		{
			fscanf(pf_file, "%lf", &d_val);
			b_ret_flag = b_ret_flag && bSetCdValueAt(iip, iif, d_val);
		}
	}

	fscanf(pf_file, "%s", s_markup);
	for (int iif = 0; iif < i_factory_number; iif++)
	{
		for (int iiw = 0; iiw < i_warehouse_number; iiw++)
		{
			fscanf(pf_file, "%lf", &d_val);
			b_ret_flag = b_ret_flag && bSetCfValueAt(iif, iiw, d_val);
		}
	}

	fscanf(pf_file, "%s", s_markup);
	for (int iiw = 0; iiw < i_warehouse_number; iiw++)
	{
		for (int iis = 0; iis < i_shop_number; iis++)
		{
			fscanf(pf_file, "%lf", &d_val);
			b_ret_flag = b_ret_flag && bSetCmValueAt(iiw, iis, d_val);
		}
	}

	fscanf(pf_file, "%s", s_markup);
	for (int iip = 0; iip < i_provider_number; iip++)
	{
		fscanf(pf_file, "%lf", &d_val);
		b_ret_flag = b_ret_flag && bSetUdValueAt(iip, d_val);
	}

	fscanf(pf_file, "%s", s_markup);
	for (int iif = 0; iif < i_factory_number; iif++)
	{
		fscanf(pf_file, "%lf", &d_val);
		b_ret_flag = b_ret_flag && bSetUfValueAt(iif, d_val);
	}

	fscanf(pf_file, "%s", s_markup);
	for (int iiw = 0; iiw < i_warehouse_number; iiw++)
	{
		fscanf(pf_file, "%lf", &d_val);
		b_ret_flag = b_ret_flag && bSetUmValueAt(iiw, d_val);
	}

	fscanf(pf_file, "%s", s_markup);
	for (int iis = 0; iis < i_shop_number; iis++)
	{
		fscanf(pf_file, "%lf", &d_val);
		b_ret_flag = b_ret_flag && bSetPValueAt(iis, d_val);
	}

	fscanf(pf_file, "%s", s_markup);
	for (int iip = 0; iip < i_provider_number; iip++)
	{
		for (int iif = 0; iif < i_factory_number; iif++)
		{
			fscanf(pf_file, "%lf", &d_val);
			b_ret_flag = b_ret_flag && bSetXdMinValueAt(iip, iif, d_val);
		}
	}

	fscanf(pf_file, "%s", s_markup);
	for (int iip = 0; iip < i_provider_number; iip++)
	{
		for (int iif = 0; iif < i_factory_number; iif++)
		{
			fscanf(pf_file, "%lf", &d_val);
			b_ret_flag = b_ret_flag && bSetXdMaxValueAt(iip, iif, d_val);
		}
	}

	fscanf(pf_file, "%s", s_markup);
	for (int iif = 0; iif < i_factory_number; iif++)
	{
		for (int iiw = 0; iiw < i_warehouse_number; iiw++)
		{
			fscanf(pf_file, "%lf", &d_val);
			b_ret_flag = b_ret_flag && bSetXmMinValueAt(iif, iiw, d_val);
		}
	}

	fscanf(pf_file, "%s", s_markup);
	for (int iif = 0; iif < i_factory_number; iif++)
	{
		for (int iiw = 0; iiw < i_warehouse_number; iiw++)
		{
			fscanf(pf_file, "%lf", &d_val);
			b_ret_flag = b_ret_flag && bSetXmMaxValueAt(iif, iiw, d_val);
		}
	}

	fscanf(pf_file, "%s", s_markup);
	for (int iiw = 0; iiw < i_warehouse_number; iiw++)
	{
		for (int iis = 0; iis < i_shop_number; iis++)
		{
			fscanf(pf_file, "%lf", &d_val);
			b_ret_flag = b_ret_flag && bSetXfMinValueAt(iiw, iis, d_val);
		}
	}

	fscanf(pf_file, "%s", s_markup);
	for (int iiw = 0; iiw < i_warehouse_number; iiw++)
	{
		for (int iis = 0; iis < i_shop_number; iis++)
		{
			fscanf(pf_file, "%lf", &d_val);
			b_ret_flag = b_ret_flag && bSetXfMaxValueAt(iiw, iis, d_val);
		}
	}

	//MODYFIKACJA LAB 9
	/*
	cout << "MODYFIKACJA:" << endl;

	for (int ii = 0; ii < 6; ii++)
	{
		fscanf(pf_file, "%s", s_markup);
		fscanf(pf_file, "%lf", &d_val);
		cout << s_markup << " " << d_val << endl;
	}
	*/
	//

	fclose(pf_file);

	if (!b_ret_flag)
	{
		*iErrFlag = E_FILE_INPUT;
		return false;
	}

	*iErrFlag = E_NO_ERROR;
	return true;
}


//LAB 10

bool CMscnProblem::bGenerateInstance(int iInstanceSeed)
{
	if (i_provider_number == 0 || i_factory_number == 0 || i_shop_number == 0 || i_warehouse_number == 0)
	{
		return false;
	}

	CRandomV2 c_rng(iInstanceSeed);
	bool b_ret_value = true;

	//C-type values
	//

	for (int iip = 0; iip < i_provider_number; iip++)
	{
		for (int iif = 0; iif < i_factory_number; iif++)
		{
			b_ret_value = b_ret_value && bSetCdValueAt(iip, iif, c_rng.dGetNextDouble(D_CD_MIN, D_CD_MAX));
		}
	}


	for (int iif = 0; iif < i_factory_number; iif++)
	{
		for (int iiw = 0; iiw < i_warehouse_number; iiw++)
		{
			b_ret_value = b_ret_value && bSetCfValueAt(iif, iiw, c_rng.dGetNextDouble(D_CF_MIN, D_CF_MAX));
		}
	}

	for (int iiw = 0; iiw < i_warehouse_number; iiw++)
	{
		for (int iis = 0; iis < i_shop_number; iis++)
		{
			b_ret_value = b_ret_value && bSetCmValueAt(iiw, iis, c_rng.dGetNextDouble(D_CM_MIN, D_CM_MAX));
		}
	}

	//U-type values
	//

	for (int iip = 0; iip < i_provider_number; iip++)
	{
		b_ret_value = b_ret_value && bSetUdValueAt(iip, c_rng.dGetNextDouble(D_UD_MIN, D_UD_MAX));
	}

	for (int iif = 0; iif < i_factory_number; iif++)
	{
		b_ret_value = b_ret_value && bSetUfValueAt(iif, c_rng.dGetNextDouble(D_UF_MIN, D_UF_MAX));
	}

	for (int iiw = 0; iiw < i_warehouse_number; iiw++)
	{
		b_ret_value = b_ret_value && bSetUmValueAt(iiw, c_rng.dGetNextDouble(D_UM_MIN, D_UM_MAX));
	}
	
	//P-type values
	//

	for (int iis = 0; iis < i_shop_number; iis++)
	{
		b_ret_value = b_ret_value && bSetPValueAt(iis, c_rng.dGetNextDouble(D_P_MIN, D_P_MAX));
	}
	
	//S-type values
	//

	for (int iip = 0; iip < i_provider_number; iip++)
	{
		b_ret_value = b_ret_value && bSetSdValueAt(iip, c_rng.dGetNextDouble(D_SD_MIN, D_SD_MAX));
	}

	for (int iif = 0; iif < i_factory_number; iif++)
	{
		b_ret_value = b_ret_value && bSetSfValueAt(iif, c_rng.dGetNextDouble(D_SF_MIN, D_SF_MAX));
	}

	for (int iiw = 0; iiw < i_warehouse_number; iiw++)
	{
		b_ret_value = b_ret_value && bSetSmValueAt(iiw, c_rng.dGetNextDouble(D_SM_MIN, D_SM_MAX));
	}

	for (int iis = 0; iis < i_shop_number; iis++)
	{
		b_ret_value = b_ret_value && bSetSsValueAt(iis, c_rng.dGetNextDouble(D_SS_MIN, D_SS_MAX));
	}
	
	//Default solution sonstraints values
	//

	for (int iip = 0; iip < i_provider_number; iip++)
	{
		for (int iif = 0; iif < i_factory_number; iif++)
		{
			b_ret_value = b_ret_value && bSetXdMinValueAt(iip, iif, D_DEFAULT_XMIN);
			b_ret_value = b_ret_value && bSetXdMaxValueAt(iip, iif, D_DEFAULT_XMAX);
		}
	}
	
	for (int iif = 0; iif < i_factory_number; iif++)
	{
		for (int iiw = 0; iiw < i_warehouse_number; iiw++)
		{
			b_ret_value = b_ret_value && bSetXfMinValueAt(iif, iiw, D_DEFAULT_XMIN);
			b_ret_value = b_ret_value && bSetXfMaxValueAt(iif, iiw, D_DEFAULT_XMAX);
		}
	}

	for (int iiw = 0; iiw < i_warehouse_number; iiw++)
	{
		for (int iis = 0; iis < i_shop_number; iis++)
		{
			b_ret_value = b_ret_value && bSetXmMinValueAt(iiw, iis, D_DEFAULT_XMIN);
			b_ret_value = b_ret_value && bSetXmMaxValueAt(iiw, iis, D_DEFAULT_XMAX);
		}
	}

	return b_ret_value;
}
