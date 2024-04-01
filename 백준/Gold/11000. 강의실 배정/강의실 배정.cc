#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int main(void)
{
	int N = 0;
	int begin = 0;
	int end = 0;
	int classcount = 0;
	vector<pair<int, int>> v_time;
	priority_queue<int, vector<int>, greater<int>> pq;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> begin >> end;
		v_time.push_back(make_pair(begin, end));
	}
	sort(v_time.begin(), v_time.end());

	pq.push(v_time[0].second); //큐에 첫번째 수업 끝나는 시간 추가

	for (int i = 1; i < N; i++)
	{
		//두번째 수업 시작시간이 첫번째 수업 끝나는 시간보다 작을 때 -> 강의 시간이 겹칠 때
		if (pq.top() > v_time[i].first) //3 2
		{
			pq.push(v_time[i].second);
		}
		else 
		{
			pq.pop();
			pq.push(v_time[i].second);
		}
	}
	cout << pq.size();
	return 0;
}