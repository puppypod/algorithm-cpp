#include <iostream>
#include <deque>
#include <queue>
#include <algorithm>
using namespace std;

#define INF 987654321
deque<pair<int, int>> d[1001]; // 다익스트라 알고리즘으로 접근할 때의 배열 선언방법
deque<int> dist;
int main()
{
	int n, m;
	cin >> n >> m;
	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		d[a].push_back({ c,b });
	}
	int src, dest;
	cin >> src >> dest;
	dist.resize(n + 1, INF);
	dist[src] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0,src });
	while (!pq.empty()) {
		int cost = pq.top().first;
		int dx = pq.top().second;
		pq.pop();

		if (dx == dest) { // 도착지 도착.
			break;
		}
		for (int i = 0; i < d[dx].size(); i++) {
			int dcost = d[dx][i].first;
			int ddx = d[dx][i].second;
			if (dist[ddx] > cost + dcost) {
				dist[ddx] = cost + dcost;
				pq.push({ dist[ddx],ddx });
			}
		}
	}
	cout << dist[dest] << endl;
}