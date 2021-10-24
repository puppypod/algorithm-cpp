#include <iostream>
#include <vector>

using namespace std;

struct Shark {
	int s, d, z;
	Shark() {
		this->s = -1;
		this->d = -1;
		this->z = -1;
	}
	Shark(int s, int d, int z) {
		this->s = s;
		this->d = d;
		this->z = z;
	}
};

int R, C, M;
vector<vector<Shark>> map;
// 상어를 잡았을 때 초기화 시켜주는 구조체
Shark init(-1, -1, -1);
//int dir[4][2] = { {1,0} ,{-1,0} ,{0,1} ,{0,-1} };

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> R >> C >> M;
	map.resize(R, vector<Shark>(C));
	for (int i = 0; i < M; i++) {
		// 행,열,속력,이동방향,크기
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		Shark tmp(s,d-1,z);
		// 맵에 상어 넣기
		map[r-1][c-1] = tmp;
	}

	int x = -1;
	int answer = 0;
	while (x != C-1) {
		vector<vector<Shark>> mapTmp(R, vector<Shark>(C));
		// 1. 낚시왕이 오른쪽으로 한 칸 이동한다.
		x++;

		// 2. 땅에서 가장 가까운 상어를 잡는다
		for (int i = 0; i < R; i++) {
			// 2-1. 상어를 발견하였다면?
			if (map[i][x].s != -1) {
				answer += map[i][x].z;
				map[i][x] = init;
				break;
			}
		}
		// 3. 상어가 이동한다.
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				// 3-1. 상어를 발견하였다면?
				if (map[i][j].s != -1) {
					// 발견한 상어를 mapTmp에 옮겨놓기
					int r = i;
					int c = j;
					int s = map[i][j].s;
					int d = map[i][j].d;
					int z = map[i][j].z;
					
					// 방향이 위 또는 아래일 경우
					if (d < 2) {
						// 위
						if (d == 0) r -= s;
						// 아래
						else r += s;

						if (r < 0 || r >= R) {
							if (r < 0) r = -r;
							int n = (r - 1) / (R - 1);
							int diff = (R - 1) * n;
							if (n % 2 == 0) {
								r -= diff;
								d = 1;
							}
							else {
								r -= diff;
								r = (R - 1) - r;
								d = 0;
							}
						}

					}
					// 방향이 오른쪽 또는 왼쪽일 경우
					else {
						// 오른쪽
						if (d == 2) c += s;
						// 왼쪽
						else c -= s;

						if (c < 0 || c >= C) {
							if (c < 0) c = -c;
							int n = (c - 1) / (C - 1);
							int diff = (C - 1) * n;
							if (n % 2 == 0) {
								c -= diff;
								d = 2;
							}
							else {
								c -= diff;
								c = (C - 1) - c;
								d = 3;
							}
						}
					}
					Shark sTmp(s, d, z);
					// 겹치는 상어가 있는지 확인
					if (mapTmp[r][c].s != -1) {
						// 겹치는 상어가 있는 경우
						if (mapTmp[r][c].z < sTmp.z) {
							mapTmp[r][c] = sTmp;
						}
					}
					else {
						// 겹치는 상어가 없는경우
						mapTmp[r][c] = sTmp;
					}
				}
			}
		}

		// 4. 이동한 상어 다시 복사하기
		map = mapTmp;
	}
	cout << answer;
}