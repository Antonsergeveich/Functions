#include<iostream>
using namespace std;

long long Factorial(short n);

void main()
{
	setlocale(LC_ALL, "");
	short n = 0;
	cout << "Введите число для вычисления факториала: "; cin >> n;
	cout << Factorial(n);
}

long long Factorial(short n)
{
	long long f = 1;
	for (int i = 1; i <= n; i++)
	{
		f *= i;
	}
	return f;
}