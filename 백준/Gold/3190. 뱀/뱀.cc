#include <iostream>
#include <queue>
using namespace std;
int main() 
{
	int N = 0;//보드의 크기
	int K = 0;//사과의 개수
	int L = 0;//뱀의 방향 변환 횟수
	int t1 = 0;//시간
	int t2 = 0;//사과 좌표
	char d3; ///방향 변환 문자열
	int cnt = 0; 
	int x = 0;//현재 좌표
	int y = 0;
	//int bt1 = 0;
	int dx[4] = { 1, 0, -1, 0 }; // 우, 하, 좌, 상
	int dy[4] = { 0, 1, 0, -1 }; //뱀이 오른쪽 방향으로 출발한다고 했으니 우방향부터 좌표 시작
	int dir = 0;

	queue<pair<int, int>> q; //뱀의 몸 좌표 입력할 큐
	int map[102][102] = { 0,  }; //맵의 좌표 및 사과 좌표
	bool visit[102][102] = { false }; //뱀이 지나간 자리 표시

	q.push(make_pair(x, y)); //처음좌표 추가하기 (0,0)

	cin >> N;
	cin >> K;

	//사과의 위치
	for (int i = 0; i < K; i++) 
	{
		cin >> t1 >> t2;
		map[t1-1][t2-1] = 1;//사과 위치 map에 대입
		//문제에선 원점(1,1) 나는 (0,0)으로 map 보기 편하게 수정
	} 

	cin >> L;

	//뱀의 방향 변황 정보
	for (int i = 0; i < L; i++) 
	{
		//시작시간, 왼쪽(L)오른쪽(D)
		cin >> t1 >> d3;

		while (cnt < t1 || i == L - 1) 
		{
			// 마지막 입력까지 게임이 끝나지 않을 경우 뱀을 끝날때까지 보내줘야함.
			cnt++;
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			// 게임이 끝나지 않을 조건
			if (nx >= 0 && ny >= 0 && nx < N && ny < N && !visit[ny][nx]) 
			{
				// 사과를 먹었을 때
				if (map[ny][nx] == 1) 
				{ 
					map[ny][nx] = 0; // 사과 없애주고
					q.push(make_pair(nx, ny)); // 몸 좌표에 추가
					visit[ny][nx] = true; // 몸 있다는걸 좌표 표시
				}
				else 
				{// 사과 없을 때
					q.push(make_pair(nx, ny));
					visit[ny][nx] = true; //nx,ny 순서 다시 확인하기

					// 꼬리 부분없애주기
					visit[q.front().second][q.front().first] = false;
					q.pop();
				}
			}
			else 
			{
				cout << cnt << "\n";
				return 0;
			}

			//현재 위치 변경
			x = nx;
			y = ny;

			if (cnt == t1) 
			{
				if (d3 == 'D')
				{ // 우측 회전
					dir = (dir + 1) % 4; //dxdy[] 상우하좌 방향 맞춰 바뀌도록
				}
				else 
				{ // 좌측 회전
					dir = (dir + 3) % 4;
				}
			}
		}
	}
	return 0;
}