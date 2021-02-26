// Lab_7_3-2.cpp
// < Кузів Назар >
// Лабораторна робота № 7.3
// Опрацювання динамічних багатовимірних масивів(iтерація 2)
// Варіант 6

#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int** a, const int rowCount, const int colCount, const int Low, const int High)
{
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int rowCount, const int colCount)
{
	cout << endl;
	for (int i = 0; i < rowCount; i++)
	{
		for (int j = 0; j < colCount; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
bool IsMinInRowN(int** a, const int n, const int k, const int colCount)
{
	for (int j = 0; j < colCount; j++)
		if (a[n][j] < a[n][k])
		{
			return false;
		}
	return true;
}
bool IsMaxInColK(int** a, const int n, const int k, const int rowCount)
{
	for (int i = 0; i < rowCount; i++)
		if (a[i][k] > a[n][k])
		{
			return false;
		}
	return true;
}
void SaddlePoint(int** a, const int rowCount, const int colCount)
{
	cout << "Saddle points: min in row & max in col" << endl;
	cout << setw(4) << "No" << setw(6) << "Row" << setw(6) << "Col" << endl;
	int No = 0;
	for (int n = 0; n < rowCount; n++)
		for (int k = 0; k < colCount; k++)
			if (IsMinInRowN(a, n, k, colCount) && IsMaxInColK(a, n, k, rowCount))
			{
				cout << setw(4) << ++No << setw(6) << n << setw(6) << k << endl;
			}
}

int main()
{
	srand((unsigned)time(NULL));
	int Low =  0;
	int High = 100;

	int rowCount, colCount;

	cout << "rowCount = "; cin >> rowCount;
	cout << "colCount = "; cin >> colCount;

	int** arr = new int* [rowCount];

	for (int i = 0; i < rowCount; i++)
		arr[i] = new int[colCount];

	Create(arr, rowCount, colCount, Low, High);
	Print(arr, rowCount, colCount);
	SaddlePoint(arr, rowCount, colCount);
	cout << endl;

	for (int i = 0; i < rowCount; i++)
		delete[] arr[i];
	delete[] arr;

	return 0;
}