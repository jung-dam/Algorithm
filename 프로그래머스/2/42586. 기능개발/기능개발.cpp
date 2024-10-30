#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int pro = 100;
    int day = 1;
    
    for(int i = 0; i < progresses.size(); i++)
    {
        int num = 1;
        int process = 0;
        process = (pro - progresses[i]) / speeds[i]; 

        if( ((pro - progresses[i]) % speeds[i]) != 0) 
        {
            process++;
        }
        
        if (process <= day)
        {
            ++answer.back();
        }
        else
        {
            answer.push_back(num);
            day = process;
        }
        
    }
    
    return answer;
}