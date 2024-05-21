#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

int main()
{
	int N = 0;
	int big_bag = 5;
	int small_bag = 3;
	int bag = 0;

	cin >> N;

	while (N >= 0)
	{
		if ( (N % big_bag) == 0)
		{
			bag += N / big_bag;
			cout << bag << endl;
			return 0;

		}
		else
		{
			N -= small_bag;
			bag++;
		}
	}

	cout << -1 << endl;

	return 0;
}