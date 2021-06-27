#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N; // 보드의 크기
int K; // 사과 개수
int L; // 뱀의 방향 변환 정보 개수
vector<vector<int>> board;
queue<pair<int, char>> cmd;
queue<pair<int, int>> q; // 뱀이 지나갔던 행열 정보
// +1 증가 -> D, -1 감소 -> L
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
		board[r][c] = -1; // -1은 사과를 의미함.
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		int t;
		char ch;
		cin >> t >> ch;
		cmd.push({ t,ch });
	}
	board[1][1] = 1; // 뱀의 시작 위치
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
		
		// 뱀의 방향 변환 시간이 일치한다면
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

		// 뱀이 이동할 좌표
		int dy = r + dir[infoNum][0];
		int dx = c + dir[infoNum][1];
		
		// 범위를 벗어나거나 자기 자신을 만나게 된다면 break;
		if (!isTrue(dy, dx) || board[dy][dx] == 1) {
			break;
		}
		// 이동하는 곳이 빈칸(0)이라면
		else if (board[dy][dx] == 0) {
			q.pop();

			board[dy][dx] = 1;
			r = dy;
			c = dx;
		}
		// 이동하는 곳에 사과(-1)가 있다면
		else if (board[dy][dx] == -1) {
			board[dy][dx] = 1;
			board[tmpY][tmpX] = 1;
			r = dy;
			c = dx;
		}
		
	}
	cout << answer;
}