#include <iostream>
using namespace std;
bool map[10000000];

int main()
{
    int n, tmp;
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;
        if (map[tmp-1])
        {
            cout << tmp;
            break;
        }
        else
            map[tmp-1] = true;
    }
    
    return 0;
}