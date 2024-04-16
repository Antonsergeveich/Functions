#include"selection_Sort.h"

void selection_Sort(int arr[], const int n)
{
	for (int i = 0; i < n; i++) // ������� i �������� ������� ������� � ������� ����� �������� ����������� ��������
	{
		for (int j = i + 1; j < n; j++) // ������� j ���������� ���������� �������� �������
		{
			//arr[i] ��������� ������� �������
			//arr[j] ������������ ������� �������
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
	//��� ��� ����� �������� �������
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			//��� ��� ����� ���������� ���������� �������� � ������ ������������ ��������
			for (int k = i; k < ROWS; k++)
			{
				for (int l = k == i ? j + 1 : 0; l < COLS; l++)
				{
					/*if (k == i && l == 0)l = j + 1;
					if (l == COLS)break;*/
					//arr[i][j] - ��������� �������
					//arr[k][l] - ������������ �������
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