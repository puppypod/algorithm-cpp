#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin >> N >> M;
	vector<vector<int>> map(N + 1, vector<int>(N + 1, 0));
	vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i-1][j-1] + map[i][j];
		}
	}
	for (int i = 0; i < M; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int answer = dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1];
		cout << answer << '\n';
	}
}