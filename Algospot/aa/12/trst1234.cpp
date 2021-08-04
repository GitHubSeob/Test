/*
Ű
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n = 0;
	cin >> n;
	vector<int>DP(n + 1, 0);
	DP[1] = 1;
	DP[2] = 3;
	int x = 0;
	for (x = 3; x <= n; ++x) {
		DP[x] = (DP[x - 2] * 2 + DP[x - 1]) % 10007;
	}

	cout << DP[n];
}