#include"ShiftRight.h"
#include"ShiftLeft.h"

void shiftRight(int arr[], const int n, int number_of_shifts)
{
	shiftLeft(arr, n, n - number_of_shifts % n);
}
void shiftRight_1(int arr[], const int n, int number_of_shifts)
{
	for (int i = 0; i < number_of_shifts % n; i++)
	{
		int buffer = arr[n - 1];
		for (int i = n - 1; i > 0; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[0] = buffer;
	}
}
void shiftRight(double arr[], const int n, int number_of_shifts)
{
	shiftLeft(arr, n, n - number_of_shifts % n);
}
void shiftRight_1(double arr[], const int n, int number_of_shifts)
{
	for (int i = 0; i < number_of_shifts; i++)
	{
		double buffer = arr[n - 1];
		for (int i = n - 2; i >= 0; i--)
		{
			arr[i + 1] = arr[i];
		}
		arr[0] = buffer;
	}
}
void shiftRight(char arr[], const int n, int number_of_shifts)
{
	for (int i = 0; i < number_of_shifts; i++)
	{
		char buffer = arr[n - 1];
		for (int i = n - 2; i >= 0; i--)
		{
			arr[i + 1] = arr[i];
		}
		arr[0] = buffer;
	}
}

void shiftRight(int arr[ROWS][COLS], const int ROWS, const int COLS, int number_of_shifts)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < number_of_shifts % COLS; j++)
		{
			int buffer = arr[i][COLS - 1];
			for (int x = COLS - 1; x > 0; x--)
			{
				arr[i][x] = arr[i][x - 1];
			}
			arr[i][0] = buffer;
		}
	}
}
void shiftRight_1(int arr[ROWS][COLS], const int ROWS, const int COLS, int number_of_shifts)
{
	for (int i = 0; i < number_of_shifts; i++)
	{
		int buffer = arr[ROWS - 1][COLS - 1];
		for (int i = ROWS - 1; i >= 0; i--)
		{
			for (int j = COLS - 1; j >= 0; j--)
			{
				if (j == 0)
				{
					arr[i][j] = arr[i - 1][COLS - 1];
				}
				else
				{
					arr[i][j] = arr[i][j - 1];
				}
			}
		}
		arr[0][0] = buffer;
	}
}
void shiftRight_2(int arr[ROWS][COLS], const int ROWS, const int COLS, int number_of_shifts)
{
	shiftLeft(arr, ROWS, COLS, ROWS * COLS - number_of_shifts);
}
void shiftRight(double arr[ROWS][COLS], const int ROWS, const int COLS, int number_of_shifts)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < number_of_shifts % COLS; j++)
		{
			double buffer = arr[i][COLS - 1];
			for (int x = COLS - 1; x > 0; x--)
			{
				arr[i][x] = arr[i][x - 1];
			}
			arr[i][0] = buffer;
		}
	}
}
void shiftRight(char arr[ROWS][COLS], const int ROWS, const int COLS, int number_of_shifts)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < number_of_shifts % COLS; j++)
		{
			char buffer = arr[i][COLS - 1];
			for (int x = COLS - 1; x > 0; x--)
			{
				arr[i][x] = arr[i][x - 1];
			}
			arr[i][0] = buffer;
		}
	}
}