#include<iostream>
using namespace std;

double Power(double a, int n);

void main()
{
	setlocale(LC_ALL, "");
	double a=0; //��������� �������
	int n=0; //���������� �������
	cout << Power(a, n);
}

double Power(double a, int n)
{
	
	double N = 1; //�������
	cout << "������� ��������� �������: "; cin >> a;
	cout << "������� ���������� �������: "; cin >> n;
	if (n < 0)
	{
		a = 1 / a;
		n = -n;
	}
	for (int i = 0; i < n; i++)
	{
		N *= a;
	}
	return N;
}