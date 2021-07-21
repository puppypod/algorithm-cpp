#include <iostream>
#include <queue>

using namespace std;

vector<vector<char>> map;
vector<vector<int>> dp;
int dir[4][2] = { {0,1} ,{1,0} ,{0,-1} ,{-1,0} };

struct waterKaktus {
	int r, c;
	char ch;
};

int R, C;
queue<waterKaktus> q;
int answer = 0;

bool isTrue(int r, int c) {
	return r >= 0 && r < R&& c >= 0 && c < C;
}
bool bfs() {
	while (!q.empty()) {
		waterKaktus tmp;

		int r1 = q.front().r;
		int c1 = q.front().c;
		char ch1 = q.front().ch;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int dy = r1 + dir[i][0];
			int dx = c1 + dir[i][1];
			if (!isTrue(dy, dx)) continue;
			tmp.r = dy; tmp.c = dx;

			if (ch1 == '*' && (map[dy][dx] == '.' || map[dy][dx]=='S')) {
				// ¹° ÆÛ¶ß¸®±â
				map[dy][dx] = '*';
				tmp.ch = map[dy][dx];
				q.push(tmp);
			}
			else if (ch1=='.' && !dp[dy][dx] && (map[dy][dx] == '.' || map[dy][dx] == 'D')) {
				dp[dy][dx] = dp[r1][c1] + 1;
				
				if (map[dy][dx] == 'D') {
					answer = dp[dy][dx];
					return true;
				}
				tmp.ch = map[dy][dx];
				q.push(tmp);
				
			}
		}
	}
	return false;
}
int main()
{
	cin >> R >> C;
	dp.resize(R, vector<int>(C, 0));
	map.resize(R, vector<char>(C));
	vector<pair<int,int>> s;
	vector<pair<int,int>> w;
	for (int i = 0; i < R; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < C; j++) {
			map[i][j] = tmp[j];
			if (tmp[j] == 'S') {
				s.push_back({ i,j });
			}
			else if (tmp[j] == '*') {
				w.push_back({ i,j });
			}
		}
	}
	for (pair<int, int> tmp: w) {
		waterKaktus tmp1;
		tmp1.r = tmp.first;
		tmp1.c = tmp.second;
		tmp1.ch = '*';
		q.push(tmp1);
	}
	for (pair<int, int> tmp : s) {
		waterKaktus tmp1;
		tmp1.r = tmp.first;
		tmp1.c = tmp.second;
		tmp1.ch = '.';
		q.push(tmp1);
	}

	if (bfs()) {
		cout << answer;
	}
	else {
		cout << "KAKTUS";
	}

}