#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<pair<int, int>>> DP;

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    int N;
    cin >> N;
    DP.resize(2, vector<pair<int, int>>(3));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> DP[i%2][j].first;
            DP[i%2][j].second = DP[i%2][j].first;
        }

        for (int j = 0; j < 3; j++) {
            int scoremx = DP[i% 2][j].first;
            int scoremn = DP[i% 2][j].second;
            if (j == 0) {
                DP[i % 2][j].first = scoremx + max(DP[(i+1)%2][j].first,
                    DP[(i+1)% 2][j + 1].first);
                DP[i%2][j].second = scoremn + min(DP[(i + 1) % 2][j].second,
                    DP[(i + 1) % 2][j + 1].second);
            }
            else if (j == 1) {
                DP[i % 2][j].first = scoremx + max(max(DP[(i + 1) % 2][j].first,
                    DP[(i + 1) % 2][j + 1].first),
                    DP[(i + 1) % 2][j - 1].first);
                DP[i % 2][j].second = scoremn + min(min(DP[(i + 1) % 2][j].second,
                    DP[(i + 1) % 2][j + 1].second),
                    DP[(i + 1) % 2][j - 1].second);
            }
            else {
                DP[i % 2][j].first = scoremx + max(DP[(i + 1) % 2][j].first,
                    DP[(i + 1) % 2][j - 1].first);
                DP[i % 2][j].second = scoremn + min(DP[(i + 1) % 2][j].second,
                    DP[(i + 1) % 2][j - 1].second);
            }
        }
    }

    int maxNum = -1;
    int minNum = 1000000;
    for (int i = 0; i < 3; i++) {
        maxNum = max(DP[(N+1)%2][i].first, maxNum);
        minNum = min(DP[(N + 1) % 2][i].second, minNum);
    }
    cout << maxNum << " " << minNum;
}