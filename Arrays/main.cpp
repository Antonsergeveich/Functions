﻿#include<iostream>
using namespace std;

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(double arr[], const int n, int minRand = 0, int maxRand = 100);
void Print(const int arr[], const int n);
void Print(const double arr[], const int n);
int Sum(const int arr[], const int n);
double Avg(const int arr[], const int n);
int minValueIn( const int arr[], const int n);
int maxValueIn(const int arr[], const int n);
void shiftLeft(int arr[], const int n);
void shiftRight(int arr[], const int n);

#define tab "\t"
void main()
{
	setlocale(LC_ALL, "");
	const int n = 5;
	int arr[n];
	int minRand, maxRand;
	/*do
	{
		cout << "Введите минимально возможное случайное число: "; cin >> minRand;
		cout << "Введите максимально возможное случайное число: "; cin >> maxRand;
		if (minRand == maxRand)cout << "Пределы диапазона не должны совпадать: " << endl;
	} while (minRand == maxRand);*/
	FillRand(arr, n); // Заполняем массив случайными числами
	cout << "Выводим массив на экран: "; Print(arr, n); cout << endl;
	cout << "Возвращаем сумму всех элементов массива: " << Sum(arr, n) << endl;
	cout << "Возвращаем среднее арифметическое элементов массива: " << Avg(arr, n) << endl;
	cout << "Возвращаем минимальное значение в массиве: " << minValueIn(arr, n) << endl;
	cout << "Возвращаем максимальное значение в массиве: " << maxValueIn(arr, n) << endl;
	cout << "Циклически сдвигаем массив на заданное число элементов влево :" << endl;
    shiftLeft(arr, n);
	cout << "Циклически сдвигаем массив на заданное число элементов вправо :" << endl;
	shiftRight(arr, n);
}
 
void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	if (maxRand < minRand)
	{
		int buffer = minRand;
		minRand = maxRand;
		maxRand = buffer;
	}
	//Заполнение массива случайными числами:
	for (int i = 0; i < n; i++)
	{
		arr[i] = minRand + rand() % (maxRand - minRand);
		//arr[i] = 50 + rand() % 50;
		//Функция rand() генерирует псевдослучайное число в диапазоне от 0 до 32 767 (RAND_MAX)
		//Это псевдослучайное число можно вывести на экран, сохранить в переменную, или элемент массива

	}
	//Вывод массива на экран:
	/*for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;*/
}
void FillRand(double arr[], const int n, int minRand, int maxRand)
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
	}
}
void Print(const int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
}
void Print(const double arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
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
double Avg(const int arr[], const int n)
{
		return (double)Sum(arr, n) / n;
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