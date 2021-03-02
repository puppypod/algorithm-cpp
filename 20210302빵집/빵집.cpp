#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;



vector<string> map;
vector<vector<int>> visit;
int r, c;
int dir[3][2] = { {-1,1} ,{0,1} ,{1,1} };
int ans = 0;
bool flag;
bool isTrue(int a, int b) {
	return a >= 0 && a < r&& b >= 0 && b < c;
}
void dfs(int x, int y) {
	visit[x][y] = 1;
	if (y == c - 1) {
		flag = true;
		ans++;
		return;
	}
	for (int i = 0; i < 3; i++) {
		int dx = x + dir[i][0];
		int dy = y + dir[i][1];
		if (isTrue(dx, dy) && !visit[dx][dy]) {
			dfs(dx, dy);
			if (flag) { return; }
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> r >> c;
	visit.resize(r, vector<int>(c, 0));
	for (int i = 0; i < r; i++) {
		string str;
		cin >> str;
		map.push_back(str);
		for (int j = 0; j < str.size(); j++) {
			if (map[i][j] == 'x') {
				visit[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < r; i++) {
		flag = false;
		dfs(i,0);
	}
	cout << ans << endl;
}