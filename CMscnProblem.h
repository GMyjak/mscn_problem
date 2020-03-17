#include "CMatrix.h"
#include "CTable.h"
#include "CRandomV2.h"
#include <vector>
#include <stdio.h>
#include <string>

#define E_NO_ERROR 0
#define E_INCORRECT_DATA_FORMAT 1
#define E_NEGATIVE_DATA_VALUES 2
#define E_NEGATIVE_SOLUTION_VALUES 3
#define E_FILE_INPUT 4
#define E_FILE_OUTPUT 5
#define E_INDEX_OUT_OF_BOUNDS 6

//Random constraints
//Production costs
#define D_CD_MIN 3.0
#define D_CD_MAX 15.0
#define D_CF_MIN 3.0
#define D_CF_MAX 15.0
#define D_CM_MIN 3.0
#define D_CM_MAX 15.0

#define D_P_MIN 20.0
#define D_P_MAX 100.0

//One time charges
#define D_UD_MIN 30.0
#define D_UD_MAX 120.0
#define D_UF_MIN 30.0
#define D_UF_MAX 120.0
#define D_UM_MIN 30.0
#define D_UM_MAX 120.0

//Production powers
#define D_SD_MIN 3.0
#define D_SD_MAX 30.0
#define D_SF_MIN 3.0
#define D_SF_MAX 30.0
#define D_SM_MIN 3.0
#define D_SM_MAX 30.0
#define D_SS_MIN 3.0
#define D_SS_MAX 30.0

//Default solution constraints
#define D_DEFAULT_XMIN 0.0
#define D_DEFAULT_XMAX 2.5

using namespace std;

class CMscnProblem
{
private:
	//DATA
	int i_provider_number;								//D
	int i_factory_number;								//F
	int i_warehouse_number;								//M
	int i_shop_number;									//S

	CMatrix<double> prod_cost_provider_factory;			//cd
	CMatrix<double> prod_cost_factory_warehouse;		//cf
	CMatrix<double> prod_cost_warehouse_shop;			//cm

	CTable<double> single_cost_provider;				//ud
	CTable<double> single_cost_factory;					//uf
	CTable<double> single_cost_warehouse;				//um
	CTable<double> profit_per_shop;						//p

	CTable<double> prod_power_provider;					//sd
	CTable<double> prod_power_factory;					//sf
	CTable<double> prod_power_warehouse;				//sm
	CTable<double> prod_demand_shop;					//ss

	//SOLUTION
	CMatrix<double> resource_amount_provider_factory;	//xd
	CMatrix<double> resource_amount_factory_warehouse;	//xf
	CMatrix<double> resource_amount_warehouse_shop;		//xm

	//SOLUTION CONSTRAINTS
	CMatrix<double> resource_amount_provider_factory_min;	//xdmin
	CMatrix<double> resource_amount_provider_factory_max;	//xdmax
	CMatrix<double> resource_amount_factory_warehouse_min;	//xfmin
	CMatrix<double> resource_amount_factory_warehouse_max;	//xfmax
	CMatrix<double> resource_amount_warehouse_shop_min;		//xmmin
	CMatrix<double> resource_amount_warehouse_shop_max;		//xmmax


public:
	CMscnProblem();
	~CMscnProblem();

	//Settery
	bool bSetProviderNumber(int iNumber);
	bool bSetFactoryNumber(int iNumber);
	bool bSetWarehouseNumber(int iNumber);
	bool bSetShopNumber(int iNumber);

	bool bSetCdValueAt(int iOffsetX, int iOffsetY, double dValue);
	bool bSetCfValueAt(int iOffsetX, int iOffsetY, double dValue);
	bool bSetCmValueAt(int iOffsetX, int iOffsetY, double dValue);

	bool bSetUdValueAt(int iOffset, double dValue);
	bool bSetUfValueAt(int iOffset, double dValue);
	bool bSetUmValueAt(int iOffset, double dValue);
	bool bSetPValueAt(int iOffset, double dValue);

	bool bSetSdValueAt(int iOffset, double dValue);
	bool bSetSfValueAt(int iOffset, double dValue);
	bool bSetSmValueAt(int iOffset, double dValue);
	bool bSetSsValueAt(int iOffset, double dValue);

	bool bSetXdMinValueAt(int iOffsetX, int iOffsetY, double dValue);
	bool bSetXdMaxValueAt(int iOffsetX, int iOffsetY, double dValue);
	bool bSetXfMinValueAt(int iOffsetX, int iOffsetY, double dValue);
	bool bSetXfMaxValueAt(int iOffsetX, int iOffsetY, double dValue);
	bool bSetXmMinValueAt(int iOffsetX, int iOffsetY, double dValue);
	bool bSetXmMaxValueAt(int iOffsetX, int iOffsetY, double dValue);

	bool bSetXdValueAt(int iOffsetX, int iOffsetY, double dValue);
	bool bSetXfValueAt(int iOffsetX, int iOffsetY, double dValue);
	bool bSetXmValueAt(int iOffsetX, int iOffsetY, double dValue);

	//Gettery
	double dGetXdMinAt(int iOffset, int* iErrFlag);
	double dGetXdMaxAt(int iOffset, int* iErrFlag);
	double dGetXfMinAt(int iOffset, int* iErrFlag);
	double dGetXfMaxAt(int iOffset, int* iErrFlag);
	double dGetXmMinAt(int iOffset, int* iErrFlag);
	double dGetXmMaxAt(int iOffset, int* iErrFlag);

	int iGetProviderNumber();
	int iGetFactoryNumber();
	int iGetWarehouseNumber();
	int iGetShopNumber();


	//Metody
	double dGetQuality(vector<double> &vdSolution, int* iErrFlag);
	bool bConstraintsSatisfied(vector<double> &vdSolution, int* iErrFlag);


	bool bLoadProblemFromFile(string sFileName, int* iErrFlag);
	bool bSaveProblemToFile(string sFileName, int* iErrFlag);

	bool bLoadSolutionFromVector(vector<double> &vdSolution, int* iErrFlag);
	bool bLoadSolutionFromFile(string sFileName, int* iErrFlag);
	bool bSaveSolutionToFile(string sFileName, int* iErrFlag);

	bool bGenerateInstance(int iInstanceSeed);

	//Metody pomocnicze
	bool bCheckDataFormat();
	bool bCheckDataValues();
	void vTest();
	int iGetSolutionSize();

private:
	bool bCheckSolutionConstraints();
	bool bCheckSolutionLegalValues();
};
