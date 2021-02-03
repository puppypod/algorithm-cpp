// 시간 초과 //

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m;
vector<vector<int>> visit;
vector<vector<int>> map;
vector<vector<int>> cpy;
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
bool isTrue(int r, int c) {
	return r >= 0 && r < n&& c >= 0 && c < m;
}
int iceberg() {
	queue<pair<int, int>> q;
	vector<vector<int>> v(n, vector<int>(m, 0));
	visit = v;
	int cnt = 0;
	int r, c;
	int dx, dy;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] && !v[i][j]) {
				q.push(make_pair(i, j));
				v[i][j] = 1;
				while (!q.empty()) {
					r = q.front().first;
					c = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++) {
						dx = r + dir[k][0];
						dy = c + dir[k][1];
						if (isTrue(dx,dy) && map[dx][dy] && !v[dx][dy] ) {
							v[dx][dy] = 1;
							q.push(make_pair(dx, dy));
						}
					}
				}
				cnt++;
			}
		}
	}
	return cnt;
}
void meltIceberg(int r, int c) {
	queue<pair<int, int>> q;
	int cnt = 0;
	int dx, dy;
	cpy = map;
	q.push(make_pair(r, c));
	visit[r][c] = 1;
	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;
		q.pop();
		cnt = 0;
		for (int i = 0; i < 4; i++) {
			dx = r + dir[i][0];
			dy = c + dir[i][1];
			if (isTrue(dx, dy) && !visit[dx][dy]) {
				if (!map[dx][dy]) { // 0인 경우
					cnt++;
				}
				else {
					q.push(make_pair(dx, dy));
					visit[dx][dy] = 1;
				}
			}
		}
		if (cnt) { // 녹일 수 있다면
			cpy[r][c] -= cnt;
			if (cpy[r][c] < 0) { cpy[r][c] = 0; }
		}
		
	}
	map = cpy;
	return;
}
int main()
{
	cin >> n >> m;
	map.resize(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	int result = 0;
	int cnt;
	bool ot;
	while (((cnt = iceberg()) < 2) || cnt==0 ) {
		ot = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j]) {
					meltIceberg(i, j);
					ot = true;
					break;
				}
			}
			if (ot) { break; }
		}
		result++;
	}
	cout << result << endl;
}