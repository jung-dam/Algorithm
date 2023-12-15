#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int N = 10;
	int A = 0;
	int B = 42;
	int C = 0;
	int Arr[42] = { 0, };

	for (int i = 0; i < N; i++)
	{
		cin >> A;
		C = A% B ;
		if (C == 0)
		{
			Arr[C] = 1;
		}
		if (Arr[C] == NULL)
		{
			Arr[C] = C;
		}
	} 

	int count = 0;

	for (int i = 0; i < B; i++)
	{
		if (Arr[i] != NULL)
		{
			++count;
		}
	}
	cout << count ;

	return 0;
}