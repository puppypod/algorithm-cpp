#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 10000000
int N, M, K;
vector<vector<int>> map;
vector<vector<int>> map_cpy;
vector<vector<int>> rotation;
vector<int> randomArr;
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} }; // 동->남->서->북
int rangeX1, rangeX2, rangeY1, rangeY2;
int answer = MAX;

bool isTrue(int r, int c) {
	return r >= rangeX1 && r <= rangeX2 && c >= rangeY1 && c <= rangeY2;
}
void mapRotation() {
	for (int next : randomArr) {
		int r = rotation[next][0];
		int c = rotation[next][1];
		int s = rotation[next][2];
		int dx = r - s;
		int dy = c - s;
		int end_dx = r + s;
		int end_dy = c + s;
		int cnt = (end_dx - dx) / 2; // 돌릴 수 있는 사각형 개수
		vector<vector<int>> tmp = map_cpy;
		// 회전
		for (int i = 0; i < cnt ; i++) { // 사각형 개수만큼 반복
			dx += i; dy += i; end_dx -= i; end_dy -= i;
			rangeX1 = dx;
			rangeY1 = dy;
			rangeX2 = end_dx;
			rangeY2 = end_dy;
			for (int j = 0; j < 4; j++) { // 방향 설정
				int nx = dx + dir[j][0];
				int ny = dy + dir[j][1];
				// 범위를 벗어나면 방향 change
				while (isTrue(nx,ny)) { 
					map_cpy[nx][ny] = tmp[dx][dy];
					dx = nx;
					dy = ny;

					nx += dir[j][0];
					ny += dir[j][1];
				}
			}
		}
		
	}
	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int j = 1; j <= M; j++) {
			sum += map_cpy[i][j];
		}
		answer = min(answer, sum);
	}
	
}
int main()
{
	cin >> N >> M >> K;
	map.resize(N + 1, vector<int>(M + 1));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		int r, c, s;
		cin >> r >> c >> s;
		rotation.push_back({ r,c,s });
	}
	for (int i = 0; i < K; i++) {
		randomArr.push_back(i);
	}

	do {
		map_cpy = map;
		mapRotation();
	} while (next_permutation(randomArr.begin(), randomArr.end()));
	cout << answer << endl;
}