#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> v;
	int n;
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	vector<int> dp(n, 0);
	dp[0] = 1;
	int answer = 0;
	for (int i = 0; i < n; i++) {
		int maxNum = 0;
		for (int j = 0; j < i; j++) {
			if (v[j] < v[i]) {
				maxNum = max(maxNum, dp[j]);
			}
		}
		dp[i] = maxNum + 1;
		answer = max(answer, dp[i]);
	}
	cout << answer;
}