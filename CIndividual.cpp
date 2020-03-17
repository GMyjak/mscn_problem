#include "pch.h"
#include "CIndividual.h"


CIndividual::CIndividual(const vector<double>& vdGenotype, CMscnProblem* pcProblemInstance)
{
	vd_genotype = vdGenotype;
	pc_problem_instance = pcProblemInstance;
}


CIndividual::~CIndividual()
{

}

CIndividual CIndividual::operator-(CIndividual &pcOther)
{
	vector<double> vd_new_genotype(vd_genotype.size());

	for (int ii = 0; ii < vd_new_genotype.size(); ii++)
	{
		vd_new_genotype[ii] = vd_genotype[ii] - pcOther.vd_genotype[ii];
	}

	CIndividual c_new_individual(vd_new_genotype, pc_problem_instance);

	c_new_individual.vCorrectGenotype();

	return c_new_individual;
}

void CIndividual::vCorrectGenotype()
{
	for (int ii = 0; ii < vd_genotype.size(); ii++)
	{
		if (vd_genotype[ii] < D_DEFAULT_XMIN)
		{
			vd_genotype[ii] = D_DEFAULT_XMIN;
		}
		if (vd_genotype[ii] > D_DEFAULT_XMAX)
		{
			vd_genotype[ii] = D_DEFAULT_XMAX;
		}
	}
}

void CIndividual::vDisplayGenotype()
{
	cout << "[";
	for (int ii = 0; ii < vd_genotype.size(); ii++)
	{
		cout << vd_genotype[ii] << ", ";
	}
	cout << "]";
}
