#include "CDiffEvol.h"

using namespace std;

class CIndividual
{
private:
	vector<double> vd_genotype;
	CMscnProblem* pc_problem_instance;

public:
	CIndividual(const vector<double>& vdGenotype, CMscnProblem* pcProblemInstance);
	~CIndividual();

	void vCorrectGenotype();
	void vDisplayGenotype();

	CIndividual operator-(CIndividual &pOther);
};

