/*
입력받는 Arr 배열, 누적값을 저장하는 DP 배열 사용한다.
DP[0][0]의 값(시작 지점)에 Arr[0][0] 값을 넣어준다.
현재 위치가(y, x)일 때, 0부터 n - 1까지 돌면서 아래 1칸, 아래 1칸 + 오른쪽 1칸에 DP[y][x] 값을 저장한다.
이미 값이 있다면 기존 값과 새로운 값 중 더 큰 값을 저장한다.
for 문이 종료되면, 마지막 줄만 돌면서 최댓값을 찾고 출력한다.
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