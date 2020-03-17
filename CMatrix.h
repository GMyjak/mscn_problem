#include <iostream>
#include <string>
#define I_DEFAULT_SIZE 10

using namespace std;

template <typename T>
class CMatrix
{
private:
	T** t_array;
	int i_size_x;
	int i_size_y;

public:
	CMatrix();
	CMatrix(int iSizeX, int iSizeY);
	~CMatrix();

	T getValueAt(int iOffsetX, int iOffsetY);
	T getValueAtArray(int iOffset);
	bool bSetValueAt(int iOffsetX, int iOffsetY, T tValue);
	bool bSetSizeX(int iSize);
	bool bSetSizeY(int iSize);
	bool bIsOfSize(int iSizeX, int iSizeY);
	bool bContainsNegativeValues();
	void vPrintMatrix();
	string sToString();

private:
	void v_alloc_memory(int iSizeX, int iSizeY);
	void v_dealloc_memory();
};

template <typename T>
CMatrix<T>::CMatrix()
{
	v_alloc_memory(I_DEFAULT_SIZE, I_DEFAULT_SIZE);
}

template <typename T>
CMatrix<T>::CMatrix(int iSizeX, int iSizeY)
{
	if (iSizeX < 1 || iSizeY < 1)
	{
		t_array = NULL;
		i_size_x = I_DEFAULT_SIZE;
		i_size_y = I_DEFAULT_SIZE;
	}
	else
	{
		v_alloc_memory(iSizeX, iSizeY);
	}
}

template <typename T>
CMatrix<T>::~CMatrix()
{
	v_dealloc_memory();
}

template <typename T>
T CMatrix<T>::getValueAt(int iOffsetX, int iOffsetY)
{
	if (t_array == NULL)
	{
		return NULL;
	}
	else if (iOffsetX >= i_size_x || iOffsetX < 0 || iOffsetY >= i_size_y || iOffsetY < 0)
	{
		return NULL;
	}
	else
	{
		return t_array[iOffsetX][iOffsetY];
	}
}

template <typename T>
T CMatrix<T>::getValueAtArray(int iOffset)
{
	if (iOffset >= i_size_x * i_size_y || iOffset < 0)
	{
		return NULL;
	}
	return t_array[iOffset % i_size_x][iOffset / i_size_x];
}

template <typename T>
bool CMatrix<T>::bSetValueAt(int iOffsetX, int iOffsetY, T tValue)
{
	if (t_array == NULL)
	{
		return false;
	}
	else if (iOffsetX >= i_size_x || iOffsetX < 0 || iOffsetY >= i_size_y || iOffsetY < 0)
	{
		return false;
	}
	else
	{
		t_array[iOffsetX][iOffsetY] = tValue;
		return true;
	}
}
template <typename T>
bool CMatrix<T>::bSetSizeX(int iSize)
{
	if (iSize < 0)
	{
		return false;
	}
	else
	{
		T** t_old_array = t_array;
		int i_old_size = i_size_x;
		v_alloc_memory(iSize, i_size_y);

		int i_lesser_size = i_old_size;
		if (i_old_size > i_size_x)
			i_lesser_size = i_size_x;

		for (int ix = 0; ix < i_lesser_size; ix++)
		{
			for (int iy = 0; iy < i_size_y; iy++)
			{
				t_array[ix][iy] = t_old_array[ix][iy];
			}
		}

		for (int ii = 0; ii < i_old_size; ii++)
		{
			delete[] t_old_array[ii];
		}
		delete[] t_old_array;

		return true;
	}
}

template <typename T>
bool CMatrix<T>::bSetSizeY(int iSize)
{
	if (iSize < 0)
	{
		return false;
	}
	else
	{
		T** t_old_array = t_array;
		int i_old_size = i_size_y;
		v_alloc_memory(i_size_x, iSize);

		int i_lesser_size = i_old_size;
		if (i_old_size > i_size_y)
			i_lesser_size = i_size_y;

		for (int ix = 0; ix < i_size_x; ix++)
		{
			for (int iy = 0; iy < i_lesser_size; iy++)
			{
				t_array[ix][iy] = t_old_array[ix][iy];
			}
		}

		for (int ii = 0; ii < i_size_x; ii++)
		{
			delete[] t_old_array[ii];
		}
		delete[] t_old_array;

		return true;
	}
}

template <typename T>
bool CMatrix<T>::bIsOfSize(int iSizeX, int iSizeY)
{
	return (iSizeY == i_size_y && iSizeY == i_size_y && t_array != NULL);

}

template <typename T>
bool CMatrix<T>::bContainsNegativeValues()
{
	for (int ix = 0; ix < i_size_x; ix++)
	{
		for (int iy = 0; iy < i_size_y; iy++)
		{
			if (t_array[ix][iy] < 0)
			{
				return true;
			}
		}
	}

	return false;
}

template <typename T>
void CMatrix<T>::vPrintMatrix()
{
	for (int ix = 0; ix < i_size_x; ix++)
	{
		for (int iy = 0; iy < i_size_y; iy++)
		{
			cout << t_array[ix][iy] << " ";
		}
		cout << endl;
	}
}

template <typename T>
string CMatrix<T>::sToString()
{
	string s_ret = "";

	for (int ix = 0; ix < i_size_x; ix++)
	{
		for (int iy = 0; iy < i_size_y; iy++)
		{
			s_ret += (to_string(t_array[ix][iy]) + " ");
		}
		s_ret += "\n";
	}

	return s_ret;
}

template <typename T>
void CMatrix<T>::v_alloc_memory(int iSizeX, int iSizeY)
{
	i_size_x = iSizeX;
	i_size_y = iSizeY;

	t_array = new T*[i_size_x];
	for (int ii = 0; ii < i_size_x; ii++)
	{
		t_array[ii] = new T[i_size_y];
	}

	for (int ix = 0; ix < i_size_x; ix++)
	{
		for (int iy = 0; iy < i_size_y; iy++)
		{
			t_array[ix][iy] = 0.;
		}
	}
}

template <typename T>
void CMatrix<T>::v_dealloc_memory()
{
	if (t_array != NULL)
	{
		for (int ii = 0; ii < i_size_x; ii++)
		{
			delete[] t_array[ii];
		}
		delete[] t_array;
	}
}