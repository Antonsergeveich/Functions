#include"stdafx.h"
#include"Constans.h"
#include"FillRand.h"
#include"Print.h"
#include"Unique.h"
//#include"Sum.h"
//#include"Avg.h"
#include"minValueIn.h"
#include"maxValueIn.h"
#include"ShiftLeft.h"
#include"ShiftRight.h"
#include"bubble_Sort.h"
#include"selection_Sort.h"

//#define I_ARR
//#define D_ARR
//#define I_ARR_2
#define CHAR

void main()
{
	setlocale(LC_ALL, "");
#ifdef I_ARR
	const int I_SIZE = 10;
	int i_arr[I_SIZE];
	int minRand = 0, maxRand = 10;
	
    /*do
	{
		cout << "Введите минимально возможное случайное число: "; cin >> minRand;
		cout << "Введите максимально возможное случайное число: "; cin >> maxRand;
		if (minRand == maxRand)cout << "Пределы диапазона не должны совпадать: " << endl;
	} while (minRand == maxRand);*/
	FillRand(i_arr, I_SIZE, minRand, maxRand);
	cout << "Выводим массив на экран: "; Print(i_arr, I_SIZE);
	cout << "Возвращаем сумму всех элементов массива: " << Sum(i_arr, I_SIZE) << endl;
	cout << "Возвращаем среднее арифметическое элементов массива: " << Avg(i_arr, I_SIZE) << endl;
	cout << "Возвращаем минимальное значение в массиве: " << minValueIn(i_arr, I_SIZE) << endl;
	cout << "Возвращаем максимальное значение в массиве: " << maxValueIn(i_arr, I_SIZE) << endl;
	/*int number_of_shifts;
	cout << "Введите количество сдвигов влево: "; cin >> number_of_shifts;
	shiftLeft(i_arr, I_SIZE, number_of_shifts);
	Print(i_arr, I_SIZE);
	cout << "Введите количесиво сдвигов вправо: "; cin >> number_of_shifts;
	shiftRight(i_arr, I_SIZE, number_of_shifts);
	Print(i_arr, I_SIZE);
	cout << endl;
	cout << "Сортируем массив выбором: ";
	selection_Sort(i_arr, I_SIZE);
	Print(i_arr, I_SIZE);
	cout << endl;
	cout << "Выводим массив уникальных чисел: ";
	Unique(i_arr, I_SIZE, minRand, maxRand);
	Print(i_arr, I_SIZE);*/
	Unique_2(i_arr[ROWS][COLS], ROWS, COLS);
	Print(i_arr, I_SIZE);
	cout << delimiter << endl;

#endif // I_ARR

	
#ifdef I_ARR_2
	int i_arr_2[ROWS][COLS];

	FillRand(i_arr_2, ROWS, COLS); //Заполнение массива случайными числами:
	Print(i_arr_2, ROWS, COLS);//Вывод двумерного массива на экран:

	//cout << "Сумма элементов массива: " << Sum(i_arr_2, ROWS, COLS) << endl;

	//cout << "Среднее арифметическое элементов массива: " << Avg(i_arr_2, ROWS, COLS) << endl;

	cout << "Минимальное значение в массиве: " << minValueIn(i_arr_2, ROWS, COLS) << endl;

	cout << "Максимальное значение в массиве: " << maxValueIn(i_arr_2, ROWS, COLS) << endl;
	Unique_2(i_arr_2, ROWS, COLS);
	Print(i_arr_2, ROWS,COLS);
	int number_of_shifts;
	cout << "Введите количество сдвигов влево: "; cin >> number_of_shifts;
	shiftLeft(i_arr_2, ROWS, COLS, number_of_shifts);
	Print(i_arr_2, ROWS, COLS);

	cout << "Введите количество сдвигов вправо: "; cin >> number_of_shifts;
	shiftRight_2(i_arr_2, ROWS, COLS, number_of_shifts);
	Print(i_arr_2, ROWS, COLS);

	cout << "Сортируем массив построчно: " << endl;
	bubble_Sort(i_arr_2, ROWS, COLS);
	Print(i_arr_2, ROWS, COLS);
	cout << endl;

	cout << "Сквозная пузырьковая сортировка : " << endl;
	bubble_Sort_1(i_arr_2, ROWS, COLS);
	Print(i_arr_2, ROWS, COLS);

	cout << "Сквозная сортировка выбором: " << endl;
	selection_Sort(i_arr_2, ROWS, COLS);
	Print(i_arr_2, ROWS, COLS);
	cout << delimiter << endl;
#endif // I_ARR_2


#ifdef D_ARR
	const int D_SIZE = 10;
	double d_arr[D_SIZE];
	FillRand(d_arr, D_SIZE);
	cout << "Массив double элементов: "; Print(d_arr, D_SIZE);
	cout << "Сумма элементов массива: " << Sum(d_arr, D_SIZE) << endl;
	cout << "Среднее арифметическое элементов массива: " << Avg(d_arr, D_SIZE) << endl;
	cout << "Минимальное значение в массиве: "; cout << minValueIn(d_arr, D_SIZE) << endl;
	cout << "Максимальное значение в массиве: "; cout << maxValueIn(d_arr, D_SIZE) << endl;
	cout << "Сдвиг массива влево: " << endl;
	shiftLeft(d_arr, D_SIZE, number_of_shifts);
	Print(d_arr, D_SIZE);
	cout << "Сдвиг массива вправо: " << endl;
	shiftRight(d_arr, D_SIZE, number_of_shifts); cout << endl;
	Print(d_arr, D_SIZE);
	cout << delimiter << endl;
#endif // 
#ifdef CHAR
	const char SYMBOL = 10;
	char s[SYMBOL];
	int minRand = 0, maxRand = 0;
	FillRand(s, SYMBOL, minRand, maxRand);
	Print(s, SYMBOL);
#endif // CHAR

}


