#include <string>
#include <vector>

using namespace std;

void dfs(vector<int> &numbers, int target, int idx, int sum, int &count)
{
    if(idx == numbers.size()) //모든 숫자 사용했을 때
    {
        if(sum == target) //결과가 target이면 정답 증가
            count++;
        
        return;
    }
    
    //현재 숫자에 +붙여서 사용
    dfs(numbers, target, idx+1, sum + numbers[idx], count);
    //현재 숫자에 -붙여서 사용 
    dfs(numbers, target, idx+1, sum - numbers[idx], count);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    dfs(numbers, target, 0, 0, answer);
    return answer;
}