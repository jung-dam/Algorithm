#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    //완주자가 없을 경우
    if (completion.empty())
    {
        answer = participant[0];
        return answer;
    }
    
    for(int i = 0; i < participant.size(); i++)
    {

        if(participant[i] != completion[i])
        {
            answer = participant[i];
            break;
        }        
    }
    
    return answer;
}