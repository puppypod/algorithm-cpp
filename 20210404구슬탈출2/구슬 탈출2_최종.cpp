#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 10
vector<vector<char>> map;
// �� -> �� -> �� -> ��
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
		// ����
		while (!isWall(rx + dir[dirNum][0], ry+dir[dirNum][1])) {
			rx += dir[dirNum][0];
			ry += dir[dirNum][1];
			if (rx == outX && ry == outY) {
				break;
			}
		}
		//�Ķ�
		while (!isWall(bx + dir[dirNum][0], by + dir[dirNum][1])) {
			bx += dir[dirNum][0];
			by += dir[dirNum][1];
			// ���� �Ķ��� Ż�ⱸ�� ���ٸ� ����
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
		
		// ���� ���� �Ķ� ��� ���ڸ��� �״�� �ִٸ� ����
		if (R.r == rx && R.c == ry && B.r == bx && B.c == by) {
			return;
		}
		
		// ���� ���� �Ķ� ������ ��ģ�ٸ� ���� ��ġ�� �������ؾ���.
		if (rx == bx && ry == by) {
			if (dirNum == 0) { // ��
				// �� ���ϳ��� �Ʒ��� ��ĭ ��������.
				if (R.r < B.r) {
					bx++;
				}
				else {
					rx++;
				}
			}
			else if (dirNum == 1) { // ��
				// �� �� ��ĭ�� ���� �÷�����
				if (R.r < B.r) {
					rx--;
				}
				else {
					bx--;
				}
			}
			else if (dirNum == 2) { // ��
				// �� �� ��ĭ�� ���������� �̵��ؾ���
				if (R.c < B.c) {
					by++;
				}
				else {
					ry++;
				}
			}
			else if (dirNum == 3) { // ��
				// �� �� ��ĭ�� �������� �̵��ؾ���
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