#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int dp[101][10001];
int w[101];
int c[101];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M;
	cin >> N >> M;
	
	for (int i = 1; i <= N; i++) {
		cin >> w[i];
	}
	int costSum = 0;
	for (int i = 1; i <= N; i++) {
		cin >> c[i];
	}

	int answer = INT_MAX;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= 10000; j++) {
			if (j >= c[i]) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - c[i]] + w[i]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}

			if (dp[i][j] >= M) {
				answer = min(answer, j);
			}
		}
	}
	cout << answer;
}