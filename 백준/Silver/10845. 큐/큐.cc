#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int main(void)
{
	int N = 0;
	queue<int> que;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		string command = " ";

		cin >> command;
		if (command == "push")
		{
			int num = 0;
			cin >> num;
			que.push(num);
		}
		else if (command == "pop")
		{
			if (que.empty() == 1)
			{
				cout << "-1" << "\n";
			}
			else
			{
				cout << que.front() << "\n";
				que.pop();
			}
		}
		else if (command == "size")
		{
			cout << que.size() << "\n";
		}
		else if (command == "empty")
		{
			cout << que.empty() << "\n";
		}
		else if (command == "front")
		{
			if (que.empty() == 1)
			{
				cout << "-1" << "\n";
			}
			else
			{
				cout << que.front() << "\n";
			}
		}
		else if (command == "back")
		{
			if (que.empty() == 1)
			{
				cout << "-1" << "\n";
			}
			else
			{
				cout << que.back() << "\n";
			}

		}
	}
	return 0;
}