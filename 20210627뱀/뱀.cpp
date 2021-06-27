#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N; // ������ ũ��
int K; // ��� ����
int L; // ���� ���� ��ȯ ���� ����
vector<vector<int>> board;
queue<pair<int, char>> cmd;
queue<pair<int, int>> q; // ���� �������� �࿭ ����
// +1 ���� -> D, -1 ���� -> L
int dir[4][2] = { {0,1} ,{1,0} ,{0,-1} ,{-1,0} };

bool isTrue(int r, int c) {
	return r >= 1 && r <= N && c >= 1 && c <= N;
}
int main()
{
	int answer = 0;
	cin >> N >> K;
	board.resize(N+1, vector<int>(N+1,0));
	for (int i = 0; i < K; i++) {
		int r, c;
		cin >> r >> c;
		board[r][c] = -1; // -1�� ����� �ǹ���.
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		int t;
		char ch;
		cin >> t >> ch;
		cmd.push({ t,ch });
	}
	board[1][1] = 1; // ���� ���� ��ġ
	q.push({ 1,1 });
	int r = 1;
	int c = 1;
	int infoNum = 0;
	int configTime = cmd.front().first;
	char configCh = cmd.front().second;
	cmd.pop();
	while (1) {
		int tmpY = q.front().first;
		int tmpX = q.front().second;
		board[tmpY][tmpX] = 0;
		q.push({ r,c });
		
		// ���� ���� ��ȯ �ð��� ��ġ�Ѵٸ�
		if (configTime == answer) {
			// info + 1 -> D
			// info - 1 -> L
			
			if (configCh == 'D') {
				infoNum = (infoNum + 1) % 4;
			}
			else if (configCh == 'L') {
				infoNum--;
				if (infoNum == -1) {
					infoNum = 3;
				}
			}
			if (!cmd.empty()) {
				configTime = cmd.front().first;
				configCh = cmd.front().second;
				cmd.pop();
			}
		}
		answer++;

		// ���� �̵��� ��ǥ
		int dy = r + dir[infoNum][0];
		int dx = c + dir[infoNum][1];
		
		// ������ ����ų� �ڱ� �ڽ��� ������ �ȴٸ� break;
		if (!isTrue(dy, dx) || board[dy][dx] == 1) {
			break;
		}
		// �̵��ϴ� ���� ��ĭ(0)�̶��
		else if (board[dy][dx] == 0) {
			q.pop();

			board[dy][dx] = 1;
			r = dy;
			c = dx;
		}
		// �̵��ϴ� ���� ���(-1)�� �ִٸ�
		else if (board[dy][dx] == -1) {
			board[dy][dx] = 1;
			board[tmpY][tmpX] = 1;
			r = dy;
			c = dx;
		}
		
	}
	cout << answer;
}