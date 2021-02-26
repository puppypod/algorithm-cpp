#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 987654321
int n, m, k;
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
vector<string> map;
vector<vector<int>> visit;
struct component {
	int r, c, cnt;
};
bool isTrue(int r, int c) {
	return r >= 0 && r < n&& c >= 0 && c < m;
}
int bfs(int x1, int y1, int x2, int y2) {
	queue<component> q;
	q.push({ x1 - 1,y1 - 1,0 });
	visit[x1 - 1][y1 - 1] = 1;
	while (!q.empty()) {
		x1 = q.front().r;
		y1 = q.front().c;
		int cnt = q.front().cnt;
		q.pop();
		for (int i = 0; i < 4; i++) {
			for (int j = 1; j <= k; j++) {
				int dx = x1 + dir[i][0] * j;
				int dy = y1 + dir[i][1] * j;
				if (!isTrue(dx, dy) || map[dx][dy] == '#' || visit[dx][dy] < cnt+1) {
					break;
				}

				if (visit[dx][dy]==INF) {
					visit[dx][dy] = cnt + 1;
					q.push({ dx,dy,cnt + 1 });

				}

			}
		}
	}
	if (visit[x2 - 1][y2 - 1]!=INF) {
		return visit[x2 - 1][y2 - 1];
	}
	else {
		return -1;
	}
}
int main()
{
	int x1, x2, y1, y2;
	cin >> n >> m >> k;
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		map.push_back(str);
	}
	cin >> x1 >> y1 >> x2 >> y2;
	visit.resize(n, vector<int>(m, INF));
	cout << bfs(x1, y1, x2, y2) << endl;
}