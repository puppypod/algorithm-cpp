#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int R, C, T;
vector<vector<int>> map;
vector<vector<int>> map_cpy;
// 반시계방향
int dir[4][2] = { {0,1} ,{-1,0} ,{0,-1}, {1,0} };
// 시계방향
int dir2[4][2] = { {0,1} ,{1,0} ,{0,-1}, {-1,0} };

bool isTrue(int r, int c) {
	return r >= 0 && r < R&& c >= 0 && c < C;
}
// 미세먼지 확산
void diffusion(int i, int j, const vector<pair<int,int>>& save) {
	int dirNum = map[i][j] / 5;
	int cnt = save.size();
	for (pair<int, int> num : save) {
		map_cpy[num.first][num.second] += dirNum;
	}
	
	map_cpy[i][j] += map[i][j] - dirNum * cnt;
}
// 공기청정기
void purification(int r, int c, bool flag) {
	int y = r;
	int x = c;
	// flag가 true면 상단, false면 하단
	if (flag) { // 반시계방향
		int dy = r;
		int dx = c;
		vector<vector<int>> tmp = map_cpy;
		for (int i = 0; i < 4; i++) {
			dy += dir[i][0];
			dx += dir[i][1];
			
			while (isTrue(dy,dx) && (y != dy || x != dx)) {
				if (tmp[r][c] != -1) {
					map_cpy[dy][dx] = tmp[r][c];
				}
				else {
					map_cpy[dy][dx] = 0;
				}
				r = dy; c = dx;
				dy += dir[i][0];
				dx += dir[i][1];
			}
			dy -= dir[i][0];
			dx -= dir[i][1];
		}
	}
	else { // 시계방향
		int dy = r;
		int dx = c;
		vector<vector<int>> tmp = map_cpy;
		for (int i = 0; i < 4; i++) {
			dy += dir2[i][0];
			dx += dir2[i][1];

			while (isTrue(dy, dx) && (y != dy || x != dx)) {
				if (tmp[r][c] != -1) {
					map_cpy[dy][dx] = tmp[r][c];
				}
				else {
					map_cpy[dy][dx] = 0;
				}
				r = dy; c = dx;
				dy += dir2[i][0];
				dx += dir2[i][1];
			}
			dy -= dir2[i][0];
			dx -= dir2[i][1];
		}
	}
}

int result() {
	int sum = 0;
	for (int i = 0; i < R; i++) {
		sum += accumulate(map[i].begin(), map[i].end(), 0);
	}
	return sum + 2;
}
int main()
{
	int upR = 0; 
	int upC = 0;
	int downR = 0;
	int downC = 0;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> R >> C >> T;
	map.resize(R, vector<int>(C));
	int trashNum = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				if (trashNum == 0) {
					upR = i; upC = j;
					trashNum++;
				}
				else {
					downR = i; downC = j;
				}
			}
		}
	}

	vector<vector<int>> init(R, vector<int>(C, 0));
	
	while (T--) {
		map_cpy = init;
		map_cpy[upR][upC] = -1;
		map_cpy[downR][downC] = -1;
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (map[i][j] > 0) {
					vector<pair<int, int>> save;
					for (int k = 0; k < 4; k++) {
						int dy = i + dir[k][0];
						int dx = j + dir[k][1];
						// 범위를 벗어나거나 공기청정기면 안됨
						if (isTrue(dy, dx) && map[dy][dx] >= 0) {
							save.push_back({ dy,dx });
						}
					}
					// 미세먼지 확산
					diffusion(i, j, save);
				}
			}
		}
		// 공기청정기 동작
		purification(upR, upC, true);
		purification(downR, downC, false);

		map = map_cpy;
	}

	cout << endl;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << map_cpy[i][j] << " ";
		}
		cout << endl;
	}

	cout << result() << '\n';
}