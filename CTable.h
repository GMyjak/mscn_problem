#include <iostream>
#include <string>
#define I_DEFAULT_SIZE 10

using namespace std;

template <typename T>
class CTable
{
private:
	T* t_array;
	int i_size;

public:
	CTable();
	CTable(int iSize);
	~CTable();

	T getValueAt(int iOffset);
	bool bSetValueAt(int iOffset, T tValue);
	bool bSetSize(int iSize);
	bool bIsOfSize(int iSize);
	bool bContainsNegativeValues();
	void vPrintTable();
	string sToString();

private:
	void v_alloc_memory(int iSize);
	void v_dealloc_memory();
};

template <typename T>
CTable<T>::CTable()
{
	v_alloc_memory(I_DEFAULT_SIZE);
}

template <typename T>
CTable<T>::CTable(int iSize)
{
	if (iSize < 1)
	{
		t_array = NULL;
		i_size = I_DEFAULT_SIZE;
	}
	else
	{
		v_alloc_memory(iSize);
	}
}

template <typename T>
CTable<T>::~CTable()
{
	v_dealloc_memory();
}

template <typename T>
T CTable<T>::getValueAt(int iOffset)
{
	if (t_array == NULL)
	{
		return NULL;
	}
	else if (iOffset >= i_size || iOffset < 0)
	{
		return NULL;
	}
	else
	{
		return t_array[iOffset];
	}
}

template <typename T>
bool CTable<T>::bSetValueAt(int iOffset, T tValue)
{
	if (t_array == NULL)
	{
		return false;
	}
	else if (iOffset >= i_size || iOffset < 0)
	{
		return false;
	}
	else
	{
		t_array[iOffset] = tValue;
		return true;
	}
}

template <typename T>
bool CTable<T>::bSetSize(int iSize)
{
	if (iSize < 0)
	{
		return false;
	}
	else
	{
		T* t_old_array = t_array;
		int i_old_size = i_size;
		v_alloc_memory(iSize);
		
		int i_lesser_size = i_old_size;
		if (i_old_size > i_size)
			i_lesser_size = i_size;

		for (int ii = 0; ii < i_lesser_size; ii++)
		{
			t_array[ii] = t_old_array[ii];
		}

		delete[] t_old_array;

		return true;
	}
}

template <typename T>
bool CTable<T>::bIsOfSize(int iSize)
{
	return (iSize == i_size && t_array != NULL);
}

template <typename T>
bool CTable<T>::bContainsNegativeValues()
{
	for (int ii = 0; ii < i_size; ii++)
	{
		if (t_array[ii] < 0)
		{
			return true;
		}
	}

	return false;
}

template <typename T>
void CTable<T>::vPrintTable()
{
	for (int ii = 0; ii < i_size; ii++)
	{
		cout << t_array[ii] << " ";
	}
	cout << endl;
}

template <typename T>
string CTable<T>::sToString()
{
	string s_ret = "";

	for (int ii = 0; ii < i_size; ii++)
	{
		s_ret += (to_string(t_array[ii]) + " ");
	}
	s_ret += "\n";

	return s_ret;
}

template <typename T>
void CTable<T>::v_alloc_memory(int iSize)
{
	i_size = iSize;
	t_array = new T[i_size];

	for (int ii = 0; ii < i_size; ii++)
	{
		t_array[ii] = 0;
	}
}

template <typename T>
void CTable<T>::v_dealloc_memory()
{
	if (t_array != NULL)
	{
		delete[] t_array;
	}
}