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
	int now_dist; // ���� �������� ���
	int now_node; // ���� ���
	int tmp_cost;
	while (!pq.empty()) {
		now_dist = -pq.top().first;
		now_node = pq.top().second;
		pq.pop();
		if (d_cost[now_node] < now_dist) { // ���� ��ΰ� �ִܰ�ζ�� pass(���ð���)
			continue;
		}
		for (int i = 0; i < graph[now_node].size(); i++) {
			tmp_cost = graph[now_node][i].second;
			// �����Ϸ��� ���� ��(tmp_cost)��
			//���� ��κ��� ����� �� �۴ٸ� priority_queue�� �߰�
			if (tmp_cost < d_cost[graph[now_node][i].first]) {
				d_cost[graph[now_node][i].first] = tmp_cost; // �ִܰ�� ����
				pq.push(make_pair(-tmp_cost, graph[now_node][i].first));
			}
		}
	}
}
int main()
{
	int n,m, start; // n�� ���, m�� ���� ����
	int a, b, c;
	cin >> n >> m >> start;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		// a->b �ΰ��� ����� c��� �ǹ�
		graph[a].push_back(make_pair(b, c));
	}
	dijkstra(start);
}