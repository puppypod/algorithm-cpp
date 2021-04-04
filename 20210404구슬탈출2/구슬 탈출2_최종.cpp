#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 10
vector<vector<char>> map;
// 상 -> 하 -> 좌 -> 우
int dir[4][2] = { {-1,0} ,{1,0} ,{0,-1} ,{0,1} };
int outX, outY;

struct marble {
	int r;
	int c;
};
marble red, blue;
int N, M;
int answer = MAX + 1;

bool isWall(int r, int c) {
	return map[r][c] == '#';
}
void dfs(marble R, marble B, int cnt, int dirNum) {
	if (cnt > MAX) {
		return;
	}
	int rx = R.r;
	int ry = R.c;
	int bx = B.r;
	int by = B.c;
	
	if (dirNum != -1) {
		bool isGo = true;
		// 빨강
		while (!isWall(rx + dir[dirNum][0], ry+dir[dirNum][1])) {
			rx += dir[dirNum][0];
			ry += dir[dirNum][1];
			if (rx == outX && ry == outY) {
				break;
			}
		}
		//파랑
		while (!isWall(bx + dir[dirNum][0], by + dir[dirNum][1])) {
			bx += dir[dirNum][0];
			by += dir[dirNum][1];
			// 만약 파랑이 탈출구에 들어간다면 실패
			if (bx == outX && by == outY) {
				isGo = false;
				return;
			}
		}
		
		if (isGo) {
			if (rx == outX && ry == outY) {
				answer = min(answer, cnt);
				return;
			}
		}
		
		// 만약 빨강 파랑 모두 제자리에 그대로 있다면 실패
		if (R.r == rx && R.c == ry && B.r == bx && B.c == by) {
			return;
		}
		
		// 만약 빨강 파랑 구슬이 겹친다면 구슬 위치를 재조정해야함.
		if (rx == bx && ry == by) {
			if (dirNum == 0) { // 상
				// 둘 중하나를 아래로 한칸 내려야함.
				if (R.r < B.r) {
					bx++;
				}
				else {
					rx++;
				}
			}
			else if (dirNum == 1) { // 하
				// 둘 중 한칸을 위로 올려야함
				if (R.r < B.r) {
					rx--;
				}
				else {
					bx--;
				}
			}
			else if (dirNum == 2) { // 좌
				// 둘 중 한칸을 오른쪽으로 이동해야함
				if (R.c < B.c) {
					by++;
				}
				else {
					ry++;
				}
			}
			else if (dirNum == 3) { // 우
				// 둘 중 한칸을 왼쪽으로 이동해야함
				if (R.c < B.c) {
					ry--;
				}
				else {
					by--;
				}
			}
		}

	}
	
	R.r = rx;
	R.c = ry;
	B.r = bx;
	B.c = by;
	
	for (int i = 0; i < 4; i++) {
		dfs(R, B, cnt + 1, i);
	}
}
int main()
{
	cin >> N >> M;
	map.resize(N, vector<char>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R') {
				red.r = i;
				red.c = j;
			}
			else if (map[i][j] == 'B') {
				blue.r = i;
				blue.c = j;
			}
			else if (map[i][j] == 'O') {
				outX = i;
				outY = j;
			}
		}
	}

	dfs(red, blue, 0, -1);
	if (answer != MAX + 1) {
		cout << answer << endl;
	}
	else {
		cout << -1 << endl;
	}
}