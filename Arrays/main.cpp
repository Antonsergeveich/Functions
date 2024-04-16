#include<iostream>
using namespace std;

using std::cout;
using std::cin;
using std::endl;

#define tab "\t"
#define delimiter "\n----------------------------------------------------------------\n"

const int ROWS = 3; //количество строк
const int COLS = 4; //количество элементов строки


void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(double arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(char arr[], const int n, int minRand = 0, int maxRand = 100); 
void FillRand(int arr[ROWS][COLS], const int ROWS, const int COLS, int minRand = 0, int maxRand = 100);
void FillRand(double arr[ROWS][COLS], const int ROWS, const int COLS, int minRand = 0, int maxRand = 100);
void FillRand(char arr[ROWS][COLS], const int ROWS, const int COLS, int minRand = 0, int maxRand = 100);
void Unique(int arr[], const int n, int minRand = 0, int maxRand = 100);
void Unique_1(int arr[], const int n);
void Unique_2(int arr[ROWS][COLS], const int ROWS, const int COLS);

void Print(const int arr[], const int n);
void Print(const double arr[], const int n);
void Print(char arr[], const int n);
void Print(const int arr[ROWS][COLS], const int ROWS, const int COLS);
void Print(const double arr[ROWS][COLS], const int ROWS, const int COLS);
void Print(char arr[ROWS][COLS],  const int ROWS, const int COLS);

int Sum(const int arr[], const int n);
double Sum(const double arr[], const int n);
char Sum(char arr[], const int n);
int Sum(const int arr[ROWS][COLS], const int ROWS, const int COLS);
double Sum(const double arr[ROWS][COLS], const int ROWS, const int COLS);
char Sum(char arr[ROWS][COLS], const int ROWS, const int COLS);

double Avg(const int arr[], const int n);
double Avg(const double arr[], const int n);
double Avg(const int arr[ROWS][COLS], const int ROWS, const int COLS);
double Avg(const double arr[ROWS][COLS], const int ROWS, const int COLS);
double Avg(const char arr[ROWS][COLS], const int ROWS, const int COLS);

int minValueIn( const int arr[], const int n);
double minValueIn( const double arr[], const int n);
char minValueIn(char arr[], const int n);
int minValueIn(const int arr[ROWS][COLS], const int ROWS, const int COLS);
double minValueIn(const double arr[ROWS][COLS], const int ROWS, const int COLS);
char minValueIn(char arr[ROWS][COLS], const int ROWS, const int COLS);

int maxValueIn(const int arr[], const int n);
double maxValueIn(const double arr[], const int n);
char maxValueIn(char arr[], const int n);
int maxValueIn(const int arr[ROWS][COLS], const int ROWS, const int COLS);
double maxValueIn(const double arr[ROWS][COLS], const int ROWS, const int COLS);
char maxValueIn(char arr[ROWS][COLS], const int ROWS, const int COLS);

void shiftLeft(int arr[], const int n, int number_of_shifts);
void shiftLeft(double arr[], const int n, int number_of_shift);
void shiftLeft(char arr[], const int n, int number_of_shifts);
void shiftLeft(char arr[ROWS][COLS], const int ROWS,const int COLS, int number_of_shifts);
void shiftLeft(int arr[ROWS][COLS], const int ROWS, const int COLS, int number_of_shifts);      //построчный
void shiftLeft_arr1(int arr[ROWS][COLS], const int ROWS, const int COLS, int number_of_shifts); //сквозной
void shiftLeft_arr2(int arr[ROWS][COLS], const int ROWS, const int COLS, int number_of_shifts); //построчный
void shiftLeft_arr3(int arr[ROWS][COLS], const int ROWS, const int COLS, int number_of_shifts); //сквозной
void shiftLeft(double arr[ROWS][COLS], const int ROWS, const int COLS, int number_of_shifts);

void shiftRight(int arr[], const int n, int number_of_shifts);
void shiftRight_1(int arr[], const int n, int number_of_shifts);
void shiftRight(double arr[], const int n, int number_of_shifts);
void shiftRight_1(double arr[], const int n, int number_of_shifts);
void shiftRight(char arr[], const int n, int number_of_shifts);
void shiftRight(int arr[ROWS][COLS], const int ROWS, const int COLS, int number_of_shifts);
void shiftRight_1(int arr[ROWS][COLS], const int ROWS, const int COLS, int number_of_shifts);
void shiftRight_2(int arr[ROWS][COLS], const int ROWS, const int COLS, int number_of_shifts);
void shiftRight(double arr[ROWS][COLS], const int ROWS, const int COLS, int number_of_shifts);
void shiftRight(char arr[ROWS][COLS], const int ROWS, const int COLS, int number_of_shifts);

void bubble_Sort(int arr[], const int n);
void bubble_Sort(int arr[ROWS][COLS], const int ROWS, const int COLS); //построчная
void bubble_Sort_1(int arr[ROWS][COLS], const int ROWS, const int COLS); //сквозная
void selection_Sort(int arr[], const int n);
void selection_Sort(int arr[ROWS][COLS], const int ROWS, const int COLS); //сквозная

//#define I_ARR
//#define D_ARR
#define I_ARR_2 //двумерный
//#define CHAR

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
	int number_of_shifts;
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
	Print(i_arr, I_SIZE);

	cout << delimiter << endl;
#endif // I_ARR

	
#ifdef I_ARR_2
	int i_arr_2[ROWS][COLS];

	FillRand(i_arr_2, ROWS, COLS); //Заполнение массива случайными числами:
	Print(i_arr_2, ROWS, COLS);//Вывод двумерного массива на экран:

	cout << "Сумма элементов массива: " << Sum(i_arr_2, ROWS, COLS) << endl;

	cout << "Среднее арифметическое элементов массива: " << Avg(i_arr_2, ROWS, COLS) << endl;

	cout << "Минимальное значение в массиве: " << minValueIn(i_arr_2, ROWS, COLS) << endl;

	cout << "Максимальное значение в массиве: " << maxValueIn(i_arr_2, ROWS, COLS) << endl;

	/*int number_of_shifts;
	cout << "Введите количество сдвигов влево: "; cin >> number_of_shifts;
	shiftLeft(i_arr_2, ROWS, COLS, number_of_shifts);
	Print(i_arr_2, ROWS, COLS);

	cout << "Введите количество сдвигов вправо: "; cin >> number_of_shifts;
	shiftRight_2(i_arr_2, ROWS, COLS, number_of_shifts);
	Print(i_arr_2, ROWS, COLS);

	cout << "Сортируем массив построчно: " << endl;
	bubble_Sort(i_arr_2, ROWS, COLS);
	Print(i_arr_2, ROWS, COLS);
	cout << endl;*/

	/*cout << "Сквозная пузырьковая сортировка : " << endl;
	bubble_Sort_1(i_arr_2, ROWS, COLS);
	Print(i_arr_2, ROWS, COLS);*/

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
		double buffer = minRand;
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
void FillRand(char arr[], const int n, int minRand, int maxRand)
{
	if (maxRand < minRand)
	{
		char buffer = minRand;
		minRand = maxRand;
		maxRand = buffer;
	}
	for (int i = 0; i < n; i++)
	{
		arr[i] = minRand + rand() % (maxRand - minRand);
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
void FillRand(double arr[ROWS][COLS], const int ROWS, const int COLS, int minRand, int maxRand)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void FillRand(char arr[ROWS][COLS], const int ROWS, const int COLS, int minRand, int maxRand)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}

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
void Unique_2(int arr[ROWS][COLS], const int ROWS,  const int COLS)
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
				     for (int l = 0; l < COLS; l++)
				     {
					      if (arr[i][j] == arr[k][l])
					      {
						      unique = false;
						      break;
					      }
				     }
			     }if (!unique)break;
			} while (!unique);
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
void Print(char arr[], const int n)
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
void Print(const double arr[ROWS][COLS], const int ROWS, const int COLS)
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
void Print(char arr[ROWS][COLS], const int ROWS, const int COLS)
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
char Sum(const char arr[], const int n)
{
	char sum = 0;
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
	}
	return sum;
}
double Sum(const double arr[ROWS][COLS], const int ROWS, const int COLS)
{
	double sum = 0;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			sum += arr[i][j];
		}
	}
	return sum;
}
char Sum(const char arr[ROWS][COLS], const int ROWS, const int COLS)
{
	int sum = 0;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			sum += arr[i][j];
		}
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
double Avg(const char arr[], const int n)
{
	return Sum(arr, n) / n; 
}

