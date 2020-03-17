#pragma once
#include "CRandomSearch.h"

using namespace std;

#define I_POPULATION_SIZE 75
#define I_RAND_SEARCH_ITERATIONS 1500
#define D_CROSS_PROB 0.1
#define D_DIFF_WEIGHT 0.2

class CDiffEvol
{
private:
	CMscnProblem* c_problem_instance;
	vector<vector<double>> vvd_population;

public:
	CDiffEvol(CMscnProblem* cProblemInstance);
	~CDiffEvol();

	int iInitiatePopulation(int iSeed);
	vector<double> vdDiffEvolSearch(int iSeed, int iEvalCount, int* i_err_flag);
	vector<double> vdFindBestIndividual(vector<vector<double>> vvd_population);
};

