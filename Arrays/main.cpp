﻿#include<iostream>
using namespace std;

#define tab "\t"
#define delimiter "\n----------------------------------------------------------------\n"

const int ROWS = 3; //количество строк
const int COLS = 4; //количество элементов строки

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(double arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(int arr[ROWS][COLS], const int ROWS, const int COLS, int minRand = 0, int maxRand = 100);

void Print(const int arr[], const int n);
void Print(const double arr[], const int n);
void Print(const int arr[ROWS][COLS], const int ROWS, const int COLS);

int Sum(const int arr[], const int n);
double Sum( const double arr[], const int n);
int Sum(const int arr[ROWS][COLS], const int ROWS, const int COLS);

double Avg(const int arr[], const int n);
double Avg(const double arr[], const int n);
double Avg(const int arr[ROWS][COLS], const int ROWS, const int COLS);

int minValueIn( const int arr[], const int n);
double minValueIn( const double arr[], const int n);
int minValueIn(const int arr[ROWS][COLS], const int ROWS, const int COLS);

int maxValueIn(const int arr[], const int n);
double maxValueIn(const double arr[], const int n);
int maxValueIn(const int arr[ROWS][COLS], const int ROWS, const int COLS);

void shiftLeft(int arr[], const int n);
void shiftLeft(double arr[], const int n);
void shiftLeft(int arr[ROWS][COLS], const int ROWS, const int COLS);

void shiftRight(int arr[], const int n);
void shiftRight(double arr[], const int n);

void main()
{
	setlocale(LC_ALL, "");
	const int I_SIZE = 5;
	int i_arr[I_SIZE];
	int minRand, maxRand;
	/*do
	{
		cout << "Введите минимально возможное случайное число: "; cin >> minRand;
		cout << "Введите максимально возможное случайное число: "; cin >> maxRand;
		if (minRand == maxRand)cout << "Пределы диапазона не должны совпадать: " << endl;
	} while (minRand == maxRand);*/
	FillRand(i_arr, I_SIZE); 
	cout << "Выводим массив на экран: "; Print(i_arr, I_SIZE); 
	cout << "Возвращаем сумму всех элементов массива: " << Sum(i_arr, I_SIZE) << endl;
	cout << "Возвращаем среднее арифметическое элементов массива: " << Avg(i_arr, I_SIZE) << endl;
	cout << "Возвращаем минимальное значение в массиве: " << minValueIn(i_arr, I_SIZE) << endl;
	cout << "Возвращаем максимальное значение в массиве: " << maxValueIn(i_arr, I_SIZE) << endl;
	cout << "Циклически сдвигаем массив на заданное число элементов влево :" << endl;
    shiftLeft(i_arr, I_SIZE);
	cout << "Циклически сдвигаем массив на заданное число элементов вправо :" << endl;
	shiftRight(i_arr, I_SIZE);
	cout << endl;

	cout << delimiter << endl;
	
	const int D_SIZE = 5;
	double d_arr[D_SIZE];
	int i_arr_2[ROWS][COLS];

	//Заполнение массива случайными числами:
	FillRand(i_arr_2, ROWS, COLS);

	//Вывод двумерного массива на экран:
	Print(i_arr_2, ROWS, COLS);

	cout << Sum(i_arr_2, ROWS, COLS) << endl;

	cout << Avg(i_arr_2, ROWS, COLS) << endl;

	cout << minValueIn(i_arr_2, ROWS, COLS) << endl;

	cout << maxValueIn(i_arr_2, ROWS, COLS) << endl;

	cout << endl;

	shiftLeft(i_arr_2, ROWS, COLS);

	cout << delimiter << endl;

	FillRand(d_arr, D_SIZE);
	cout << "Массив double элементов: "; Print(d_arr, D_SIZE);
	cout << "Сумма элементов массива: " << Sum(d_arr, D_SIZE) << endl;
	cout << "Среднее арифметическое элементов массива: " << Avg(d_arr, D_SIZE) << endl;
	cout << "Минимальное значение в массиве: "; cout <<  minValueIn(d_arr, D_SIZE) << endl;
	cout << "Максимальное значение в массиве: "; cout << maxValueIn(d_arr, D_SIZE) << endl;
	cout << "Сдвиг массива влево: " << endl;
	shiftLeft(d_arr, D_SIZE); cout << endl;
	cout << "Сдвиг массива вправо: " << endl;
	shiftRight(d_arr, D_SIZE); cout << endl;

	cout << delimiter << endl;
}
void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	if (maxRand < minRand)
	{
		int buffer = minRand;
		minRand = maxRand;
		maxRand = buffer;
	}
	for (int i = 0; i < n; i++)
	{
		arr[i] = minRand + rand() % (maxRand - minRand);
		//arr[i] = 50 + rand() % 50;
		//Функция rand() генерирует псевдослучайное число в диапазоне от 0 до 32 767 (RAND_MAX)
		//Это псевдослучайное число можно вывести на экран, сохранить в переменную, или элемент массива
	}
}
void FillRand(double arr[], const int n, int minRand, int maxRand)
{
	if (maxRand < minRand)
	{
		int buffer = minRand;
		minRand = maxRand;
		maxRand = buffer;
	}
	minRand *= 100;
	maxRand *= 100;
	for (int i = 0; i < n; i++)
	{
		arr[i] = minRand + rand() % (maxRand - minRand);
		arr[i] /= 100;
	}
}
void FillRand(int arr[ROWS][COLS], const int ROWS, const int COLS, int minRand, int maxRand)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void Print(const int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
void Print(const double arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
void Print(const int arr[ROWS][COLS], const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
}
int Sum( const int arr[], const int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	return sum;
}
double Sum( const double arr[], const int n)
{
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	return sum;
}
int Sum(const int arr[ROWS][COLS], const int ROWS, const int COLS)
{
	int sum = 0;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			sum += arr[i][j];
		}
		cout << endl;
	}
	return sum;
}
double Avg(const int arr[], const int n)
{
	return (double)Sum(arr, n) / n;
}
double Avg(const double arr[], const int n)
{
	return Sum(arr, n) / n;
}
double Avg(const int arr[ROWS][COLS], const int ROWS, const int COLS)
{
	return (double)Sum(arr, ROWS, COLS) / (ROWS*COLS);
}
int minValueIn(const int arr[], const int n)
{
	int min;
	min = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min)min = arr[i];
	}
	return min;
}
double minValueIn(const double arr[], const int n)
{
	double min;
	min = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min)min = arr[i];
	}
	return min;
}
int minValueIn(const int arr[ROWS][COLS], const int ROWS, const int COLS)
{
	int min;
	min = arr[0][0];
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (arr[i][j] < min)min = arr[i][j];
		}
		cout << endl;
	}
	return min;
}
int maxValueIn(const int arr[], const int n)
{
	int max;
    max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)max = arr[i];
	}
	return max;
}
double maxValueIn(const double arr[], const int n)
{
	double max;
	max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)max = arr[i];
	}
	return max;
}
int maxValueIn(const int arr[ROWS][COLS], const int ROWS, const int COLS)
{
	int max;
	max = arr[0][0];
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (arr[i][j] > max)max = arr[i][j];
		}
		cout << endl;
	}
	return max;
}
void shiftLeft(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		int buffer = arr[0];
		for (int i = 0; i < n; i++)
		{
			arr[i] = arr[i + 1];
		}
		arr[n - 1] = buffer;
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << "\t";
		}
		cout << endl;
	}
}
void shiftLeft(double arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		double buffer = arr[0];
		for (int i = 0; i < n; i++)
		{
			arr[i] = arr[i + 1];
		}
		arr[n - 1] = buffer;
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << "\t";
		}
		cout << endl;
	}
}
void shiftLeft(int arr[ROWS][COLS], const int ROWS, const int COLS)
{
	for (int i = 0; i < COLS; i++)
	{
		int buffer = arr[0][0];
		for (int i = 0; i < COLS; i++)
		{
			arr[i][i] = arr[i][i + 1];
		}
		arr[i][i] = buffer;
		//Print(arr, ROWS, COLS);
		for (int i = 0; i < COLS; i++)
		{
			cout << arr[i][i] << "\t";
		}
		cout << endl;
	}
}
void shiftRight(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		int buffer = arr[n-1];
		for (int i = n-2; i >= 0; i--)
		{
			arr[i+1] = arr[i];
		}
		arr[0] = buffer;
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << "\t";
		}
		cout << endl;
	}
}
void shiftRight(double arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		double buffer = arr[n - 1];
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
