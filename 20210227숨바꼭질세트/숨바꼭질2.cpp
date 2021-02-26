#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> visit(100001, 0);
int ans = 0;
int min_cnt = 0;

int scope[3];
void bfs(int a, int b) {
	queue<pair<int, int>> q;
	int cnt = 0;
	q.push({ a,0 });
	bool isfirst = false;
	scope[0] = b * 2;
	scope[1] = b * 2;
	scope[2] = b * 2;
	if (scope[0] > 100000) {
		scope[0] = 100000;
		scope[1] = 100000;
		scope[2] = 100000;
	}
	while (!q.empty()) {
		a = q.front().first;
		cnt = q.front().second;
		q.pop();
		visit[a] = 1;
		if (min_cnt && a == b && min_cnt==cnt) {
			ans++;
		}

		if (!min_cnt && a == b) {
			min_cnt = cnt;
			ans++;
		}
		
		if (a * 2 <= 100000 && !visit[a * 2]) {
			q.push({ a * 2,cnt + 1 });
		}
		if (a + 1 <= 100000 && !visit[a + 1]) {
			q.push({ a + 1,cnt + 1 });
		}
		if (a - 1 >= 0 && !visit[a - 1]) {
			q.push({ a - 1,cnt + 1 });
		}
	}
}
int main()
{
	int n, k;
	cin >> n >> k;
	visit[n] = 1;
	bfs(n, k);
	cout << min_cnt << endl << ans << endl;
}