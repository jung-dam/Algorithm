#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define MAX 9  //(1 ≤ M ≤ N ≤ 8)
using namespace std;

int N = 0;
int M = 0;
int arr[MAX]; //출력값 배열
bool visited[MAX]; //백트래킹하며 이미 방문된 숫자인지 판별하는 배열

void dfs(int depth)
{
	/*
			 1
	2        3        4
  3  4    2  4     2  3
 4    3  4    2   3    2
*/
	if (depth == M)
	{
		for (int i = 0; i < M; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++)//숫자 i가 아직 선택 안됨
	{
		if (!visited[i])
		{
			visited[i] = true; // 숫자 i 선택
			arr[depth] = i; // 몇 번째 depth(숫자 갯수)위치에  i  저장
			dfs(depth + 1); //다음 숫자 선택하기 위해 재귀 호출
			visited[i] = false; //현재 선택한 숫자i를 선택하지 않음을 표시, 다음 순열에서 사용하기 위함
		}
	}
}

int main(void)
{
	cin >> N >> M;

	dfs(0);


	return 0;
}

