#include<iostream>
using namespace std;

using std::cout;
using std::cin;
using std::endl;

void ASCII();
void to_lower(char str[]); //��������� ������ � ������ �������
void to_upper(char str[]); //��������� ������ � ������� �������
void shrink(char str[]);//������� �� ������ ������ �������


void main()
{
	setlocale(LC_ALL, "");
	//ASCII();
	char str[] = " Hello Pap  and   Mam";
	printf(str);
	cout << endl;
	to_lower(str);
	printf(str);
	cout << endl;
	to_upper(str);
	printf(str);
	cout << endl;
	shrink(str);
	printf(str);

}

void ASCII()
{
	for (int i = 0; i < 256; i++)
	{
		cout << i << "\t" << (char)i << endl;
	}
}

void to_lower(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z' || str[i] >= '�' && str[i] <= '�')
		{
			str[i] += 32;
		}
		else if (str[i] == '�')str[i] += 16;
	}
}

void to_upper(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= '�' && str[i] <= '�')
		{
			str[i] -= 32;
		}
		else if (str[i] == '�')str[i] -= 16;
	}
}

void shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ' && str[i + 1] == ' ')
		{
			for (int j = i; str[j]; j++)//�������� ����� ������ �����
			{
				str[j] = str[j + 1];
			}
		}
	}
}
