#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int N = 0;
int M = 0;
int map[501][501];
int visit[501][501];
int ans = 0;
int dx[] = { -1, 0, 0, 1 }; //상좌우하? 좌표
int dy[] = { 0, -1, 1, 0 };//(-1,0) (0,-1),(0,1) (1,0)

void dfs(int x, int y, int depth, int curScore)
{
	if (depth == 4) { // 깊이가 4가 되면
		if (ans < curScore) ans = curScore;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i]; //현 위치에서 상하좌우 이동을 한 값을 대입해서 이동
		int ny = y + dy[i];

		// 도형 범위를 벗어나거나, 이미 방문한 위치는 무시
		if (nx < 1 || ny < 1 || nx > N || ny > M || visit[nx][ny])
		{
			continue;
		}
		visit[nx][ny] = 1;
		dfs(nx, ny, depth + 1, curScore+ map[nx][ny]);
		visit[nx][ny] = 0; //백트래킹 지금 이 좌표를 쓰지 않는다 다시 돌아가서 다른 상하좌우 탐색하기 위해 0으로 바꿈

	}

	if (x - 1 >= 1 && y - 1 >= 1 && x + 1 <= N)
	{ //ㅓ
		ans = max(ans, (map[x - 1][y] + map[x][y - 1] + map[x][y] + map[x + 1][y]));
	}
	if (x - 1 >= 1 && y + 1 <= M && x + 1 <= N)
	{ //ㅏ
		ans = max(ans, (map[x - 1][y] + map[x][y + 1] + map[x][y] + map[x + 1][y]));
	}
	if (y - 1 >= 1 && y + 1 <= M && x + 1 <= N)
	{ //ㅗ
		ans = max(ans, (map[x][y] + map[x + 1][y] + map[x + 1][y - 1] + map[x + 1][y + 1]));
	}
	if (y - 1 >= 1 && y + 1 <= M && x + 1 <= N)
	{ //ㅜ
		ans = max(ans, (map[x][y - 1] + map[x][y] + map[x][y + 1] + map[x + 1][y]));
	}

}

int main()
{
	memset(visit, 0, sizeof(visit));

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			visit[i][j] = 1;
			dfs(i, j, 1, map[i][j]);
			visit[i][j] = 0; //백트래킹
		}
	}

	cout << ans;

}