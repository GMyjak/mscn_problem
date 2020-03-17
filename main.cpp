#include "pch.h"
#include <iostream>
#include "CRandomSearch.h"
#include "CRandomV2.h"
#include "CDiffEvol.h"
#include "CIndividual.h"

using namespace std;

/*
void vTest1()
{
	CMscnProblem problem;
	problem.bSetProviderNumber(1);
	problem.bSetFactoryNumber(1);
	problem.bSetWarehouseNumber(1);
	problem.bSetShopNumber(1);

	problem.bSetSdValueAt(0, 100.);
	problem.bSetSfValueAt(0, 50.);
	problem.bSetSmValueAt(0, 10.5);
	problem.bSetSsValueAt(0, 100.);

	problem.bSetCdValueAt(0, 0, 3.);
	problem.bSetCfValueAt(0, 0, 4.);
	problem.bSetCmValueAt(0, 0, 1.);

	problem.bSetUdValueAt(0, 10.);
	problem.bSetUfValueAt(0, 10.);
	problem.bSetUmValueAt(0, 10.);
	problem.bSetPValueAt(0, 100.);

	problem.bSetXdMinValueAt(0, 0, 0.);
	problem.bSetXdMaxValueAt(0, 0, 100.);
	problem.bSetXfMinValueAt(0, 0, 0.);
	problem.bSetXfMaxValueAt(0, 0, 100.);
	problem.bSetXmMinValueAt(0, 0, 0.);
	problem.bSetXmMaxValueAt(0, 0, 100.);

	vector<double> solution;
	solution.push_back(1.);
	solution.push_back(1.);
	solution.push_back(1.);

	int* errflag = new int;

	cout << problem.dGetQuality(solution, errflag) << endl;
	cout << *errflag << endl;

	//Nazwy zmienione!
	problem.bSaveSolutionToFile("hehe.txt", errflag);
	problem.bSaveProblemToFile("problem.txt", errflag);
	//problem.bLoadSolutionFromFile("hehe.txt", errflag);	//Nie niszczy danych problemu :)
	problem.vTest();

	delete errflag;
}

void vTest2()
{
	CMscnProblem problem;
	int* errflag = new int;

	//Nazwy zmienione!
	problem.bLoadSolutionFromFile("hehe.txt", errflag);
	problem.bLoadProblemFromFile("problem.txt", errflag);

	problem.vTest();

	delete errflag;
}

void vTest3()
{
	CMscnProblem problem;
	int* errflag = new int;

	//Nazwy zmienione!
	problem.bLoadProblemFromFile("test_2.txt", errflag);
	//cout << *errflag << endl;

	//problem.vTest();
	delete errflag;
}

//TEST LAB 10
//Test metody generate instance
void vTest4()
{
	CMscnProblem problem;
	problem.bSetProviderNumber(3);
	problem.bSetFactoryNumber(3);
	problem.bSetWarehouseNumber(3);
	problem.bSetShopNumber(4);
	CRandomV2 rng(32671);
	int* flag = new int;

	for (int i = 0; i < 10; i++)
	{
		problem.bGenerateInstance(rng.iGetNextInt(0, 100000));
		problem.bSaveProblemToFile("test4-" + to_string(i) + ".txt", flag);
	}
}

void vTest5(int iSeed)
{
	CMscnProblem problem;
	problem.bSetProviderNumber(3);
	problem.bSetFactoryNumber(3);
	problem.bSetWarehouseNumber(3);
	problem.bSetShopNumber(4);
	problem.bGenerateInstance(2137);//15672
	int* i_err_flag = new int;
	*i_err_flag = 0;
	
	CRandomSearch c_rand_search(&problem, iSeed);

	vector<double> vec = c_rand_search.vdRandomSearch(20000, i_err_flag);
	cout << "Best solution: " << problem.dGetQuality(vec, i_err_flag) << endl;
}*/

void vTest6(int iSeed)
{
	CMscnProblem problem;
	problem.bSetProviderNumber(3);
	problem.bSetFactoryNumber(3);
	problem.bSetWarehouseNumber(3);
	problem.bSetShopNumber(4);
	problem.bGenerateInstance(2137);

	int* i_err_flag = new int;
	*i_err_flag = 0;

	CDiffEvol cdiffevol(&problem);
	cdiffevol.iInitiatePopulation(420);
	cdiffevol.vdDiffEvolSearch(1341, 20000, i_err_flag);
}

void vTest7(int iSeed)
{
	CMscnProblem problem;
	problem.bSetProviderNumber(3);
	problem.bSetFactoryNumber(3);
	problem.bSetWarehouseNumber(3);
	problem.bSetShopNumber(4);
	problem.bGenerateInstance(2137);

	int* i_err_flag = new int;
	*i_err_flag = 0;

	CRandomSearch crand(&problem, 8643);

	vector<double> vec = crand.vdRandomSearch(20000, i_err_flag);
	cout << "Best solution: " << problem.dGetQuality(vec, i_err_flag) << endl;
}

int main()
{
	CMscnProblem cpr;

	vector<double> v1(3);
	vector<double> v2(3);

	v1[0] = 0.5;
	v1[1] = 1.0;
	v1[2] = 0.75;
	v2[0] = 1.0;
	v2[1] = 0.25;
	v2[2] = 0.8;

	CIndividual c1(v1, &cpr);
	CIndividual c2(v2, &cpr);

	CIndividual c3 = c1 - c2;
	c3.vDisplayGenotype();

	//vTest6(865);
	//vTest7(865);

	// 2 testy
	// takie same dane wejœciowe
	// taki sam seed
	// DiffEvol: 703.366
	// RandSearch: 152.917
}
