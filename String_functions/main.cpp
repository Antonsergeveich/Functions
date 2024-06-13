#include<iostream>
using namespace std;

using std::cout;
using std::cin;
using std::endl;

void ASCII();

void main()
{
	setlocale(LC_ALL, "");
	ASCII();
}

void ASCII()
{
	for (int i = 0; i < 256; i++)
	{
		cout << i << "\t" << (char)i << endl;
	}
}