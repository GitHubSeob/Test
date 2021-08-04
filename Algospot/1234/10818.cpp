/*
Å×½ºÆ®
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N = 0;
	int num = 0;
	int big = -1000000;
	int small = 1000000;
	cin >> N;

	for (int x = 1; x <= N; ++x) {
		cin >> num;
		if (small > num) small = num;
		if (big < num)big = num;
	}
	cout << small << " " << big;
}