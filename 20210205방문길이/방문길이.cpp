#include <string>
#include <iostream>
#include <vector>
using namespace std;

int n = 11;
int m = 11;
vector<vector<int>> visit(n, vector<int>(m, 0));
// 1000 -> 오른쪽, 0100 -> 왼쪽, 0010 -> 위쪽, 0001 -> 아래쪽
vector<vector<int>> dir(n, vector<int>(m, 0)); 
string str;
int answer = -1; // dfs를 시작했을 때 초반 덧셈은 무시해야하기 때문에 -1로 세팅

bool isTrue(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m;
}
void dfs(int r, int c, int b) {
    if (!isTrue(r, c)) { // 범위를 벗어났다면 return
        return;
    }
    if (!visit[r][c]) {
        if (b == 0b1000) {
            dir[r][c] = dir[r][c] | 0b0100;
        }
        else if (b == 0b0100) {
            dir[r][c] = dir[r][c] | 0b1000;
        }
        else if (b == 0b0010) {
            dir[r][c] = dir[r][c] | 0b0001;
        }
        else if (b == 0b0001) {
            dir[r][c] = dir[r][c] | 0b0010;
        }
        answer++;
    }
    else { // 방문한 적이 있다면 방향이 일치하지 않는지 확인해야함
        if (b == 0b1000) {
            if ((dir[r][c] & 0b0100) == 0) {
                dir[r][c] = dir[r][c] + 0b0100;
                answer++;
            }
        }
        else if (b == 0b0100) {
            if ((dir[r][c] & 0b1000) == 0) {
                dir[r][c] = dir[r][c] + 0b1000;
                answer++;
            }
        }
        else if (b == 0b0010) {
            if ((dir[r][c] & 0b0001) == 0) {
                dir[r][c] = dir[r][c] + 0b0001;
                answer++;
            }
        }
        else if (b == 0b0001) {
            if ((dir[r][c] & 0b0010) == 0) {
                dir[r][c] = dir[r][c] + 0b0010;
                answer++;
            }
        }
    }
    visit[r][c] = 1;
    
    while (!str.empty()) {
        char tmp = str[0];
        str.erase(str.begin());
        if (tmp == 'R') {
            dir[r][c] = dir[r][c] | 8;
            dfs(r, c + 1, 0b1000);
        }
        else if (tmp == 'L') {
            dir[r][c] = dir[r][c] | 4;
            dfs(r, c - 1, 0b0100);
        }
        else if (tmp == 'U') {
            dir[r][c] = dir[r][c] | 2;
            dfs(r - 1, c, 0b0010);
        }
        else if (tmp == 'D') {
            dir[r][c] = dir[r][c] | 1;
            dfs(r + 1, c, 0b0001);
        }
    }
}
int solution(string dirs) {
    // 초기 시작은 (5,5) 부터
    str = dirs;
    dfs(5, 5, 0b0000);
    
    return answer;
}
int main()
{
    cout << solution("ULURRDLLU") << endl;
}