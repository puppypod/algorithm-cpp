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
// �� ����� �� �ʱ�ȭ �����ִ� ����ü
Shark init(-1, -1, -1);
//int dir[4][2] = { {1,0} ,{-1,0} ,{0,1} ,{0,-1} };

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> R >> C >> M;
	map.resize(R, vector<Shark>(C));
	for (int i = 0; i < M; i++) {
		// ��,��,�ӷ�,�̵�����,ũ��
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		Shark tmp(s,d-1,z);
		// �ʿ� ��� �ֱ�
		map[r-1][c-1] = tmp;
	}

	int x = -1;
	int answer = 0;
	while (x != C-1) {
		vector<vector<Shark>> mapTmp(R, vector<Shark>(C));
		// 1. ���ÿ��� ���������� �� ĭ �̵��Ѵ�.
		x++;

		// 2. ������ ���� ����� �� ��´�
		for (int i = 0; i < R; i++) {
			// 2-1. �� �߰��Ͽ��ٸ�?
			if (map[i][x].s != -1) {
				answer += map[i][x].z;
				map[i][x] = init;
				break;
			}
		}
		// 3. �� �̵��Ѵ�.
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				// 3-1. �� �߰��Ͽ��ٸ�?
				if (map[i][j].s != -1) {
					// �߰��� �� mapTmp�� �Űܳ���
					int r = i;
					int c = j;
					int s = map[i][j].s;
					int d = map[i][j].d;
					int z = map[i][j].z;
					
					// ������ �� �Ǵ� �Ʒ��� ���
					if (d < 2) {
						// ��
						if (d == 0) r -= s;
						// �Ʒ�
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
					// ������ ������ �Ǵ� ������ ���
					else {
						// ������
						if (d == 2) c += s;
						// ����
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
					// ��ġ�� �� �ִ��� Ȯ��
					if (mapTmp[r][c].s != -1) {
						// ��ġ�� �� �ִ� ���
						if (mapTmp[r][c].z < sTmp.z) {
							mapTmp[r][c] = sTmp;
						}
					}
					else {
						// ��ġ�� �� ���°��
						mapTmp[r][c] = sTmp;
					}
				}
			}
		}

		// 4. �̵��� ��� �ٽ� �����ϱ�
		map = mapTmp;
	}
	cout << answer;
}