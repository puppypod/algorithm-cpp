#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int triangle[501][501];
int dp[501][501];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			int num; cin >> num;
			triangle[i][j] = num;
		}
	}

	dp[1][1] = triangle[1][1];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1 || j == i) {
				if (j == 1) {
					dp[i][j] += triangle[i][j] + dp[i - 1][j];
				}
				else {
					dp[i][j] += triangle[i][j] + dp[i - 1][j - 1];
				}
				
			}
			else {
				dp[i][j] += triangle[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
			}
		}
	}
	int mx = -1;
	for (int i = 1; i <= n; i++) {
		mx = max(dp[n][i], mx);
	}
	cout << mx;
}