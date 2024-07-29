#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int N = 0;
vector<vector<int>> edges;
vector<int> isVisited;
int dp[1000001][2];//최소 얼리의 개수

void dfs(int node)
{
	isVisited[node] = 1;
	dp[node][0] = 0; //본인 얼리 x -> 얼리 개수 0
	dp[node][1] = 1; //본인 얼리 o -> 얼리 개수 1

	for (int i = 0; i < edges[node].size(); i++)
	{
		int child_node = edges[node][i];

		//자식노드로 내려가기
		if (isVisited[child_node] == 0) 
		{
			dfs(child_node);

			//현재 노드가 얼리가 아니면 자식은 필수로 얼리노드여야함
			//현재 노드가 얼리면 자식 중 최소값 +
			dp[node][0] += dp[child_node][1];
			dp[node][1] += min(dp[child_node][0], dp[child_node][1]);
		}
	}
}

int main(void)
{
	int u, v;

	cin >> N;

	edges.resize(N + 1);
	isVisited.resize(N + 1);

	for (int i = 0; i < N - 1; i++)
	{
		cin >> u >> v;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	dfs(1);

	cout << min(dp[1][0], dp[1][1]) << "\n";

	return 0;
}