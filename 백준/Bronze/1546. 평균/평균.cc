#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N = 0;
	double aScore[1001] = {0, };

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> aScore[i];
	} 

	sort(aScore, aScore + N);
	double sum = 0;

	for (int i = 0; i < N; i++)
	{
		sum = sum + (aScore[i] / aScore[N - 1]) * 100;
	}
	cout << sum / N ;

	return 0;
}