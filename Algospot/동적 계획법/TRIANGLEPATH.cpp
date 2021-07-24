/*
�Է¹޴� Arr �迭, �������� �����ϴ� DP �迭 ����Ѵ�.
DP[0][0]�� ��(���� ����)�� Arr[0][0] ���� �־��ش�.
���� ��ġ��(y, x)�� ��, 0���� n - 1���� ���鼭 �Ʒ� 1ĭ, �Ʒ� 1ĭ + ������ 1ĭ�� DP[y][x] ���� �����Ѵ�.
�̹� ���� �ִٸ� ���� ���� ���ο� �� �� �� ū ���� �����Ѵ�.
for ���� ����Ǹ�, ������ �ٸ� ���鼭 �ִ��� ã�� ����Ѵ�.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int x, y;
int DP[100][100] = { 0, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

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
		int ans = 0;
		for (x = 0; x < n; ++x) {
			ans = max(ans, DP[n - 1][x]);
		}

		cout << ans << "\n";
	}
}