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
	// 1. 종료 조건
	if (bitState == flag) {
		// INF는 길이 없다는 의미
		if (DP[cursor][0] == 0) return INF;
		else return DP[cursor][0];
	}

	// 최솟값을 이미 구함.
	if (w[cursor][bitState] != -1) {
		return w[cursor][bitState];
	}
	// 초기값 세팅
	w[cursor][bitState] = INF;

	for (int i = 0; i < N; i++) {
		// 0이면 길이 없다는 의미
		if (DP[cursor][i] == 0) continue;
		// i번째는 이미 방문했다는 의미
		if ((bitState & (1 << i)) == (1 << i)) continue;

		int cost = dfs(i, bitState | 1 << i);

		// 방문 안했을 때의 값 구하기
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
	// 비트마스크를 위한 작업, flag는 모든 곳을 방문했다는 의미임
	flag = (1 << N) - 1;

	cout << dfs(0, 1);
}