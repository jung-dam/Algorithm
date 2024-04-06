#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include<vector>
#include<queue>
using namespace std;

struct cmp
{
	bool operator()(int a , int b)
	{
		if (abs(a) == abs(b))
		{
			if (a > b)
			{
				return a > b; // true
			}
			else
			{
				return b < a; // false
			}
		}
		return abs(a) > abs(b); //절대값이 작은 순서대로
	}
};

int main()
{
	int N = 0;
	int X = 0;
	vector<int> v;
	priority_queue<int, vector<int>, cmp> pq; //true를 반환해야 swap

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> X;
		if (X == 0)
		{
			if (pq.empty())
			{
				cout << 0 << endl;
			}
			else
			{
				cout << pq.top() << endl;
				pq.pop();
			}
		}
		else
		{
			pq.push(X);
		}
	}
	return 0;
}
