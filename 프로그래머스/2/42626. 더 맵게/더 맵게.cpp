#include <string>
#include <vector>
#include <queue>

using namespace std;
//섞은 음식의 스코빌 지수 = 가장 맵지 않은 음식의 스코빌 지수 + (두 번째로 맵지 않은 음식의 스코빌 지수 * 2)
int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int> > pq;
    
    for(int i = 0; i < scoville.size(); i++)
    {
        pq.push(scoville[i]);
    }
    while(pq.top() < K)
    {
        //모든 음식의 스코빌 지수를 K 이상으로 만들 수 없는 경우
        if(pq.size() < 2)
            return -1;
        
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        int c = a + (b*2);
        pq.push(c);
        
        answer++;
        
    }
    return answer;
}