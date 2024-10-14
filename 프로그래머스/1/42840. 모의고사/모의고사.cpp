#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer; 
    vector<vector<int>> math{{1, 2, 3, 4, 5},
                             {2, 1, 2, 3, 2, 4, 2, 5},
                             {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}}; //수포자들의 찍는 방식
    int count[3] = {0, }; //맞춘 개수
    
    for(int i = 0; i < answers.size(); i++)
    {
        if(answers[i] == math[0][i % math[0].size()])
        {
            count[0]++;
        }
        if(answers[i] == math[1][i % math[1].size()])
        {
            count[1]++;
        }
        if(answers[i] == math[2][i % math[2].size()])
        {
            count[2]++;
        }
    }
    
    int max = *max_element(count, count+3 ); //제일 높은 점수찾기
    
    //제일 높은 점수와 같은 사람 찾아서 정답에 추가, 앞에서 부터 추가했기때문에 정렬 필요없음
    for (int i = 0; i < 3; i++)
    {
        if (max == count[i])    
        {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}