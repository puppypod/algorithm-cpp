#include <iostream>
#include <deque>
#include <vector>
#include <queue>

using namespace std;

deque<int> d[51];
vector<vector<int>> visited;
int N, M, T;
int dir[4][2] = { {0,1} ,{1,0} ,{0,-1} ,{-1,0} };
bool flag2;
deque<pair<int, int>> zeroSet;

bool isTrue(int r) {
	return r >= 1 && r <= N;
}
void bfs(int r, int c) {
	queue<pair<int, int>> q;
	q.push({ r,c });
	visited[r][c] = 1;
	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int dy = r + dir[i][0];
			int dx = c + dir[i][1];
			if (dx < 0) dx = M - 1;
			else if (dx == M) dx = 0;

			if (!isTrue(dy)) continue;

			if (!visited[dy][dx] && d[dy][dx] == d[r][c]) {
				flag2 = true;
				visited[dy][dx] = 1;
				q.push({ dy,dx });
				zeroSet.push_back({ dy,dx });
			}
		}
	}
}
int main()
{
	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int a; cin >> a;
			d[i].push_back(a);
		}
	}
	int count = N * M;
	for (int i = 0; i < T; i++) {
		int X, D, K;
		deque<int> tmp;
		cin >> X >> D >> K;
		// 시계 방향
		if (D == 0) {
			// x배수 구하기
			for (int j = 1; j*X <= N; j++) {
				int room = j * X;
				for (int num = 0; num < K; num++) {
					tmp.push_back(d[room].back());
					d[room].pop_back();
				}
				// 회전
				while (!tmp.empty()) {
					d[room].push_front(tmp.front());
					tmp.pop_front();
				}
			}
		}
		// 반시계 방향
		else {
			// x배수 구하기
			for (int j = 1; j * X <= N; j++) {
				int room = j * X;
				for (int num = 0; num < K; num++) {
					tmp.push_back(d[room].front());
					d[room].pop_front();
				}
				// 회전
				while (!tmp.empty()) {
					d[room].push_back(tmp.front());
					tmp.pop_front();
				}
			}
		}
		vector<vector<int>> init(N + 1, vector<int>(M, 0));
		visited = init;
		double sum = 0;
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < M; k++) {
				sum += (double)d[j][k];
				if (!visited[j][k] && d[j][k]!=0) {
					flag2 = false;
					bfs(j, k);
					if (flag2) zeroSet.push_back({ j,k });
				}
			}
		}
		int cnt = 0;

		if (!zeroSet.empty()) {
			while (!zeroSet.empty()) {
				int r = zeroSet.front().first;
				int c = zeroSet.front().second;
				zeroSet.pop_front();
				d[r][c] = 0;
				cnt++;
			}
			count -= cnt;
		}
		else {
			sum = sum / ((double)count);
			for (int j = 1; j <= N; j++) {
				for (int k = 0; k < M; k++) {
					if (d[j][k] == 0) continue;

					if (d[j][k] > sum) d[j][k]--;
					else if(d[j][k]<sum)d[j][k]++;
				}
			}
		}
	}

	int answer = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			answer += d[i][j];
		}
	}
	cout << answer;
}