#include <iostream>
#include <cmath>
#include<algorithm>
using namespace std;

int main() {

    int T = 0;
    long x = 0;
    long y = 0;

    cin >> T;

    for (int i = 0; i < T; i++)
    {
        cin >> x >> y;
        double dist = y - x; //두 지점 사이의 거리
        double dpow = sqrt(dist); //거리의 제곱근
        int pow = round(sqrt((dist))); //거리의 제곱근 반올림


        if (dpow <= pow)
        {
            cout << pow * 2 - 1 << "\n";
        }
        else
        {
            cout << pow * 2 << "\n";
        }
    }
	return 0;
}