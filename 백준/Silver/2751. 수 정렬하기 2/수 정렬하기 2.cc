#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000000] = { 0, };

int main()
{
	//수 정렬하기 nlogn 정렬 알고리즘
	int N = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);

	for (int i = 0; i < N; i++)
	{
		cout << arr[i] <<"\n";
	}

	return 0;
}
