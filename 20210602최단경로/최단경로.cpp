#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 987654321
vector<pair<int, int>> arrowV[300001];

int main()
{
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);
	int V, E;
	cin >> V >> E;
	int startV;
	cin >> startV;
	vector<int> arr(V+1, INF);
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	arr[startV] = 0;
	pq.push({ 0,startV });

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		// u == a, v == b, w == c;
		arrowV[a].push_back({ c,b });
	}
	/*for (int i = 1; i <= V; i++) {
		sort(arrowV[i].begin(), arrowV[i].end());
	}*/

	while (!pq.empty()) {
		int cost = pq.top().first;
		int vertex = pq.top().second;
		pq.pop();

		for (int i = 0; i < arrowV[vertex].size(); i++) {
			int dCost = arrowV[vertex][i].first;
			int dVertex = arrowV[vertex][i].second;
			if (arr[dVertex] > cost + dCost) {
				arr[dVertex] = cost + dCost;
				pq.push({ arr[dVertex], dVertex });
			}
		}
	}
	for (int i = 1; i <= V; i++) {
		if (arr[i] == INF) {
			cout << "INF" << '\n';
			continue;
		}
		cout << arr[i] << '\n';
	}
}