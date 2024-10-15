#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b)
{
   return a + b > b + a;
    //return a.front() > b.front(); 스트링에서 앞자리만 대소 비교할라했는데 잘못된 생각
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> temp;
    
    for(int i = 0; i < numbers.size(); i++)
    {//벡터요소값 string으로 받아서 다시 벡터에 넣기
        temp.push_back(to_string(numbers[i])); 
    }
    
    sort(temp.begin(), temp.end(), cmp);
    
    if (temp.at(0) == "0")        
    {
        return "0";
    }
    for(int j = 0; j < temp.size(); j++)
    {
        answer += temp[j];
    }
  
    return answer;
}