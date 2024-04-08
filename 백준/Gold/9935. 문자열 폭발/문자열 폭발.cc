#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include<vector>
#include<queue>
using namespace std;

int main()
{
	string s = "";
	string del_s = "";
	string temp = "";
	cin >> s;
	cin >> del_s;

	for (int i = 0; i < s.size(); i++)
	{
		temp += s[i];
		if (del_s.size() <= temp.size())
		{
			if (temp.substr(temp.size() - del_s.size(), del_s.size()) == del_s)
			{
				temp.erase(temp.size() - del_s.size(), del_s.size());
			}
		}
	}
	if (temp.empty())
	{
		cout << "FRULA" << endl;
	}
	else
	{
		cout << temp << endl;
	}
	return 0;
}