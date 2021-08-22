#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> map(n+1, vector<int>(m+1));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char c; cin >> c;
			map[i][j] = c - '0';
		}
	}
	int answer = 0;
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= m; j++) {
			if (map[i][j] != 0) {
				int sizeNum = min(map[i - 1][j - 1], min(map[i - 1][j], map[i][j - 1]));
				map[i][j] = sizeNum + 1;
				answer = max(map[i][j], answer);
			}
		}
	}
	if (answer == 0) {
		for (int i = 1; i <= n; i++) {
			if (map[1][i] == 1) { answer = 1; break; }
			if (map[i][1] == 1) { answer = 1; break; }
		}
	}
	cout << answer * answer;
}