#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<char>> map;
vector<vector<bool>> visit;
int dir[4][2] = { {0,1} ,{1,0} ,{-1,0} ,{0,-1} };

bool isTrue(int r, int c) {
	return r >= 0 && r < N&& c >= 0 && c < N;
}
void dfsColorWeakness(int r, int c, char ch) {
	if (ch == 'R' || ch == 'G') {
		if (map[r][c] == 'B') {
			return;
		}
		visit[r][c] = true;
		for (int i = 0; i < 4; i++) {
			int dx = r + dir[i][0];
			int dy = c + dir[i][1];
			if (isTrue(dx, dy) && !visit[dx][dy] && 
				(map[dx][dy] == 'R' || map[dx][dy] == 'G')) {
				dfsColorWeakness(dx, dy, ch);
			}
		}
	}
	else {
		if (ch != map[r][c]) {
			return;
		}
		visit[r][c] = true;
		for (int i = 0; i < 4; i++) {
			int dx = r + dir[i][0];
			int dy = c + dir[i][1];
			if (isTrue(dx, dy) && !visit[dx][dy] && ch == map[dx][dy]) {
				dfsColorWeakness(dx, dy, ch);
			}
		}
	}
}
void dfsColor(int r, int c, char ch) {
	if (ch != map[r][c]) {
		return;
	}
	visit[r][c] = true;
	for (int i = 0; i < 4; i++) {
		int dx = r + dir[i][0];
		int dy = c + dir[i][1];
		if (isTrue(dx, dy) && !visit[dx][dy] && ch == map[dx][dy]) {
			dfsColor(dx, dy, ch);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N;
	map.resize(N, vector<char>(N));
	visit.resize(N, vector<bool>(N, false));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	int answer[2] = { 0, };
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visit[i][j]) {
				answer[0]++;
				dfsColor(i, j, map[i][j]);
			}
		}
	}
	vector<vector<bool>> init(N, vector<bool>(N, false));
	visit = init;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visit[i][j]) {
				answer[1]++;
				dfsColorWeakness(i, j, map[i][j]);
			}
		}
	}
	
	cout << answer[0] << " " << answer[1] << '\n';

}