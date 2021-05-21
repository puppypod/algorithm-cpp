#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int R, C;
int cnt = 0;
int dir[4][2] = { {0,0} ,{0,1} ,{1,0} ,{1,1} };

void dfs(int r, int c, int n) {

	if (r == R && c == C) {
		cout << cnt;
		return;
	}

	if (R < r + n && R >= r) {
		if (C < c + n && C >= c) {
			dfs(r, c, n / 2);
			dfs(r, c + (n / 2), n / 2);
			dfs(r + (n / 2), c, n / 2);
			dfs(r + (n / 2), c + (n / 2), n / 2);
		}
		else {
			cnt += n * n;
		}
	}
	else {
		cnt += n * n;
	}

	return;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	cin >> N >> R >> C;

	dfs(0, 0, 1 << N);
}