#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int n, k;
bool isTrue(int idx) {
	return idx >= 0 && idx <= 100000;
}
int bfs() {
	queue<pair<int,int>> q;
	vector<int> visit(100001, 0);
	q.push(make_pair(n, 0));
	visit[n] = 1;

	int cnt = 0;
	while (!q.empty()) {
		n = q.front().first;
		cnt = q.front().second;
		if (n == k) { return cnt; }
		q.pop();
		if (isTrue(n * 2) && !visit[n * 2]) {
			visit[n * 2] = 1;
			q.push(make_pair(n * 2, cnt + 1));
		}
		if (isTrue(n + 1) && !visit[n + 1]) {
			visit[n + 1] = 1;
			q.push(make_pair(n + 1, cnt + 1));
		}
		if (isTrue(n - 1) && !visit[n - 1]) {
			visit[n - 1] = 1;
			q.push(make_pair(n - 1, cnt + 1));
		}
	}
	return -1;
}
int main()
{
	cin >> n >> k;
	cout << bfs() << endl;
}