#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

int main()
{
	int N = 0;
	int M = 0;
	int count = 0;
	string s_string;
	vector<string> v_compare;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> s_string;
		v_compare.push_back(s_string);
	}

	sort(v_compare.begin(), v_compare.end());

	for (int j = N; j < N + M; j++)
	{
		cin >> s_string;
		if (binary_search(v_compare.begin(), v_compare.end(), s_string))
		{
			count++;
		}
	}

	cout << count << "\n";

	return 0;
}
