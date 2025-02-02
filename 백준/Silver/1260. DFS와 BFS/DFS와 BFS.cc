#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int N, M, V;
int graph[1001][1001];
bool visit[1001];
queue <int> q;

void dfs(int v)
{
	visit[v] = true;
	cout << v << " ";

	for (int i = 1; i <= N; i++)
	{
		if (graph[v][i] == 1 && visit[i] == 0)
		{
			dfs(i);
		}
	}
}

void bfs(int v)
{
	q.push(v); //시작 노드 큐에 넣음
	visit[v] = true;
	cout << v << " ";
	while (!q.empty())
	{
		v = q.front();
		q.pop();

		for (int i = 1; i <= N; i++)
		{
			if (graph[v][i] == 1 && visit[i] == 0)
			{
				q.push(i);
				visit[i] = true;
				cout << i << " ";
			}
		}
	}


}

void reset()
{
	for (int i = 1; i <= N; i++)
	{
		visit[i] = false;
	}
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++)
	{
		int x, y;
		cin >> x >> y;
		graph[x][y] = 1;
		graph[y][x] = 1; //양방향 연결되어 있음
	}

	reset();
	dfs(V);

	cout << '\n';

	reset();
	bfs(V);

	return 0;
}