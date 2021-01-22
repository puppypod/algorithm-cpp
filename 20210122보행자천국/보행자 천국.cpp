#include <vector>
#include <string>
#include <iostream>
using namespace std;

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
int MOD = 20170805;
vector<vector<int>> map;
int dir[2][2]; // ������ �Ǵ� ���� ���� ������ ���� ����
vector<vector<int>> visit;
int answer;
int row, col;
bool isTrue(int r, int c) {
    return (r >= 0 && r < row) && (c >= 0 && c < col);
}
void dfs(int r, int c) { // flag<0�̸� ���, flag==0 �̸� ���θ�, flag==1�̸� ���θ�
    if (visit[row - 1][col - 1] == 1) {
        answer++;
        if (answer >= MOD) { answer %= MOD; }
        return;
    }

    int dx, dy;
    for (int i = 0; i < 2; i++) { // i==0�̸� ����, i==1�̸� ����
        dx = r + dir[i][0];
        dy = c + dir[i][1];
        while(isTrue(dx,dy) && map[dx][dy]==2){ // �ѹ��� ����
            dx += dir[i][0];
            dy += dir[i][1];
        }
        if (isTrue(dx, dy)) {
            cout << dx << " " << dy << endl;
            if (map[dx][dy] == 1) { continue; }
            else if (!visit[dx][dy] && map[dx][dy] == 0) {
                visit[dx][dy] = 1;
                dfs(dx, dy);
                visit[dx][dy] = 0;
            }
        }
    }
}
int solution(int m, int n, vector<vector<int>> city_map) {
    map = city_map;
    visit.resize(m, vector<int>(n,0));
    answer = 0;
    dir[0][0] = 0; dir[0][1] = 1; dir[1][0] = 1; dir[1][1] = 0;
    visit[0][0] = 1;
    row = m; col = n;
    dfs(0, 0);
    return answer;
}
int main()
{
    cout << solution(3, 6, { {0, 2, 0, 0, 0, 2}, {0, 0, 2, 0, 1, 0}, {1, 0, 0, 2, 2, 0} });
}