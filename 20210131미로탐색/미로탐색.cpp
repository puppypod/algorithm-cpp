#include <iostream>
#include <vector>
#include <queue>
#pragma warning(disable:4996)
using namespace std;

vector<vector<int>> map;
vector<vector<int>> visit;
int n, m;
int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
bool isTrue(int r, int c) {
	return r >= 0 && r < n&& c >= 0 && c < m;
}
int bfs(int r, int c, int cnt) {
	int dx, dy;
	queue<pair<pair<int, int>,int>> q;
	q.push(make_pair(make_pair(r, c), cnt + 1));
	while (!q.empty()) {
		r = q.front().first.first;
		c = q.front().first.second;
		cnt = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			dx = r + dir[i][0];
			dy = c + dir[i][1];
			if (isTrue(dx, dy) && map[dx][dy] && !visit[dx][dy]) {
				if (dx == n - 1 && dy == m - 1) { return cnt + 1; }
				visit[dx][dy] = 1;
				q.push(make_pair(make_pair(dx, dy), cnt + 1));
			}
		}
	}
	return cnt;
}
int main()
{
	cin >> n >> m;
	map.resize(n, vector<int>(m));
	visit.resize(n, vector<int>(m,0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d",&map[i][j]);
		}
	}
	visit[0][0] = 1;
	cout << bfs(0, 0, 0);
}