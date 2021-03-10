#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// dp[a][b] = min(dp[a-1][b], min(dp[a-1][b-1], dp[a][b-1]))
vector<vector<int>> map;
int N, M;
int main()
{
	cin >> N >> M;
	map.resize(N + 1, vector<int>(M + 1));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			char c;
			cin >> c;
			map[i][j] = c - 48;
		}
	}
	int mx = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (map[i][j] == 1) {
				map[i][j] = min(map[i - 1][j - 1],
					min(map[i - 1][j], map[i][j - 1])) + 1;
				mx = max(mx, map[i][j]);
			}
		}
	}
	cout << mx*mx << endl;
}