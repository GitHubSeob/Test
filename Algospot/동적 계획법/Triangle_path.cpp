#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int x, y;
int DP[100][100] = { 0, };


int main() {
	int C = 0;
	cin >> C;

	int n = 0;
	int num = 0;


	while (C-- > 0) {
		cin >> n;
		vector<vector<int>>Arr(n, vector<int>(0, 0));
		for (y = 0; y < n; ++y) {
			for (x = 0; x <= y; ++x) {
				cin >> num;
				Arr[y].push_back(num);
				DP[y][x] = 0;
			}
		}

		DP[0][0] = Arr[0][0];
		for (y = 0; y < n - 1; ++y) {
			for (x = 0; x <= y; ++x) {
				DP[y + 1][x] = max(DP[y + 1][x], DP[y][x] + Arr[y + 1][x]);
				DP[y + 1][x + 1] = DP[y][x] + Arr[y + 1][x + 1];
			}
		}
		cout << "\n";
		int ans = 0;


		for (x = 0; x < n; ++x) {
			ans = max(ans, DP[n - 1][x]);
		}

		cout << ans;
	}
}