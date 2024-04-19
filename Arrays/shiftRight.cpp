#include"stdafx.h"
template<typename T>
void shiftRight(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		T buffer = arr[n - 1];
		for (int i = n - 2; i >= 0; i--)
		{
			arr[i + 1] = arr[i];
		}
		arr[0] = buffer;
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << "\t";
		}
		cout << endl;
	}
}