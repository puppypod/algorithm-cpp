#include <string>
#include <vector>
#include <iostream>
using namespace std;

int dir[4][2] = { {0,1},{1,0},{0,-1}, {-1,0} };
int n;
vector<vector<int>> map;
int mn = 500000;

bool isTrue(int r, int c) {
    return (r >= 0 && r < n) && (c >= 0 && c < n);
}
void dfs(int a, int b, int sum, bool isrow, bool iscol) {
    if (mn <= sum) {
        return;
    }
    if (map[n-1][n-1]==2) {
        if (mn > sum) {
            mn = sum;
        }
        return;
    }
    ////////////////////////////////////////////////////////////
    int r;
    int c;
    for (int i = 0; i < 4; i++) {
        r = a + dir[i][0];
        c = b + dir[i][1];
        
        if (isTrue(r, c) && !map[r][c]) {
            map[r][c] = 2;

            if ((r == 1 && c == 0) || (r == 0 && c == 1)) {
                if (c) { // 초반세팅은 가로방향
                    isrow = true; iscol = false;
                }
                else if (r) { // 초반세팅은 세로방향
                    isrow = false; iscol = true;
                }
                dfs(r, c, sum + 100, isrow, iscol);
            }
            else {
                if (isrow) { // 가로방향일때
                    if (!dir[i][0]) { // 가로방향 유지
                        dfs(r, c, sum + 100, isrow, iscol);
                    }
                    else { // 세로방향으로 바뀌었다면
                        isrow = false; iscol = true;
                        dfs(r, c, sum + 600, isrow, iscol);
                        if (b == c) { isrow = true; iscol = false; } // 이전값과 비교하여 flag 할당
                    }
                }
                else if (iscol) { // 세로방향일때
                    if (!dir[i][1]) { // 세로방향 유지
                        dfs(r, c, sum + 100, isrow, iscol);
                    }
                    else { // 가로방향으로 바뀌었다면
                        isrow = true; iscol = false;
                        dfs(r, c, sum + 600, isrow, iscol);
                        if (a == r) { isrow = false; iscol = true; } // 이전값과 비교하여 flag 할당
                    }
                }
            }
            
            map[r][c] = 0;
        }
    }
}
int solution(vector<vector<int>> board) {
    n = board.size();
    map = board;

    map[0][0] = 2;
    dfs(0, 0, 0, 0, 0);

    return mn;
}
int main() {
    cout << solution({ {0,0,0,0,0,0},{0,1,1,1,1,0},{0,0,1,0,0,0},{1,0,0,1,0,1},{0,1,0,0,0,1},{0,0,0,0,0,0} });
}