double Avg(const int arr[ROWS][COLS], const int ROWS, const int COLS)
{
	return (double)Sum(arr, ROWS, COLS) / (ROWS*COLS);
}
double Avg(const double arr[ROWS][COLS], const int ROWS, const int COLS)
{
	return (double)Sum(arr, ROWS, COLS) / (ROWS * COLS);
}
double Avg(const char arr[ROWS][COLS], const int ROWS, const int COLS)
{
	return (double)Sum(arr, ROWS, COLS) / (ROWS * COLS);
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
char minValueIn(char arr[], const int n)
{
	char min;
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
	}
	return min;
}
double minValueIn(const double arr[ROWS][COLS], const int ROWS, const int COLS)
{
	double min;
	min = arr[0][0];
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (arr[i][j] < min)min = arr[i][j];
		}
	}
	return min;
}
char minValueIn(char arr[ROWS][COLS], const int ROWS, const int COLS)
{
	char min;
	min = arr[0][0];
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (arr[i][j] < min)min = arr[i][j];
		}
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
char maxValueIn(char arr[], const int n)
{
	char max;
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
	}
	return max;
}
double maxValueIn(const double arr[ROWS][COLS], const int ROWS, const int COLS)
{
	double max;
	max = arr[0][0];
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (arr[i][j] > max)max = arr[i][j];
		}
	}
	return max;
}
char maxValueIn(char arr[ROWS][COLS], const int ROWS, const int COLS)
{
	char max;
	max = arr[0][0];
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (arr[i][j] > max)max = arr[i][j];
		}
	}
	return max;
}

