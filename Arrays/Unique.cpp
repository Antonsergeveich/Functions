#include"Unique.h"

void Unique(int arr[], const int n, int minRand, int maxRand)
{
	bool exists; //существует
	for (int i = 0; i < n;)
	{
		exists = false;
		int newValue = minRand + rand() % (maxRand - minRand);
		for (int j = 0; j < i; j++)
		{
			if (arr[j] == newValue)
			{
				exists = true;
				break;
			}
		}
		if (exists == false)
		{
			arr[i] = newValue;
			i++;
		}
	}
}
void Unique(char arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		bool unique;
		do
		{
			arr[i] = rand() % n;
			unique = true;
			for (int j = 0; j < i; j++)
			{
				if (arr[i] == arr[j])
				{
					unique = false;
					break;
				}
			}
		} while (!unique);
	}
}
void Unique_1(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		bool unique;
		do
		{
			arr[i] = rand() % n;
			unique = true;//предполагаем, что сгенерировалось уникальное
			//случайное число, но это нужно проверить:
			for (int j = 0; j < i; j++)
			{
				if (arr[i] == arr[j])
				{
					unique = false;
					break;
				}
			}
		} while (!unique);
	}
}
void Unique_2(int arr[ROWS][COLS], const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			bool unique;
			do
			{
				arr[i][j] = rand() % (ROWS * COLS);
				unique = true;
				for (int k = 0; k <= i; k++)
				{
					for (int l = 0; l < (k == i ? j : COLS); l++)
					{
						if (arr[i][j] == arr[k][l])
						{
							unique = false;
							break;
						}
					}
					if (!unique)break;
				}
			} while (!unique);
		}
	}
}