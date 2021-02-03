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
void melt(int r, int c) {
	int dx, dy;
	for (int i = 0; i < 4; i++) {
		dx = r + dir[i][0];
		dy = c + dir[i][1];

		if (isTrue(dx, dy) && map[dx][dy] == 0 && cpy[r][c] != 0) {
			cpy[r][c]--;
		}
	}
}
void bfs(int r, int c) { // 빙산 녹이기
	int dx, dy;
	queue<pair<int, int>> q;
	q.push(make_pair(r, c));
	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;
		q.pop();

		melt(r, c);
		for (int i = 0; i < 4; i++) {
			dx = r + dir[i][0];
			dy = c + dir[i][1];
			if (isTrue(dx, dy) && !visit[dx][dy] && map[dx][dy]) {
				visit[dx][dy] = 1;
				q.push(make_pair(dx, dy));
			}
		}
	}
}
int iceberg() { // 결과값 출력
	vector<vector<int>> v(n, vector<int>(m, 0));
	
	int cnt;
	int result = 0;
	cpy = map;
	while (1) {
		cnt = 0;
		visit = v;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] && !visit[i][j]) {
					visit[i][j] = 1;
					bfs(i, j);
					cnt++;
				}
			}
		}
		if (cnt == 1) { 
			result++;
			map = cpy;
		}
		else if (cnt == 0) { cout << cnt << endl; return 0; }
		else { break; }
		
	}
	cout << result << endl;
	return 0;
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
	iceberg();
}