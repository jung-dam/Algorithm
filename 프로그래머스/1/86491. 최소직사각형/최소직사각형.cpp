#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    
    int w = 0;//가로
    int h = 0;//세로
    
    for(int i = 0; i < sizes.size(); i++)
    {
       if(sizes[i][0] > sizes[i][1])//가로가 세로보다 길 때
       {
           w = max(w, sizes[i][0]);
           h = max(h, sizes[i][1]);
       }
        else//세로가 가로보다 길 때
       {
           w = max(w, sizes[i][1]);
           h = max(h, sizes[i][0]);
       }
    }
    
    answer = w*h;
    
    return answer;
}