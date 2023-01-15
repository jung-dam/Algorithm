#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N = 0;
    cin >> N;

    int cnt = N;
    string str = "";
    for (int i = 0; i < N; i++)   
    {
        cin >> str;
        for(int j = 0; j < str.length(); j++)
        {
            if (str[j] != str[j+1])
            {
                for(int k = j+1; k < str.length(); k++)
                {
                    if(str[j] == str[k])
                    {
                        cnt-- ;
                        goto STOPCNT;
                    }
                }
            }
        }
        STOPCNT: ;
    }

    cout << cnt ;
    return 0;
}