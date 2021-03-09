#include <iostream>
#include <vector>

using namespace std;

#define MOD 1000000000
// DP[k][n] -> k개를 더해서 n이 나오는 경우
vector<vector<long long>> DP;
long long calc(int k, int n) {
	long long sum = 0;
	for (int j = 0; j <= n; j++) {
		sum = (sum + DP[k][j]) % MOD;
	}
	return sum;
}
int main()
{
	int N, K;
	cin >> N >> K;
	DP.resize(K + 1, vector<long long>(N + 1, 0));
	for (int i = 0; i <= N; i++) {
		DP[1][i] = 1;
	}
	for (int i = 2; i <= K; i++) {
		for (int j = 0; j <= N; j++) {
			DP[i][j] = calc(i-1, j);
		}
	}
	cout << DP[K][N] << endl;
}