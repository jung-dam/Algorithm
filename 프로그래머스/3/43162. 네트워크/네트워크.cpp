#include <string>
#include <vector>

using namespace std;

bool visited[201] = {0, };
int count = 0;

void dfs(int n , vector<vector<int>> &computers)
{
    visited[n] = true;
    
    for(int i = 0; i < computers.size(); i++)
    {
        if( (!visited[i]) && (computers[n][i] == 1) )
        {
            dfs(i, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    
    for(int a = 0; a < n; a++)
    {
        if(!visited[a])
        {
            dfs(a, computers);
            count++; //dfs 시작한 횟수가 곧 네크워크 개수
        }
    }
        
    return count;
}