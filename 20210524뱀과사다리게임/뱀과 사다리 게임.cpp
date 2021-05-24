#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> info(101, 0);
vector<int> visited(101, 0);
int dice[6] = { 1,2,3,4,5,6 };

bool isTrue(int x) {
	return x <= 100;
}
int bfs() {
	queue<pair<int,int>> q;
	int answer = 0;
	q.push({ 1,0 });
	while (!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();
		visited[x] = cnt;
		if (visited[100]) { break; }
		for (int i = 0; i < 6; i++) {
			int dx = x + dice[i];
			if (isTrue(dx) && !visited[dx]) {
				if (info[dx]) { // 사다리 또는 뱀이라면
					dx = info[dx];
				}
				q.push({ dx,cnt + 1 });
			}
		}
	}
	return visited[100];
}
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n + m; i++) {
		int a, b;
		cin >> a >> b;
		info[a] = b;
	}
	cout << bfs();
}