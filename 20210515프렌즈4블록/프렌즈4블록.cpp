#include <string>
#include <vector>
#include <iostream>
using namespace std;


vector<string> map;
int N, M;
int dir[3][2] = { {0,1} ,{1,1} ,{1,0} };

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    /////
    int prev = -1;
    map = board;

    while (prev != answer) {
        // 4개씩 묶여있는 블록 check
        prev = answer;
        vector<pair<int, int>> visited;

        
        N = map.size();
        M = map[0].size();
        for (int i = 0; i < N - 1; i++) {
            for (int j = 0; j < M - 1; j++) {
                char target = map[i][j];
                bool isTrue = true;
                for (int k = 0; k < 3; k++) {
                    int dy = i + dir[k][0];
                    int dx = j + dir[k][1];
                    if (target != map[dy][dx]) {
                        isTrue = false;
                        break;
                    }
                }
                if (isTrue) {
                    visited.push_back({ i,j });
                }
            }
        }
        // 블록 제거
        for (pair<int, int> tmp : visited) {
            int y = tmp.first;
            int x = tmp.second;
            if (map[y][x] != '0') {
                answer++;
                map[y][x] = '0';
            }

            for (int i = 0; i < 3; i++) {
                if (map[y + dir[i][0]][x + dir[i][1]] != '0') {
                    answer++;
                    map[y + dir[i][0]][x + dir[i][1]] = '0';
                }

            }
        }
        // 블록 down
        for (int j = 0; j < M; j++) {
            int cnt = 0;
            for (int i = N - 1; i >= 0; i--) {
                if (map[i][j] == '0') {
                    cnt++;
                }
                else {
                    if (cnt == 0)continue;
                    map[i + cnt][j] = map[i][j];
                    map[i][j] = '0';
                }

            }
        }

    }

    return answer;
}