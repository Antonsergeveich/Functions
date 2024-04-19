#include"stdafx.h"
#include"Constants.h"
#include"Print.h"
#include"Print.cpp"
#include"Sum.h"
#include"Sum.cpp"
#include"Avg.h"
#include"Avg.cpp"
#include"minValueIn.h"
#include"minValueIn.cpp"
#include"maxValueIn.h"
#include"maxValueIn.cpp"
#include"shiftLeft.h"
#include"shiftLeft.cpp"
#include"shiftRight.h"
#include"shiftRight.cpp"
#include"selection_Sort.h"
#include"selection_Sort.cpp"
#include"Search.h"
#include"Search.cpp"
#include"Unique.h"
#include"Unique.cpp"

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(double arr[], const int n, int minRand = 0, int maxRand = 100);
//template - создаёт шаблон
//typename - создаёт шаблонный тип данных
//T - имя шаблонного типа

void Search_1(int arr[], int n);
void main()
{
	setlocale(LC_ALL, "");
	const int n = 10;
	int arr[n];
	int minRand, maxRand;
	FillRand(arr, n,0,10);
	Print(arr, n);
	cout << endl;
	Search(arr, n);
	cout << delimiter;
	Unique(arr, n);
	Print(arr, n);
	//Search_1(arr, n);
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
void Search_1(int arr[], int n)
{

	int buffer = 0;
	for (int i = 0; i < n; i++)
	{
		int number = arr[0];//число
		int repeat = 0; //повторения
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] == arr[j])
			{
				buffer = arr[i];
				number = arr[i];
				repeat++;
			}
		}
		if (number == buffer)cout << buffer << " = " << repeat << endl;
	}
}
