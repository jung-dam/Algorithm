#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int N = 0;
	int A = 0;
	int min = 1000000;
	int max = -1000000;
	
	string b = " ";
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> A;
		if (min > A)
		{
			min = A;
		}
		if (max < A)
		{
			max = A;
		}
	}
	cout << min << " " << max;

	return 0;
}