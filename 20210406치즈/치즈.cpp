#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> cheese;
vector<vector<int>> visit;
int dir[4][2] = { {0,1} ,{1,0} ,{0,-1} ,{-1,0} };
int cheeseCnt;

bool isTrue(int r, int c) {
	return r >= 0 && r < N&& c >= 0 && c < M;
}
void bfs(int r, int c) {
	visit[r][c] = 1;
	queue<pair<int, int>> q;
	q.push({ r,c });
	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int dy = r + dir[i][0];
			int dx = c + dir[i][1];
			if (isTrue(dy, dx) && !visit[dy][dx]) {
				visit[dy][dx] = 1;
				if (!cheese[dy][dx]) {
					q.push({ dy,dx });
				}
				else {
					cheeseCnt++;
					cheese[dy][dx] = 0;
				}
			}
		}
	}
	
}
int main()
{
	cin >> N >> M;
	cheese.resize(N, vector<int>(M));
	vector<vector<int>> visit_init(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> cheese[i][j];
		}
	}
	int answer[2] = {0,0};
	cheeseCnt = -1;
	while (1) {
		visit = visit_init;
		cheeseCnt = 0;
		bfs(0, 0);
		if (cheeseCnt == 0) { break; }
		answer[0]++;
		answer[1] = cheeseCnt;
	}
	for (int i = 0; i < 2; i++) {
		cout << answer[i] << endl;
	}
}