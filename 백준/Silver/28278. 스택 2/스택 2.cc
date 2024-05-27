#include <iostream>
#include <stack>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin>>N;

    stack<int> S;

    int order;
    while(N--){
        cin>>order;
        switch(order){
            case 1:
                int num;
                cin>>num;
                S.push(num);
                break;
            case 2:
                if(!S.empty()){
                    cout<<S.top()<<'\n';
                    S.pop();
                    // 빼낸 요소를 출력해야 하기 때문에 pop이 나중에 선언되어야 한다.
                }else{
                    cout<<-1<<'\n';
                }
                break;
            case 3:
                cout<<S.size()<<'\n';
                break;
            case 4:
                if(!S.empty()){
                    cout<<0<<'\n';
                }else{
                    cout<<1<<'\n';
                }
                break;
            case 5:
                if(!S.empty()){
                    cout<<S.top()<<'\n';
                }else{
                    cout<<-1<<'\n';
                }
                break;
        }
    }
    return 0;
}