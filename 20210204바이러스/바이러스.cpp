#include<iostream>
#include<vector>
using namespace std;

vector<int> visit;
vector<vector<int>> net;
int n;
int result = 0;
void dfs(int v) {
	visit[v] = 1;
	for (int i = 0; i < n; i++) {
		if (!visit[i] && net[v][i]) {
			result++;
			dfs(i);
		}
	}
}
int main()
{
	cin >> n;
	visit.resize(n, 0);
	int relation;
	cin >> relation;
	net.resize(n, vector<int>(n, 0));
	int l, r;
	for (int i = 0; i < relation; i++) {
		cin >> l >> r;
		net[l - 1][r - 1] = 1;
		net[r - 1][l - 1] = 1;
	}
	dfs(0);
	cout << result << endl;
}