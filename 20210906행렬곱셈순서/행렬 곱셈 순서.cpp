#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF INT_MAX

long long dp[501][501];
vector<pair<long long, long long>> info;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N;
    cin >> N;
    info.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        long long a, b; cin >> a >> b;
        info[i].first = a;
        info[i].second = b;
    }

    // i는 범위
    for (int i = 1; i <= N; i++) {
        // j는 시작점
        for (int j = 1; j <= N; j++) {
            dp[j][i + j] = INF;
            if (i + j == N + 1) break;
            // k는 기준점
            for (int k = j; k < i + j; k++) {
                dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + info[j].first * info[k].second * info[i + j].second);
            }
        }
    }
    cout << dp[1][N];
}