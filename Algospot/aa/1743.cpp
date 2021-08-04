/*
�Է¹��� ��ǥ�� �迭 ���� 1�� �����Ѵ�.
���� �ȿ� �ִ� �迭�� ���鼭 �迭 ���� 1�̸� ���Ĺ� ������ ������ cnt�� 0���� �ʱ�ȭ�ϰ� Garbage �Լ��� �����Ѵ�.
�湮�� ������ cnt++ �ϰ� �湮�� �迭 ���� 0���� �ٲ۴�.
�̵��� �� �ִ� ĭ�� ������ (���� �ȿ� ��� ���� 1�� ĭ) �Լ��� ������� �̵��Ѵ�.
�����¿쿡 �����Ⱑ ������ Garbage �Լ��� �����Ѵ�.
�湮���� ���� ĭ�� 1�� ������ �ݺ��ϰ� cnt�� �ִ��� ans�� ����Ѵ�.
��
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, K;
int ans;
int cnt;
vector<vector<int>>loc = { {-1,0},{1,0},{0,-1},{0,1} };
vector<vector<int>>Arr(101, vector<int>(101, 0));

void Garbage(int y, int x) {
	cnt++;
	Arr[y][x] = 0;
	for (int mv = 0; mv < 4; ++mv) {
		int n_y = y + loc[mv][0];
		int n_x = x + loc[mv][1];
		if (n_y >= 1 && n_y <= N && n_x >= 1 && n_x <= M) {
			if (Arr[n_y][n_x] == 1) {
				Garbage(n_y, n_x);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int y, x;

	cin >> N >> M >> K;

	while (K--) {
		cin >> y >> x;
		Arr[y][x] = 1;
	}

	for (y = 1; y <= N; ++y) {
		for (x = 1; x <= M; ++x) {
			if (Arr[y][x] == 1) {
				cnt = 0;
				Garbage(y, x);
				ans = max(ans, cnt);
			}
		}
	}
	cout << ans;
}