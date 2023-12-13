#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int A[10000] = { 0, }; //정수 N개로 이루어진 수열 A
	int X = 0;
	int N = 0;
	// A에서 X보다 작은 수를 모두 출력

	cin >> N >> X;

	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	for (int j = 0; j < N; j++)
	{
		if (A[j] < X)
		{
			cout << A[j] << " ";
		}
	}

	return 0;
}
