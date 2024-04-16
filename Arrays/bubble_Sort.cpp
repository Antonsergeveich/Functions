#include"bubble_Sort.h"

void bubble_Sort(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int buffer = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = buffer;
			}
		}
	}
}
void bubble_Sort(char arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int buffer = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = buffer;
			}
		}
	}
}
void bubble_Sort(int arr[ROWS][COLS], const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			for (int i = 0; i < ROWS; i++)
			{
				for (int j = 0; j < COLS - 1; j++)
				{
					if (arr[i][j] > arr[i][j + 1])
					{
						int buffer = arr[i][j];
						arr[i][j] = arr[i][j + 1];
						arr[i][j + 1] = buffer;
					}
				}
			}
		}
	}
}

void bubble_Sort_1(int arr[ROWS][COLS], const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			for (int k = 0; k < ROWS; k++)
			{
				for (int l = 0; l < COLS; l++)
				{
					if (k + 1 == ROWS and l + 1 == COLS)continue;
					if (l + 1 == COLS)
					{
						int buffer = arr[k][l];
						arr[k][l] = arr[k + 1][0];
						arr[k + 1][0] = buffer;
					}
					if (arr[k][l] > arr[k][l + 1])
					{
						int buffer = arr[k][l];
						arr[k][l] = arr[k][l + 1];
						arr[k][l + 1] = buffer;
					}
				}
			}
		}
	}
}