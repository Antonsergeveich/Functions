#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<ctype.h> //Для проверки, является ли символ цифрой
#include<Windows.h>	

using namespace std;
using std::cout;
using std::cin;
using std::endl;

void ASCII();
int StrLen(char str[]);//Определяет длину строки
void to_lower(char str[]); //переводит строку в нижний регистр
void to_upper(char str[]); //переводит строку в верхний регистр
void capitalize(char str[]);//Первую букву каждого слова в предложении делает заглавной
void shrink(char str[]);//Удаляет из строки лишние пробелы
void remove_symbol(char str[], char symbol);
bool is_palindrome(char str[]); //Определяет, является ли строка палиндромом
bool is_int_number(char str[]);//Определяет, является ли строка целым числом
int to_int_number(char str[]);//Если строка является целым числом, возвращает его значение
bool is_bin_number(char str[]);//Определяет, является ли строка двоичным числом
void insert_spaces(char str[]);
char* dec_to_bin(int decimal);
int bin_to_dec(char str[]);//Если строка является двоичным числом, возвращает его десятичное значение
int bin_to_dec1(char str[]);
bool is_hex_number(char str[]); //определяет, является ли строка шестнадцатеричным числом
int hex_to_dec(char str[]);//Если строка является шестнадцатеричным числом, возвращает его десятичное значение
int  hex_to_dec1(char hex[]);

void main()
{
	setlocale(LC_ALL, "");
	system("CHCP 1251");
	system("CLS");
	char strx[] = { 'H', 'o', 'p', ' ', 'l', 'a', 'i', ' ', 'l', 'a', 'l', 'a', ' ', 'l', 'a', 'i', 0};
	char strm[] = "Helleh";
	const int n = 256;
	char strt[n];
	cout << "Введите строку: ";
	/*SetConsoleCP(1251);
	cin >> strt;*/
	cin.getline(strt, n);
	//ASCII();
	char str[] = "Hello Pap  and   Mam";
	char strch[] = "FC99";
	printf(str);
	cout << endl;
	/*capitalize(strch);
	cout << str << endl;*/
	cout << "Размер строки в Байтах:  " << sizeof(str) << endl;
	cout << "Размер строки в символах:" << StrLen(str) << endl;
	cout << endl;
	to_lower(strx);
	printf(strx);
	cout << endl;
	to_upper(str);
	printf(str);
	cout << endl;
	shrink(str);
	printf(str);
	cout << endl;
	cout << (is_int_number(strch) ? "Число" : "НЕ число") << endl;
	cout << to_int_number(strch) << endl;
	cout << "Строка " << (is_bin_number(strch) ? "" : "НЕ ") << "является двоичным числом" << endl;
	cout << strch << "(bin) = " << bin_to_dec(strch) << "(dec)" << endl;
	cout << "Строка" << (is_hex_number(strch) ? "" : " НЕ") << " является шестнадцатеричным числом" << endl;
	cout << strch << "(Hex) = " << hex_to_dec(strch) << "(Dec)" << endl;
	cout << is_palindrome(str) << endl;
	if (is_palindrome(strm))
	{
		cout << "Введенная строка - палиндром" << endl;
	}
	else
	{
		cout << "Введенная строка - НЕ палиндром" << endl;
	}
	cout << strm << endl;
}

void ASCII()
{
	for (int i = 0; i < 256; i++)
	{
		cout << i << "\t" << (char)i << endl;
	}
}

int StrLen(char str[])
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}

void to_lower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'А' && str[i] <= 'Я')
		{
			str[i] += 32;
		}
		else if (str[i] == 'Ё')str[i] += 16;
	}
}

void to_upper(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'а' && str[i] <= 'я')
		{
			str[i] -= 32;
		}
		else if (str[i] == 'ё')str[i] -= 16;
	}
}

void capitalize(char str[])
{
	to_lower(str);
	if (str[0] >= 'a' && str[0] <= 'z' || str[0] >= 'а' && str[0] <= 'я')str[0] -= 32;
	else if (str[0] == 'ё')str[0] -= 16;
	for (int i = 1; str[i]; i++)
	{
		if ((str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'а' && str[i] <= 'я') && str[i - 1] == ' ')str[i] -= 32;
		else if (str[i] == 'ё' && str[i - 1] == ' ')str[i] -= 16;
	}
}

void shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ' && str[i + 1] == ' ')
		{
			for (int j = i; str[j]; j++)//Сдвигает часть строки влево
			{
				str[j] = str[j + 1];
			}
		}
	}
}

void remove_symbol(char str[], char symbol)
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == symbol)
		{
			for (int j = i; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
		}
	}
}

