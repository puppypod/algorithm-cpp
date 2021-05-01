#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    int dir[3][2] = { {-1,-1},{-1,0},{0,-1} };
    // ���� ó��
    for (int i = 0; i < board.size(); i++) {
        if (board[i][0] == 1) { answer = 1; break; }
        if (board[0][i] == 1) { answer = 1; break; }
    }

    for (int i = 1; i < board.size(); i++) {
        for (int j = 1; j < board[i].size(); j++) {
            if (board[i][j] == 1) { // ��� 1�� �Ǿ�� �ּ� ���簢�� ������ ��.
                int mn = 1001;
                for (int k = 0; k < 3; k++) { // ���� check
                    mn = min(mn, board[i + dir[k][0]][j + dir[k][1]]);
                }
                board[i][j] = mn + 1;
                answer = max(answer, board[i][j]);
            }
        }
    }

    return answer * answer;
}