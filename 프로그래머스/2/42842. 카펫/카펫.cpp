#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int y_w = 0;
    int y_h = 0;
    int b_w = 0;
    int b_h = 0;
    int w = 0;
    int h = 0;
    int b_area = brown;
    int y_area = yellow;
    int area = b_area + y_area; //전체 면적
    vector<pair<int,int>> v;
    
    //전체 면적 약수 조합 구하기(= (b_w,b_h) 조합)
    for(int i = 3; i <= area; i++)//세로 최소값이 3이기 때문
    {
        if(area % i == 0) //약수들만
        {
            int num = area / i;
            if(num >= i) 
            {
                v.push_back(make_pair(num,i));
            }
        } 
    }

    for(int j = 0; j < v.size(); j++)
    {
        w = v[j].first *2;
        h = (v[j].second *2) - 4;
        b_w = v[j].first;
        b_h = v[j].second;
        y_w = v[j].first - 2;
        y_h = v[j].second - 2; 
        
        if( ((y_w * y_h) == y_area) && ((w + h) == b_area) )
        {
            answer.push_back(v[j].first);
            answer.push_back(v[j].second);
            break;
        }
    }  
    return answer;
}