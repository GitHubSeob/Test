/*
DFS�� �̿��ϴ� �����̴�.
ans ���� �����Ӱ� 100���� �����Ѵ�.
������ �ּڰ�+1 ���� ����ؾ� �ϹǷ� cnt=1�� ���·� A���� DFS �Լ��� �����Ѵ�.
A=B �̸� ans ���� cnt ���� ���� �� ���� ���� �����Ѵ�.
A*2 <= B �̸� DFS�� A*2, cnt+1 ���� �ְ� DFS �Լ���,
A*10+1 <= B �̸� DFS�� A*10+1, cnt+1 ���� �ְ� DFS �Լ��� �����Ѵ�.
ans ���� ������ �ʾҴٸ� A->B�� ��ȯ�� �Ұ����ϹǷ� -1�� ����Ѵ�.
�� �ܿ��� ans ���� ����Ѵ�.
*/

#include <iostream>
#include <algorithm>
using namespace std;

long long A, B;
int ans=100;

void DFS(long long A, int cnt) {
	if (A == B) ans=min(ans,cnt);
	if(A*2<=B)
	DFS(A * 2,cnt+1);
	if (A * 10 + 1 <= B)
	DFS(A * 10 + 1,cnt+1);	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> A >> B;

	DFS(A,1);
	if (ans==100) cout << "-1";
	else cout << ans;	
}