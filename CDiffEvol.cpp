#include "pch.h"
#include "CDiffEvol.h"


CDiffEvol::CDiffEvol(CMscnProblem* cProblemInstance)
{
	c_problem_instance = cProblemInstance;
}


CDiffEvol::~CDiffEvol()
{
}

int CDiffEvol::iInitiatePopulation(int iSeed)
{
	CRandomSearch c_rng(c_problem_instance, iSeed);
	int* i_err_flag = new int;
	*i_err_flag = 0;

	while (I_POPULATION_SIZE > vvd_population.size())
	{
		vvd_population.push_back(c_rng.vdRandomSearch(I_RAND_SEARCH_ITERATIONS, i_err_flag));
	}

	cout << "Population instantiated" << endl;

	int i_return = *i_err_flag;
	delete i_err_flag;
	return i_return;
}

vector<double> CDiffEvol::vdDiffEvolSearch(int iSeed, int iEvalCount, int* i_err_flag)
{
	if (vvd_population.size() != I_POPULATION_SIZE)
	{
		iInitiatePopulation(0);
	}

	CRandomV2 c_rng(iSeed);
	int i_sample_size = 4;
	int* pi_index_table = new int[i_sample_size];
	int i_genotype_size = vvd_population[0].size();
	int i_evaluation_counter = 0;
	
	while (i_evaluation_counter < iEvalCount)
	{
		vector<vector<double>> vvd_new_population(I_POPULATION_SIZE);
		
		for (int ii = 0; ii < vvd_population.size(); ii++)
		{
			pi_index_table[0] = ii;
			for (int ij = 1; ij < i_sample_size; ij++)
			{
				pi_index_table[ij] = c_rng.iGetNextInt(0, vvd_population.size() - 1);
			}

			bool b_condition = true;
			for (int ij = 0; ij < i_sample_size - 1; ij++)
			{
				for (int ik = ij + 1; ik < i_sample_size; ik++)
				{
					b_condition = b_condition && (pi_index_table[ij] != pi_index_table[ik]);
				}
			}

			if (b_condition)
			{
				
				vector<double> vd_new_individual(i_genotype_size);
				
				for (int ij = 0; ij < i_genotype_size; ij++)
				{
					if (c_rng.dGetNextDouble(0, 1) < D_CROSS_PROB)
					{
						int i_gene_val = (vvd_population[pi_index_table[1]])[ij] + D_DIFF_WEIGHT * ((vvd_population[pi_index_table[2]])[ij] - (vvd_population[pi_index_table[3]])[ij]);
						vd_new_individual[ij] = i_gene_val;
					}
					else
					{
						vd_new_individual[ij] = ((vvd_population[pi_index_table[0]])[ij]);
					}
				}
				
				//Ewaluacja
				if (c_problem_instance->bConstraintsSatisfied(vd_new_individual, i_err_flag))
				{
					double d_new_ind_quality = c_problem_instance->dGetQuality(vd_new_individual, i_err_flag);
					i_evaluation_counter++;

					if (d_new_ind_quality > c_problem_instance->dGetQuality(vvd_population[ii], i_err_flag))
					{
						vvd_new_population[ii] = vd_new_individual;
						cout << d_new_ind_quality << endl;
					}
					else
					{
						vvd_new_population[ii] = vvd_population[ii];
					}
				}
				else
				{
					vvd_new_population[ii] = vvd_population[ii];
				}
			}
			else
			{
				vvd_new_population[ii] = vvd_population[ii];
			}
		}
		
		vvd_population = vvd_new_population;
	}

	delete pi_index_table;
	
	vector<double> vd_best = vdFindBestIndividual(vvd_population);
	cout << "Best solution: " << endl << c_problem_instance->dGetQuality(vd_best, i_err_flag) << endl;

	return  vd_best;
}

vector<double> CDiffEvol::vdFindBestIndividual(vector<vector<double>> vvd_population)
{
	int* i_err_flag = new int;
	double d_best_score = c_problem_instance->dGetQuality(vvd_population[0], i_err_flag);
	int i_best_index = 0;

	for (int ii = 1; ii < vvd_population.size(); ii++)
	{
		double d_current_quality = c_problem_instance->dGetQuality(vvd_population[ii], i_err_flag);
		if (d_current_quality > d_best_score)
		{
			d_best_score = d_current_quality;
			i_best_index = ii;
		}
	}

	delete i_err_flag;
	return vvd_population[i_best_index];
}