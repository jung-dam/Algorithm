#include <string>
#include <vector>
#include <queue>

using namespace std;

bool isOnediff(string a, string b)
{
    int diff = 0; //다른 문자 개수
    for(int i = 0; i < a.length(); i++)
    {
        if(a[i] != b[i]) // 문자가 서로 다를 때
        {
            diff++;
        }
    }
    
    //한 글자만 다를 때
    if(diff == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int solution(string begin, string target, vector<string> words) {
    queue<pair<string, int>> q; //현재단어, 변환횟수
    vector<bool> visited(words.size(), false);
    
    q.push({begin, 0}); 
    
    while(!q.empty())
    {
        string current = q.front().first;
        int step = q.front().second;
        q.pop();
        
        //목표 단어와 일치
        if(current == target)
        {
            return step;
        }
        
        for(int i = 0; i < words.size(); i ++)
        {
            //방문하지 않고, 한 글자만 다를 때
            if(!visited[i] && isOnediff(current, words[i]))
            {
                visited[i] = true;
                q.push({words[i], step+1});
            }
        }
    }
    
    
    return 0;
}