#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int a = 0;
	int b = 0;
	int num = 0; //색종이 수
	int sum = 0; //면적 수
	bool paper[100][100] = {0, };

	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> a >> b;

		for (int x = a; x < a+10; x++)
		{
			for (int y = b; y < b + 10; y++)
			{
				if (paper[x][y])
				{
					continue;
				}
				paper[x][y] = 1;
				sum++;
			}			
		}
	} 

	cout << sum;

	return 0;
}