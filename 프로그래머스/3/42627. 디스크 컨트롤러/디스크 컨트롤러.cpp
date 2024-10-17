#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct cmp {
	bool operator()(vector<int> a, vector<int> b) {
		return a.at(1) > b.at(1); //b a 순으로 오름차순
	}
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int time = 0; //현재 작업시간
    int index = 0;
	priority_queue<vector<int>, vector<vector<int>>, cmp> pq;

	sort(jobs.begin(), jobs.end()); //시작시간을 기준으로 오름차순 정렬

	while (!pq.empty() || jobs.size() > index)
	{
		if (jobs.size() > index)
		{
			if (time >= jobs[index][0] )
			{
				pq.push(jobs[index]);
				index++;

				continue;
			}

		}
		if (!pq.empty())
		{
			time += pq.top()[1];

			answer += (time - pq.top()[0]);
			pq.pop();
		}
		else
		{
			time = jobs[index][0];
		}
	}	
	// 시간 평균 내기
	answer /= jobs.size();

    return answer;
}