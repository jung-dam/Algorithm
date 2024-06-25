#include<string>
#include<stack>
#include <iostream>

using namespace std;

bool solution(string s)
{
    stack<char> st ;
    bool answer = true;
    
    for ( int i =0; i < s.size(); i++)
    {
        if(s[i] == '(')
        {
            st.push('(');
        }
        else
        {           
            if(!st.empty() && st.top() == '(')
            {
                st.pop();
            }
            else
            {
                st.push(')');
            }
            
        }
            
    }
     if(st.empty())
        return true;
    else
        return false;

}