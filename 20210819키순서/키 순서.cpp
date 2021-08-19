#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 987654321
vector<vector<int>> dist;

int main()
{
	int n, m;
	cin >> n >> m;
	dist.resize(n + 1, vector<int>(n + 1,MAX));

	for (int i = 1; i <= n; i++) {
		dist[i][i] = 0;
	}

	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		dist[a][b] = 1;
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	int ans = 0;
	
	for (int i = 1; i <= n; i++) {
		bool flag = false;
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == MAX && dist[j][i] == MAX) {
				flag = true;
				break;
			}
		}
		if (!flag) { ans++; }
	}
	cout << ans;
}