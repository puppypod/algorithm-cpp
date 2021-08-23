#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int> stair(n+1);
	vector<int> dp(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> stair[i];
	}

	if (n <= 1) {
		dp[1] = stair[1];
	}
	else if (n <= 2) {
		dp[1] = stair[1];
		dp[2] = max(stair[1] + stair[2], stair[2]);
	}
	else {
		dp[1] = stair[1];
		dp[2] = max(stair[1] + stair[2], stair[2]);
		dp[3] = max(stair[1] + stair[3], stair[2] + stair[3]);
	}

	for (int i = 4; i <= n; i++) {
		dp[i] = max(stair[i] + dp[i - 2], stair[i] + stair[i - 1] + dp[i - 3]);
	}

	cout << dp[n];
}