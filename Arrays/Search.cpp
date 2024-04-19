#include"stdafx.h"
template<typename T>
void Search(T arr[], int n)
{
	selection_Sort(arr, n);
	for (int i = 0; i < n; i++)
	{
		T x = arr[0];
		T number = arr[i]; //число
		int repeat = 0; //повторения
		if (arr[i] != arr[i - 1])
		{
			for (int j = i + 1; j < n; j++)
			{
				if (arr[j] == arr[i])
				{
					repeat++;
					x = arr[j];
				}
			}
		}
		if (x == arr[i + 1])
		{
			cout << number << " = " << repeat << endl;
		}
	}
}