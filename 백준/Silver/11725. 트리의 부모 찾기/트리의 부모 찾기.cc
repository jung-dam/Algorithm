#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include<vector>
#include<queue>
using namespace std;
vector<int> edges[100001];
bool isVisited[100001];
int arr[100001];

void dfs(int node)
{
	isVisited[node] = true;

	for (int i = 0; i < edges[node].size(); i++)
	{
		int child_node = edges[node][i];

		if (!isVisited[child_node])
		{
			arr[child_node] = node;
			dfs(child_node);
		}
	}
}

int main()
{
	int x, y;
	int N = 0;
	cin >> N;

	for (int i = 0; i < N-1; i++)
	{
		cin >> x >> y;

		edges[x].push_back(y);
		edges[y].push_back(x);
	}

	dfs(1);

	for (int i = 2; i <= N; i++)
		cout << arr[i] << "\n";

	return 0;
}
