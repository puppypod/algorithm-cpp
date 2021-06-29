#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int N, M, x, y, K;
int dir[4][2] = { {0,1} ,{0,-1} ,{-1,0} ,{1,0} };
vector<vector<int>> board;
vector<int> cmd;

bool isTrue(int r, int c) {
	return r >= 0 && r < N&& c >= 0 && c < M;
}
int main()
{
	cin >> N >> M >> x >> y >> K;
	board.resize(N, vector<int>(M));
	deque<int> left_right(4, 0);
	deque<int >up_down(4, 0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		int num;
		cin >> num;
		cmd.push_back(num - 1);
	}

	for (int i = 0; i < K; i++) {
		int d = cmd[i];

		int dx = x + dir[d][0];
		int dy = y + dir[d][1];
		if (!isTrue(dx, dy)) {
			continue;
		}
		int tmp;

		if (d <= 1) { // µ¿ or ¼­
			if (d == 0) { // µ¿
				if (board[dx][dy] != 0) {
					left_right[1] = board[dx][dy];
					board[dx][dy] = 0;
				}
				else {
					board[dx][dy] = left_right[1];
				}
				tmp = left_right.back();
				left_right.pop_back();
				left_right.push_front(tmp);
			}
			else { // ¼­
				if (board[dx][dy] != 0) {
					left_right[3] = board[dx][dy];
					board[dx][dy] = 0;
				}
				else {
					board[dx][dy] = left_right[3];
				}
				tmp = left_right.front();
				left_right.pop_front();
				left_right.push_back(tmp);
			}
			up_down[0] = left_right[0];
			up_down[2] = left_right[2];
		}
		else { // ºÏ or ³²
			if (d == 2) { // ºÏ
				if (board[dx][dy] != 0) {
					up_down[3] = board[dx][dy];
					board[dx][dy] = 0;
				}
				else {
					board[dx][dy] = up_down[3];
				}
				tmp = up_down.front();
				up_down.pop_front();
				up_down.push_back(tmp);
			}
			else { // ³²
				if (board[dx][dy] != 0) {
					up_down[1] = board[dx][dy];
					board[dx][dy] = 0;
				}
				else {
					board[dx][dy] = up_down[1];
				}
				tmp = up_down.back();
				up_down.pop_back();
				up_down.push_front(tmp);
			}
			left_right[0] = up_down[0];
			left_right[2] = up_down[2];
		}
		cout << up_down[0] << '\n';
		x = dx;
		y = dy;
	}
}