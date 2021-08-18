#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define INF 987654321

vector<int> dist;
vector<pair<int,int>> dir[20001];

struct Edge {
	int node, cost;
};
struct Cmp {
	bool operator()(const Edge& a, const Edge& b) {
		return a.cost > b.cost;
	}
};
priority_queue<Edge, vector<Edge>, Cmp> pq;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int V, E;
	int start;
	cin >> V >> E;
	cin >> start;

	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		dir[u].push_back({ v,w });
	}

	dist.resize(V + 1, INF);
	dist[start] = 0;
	
	pq.push({ start,0 });

	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();

		if (now.cost > dist[now.node]) continue;

		for (int i = 0; i < dir[now.node].size(); i++) {
			int next = dir[now.node][i].first;
			int nextCost = dir[now.node][i].second;
			if (dist[next] > now.cost + nextCost) {
				dist[next] = now.cost + nextCost;
				pq.push({ next,dist[next] });
			}
		}
	}

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) {
			cout << "INF" << '\n';
			continue;
		}
		cout << dist[i] << '\n';
	}
}