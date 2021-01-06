#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dp[60001];

int solution(int n) {
    dp[0] = 1;
    dp[1] = 1;
    // dp 문제 풀이
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
        if (dp[i] >= 1000000007) {
            dp[i] = dp[i] % 1000000007;
        }
    }

    return dp[n];
}
int main()
{
    cout << solution(500);
}