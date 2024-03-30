#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

int main()
{
	int N = 0;
	int begin = 0;
	int end = 0;
	vector<pair<int, int>>time;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> begin >> end;
		time.push_back(make_pair(end, begin)); //종료 시점 , 시작 시점 쌍으로 벡터에 저장
	}
	sort(time.begin(), time.end()); //종료시점이 빠른 순으로 정렬

	int first_time = time[0].first; // 제일 빠른 종료시점 시간
	int count = 1;

	for (int i = 1; i < N; i++)
	{
		if (first_time <= time[i].second) // i번째 종료시간 보다 i+1번째 시작시간이 클 때
		{
			first_time = time[i].first;
			count++;
		}
	}
	cout << count << "\n";
	return 0;
}
