#include<iostream>
#include<string>
using namespace std;
int a, b, c, d, e, f;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> a >> b >> c >> d >> e >> f;

	for (int i = -999; i <= 999; i++) {
		for (int j = -999; j <= 999; j++) {
			if ((i * a + j * b == c) && (i * d + j * e == f)) {
				cout << i << " " << j;
				return 0;
			}
			else continue;
		}
	}
}