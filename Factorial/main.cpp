#include<iostream>
using namespace std;

long long Factorial(int n);

void main()
{
	setlocale(LC_ALL, "");
	int n = 0;
	cout << Factorial(n);
}

long long Factorial(int n)
{
	cout << "¬ведите число дл€ вычислени€ факториала: "; cin >> n;
	long long f = 1;
	for (int i = 1; i <= n; i++)
	{
		f *= i;
	}
	return f;

}