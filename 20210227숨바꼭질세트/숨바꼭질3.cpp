#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> visit(100001, 0);
int min_cnt = 987654321;
void bfs(int a, int b) {
	queue<pair<int, int>> q;
	q.push({ a,0 });
	int cnt = 0;
	
	while (!q.empty()) {
		a = q.front().first;
		cnt = q.front().second;
		q.pop();
		visit[a] = 1;
		if (a == b) {
			if (min_cnt > cnt) {
				min_cnt = cnt;
			}
		}

		if (a * 2 <= 100000 && !visit[a * 2]) {
			q.push({ a * 2,cnt });
		}
		if (a + 1 <= 100000 && !visit[a + 1]) {
			q.push({ a + 1,cnt + 1 });
		}
		if (a - 1 >= 0 && !visit[a - 1]) {
			q.push({ a - 1,cnt +1 });
		}
	}
}
int main()
{
	int n, k;
	cin >> n >> k;
	bfs(n, k);
	cout << min_cnt << endl;
}