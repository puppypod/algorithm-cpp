#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int R, C;
string map[50];
int mapCnt[50][50];
int sr, sc;
int dr, dc;
queue<pair<int, int>> water;
int dir[4][2] = { {0,1} ,{1,0} ,{0,-1} ,{-1,0} };

bool isTrue(int r, int c) {
	return r >= 0 && r < R&& c >= 0 && c < C;
}
void bfs() {
	queue<pair<int,int>> q;
	q.push({ sr,sc });

	// 고슴도치가 더이상 이동할 수 없다면 break
	while (!q.empty()) {
		int waterSize = water.size();
		int qSize = q.size();
		// 1. 물 채우기
		for (int k = 0; k < waterSize; k++) {
			int r = water.front().first;
			int c = water.front().second;
			water.pop();

			for (int i = 0; i < 4; i++) {
				int dy = r + dir[i][0];
				int dx = c + dir[i][1];

				if (!isTrue(dy, dx)) continue;

				if (map[dy][dx] == '.') {
					map[dy][dx] = '*';
					water.push({ dy,dx });
				}
			}
		}

		// 2. 고슴도치 이동
		for (int k = 0; k < qSize; k++) {
			int r = q.front().first;
			int c = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int dy = r + dir[i][0];
				int dx = c + dir[i][1];
				
				if (!isTrue(dy, dx)) continue;

				if ((map[dy][dx] == '.' || map[dy][dx] == 'D') && mapCnt[dy][dx] == 0) {
					mapCnt[dy][dx] = mapCnt[r][c] + 1;
					q.push({ dy,dx });
					// 목적지에 도착하였다면
					if (dr == dy && dc == dx) return;
				}
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> map[i];
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == 'S') {
				sr = i;
				sc = j;
				map[i][j] = '.';
			}
			else if (map[i][j] == 'D') {
				dr = i;
				dc = j;
			}
			else if (map[i][j] == '*') {
				water.push({ i,j });
			}
		}
	}
	mapCnt[sr][sc] = 1;
	bfs();
	if (mapCnt[dr][dc] != 0) {
		cout << mapCnt[dr][dc]-1;
	}
	else {
		cout << "KAKTUS";
	}
}