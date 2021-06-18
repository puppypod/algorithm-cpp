#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<vector<int>> v(N + 1, vector<int>(N + 1, 0));
	vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> v[i][j];
			dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + v[i][j];
		}
	}
	int answer = -1;
	for (int i = 1; i <= N; i++) {
		answer = max(answer, dp[N][i]);
	}
	cout << answer;
}