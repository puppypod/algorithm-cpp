#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 987654321

vector<vector<int>> w;
vector<vector<int>> DP;
int flag;
int N;

int dfs(int cursor, int bitState) {
	// 1. ���� ����
	if (bitState == flag) {
		// INF�� ���� ���ٴ� �ǹ�
		if (DP[cursor][0] == 0) return INF;
		else return DP[cursor][0];
	}

	// �ּڰ��� �̹� ����.
	if (w[cursor][bitState] != -1) {
		return w[cursor][bitState];
	}
	// �ʱⰪ ����
	w[cursor][bitState] = INF;

	for (int i = 0; i < N; i++) {
		// 0�̸� ���� ���ٴ� �ǹ�
		if (DP[cursor][i] == 0) continue;
		// i��°�� �̹� �湮�ߴٴ� �ǹ�
		if ((bitState & (1 << i)) == (1 << i)) continue;

		int cost = dfs(i, bitState | 1 << i);

		// �湮 ������ ���� �� ���ϱ�
		w[cursor][bitState] = min(w[cursor][bitState],
			DP[cursor][i] + cost);
	}
	return w[cursor][bitState];
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	w.resize(N, vector<int>((1 << N), -1));
	DP.resize(N, vector<int>(N, 0));
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> DP[i][j];
		}
	}
	// ��Ʈ����ũ�� ���� �۾�, flag�� ��� ���� �湮�ߴٴ� �ǹ���
	flag = (1 << N) - 1;

	cout << dfs(0, 1);
}