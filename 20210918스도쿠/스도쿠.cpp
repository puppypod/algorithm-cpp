#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int map[9][9];
bool candidate[3][3][10];
vector<pair<int, int>> pointer;
int K = 0;
bool flag = false;

bool isTrue(int r, int c) {
    int r1 = r / 3;
    int c1 = c / 3;
    // 3x3 check
    for (int i = r1*3; i < r1*3 + 3; i++) {
        for (int j = c1*3; j < c1*3 + 3; j++) {
            if (map[r][c] == map[i][j] && r!=i && c!=j) {
                return false;
            }
        }
    }

    // 가로 세로 확인
    for (int i = 0; i < 9; i++) {
        if (map[r][c] == map[r][i] && c != i) {
            return false;
        }
        if (map[r][c] == map[i][c] && r != i) {
            return false;
        }
    }

    return true;
}
void dfs(int cnt) {
    if (cnt == K) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << map[i][j] << " ";
            }
            cout << '\n';
        }
        flag = true;
        return;
    }

    int r = pointer[cnt].first;
    int c = pointer[cnt].second;

    for (int i = 1; i <= 9; i++) {
        
        map[r][c] = i;
        if (isTrue(r, c)) {
            dfs(cnt + 1);
        }

        if (flag) { return; }
    }

    map[r][c] = 0;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> map[i][j];
            if (map[i][j] == 0) {
                pointer.push_back({ i,j });
                K++;
            }
        }
    }

    dfs(0);
}