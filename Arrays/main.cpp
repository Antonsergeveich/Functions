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
	/*do
	{
		cout << "Введите минимально возможное случайное число: "; cin >> minRand;
		cout << "Введите максимально возможное случайное число: "; cin >> maxRand;
		if (minRand == maxRand)cout << "Пределы диапазона не должны совпадать: " << endl;
	} while (minRand == maxRand);*/
	//FillRand(arr, n, 0, 10); // Заполняем массив случайными числами
	//cout << "Выводим массив на экран: "; Print(arr, n); cout << endl;
	//cout << "Возвращаем сумму всех элементов массива: " << Sum(arr, n) << endl;
	//cout << "Возвращаем среднее арифметическое элементов массива: " << Avg(arr, n) << endl;
	//cout << "Возвращаем минимальное значение в массиве: " << minValueIn(arr, n) << endl;
	//cout << "Возвращаем максимальное значение в массиве: " << maxValueIn(arr, n) << endl;
	//cout << "Сдвигаем массив влево: " << endl; shiftLeft(arr, n);
	//cout << "Сдвигаем массив вправо: " << endl; shiftRight(arr, n);

	const int D_SIZE = 8;
	double d_arr[D_SIZE];
	FillRand(d_arr, D_SIZE, 0, 10);
	Print(d_arr, D_SIZE);
	cout << "Возвращаем сумму всех элементов массива: " << Sum(d_arr, D_SIZE) << endl;
	cout << "Возвращаем среднее арифметическое элементов массива: " << Avg(d_arr, D_SIZE) << endl;
	cout << "Возвращаем минимальное значение в массиве: " << minValueIn(d_arr, D_SIZE) << endl;
	cout << "Возвращаем максимальное значение в массиве: " << maxValueIn(d_arr, D_SIZE) << endl;
	cout << "Сдвигаем массив влево: " << endl; shiftLeft(d_arr, D_SIZE);
	cout << "Сдвигаем массив вправо: " << endl; shiftRight(d_arr, D_SIZE);
	FillRand(arr, n,0,10);
	Print(arr, n);
	cout << endl;
	Search(arr, n);
	cout << delimiter;
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
