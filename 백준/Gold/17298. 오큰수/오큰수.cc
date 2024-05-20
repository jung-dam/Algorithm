#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
int arr[1000001] = {  };
int big_arr[1000001] = {  };

int main()
{
	int N = 0;
	stack<int> num;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];	
	}
	for (int i = N-1; i >=0; i--)
	{
		while (!num.empty()&& num.top() <= arr[i])
		{
			num.pop();
		}
		if (num.empty())
		{
			big_arr[i] = -1;
		}
		else
		{
			big_arr[i] = num.top();
		}
		num.push(arr[i]);
	}

	for (int i = 0; i < N; i++)
	{
		cout << big_arr[i] << " ";
	}
	
	return 0;
}