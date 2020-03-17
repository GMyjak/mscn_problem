#pragma once
#include "CMscnProblem.h"

#define E_SOLUTION_NOT_FOUND 1

class CRandomSearch
{
private:
	CMscnProblem* pc_problem_instance;
	CRandomV2 c_rng;

public:
	CRandomSearch(CMscnProblem *pcProblemInstance, int iSeed);
	~CRandomSearch();

	vector<double> vdGenerateSolution();
	vector<double> vdRandomSearch(int iNumberOfIterations, int* iErrFlag);

	int iGetSeed();
	void vSetSeed(int iSeed);
};