bool is_palindrome(char str[])
{
	//Определяем длину строки
	int size = StrLen(str);
	char* buffer = new char[size + 1] {};
	//for (int i = 0; str[i]; i++)buffer[i] = str[i];
	strcpy(buffer, str);//String Copy
	//buffer - строка получатель
	//str - строка источник
	to_lower(buffer);
	remove_symbol(buffer, ' ');
	size = strlen(buffer);
	for (int i = 0; i < size / 2; i++)
	{
		if (buffer[i] != buffer[size - 1 - i])
		{
			delete[] buffer;
			return false;
		}
	}
	delete[] buffer;
	return true;
}

bool is_int_number(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != ' ')return false;
		if (str[i] == ' ' && str[i + 1] == ' ')return false;
	}
	return true;
}

int to_int_number(char str[])
{
	if (!is_int_number(str))return 0;
	int number = 0;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == ' ')continue;
		number *= 10; //Сдвигаем число на разряд влево (освобождаем младший разряд)
		number += str[i] - 48;
	}
	return number;
}

bool is_bin_number(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != ' ')
			return false;
		if (str[i - 1] == ' ' && str[i] == ' ' && str[i + 1] == ' ')
			return false;
	}
	return true;
}

char* dec_to_bin(int decimal)
{
	//1) Определим количество двоичных разрядов:
	int capacity = 0;
	int buffer = decimal;
	for (; buffer; capacity++)
	{
		buffer /= 2;
		if (capacity % 4 == 0)capacity++;
	}
	//2) Выделяем память под двоичное число:
	char* bin = new char[capacity + 1] {};
	//3) Получаем разряды двоичного числа, и сохраняем их в строку:
	for (int i = 0, digit = 0; decimal; i++, digit++)
	{
		//if (i % 4 == 0)
		//{
		//	//bin[i] = ' ';
		//}
		//else
		{
			bin[i] = decimal % 2 + '0';	//Получаем младший разряд числа:
			decimal /= 2;				//Убираем младший разряд из числа
		}
	}
	insert_spaces(bin);
	return bin;
}
int bin_to_dec1(char str[])
{
	if (!is_bin_number(str))return 0;
#ifdef DEBUG
	int decimal = 0;	//Конечное десятичное число
	int weight = 1;		//Весовой коэффициент разряда 2^n;
	int capacity = strlen(str);	//Разрядность двоичного числа
	for (int i = capacity - 1; i >= 0; i--)
	{
		decimal +=
	}
#endif // DEBUG

	int decimal = 0;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != ' ')
		{
			decimal *= 2;
			decimal += str[i] - '0';
		}
	}
	return decimal;
}

int bin_to_dec(char str[])
{
	if (!is_bin_number(str))return 0;
	int n = StrLen(str);//Разрядность числа
	int decimal = 0;  //Конечное десятичноее число
	int weight = 1;   //Весовой коэффициент разряда
	for (int i = n - 1; i >= 0; i--)
	{
		if (str[i] != ' ')
		{
			decimal += (str[i] - 48) * weight;
			weight *= 2;
		}
	}
	return decimal;
}

bool is_hex_number(char str[])
{
	for (int i = str[0] == '0' && str[1] == 'x' ? 2 : 0; str[i]; i++)
	{
		if (
			!(str[i] >= '0' && str[i] <= '9') &&
			!(str[i] >= 'a' && str[i] <= 'f') &&
			!(str[i] >= 'A' && str[i] <= 'F') &&
			str[i] != ' '
			)
		{
			return false;
		}
		if (str[i] == ' ' && str[i + 1] == ' ')return false;
	}
	return true;
}

int hex_to_dec(char str[])
{
	if (!is_hex_number(str))return 0;
	int n = strlen(str);
	char* buffer = new char[n + 1] {};
	strcpy(buffer, str);
	to_upper(buffer);

	int decimal = 0;
	int weight = 1;
	for (int i = n - 1; i >= 0; i--)
	{
		if (buffer[i] == 'x' || buffer[i] == 'X')break;
		if (buffer[i] != ' ')
		{
			decimal += (buffer[i] - (isdigit(buffer[i]) ? 48 : 55)) * weight;
			weight *= 16;
		}
	}
	return decimal;
}
int  hex_to_dec1(char hex[])
{
	if (!is_hex_number(hex))return 0;
	int decimal = 0;
	for (int i = 0; hex[i]; i++)
	{
		decimal *= 16;
		if (hex[i] >= '0' && hex[i] <= '9')decimal += hex[i] - '0';
		if (hex[i] >= 'A' && hex[i] <= 'F')decimal += hex[i] - 'A' + 10;
		if (hex[i] >= 'a' && hex[i] <= 'f')decimal += hex[i] - 'a' + 10;
	}
	return decimal;
}

void insert_spaces(char str[])
{
	for (int i = 1, digit = 0; str[i]; i++)
	{
		if (digit % 4 == 0)
		{
			for (int j = strlen(str); j > i; j--)
			{
				str[j] = str[j - 1];
			}
			str[i] = ' ';
			continue;
		}
		digit++;
	}
}