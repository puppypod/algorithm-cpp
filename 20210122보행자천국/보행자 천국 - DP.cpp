#include <vector>
#include <iostream>
using namespace std;

int MOD = 20170805;

int solution(int m, int n, vector<vector<int>> city_map) {
    vector<vector<int>> u_d(m+1, vector<int>(n+1, 0)); // 위에서 아래로 가는 dp
    vector<vector<int>> l_r(m+1, vector<int>(n+1, 0)); // 왼쪽에서 오른쪽으로 가는 dp
    
    u_d[1][1] = 1; l_r[1][1] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (city_map[i - 1][j - 1] == 0) { // 왼쪽과 위쪽으로부터 올 수 있음
                u_d[i][j] += (u_d[i - 1][j] + l_r[i][j - 1]) % MOD;
                l_r[i][j] += (u_d[i - 1][j] + l_r[i][j - 1]) % MOD;
            }
            else if (city_map[i - 1][j - 1] == 1) { // 왼쪽과 위쪽으로부터 올 수 없음
                u_d[i][j] = 0;
                l_r[i][j] = 0;
            }
            else { // 위쪽에서 아래쪽으로만, 왼쪽에서 오른쪽으로만
                u_d[i][j] += u_d[i - 1][j];
                l_r[i][j] += l_r[i][j - 1];
            }
        }
    }
    return l_r[m][n];
}
int main()
{
    cout << solution(3, 6, { {0, 2, 0, 0, 0, 2}, {0, 0, 2, 0, 1, 0}, {1, 0, 0, 2, 2, 0} });
}