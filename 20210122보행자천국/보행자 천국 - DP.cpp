#include <vector>
#include <iostream>
using namespace std;

int MOD = 20170805;

int solution(int m, int n, vector<vector<int>> city_map) {
    vector<vector<int>> u_d(m+1, vector<int>(n+1, 0)); // ������ �Ʒ��� ���� dp
    vector<vector<int>> l_r(m+1, vector<int>(n+1, 0)); // ���ʿ��� ���������� ���� dp
    
    u_d[1][1] = 1; l_r[1][1] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (city_map[i - 1][j - 1] == 0) { // ���ʰ� �������κ��� �� �� ����
                u_d[i][j] += (u_d[i - 1][j] + l_r[i][j - 1]) % MOD;
                l_r[i][j] += (u_d[i - 1][j] + l_r[i][j - 1]) % MOD;
            }
            else if (city_map[i - 1][j - 1] == 1) { // ���ʰ� �������κ��� �� �� ����
                u_d[i][j] = 0;
                l_r[i][j] = 0;
            }
            else { // ���ʿ��� �Ʒ������θ�, ���ʿ��� ���������θ�
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