#include <string>
#include <iostream>
#include <vector>
using namespace std;

int n = 11;
int m = 11;
vector<vector<int>> visit(n, vector<int>(m, 0));
// 1000 -> ������, 0100 -> ����, 0010 -> ����, 0001 -> �Ʒ���
vector<vector<int>> dir(n, vector<int>(m, 0)); 
string str;
int answer = -1; // dfs�� �������� �� �ʹ� ������ �����ؾ��ϱ� ������ -1�� ����

bool isTrue(int r, int c) {
    return r >= 0 && r < n && c >= 0 && c < m;
}
void dfs(int r, int c, int b) {
    if (!isTrue(r, c)) { // ������ ����ٸ� return
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
    else { // �湮�� ���� �ִٸ� ������ ��ġ���� �ʴ��� Ȯ���ؾ���
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
    // �ʱ� ������ (5,5) ����
    str = dirs;
    dfs(5, 5, 0b0000);
    
    return answer;
}
int main()
{
    cout << solution("ULURRDLLU") << endl;
}