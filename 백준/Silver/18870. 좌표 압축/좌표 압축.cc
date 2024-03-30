#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(void)
{
	int N = 0;
	int temp = 0;
	
	vector<int>ori_v(N); //원본 벡터
	vector<int>com_v(N); //비교 벡터

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		ori_v.push_back(temp) ;
		com_v.push_back(temp);
	}
	sort(com_v.begin(), com_v.end());
	com_v.erase( unique(com_v.begin(), com_v.end() ), com_v.end() );

	for (int i = 0; i < N; i++)
	{
		cout << (lower_bound(com_v.begin(), com_v.end(), ori_v[i]) - com_v.begin()) <<  " " ;
	}

	return 0;
}