#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int N, L, R;
vector<vector<int>> visit;
vector<vector<int>> map;
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int sum = 0;
int cnt = 0;
int answer = 0;
int number = 0;
queue<pair<int,int>> save;
bool isTrue(int r, int c) {
	return r >= 0 && r < N&& c >= 0 && c < N;
}
void bfs(int r, int c) {
	queue<pair<int, int>> q;
	q.push({ r,c });
	sum = 0;
	number = 0;
	visit[r][c] = 1;
	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;
		save.push({ r,c });
		q.pop();
		
		sum += map[r][c];
		number++;
		for (int i = 0; i < 4; i++) {
			int dx = r + dir[i][0];
			int dy = c + dir[i][1];
			if (isTrue(dx, dy) && !visit[dx][dy] &&
				abs(map[r][c] - map[dx][dy]) >= L &&
				abs(map[r][c] - map[dx][dy]) <= R) {
				visit[dx][dy] = 1;
				q.push({ dx,dy });
			}
		}
	}
}
int main()
{
	cin >> N >> L >> R;
	map.resize(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int n;
			cin >> n;
			map[i][j] = n;
		}
	}
	int contry = N * N;
	vector<vector<int>> init(N, vector<int>(N, 0));
	while (1) {
		visit = init;
		cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (!visit[i][j]) {
					cnt++;
					bfs(i, j);
					float a = sum / (float)number;
					int num = floor(sum / number);
					while (!save.empty()) {
						int r = save.front().first;
						int c = save.front().second;
						save.pop();
						map[r][c] = num;
					}
				}
			}
		}
		
		if (cnt == contry) { break; }
		answer++;
	}
	cout << answer << endl;
}