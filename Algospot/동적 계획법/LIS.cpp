/*
Arr�� �Է¹޴� �Լ�, DP�� ���� �������̴�.
���� ���� n1�� ��, n2= 0���� n1-1���� ���鼭
Arr[n1]<Arr[n2]�� ��� DP[n2]+1 > DP[n1]�̸� DP[n1]�� ���� �����Ѵ�.
 
ex) 1 2 3 1 10 11
���� ���� 5�̴�. (1, 2, 3, 10, 11)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int C = 0;
	int N = 0;
	int n1, n2;
	cin >> C;

	while (C-- > 0) {
		cin >> N;
		vector<int>Arr(N, 0);
		vector<int>DP(N, 1);

		for (n1 = 0; n1 < N; ++n1) {
			cin >> Arr[n1];
		}
		for (n1 = 1; n1 < N; ++n1) {
			for (n2 = 0; n2 < n1; ++n2) {
				if (Arr[n2] < Arr[n1]) {
					DP[n1] = max(DP[n1], DP[n2] + 1);
				}
			}
		}
		int ans = 0;
		for (n1 = 1; n1 < N; ++n1) {
			ans = max(ans, DP[n1]);
		}
		cout << ans << "\n";
	}
}