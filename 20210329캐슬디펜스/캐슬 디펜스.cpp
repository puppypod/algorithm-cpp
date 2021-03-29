#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, D;
vector<vector<int>> map; // 적들이 위치하는 격자판
int tmp[3]; // 조합에 따른 궁수들의 위치
vector<int> push_tmp; // 궁수가 위치할 수 있는 모든 
int dir[3][2] = { {0,-1},{-1,0},{0,1} };
int answer; // 제거한 적들의 수
priority_queue<int> pq; // pq.top()은 궁수가 제거할 수 있는 가장 큰 값을 구할 수 있음.

struct enemy{ // 적들의 위치 및 궁수와 떨어진 거리
	int r = -1;
	int c = -1;
	int d = 1;
};

bool isTrue(int r, int c) {
	return r >= 0 && r < N&& c >= 0 && c < M;
}
bool cmp(const enemy& a, const enemy& b) {
	if (a.d != b.d) {
		return a.d < b.d;
	}
	return a.c < b.c;
}
void move() { // 적들 한칸아래로 이동
	
	for (int i = N - 1; i >= 1; i--) {
		for (int j = 0; j < M; j++) {
			map[i][j] = map[i - 1][j];
		}
	}
	for (int j = 0; j < M; j++) {
		map[0][j] = 0;
	}
	
}
void rm(vector<enemy> v[3]) { // 적들 제거
	// 궁수마다 제거할 수 있는 적 후보들 Sort()
	for (int i = 0; i < 3; i++) {
		sort(v[i].begin(), v[i].end(), cmp);
	}

	// 적들 제거, 같은 적이 제거될 수도 있음.
	for (int i = 0; i < 3; i++) {
		if (v[i].empty()) {
			continue;
		}
		int a = v[i][0].r;
		int b = v[i][0].c;
		if (map[a][b] == 1) {
			map[a][b] = 0;
			answer++;
		}
		
	}
}
void bfs() {
	for (int k = 0; k < N; k++) {
		vector<enemy> v[3]; // 궁수가 제거할 수 있는 적 후보들 Save 
		for (int i = 0; i < 3; i++) {
			queue<enemy> q;
			enemy e;
			vector<vector<int>> visit;
			visit.resize(N, vector<int>(M, 0));
			e.c = tmp[i];
			e.r = N - 1;
			q.push(e);
			visit[N - 1][e.c] = 1;
			v[i].push_back(e); 
			while (!q.empty()) {
				int x = q.front().r;
				int y = q.front().c;
				int dis = q.front().d + 1;
				if (dis > D) { // 궁수가 공격할 수 있는 거리를 벗어났다면 더 이상 BFS를 진행할 필요 없음.
					break;
				}
				q.pop();
				for (int j = 0; j < 3; j++) {
					int dx = x + dir[j][0];
					int dy = y + dir[j][1];
					if (isTrue(dx, dy) && !visit[dx][dy]) {
						visit[dx][dy] = 1;
						e.r = dx;
						e.c = dy;
						e.d = dis;
						q.push(e);
						if (map[dx][dy] == 1) { // 적 후보 Save
							v[i].push_back(e);
						}
					}
				}
			}

		}
		rm(v); // 적 제거
		move(); // 적 이동
	}
	return;
}
void randomSetting(int a, int b) { // 조합
	if (b == 3) {
		vector<vector<int>> cpy;
		cpy = map;
		answer = 0;
		bfs();
		pq.push(answer);
		map = cpy;
		return;
	}
	for (int i = a; i < M; i++) {
		tmp[b] = push_tmp[i];
		randomSetting(i + 1, b + 1);
	}
}
int main()
{
	cin >> N >> M >> D;
	map.resize(N, vector<int>(M));
	push_tmp.resize(M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < M; i++) {
		push_tmp[i] = i;
	}
	randomSetting(0, 0);
	cout << pq.top() << endl;
}