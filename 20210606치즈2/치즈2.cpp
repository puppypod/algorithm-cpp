#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> map;
vector<vector<int>> visited;
vector<vector<int>> cpy;
queue<pair<int, int>> rm;
int dir[4][2] = { {0,1} ,{1,0} ,{0,-1} ,{-1,0} };

bool isTrue(int r, int c) {
	return r >= 0 && r < N&& c >= 0 && c < M;
}
bool isFinish() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1) {
				return false;
			}
		}
	}
	return true;
}
void cheeseRemove() {
	while (!rm.empty()) {
		int r = rm.front().first;
		int c = rm.front().second;
		rm.pop();
		map[r][c] = 0;
	}
}
void findCheese(int r, int c) {
	queue<pair<int, int>> q;
	q.push({0,0});
	visited[r][c] = 1;
	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;
		
		q.pop();
		for (int i = 0; i < 4; i++) {
			int dy = r + dir[i][0];
			int dx = c + dir[i][1];
			if (isTrue(dy, dx) && !visited[dy][dx]) {
				if (cpy[dy][dx] == 0) {
					q.push({ dy,dx });
					visited[dy][dx] = 1;
				}
				else {
					cpy[dy][dx]++;
					if (cpy[dy][dx] == 3) {
						rm.push({ dy,dx });
					}
				}
			}
		}
	}
}
int main()
{
	int answer = 0;
	cin >> N >> M;
	map.resize(N, vector<int>(M, 0));
	visited.resize(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	while (!isFinish()) {
		vector<vector<int>> init(N, vector<int>(M, 0));
		visited = init;
		answer++;
		cpy = map;
		
		findCheese(0,0);
		cheeseRemove();
	}
	cout << answer << endl;
}