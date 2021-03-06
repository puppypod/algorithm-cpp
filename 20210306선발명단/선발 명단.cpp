#include <iostream>
#include <vector>

using namespace std;

vector<int> visit;
vector<vector<int>> map;
int mx;
void dfs(int idx, int sum) {
	if (idx == 11) {
		mx = (mx > sum) ? mx : sum;
		return;
	}
	for (int i = 0; i < 11; i++) {
		if (!visit[i] && map[idx][i]) {
			visit[i] = 1;
			dfs(idx + 1, sum + map[idx][i]);
			visit[i] = 0;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c;
	cin >> c;
	while (c--) {
		visit.resize(11, 0);
		map.resize(11, vector<int>(11, 0));
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				int n;
				cin >> n;
				map[i][j] = n;
			}
		}
		mx = -1;
		dfs(0, 0);
		cout << mx << '\n';
	}
}