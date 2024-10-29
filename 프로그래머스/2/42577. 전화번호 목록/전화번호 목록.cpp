#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b)
{
    return a.size() < b.size();
}
    
bool solution(vector<string> phone_book) {
    bool answer = true;
    string str = "";
    string cmpstr = "";

    if(phone_book.size() == 1)
    {
        return answer;
    }
    sort(phone_book.begin(), phone_book.end());

    for (int i = 0; i < phone_book.size()-1; i++)
    {
        // int j = i + 1;
        // for ( j ; j < phone_book.size() ; j++)
        // {
            str = phone_book[i];
            cmpstr = phone_book[i+1];
            if (cmpstr.find(str) == 0)
            {
                answer = false;
                return answer;
            }
        // }     
    }
    return answer;
}