#include "pch.h"
#include "CRandomSearch.h"


CRandomSearch::CRandomSearch(CMscnProblem *pcProblemInstance, int iSeed)
{
	pc_problem_instance = pcProblemInstance;
	c_rng = CRandomV2(iSeed);
}


CRandomSearch::~CRandomSearch()
{

}

vector<double> CRandomSearch::vdGenerateSolution()
{
	int i_provider_number = pc_problem_instance->iGetProviderNumber();
	int i_factory_number = pc_problem_instance->iGetFactoryNumber();
	int i_warehouse_number = pc_problem_instance->iGetWarehouseNumber();
	int i_shop_number = pc_problem_instance->iGetShopNumber();

	int i_solution_size = i_provider_number * i_factory_number + i_factory_number * i_warehouse_number + i_warehouse_number * i_shop_number;
	vector<double> vd_solution(i_solution_size);

	int i_index = 0;
	int i_offset = 0;
	int* i_err_flag = new int;
	*i_err_flag = 0;

	for (int iip = 0; iip < i_provider_number; iip++)
	{
		for (int iif = 0; iif < i_factory_number; iif++)
		{
			vd_solution[i_index + i_offset] = c_rng.dGetNextDouble(pc_problem_instance->dGetXdMinAt(i_index, i_err_flag), pc_problem_instance->dGetXdMaxAt(i_index, i_err_flag));
			i_index++;
		}
	}
	
	i_index = 0;
	i_offset += i_provider_number * i_factory_number;

	for (int iif = 0; iif < i_factory_number; iif++)
	{
		for (int iiw = 0; iiw < i_warehouse_number; iiw++)
		{
			vd_solution[i_index + i_offset] = c_rng.dGetNextDouble(pc_problem_instance->dGetXfMinAt(i_index, i_err_flag), pc_problem_instance->dGetXfMaxAt(i_index, i_err_flag));
			i_index++;
		}
	}
	
	i_index = 0;
	i_offset += i_factory_number * i_warehouse_number;

	for (int iiw = 0; iiw < i_warehouse_number; iiw++)
	{
		for (int iis = 0; iis < i_shop_number; iis++)
		{
			vd_solution[i_index + i_offset] = c_rng.dGetNextDouble(pc_problem_instance->dGetXmMinAt(i_index, i_err_flag), pc_problem_instance->dGetXmMaxAt(i_index, i_err_flag));
			i_index++;
		}
	}

	return vd_solution;
}

vector<double> CRandomSearch::vdRandomSearch(int iNumberOfIterations, int* iErrFlag)
{
	vector<double> vd_current_best;

	double d_current_best = 0;
	bool b_is_best_set = false;

	for (int ii = 0; ii < iNumberOfIterations; ii++)
	{
		vector<double> vd_solution = vdGenerateSolution();
		if (pc_problem_instance->bConstraintsSatisfied(vd_solution, iErrFlag))
		{
			double d_new_quality = pc_problem_instance->dGetQuality(vd_solution, iErrFlag);
			
			if (!b_is_best_set)
			{
				b_is_best_set = true;
				d_current_best = d_new_quality;
				vd_current_best = vd_solution;
				//cout << d_current_best << endl;
			}
			else
			{
				//MODYFIKACJA
				//
				if (d_new_quality < d_current_best && true)
				{
					int i_replaced_genes = 1;
					vector<bool> vb_replaced_flag;
					for (int ii = 0; ii < vd_solution.size(); ii++)
					{
						vb_replaced_flag.push_back(false);
					}

					while (d_new_quality < d_current_best && i_replaced_genes < vd_solution.size())
					{
						int i_index_order = c_rng.iGetNextInt(0, vd_solution.size() - i_replaced_genes - 1);
						int i_index = -1;

						int i_flag_offset = 0;
						while (i_index_order >= 0)
						{
							if (!(vb_replaced_flag[i_flag_offset]))
							{
								i_index++;
								i_index_order--;
							}
							i_flag_offset++;
						}

						vb_replaced_flag[i_index] = true;
						vd_solution[i_index] = vd_current_best[i_index];
						d_new_quality = pc_problem_instance->dGetQuality(vd_solution, iErrFlag);

						i_replaced_genes++;
					}
				}
				
				//
				//

				if (d_new_quality > d_current_best)
				{
					d_current_best = d_new_quality;
					vd_current_best = vd_solution;
					//cout << d_current_best << endl;
				}
			}
		}
	}
	

	if (!b_is_best_set)
	{
		*iErrFlag = E_SOLUTION_NOT_FOUND;
	}

	return vd_current_best;
}

int CRandomSearch::iGetSeed()
{
	return c_rng.iGetSeed();
}

void CRandomSearch::vSetSeed(int iSeed)
{
	c_rng.vSetSeed(iSeed);
}
