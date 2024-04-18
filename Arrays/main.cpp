#include<iostream>
using namespace std;

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(double arr[], const int n, int minRand = 0, int maxRand = 100);
//template - создаёт шаблон
//typename - создаёт шаблонный тип данных
//T - имя шаблонного типа
template<typename T>
void Print(const T arr[], const int n);
template<typename T>
T Sum(const T arr[], const int n);

double Avg(const int arr[], const int n);

int minValueIn( const int arr[], const int n);
int maxValueIn(const int arr[], const int n);

void shiftLeft(int arr[], const int n);
void shiftRight(int arr[], const int n);

void selection_Sort(int arr[], const int n);

void Search(int arr[], int n);

#define tab "\t"
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
	FillRand(arr, n, 0, 10); // Заполняем массив случайными числами
	cout << "Выводим массив на экран: "; Print(arr, n); cout << endl;
	/*cout << "Возвращаем сумму всех элементов массива: " << Sum(arr, n) << endl;
	cout << "Возвращаем среднее арифметическое элементов массива: " << Avg(arr, n) << endl;
	cout << "Возвращаем минимальное значение в массиве: " << minValueIn(arr, n) << endl;
	cout << "Возвращаем максимальное значение в массиве: " << maxValueIn(arr, n) << endl;
	cout << "Циклически сдвигаем массив на заданное число элементов влево :" << endl;
    shiftLeft(arr, n);
	cout << "Циклически сдвигаем массив на заданное число элементов вправо :" << endl;
	shiftRight(arr, n);

	const int D_SIZE = 8;
	double d_arr[D_SIZE];
	FillRand(d_arr, D_SIZE);
	Print(d_arr, D_SIZE);
	cout << "Сумма элементов массива: " << Sum(d_arr, D_SIZE);*/
	/*selection_Sort(arr, n);
	Print(arr, n);*/
	cout << endl;
	Search(arr, n);
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
template<typename T>
void Print(const T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}
template<typename T>
T Sum( const T arr[], const int n)
{
	T sum = 0;
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
void selection_Sort(int arr[], const int n)
{
	for (int i = 0; i < n; i++) 
	{
		for (int j = i + 1; j < n; j++) 
		{
			if (arr[j] < arr[i])
			{
				int buffer = arr[i];
				arr[i] = arr[j];
				arr[j] = buffer;
			}
		}
	}
}

void Search(int arr[], int n)
{
	selection_Sort(arr, n);
	for (int i = 0; i < n; i++)
	{
		int x = arr[0];
		int number = arr[i]; //число
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