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
void capitalize(char str[]);
void shrink(char str[]);//удаляет из строки лишние пробелы
void remove_symbol(char str[], char symbol);
bool is_palindrome(char str[]); //Определяет, является ли строка палиндромом
bool is_int_number(char str[]);//определяет, является ли строка целым числом
int to_int_number(char str[]);//Если строка является целым числом, возвращает его значение
bool is_bin_number(char str[]);//определяет, является ли строка двоичным числом
int bin_to_dec(char str[]);//Если строка является двоичным числом, возвращает его десятичное значение
bool is_hex_number(char str[]); //определяет, является ли строка шестнадцатеричным числом
int hex_to_dec(char str[]);//Если строка является шестнадцатеричным числом, возвращает его десятичное значение
void main()
{
	setlocale(LC_ALL, "");
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
	to_lower(str);
	printf(str);
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

int bin_to_dec(char str[])
{
	if(!is_bin_number(str))return 0;
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