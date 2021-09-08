#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int dir[4][2] = { {0,1} ,{1,0} ,{0,-1} ,{-1,0} };
int dp[50][50];
bool visited[50][50];
char map[50][50];
int answer = 0;
bool flag = true;

bool isTrue(int r, int c) {
	return r >= 0 && r < N && c >= 0 && c < M;
}
void dfs(int r, int c, int cnt) {
	if (!isTrue(r, c)) return;
	// 1. ���ѹ� ������ �� �ִ� ���
	if (visited[r][c]) {
		flag = false;
		return;
	}
	if (map[r][c] == 'H') return;

	// 2. üũ�� + �޸����̼�
	visited[r][c] = true;

	if (dp[r][c] != 0) {
		// �̹� �� ū ���� �����ϱ� ������ �� Ȯ���� �ʿ����
		if (dp[r][c] >= cnt) {
			visited[r][c] = false;
			return;
		}
	}
	dp[r][c] = cnt;
	answer = max(answer, cnt);

	// 3. ��ȸ
	for (int i = 0; i < 4; i++) {
		int dy = r + (map[r][c]-48)*dir[i][0];
		int dx = c + (map[r][c]-48)*dir[i][1];

		dfs(dy, dx, cnt + 1);
		if (!flag) { visited[r][c] = false; return; }
	}

	// 6. üũ�ƿ�
	visited[r][c] = false;

	return;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	dfs(0, 0, 1);
	if (flag) {
		cout << answer;
	}
	else {
		cout << -1;
	}
}