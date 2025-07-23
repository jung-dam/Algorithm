#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    int index = 0;
    answer.push_back(arr[0]);
    
    for(int i = 0; i < arr.size(); i++)
    {
        if(answer[index] != arr[i])
        {
            answer.push_back(arr[i]);
            index++;
        }
    }
    
    return answer;
}