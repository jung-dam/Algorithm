#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 501;

int dp[MAX][MAX];

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    //초기 지정.
    dp[0][0] = triangle[0][0];

    for (int i = 1; i < triangle.size(); i++) 
    {
        for (int j = 0; j <= i; j++) 
        {
            //1) 행에서 젤 왼쪽인 경우엔 바로 위에꺼
            if (j == 0) dp[i][j] = dp[i - 1][j] + triangle[i][j];
            //2) 행에서 젤 오른쪽인 경우엔 왼쪽 위에꺼
            else if (j == i) dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
            //나머지
            else dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];

            // dp 배열의 제일 마지막 줄 중 가장 큰 값
            answer = max(answer, dp[i][j]);
        }
    }
    return answer;
}