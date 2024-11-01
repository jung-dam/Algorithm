#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int num = 0;
int visited[9] = { 0, };//방문 여부

int dfs(vector<vector<int>> dungeons, int k, int cnt) //던전, 현재피로도, 던전 탐험 수
{
    if (cnt > num)
    {
        num = cnt;
    }
    for (int i = 0; i < dungeons.size(); i++)
    {
        if ((visited[i] == 0) && ( dungeons[i][0] <= k) )
        {
            visited[i] = 1;
            dfs(dungeons, k - dungeons[i][1], cnt + 1);
            visited[i] = 0;
        }
    }
    return 0;
}

int solution(int k, vector<vector<int>> dungeons)
{
    dfs(dungeons, k, 0);
     return num;    
}