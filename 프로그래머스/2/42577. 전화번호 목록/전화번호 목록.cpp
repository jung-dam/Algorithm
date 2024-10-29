#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
    
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
            str = phone_book[i];
            cmpstr = phone_book[i+1];
            if (cmpstr.find(str) == 0)
            {
                answer = false;
                return answer;
            }     
    }
    return answer;
}