void shiftLeft(int arr[], const int n, int number_of_shifts)
{
	for (int i = 0; i < number_of_shifts; i++)
	{
		int buffer = arr[0];
		for (int i = 1; i < n; i++)
		{
			arr[i-1] = arr[i];
		}
		arr[n - 1] = buffer;
	}
}
void shiftLeft(double arr[], const int n, int number_of_shifts)
{
	for (int i = 0; i < number_of_shifts; i++)
	{
		double buffer = arr[0];
		for (int i = 0; i < n; i++)
		{
			arr[i-1] = arr[i];
		}
		arr[n - 1] = buffer;
	}
}
void shiftLeft(char arr[], const int n, int number_of_shifts)
{
	for (int i = 0; i < number_of_shifts % n; i++)
	{
		char buffer = arr[0];
		for (int i = 0; i < n; i++)
		{
			arr[i] = arr[i + 1];
		}
		arr[n - 1] = buffer;
	}
}

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

void shiftLeft(int arr[ROWS][COLS], const int ROWS, const int COLS, int number_of_shifts)
{
    for (int i = 0; i < ROWS; i++)
    {
		shiftLeft(arr[i], COLS, number_of_shifts);
    }
}
void shiftLeft_arr1(int arr[ROWS][COLS], const int ROWS, const int COLS, int number_of_shifts)
{
	for (int i = 0; i < number_of_shifts; i++)
	{
		int buffer = arr[0][0];
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				if (j == COLS - 1)
				{
					arr[i][j] = arr[i + 1][0];
				}
				else
				{
					arr[i][j] = arr[i][j + 1];
				}
			}
		}
		arr[ROWS - 1][COLS - 1] = buffer;
	}
}
void shiftLeft_arr2(int arr[ROWS][COLS], const int ROWS, const int COLS, int number_of_shifts)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < number_of_shifts % COLS; j++)
		{
			int buffer = arr[i][0];
			for (int x = 1; x < COLS; x++)
			{
				arr[i][x - 1] = arr[i][x];
			}
			arr[i][COLS - 1] = buffer;
		}
	}
}
void shiftLeft_arr3(int arr[ROWS][COLS], const int ROWS, const int COLS, int number_of_shifts)
{
	for (int i = 0; i < number_of_shifts; i++)
	{
		int buffer = arr[0][0];
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 1; j < COLS; j++)
			{
				arr[i][j - 1] = arr[i][j];
			}
			if (i < ROWS - 1)arr[i][COLS - 1] = arr[i + 1][0];				
		}
		arr[ROWS - 1][COLS - 1] = buffer;
	}
}
void shiftLeft(double arr[ROWS][COLS], const int ROWS, const int COLS, int number_of_shifts)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < number_of_shifts % COLS; j++)
		{
			double buffer = arr[i][0];
			for (int x = 1; x < COLS; x++)
			{
				arr[i][x - 1] = arr[i][x];
			}
			arr[i][COLS - 1] = buffer;
		}
	}
}
void shiftLeft(char arr[ROWS][COLS], const int ROWS, const int COLS, int number_of_shifts)
{
	for ( int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < number_of_shifts % COLS; j++)
		{
			char buffer = arr[i][0];
			for (int x = 1; x < COLS; x++)
			{
				arr[i][x - 1] = arr[i][x];
			}
			arr[i][COLS - 1] = buffer;
		}
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
		int buffer = arr[ROWS - 1][COLS -1];
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

void bubble_Sort(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
		        int buffer = arr[j];
				arr[j]= arr[j+1];
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
				for (int j = 0; j < COLS-1; j++)
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
				for (int l = 0 ; l < COLS; l++)
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
						arr[k][l] = arr[k][l+1];
						arr[k][l+1] = buffer;
					}
				}
			}
		}
	}
}

void selection_Sort(int arr[], const int n)
{
	for (int i = 0; i < n; i++) // счётчик i выбирает элемент массива в который будет помещено минимальное значение
	{
		for (int j = i + 1; j < n; j++) // счётчик j перебирает оставшиеся элементы массива
		{
			//arr[i] выбранный элемент массива
			//arr[j] перебираемый элемент массива
			if (arr[j] < arr[i])
			{
				int buffer = arr[i];
				arr[i] = arr[j];
				arr[j] = buffer;
			}
		}
	}
}

void selection_Sort(int arr[ROWS][COLS], const int ROWS, const int COLS)
{
	//Эти два цикла выбирают элемент
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			//Эти два цикла перебирают оставшиеся элементы в поиске минимального значения
			for (int k = i; k < ROWS; k++)
			{
				for (int l = k == i ? j + 1 : 0; l < COLS; l++)
				{
					/*if (k == i && l == 0)l = j + 1;
					if (l == COLS)break;*/
					//arr[i][j] - выбранный элемент
					//arr[k][l] - перебираемый элемент
					
					if (arr[i][j] > arr[k][l])
					{
						int buffer = arr[i][j];
						arr[i][j] = arr[k][l];
						arr[k][l] = buffer;
					}
				}
			}
		}
	}
}
