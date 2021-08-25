#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> map(n + 1, vector<int>(n + 1));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int num; cin >> num;
			map[i][j] = map[i][j - 1] + num;
		}
	}
	for (int j = 1; j <= n; j++) {
		for (int i = 1; i <= n; i++) {
			map[i][j] += map[i - 1][j];
		}
	}

	for (int i = 0; i < m; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		cout << map[x2][y2] - map[x2][y1 - 1] - map[x1 - 1][y2] + map[x1 - 1][y1 - 1] << '\n';
	}
}