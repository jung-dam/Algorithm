#include <iostream>
using namespace std;
int main()
{
    string str = "";
    cin >> str;
    int alpha[26] = {0,};
    
    for (int i = 0; i < str.length(); i++)
    {
        //대문자일 때
        if(str[i] < 97)
        {
            alpha[ str[i] - 65 ]++;
        }
        else
        {
            alpha[ str[i] - 97 ]++;
        }
    }

    int max = 0;
    int maxindex = 0;
    int count = 0;
    int alphanum = 26;

    for (int i = 0; i < alphanum; i++)
    {
        
        if (max < alpha[i])
        {
            max = alpha[i];
            maxindex = i;
        }
    }
    for (int i = 0; i < alphanum; i++)
    {
        
        if (max == alpha[i])
        {
            count ++;
        }
    }

    if (count > 1)
    {
        cout << "?";
    }
    else
    {
        cout << (char)(maxindex+65);
    }


    return 0;
}