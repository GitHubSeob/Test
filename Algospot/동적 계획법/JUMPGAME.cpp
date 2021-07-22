#include <iostream>
#include <vector>
using namespace std;

int main() {
	int C = 0;
	int n = 0;
	int y = 0, x = 0;
	cin >> C;
	

	while (C-- > 0) {
		cin >> n;
		vector<vector<int>>Arr(n, vector<int>(n, 0));
		vector<vector<int>>DP(n, vector<int>(n, 0));
		for (y = 0; y < n; ++y) {
			for (x = 0; x < n; ++x) {
				cin >> Arr[y][x];
			}
		}
		DP[0][0] = 1;
		for (y = 0; y < n; ++y) {
			for (x = 0; x < n; ++x) {
				int n_y = y + Arr[y][x];
				int n_x = x + Arr[y][x];
				if (DP[y][x] != 0) {
					if (n_y > 0 && n_y < n) {
						DP[n_y][x] += Arr[y][x];
					}
					if (n_x > 0 && n_x < n) {
						DP[y][n_x] += Arr[y][x];
					}
				}
			}
		}
		if (DP[n-1][n-1] > 0) cout << "YES";
		else cout << "NO";
		cout << "\n";
	}

	return 0;
}