#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> visit(12, vector<int>(6, 0));
vector<string> str;
vector<pair<int, int>> v;
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

bool isTrue(int r, int c) {
	return r >= 0 && r < 12 && c >= 0 && c < 6;
}
void reMake() {
	int r, c;
	for (pair<int,int> tmp : v) {
		r = tmp.first;
		c = tmp.second;
		str[r][c] = '.';
	}
}
void gravity() {
	vector<char> tmp;
	int cnt;
	for (int j = 0; j < 6; j++) {
		for (int i = 11; i >= 0; i--) {
			if (str[i][j] != '.') {
				tmp.push_back(str[i][j]);
				str[i][j] = '.';
			}
		}
		cnt = tmp.size();
		for (int i = 11; i >= 12-cnt; i--) {
			str[i][j] = tmp.front();
			tmp.erase(tmp.begin());
		}
	}

}
void bfs(int r, int c, char color) {
	queue<pair<int, int>> q;
	int dx, dy;
	visit[r][c] = 1;

	v.clear();
	v.push_back(make_pair(r, c));
	
	q.push(make_pair(r, c));
	
	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			dx = r + dir[i][0];
			dy = c + dir[i][1];
			if (isTrue(dx, dy) && str[dx][dy] == color && !visit[dx][dy]) {
				q.push(make_pair(dx, dy));
				v.push_back(make_pair(dx, dy));
				visit[dx][dy] = 1;
			}
		}
	}
	return;
}
int main()
{
	vector<vector<int>> rset(12, vector<int>(6, 0));
	string a;
	for (int i = 0; i < 12; i++) {
		cin >> a;
		str.push_back(a);
	}
	bool isGo;
	int answer = 0;
	while (1) {
		isGo = false;
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (!visit[i][j] && str[i][j] != '.') {
					bfs(i, j, str[i][j]); // 연속 색깔 찾기
					if (v.size() >= 4) { // 4개이상 짝이라면 삭제
						isGo = true;
						reMake();
					}
				}
			}
		}
		if (!isGo) { break; }
		gravity(); // 삭제 후, 중력 적용
		answer++;
		visit = rset;
	}
	
	cout << answer << endl;
}