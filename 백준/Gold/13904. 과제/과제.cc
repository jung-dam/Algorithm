#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include<vector>
#include<queue>
using namespace std;
int arr[1001];

bool cmp(pair<int, int> a, pair<int,int> b)
{
	if (a.first > b.first)
	{
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	int N = 0;
	int d = 0;
	int w = 0;
	int count = 0;
	//memset(arr, 0, sizeof(arr));
	vector < pair<int, int>> v;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> d >> w;
		v.push_back(make_pair(w, d)); //점수 , 시간
	}
	sort(v.begin(), v.end(), cmp); //점수 순으로 정렬

	for (int i = 0; i < N; i++)
	{
		for(int j = v[i].second ;  j > 0; j-- )
		{
			if(arr[j] == 0) 
			{
				arr[j] = v[i].first; //마감일 위치 배열에 점수값 넣기
				count += v[i].first;
				break;
			}
			//else 마감일에 다른 점수가 있다? -> 더 높은 점수의 과제가 자리를 차지했다
		}
	}
	cout << count << endl;
	return 0;
}