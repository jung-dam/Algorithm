#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
int arr[1000001] = { };
int F_arr[1000001] = { };
int NGF[1000001] = { };

int main()
{
	int N = 0;
	cin >> N;

	stack<int> s;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		F_arr[arr[i]]++;
	}

	for (int i = N-1; i >= 0; i--)
	{
		while (!s.empty() && F_arr[s.top()] <= F_arr[arr[i]])
		{
			s.pop();
		}
		if (s.empty())
		{
			NGF[i] = -1;
		}
		else
		{
			NGF[i] = s.top();
		}
		s.push(arr[i]);
	}

	for (int i = 0; i < N; i++)
	{
		cout << NGF[i] << " ";
	}

	return 0;
}