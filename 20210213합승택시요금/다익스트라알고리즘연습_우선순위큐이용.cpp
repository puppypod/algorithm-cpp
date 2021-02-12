#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define INF 1e9
#define MAX_GRAPH 100001
vector<pair<int, int>> graph[MAX_GRAPH];
vector<int> d_cost(MAX_GRAPH, INF);

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;
	d_cost[start] = 0;
	pq.push(make_pair(0, start));
	int now_dist; // 현재 노드까지의 비용
	int now_node; // 현재 노드
	int tmp_cost;
	while (!pq.empty()) {
		now_dist = -pq.top().first;
		now_node = pq.top().second;
		pq.pop();
		if (d_cost[now_node] < now_dist) { // 기존 경로가 최단경로라면 pass(무시가능)
			continue;
		}
		for (int i = 0; i < graph[now_node].size(); i++) {
			tmp_cost = graph[now_node][i].second;
			// 진행하려는 방향 값(tmp_cost)이
			//기존 경로보다 비용이 더 작다면 priority_queue에 추가
			if (tmp_cost < d_cost[graph[now_node][i].first]) {
				d_cost[graph[now_node][i].first] = tmp_cost; // 최단경로 갱신
				pq.push(make_pair(-tmp_cost, graph[now_node][i].first));
			}
		}
	}
}
int main()
{
	int n,m, start; // n은 노드, m은 간선 개수
	int a, b, c;
	cin >> n >> m >> start;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		// a->b 로가는 비용이 c라는 의미
		graph[a].push_back(make_pair(b, c));
	}
	dijkstra(start);
}