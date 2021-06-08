#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define INF 2000000000

int N, E;
int x1, x2;
vector<pair<int,int>> graph[801];
vector<int> dist;

int main()
{
	cin >> N >> E;
	dist.resize(N + 1, INF);
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ c,b });
		graph[b].push_back({ c,a });
	}
	cin >> x1 >> x2;

	priority_queue<pair<int, int>> pq_init;
	
	long long answer = INF;
	for (int i = 0; i < 2; i++) { // x1 -> x2 || x2 -> x1
		priority_queue<pair<int, int>> pq = pq_init;
		vector<int> cpy = dist;
		cpy[1] = 0;
		pq.push({ 0,1 });
		long long sum = 0;
		for (int j = 0; j < 3; j++) {
			if (j == 2) { // last ㄱㄱ
				while (!pq.empty()) {
					int cost = pq.top().first;
					int x = pq.top().second;
					pq.pop();
					for (int i = 0; i < graph[x].size(); i++) {
						int dcost = graph[x][i].first;
						int dx = graph[x][i].second;
						if (cpy[dx] > cost + dcost) {
							cpy[dx] = cost + dcost;
							pq.push({ cpy[dx],dx });
						}
					}
				}
				sum += cpy[N];
			}
			else if ((i + j) % 2 == 0) { // x1 먼저
				while (!pq.empty()) {
					int cost = pq.top().first;
					int x = pq.top().second;
					pq.pop();
					for (int i = 0; i < graph[x].size(); i++) {
						int dcost = graph[x][i].first;
						int dx = graph[x][i].second;
						if (cpy[dx] > cost + dcost) {
							cpy[dx] = cost + dcost;
							pq.push({ cpy[dx],dx });
						}
					}
				}
				sum += cpy[x1];
				pq = pq_init;
				cpy = dist;
				cpy[x1] = 0;
				pq.push({ cpy[x1],x1 });
			}
			else if ((i + j) % 2 == 1) { // x2 먼저
				while (!pq.empty()) {
					int cost = pq.top().first;
					int x = pq.top().second;
					pq.pop();
					for (int i = 0; i < graph[x].size(); i++) {
						int dcost = graph[x][i].first;
						int dx = graph[x][i].second;
						if (cpy[dx] > cost + dcost) {
							cpy[dx] = cost + dcost;
							pq.push({ cpy[dx],dx });
						}
					}
				}
				sum += cpy[x2];
				pq = pq_init;
				cpy = dist;
				cpy[x2] = 0;
				pq.push({ cpy[x2],x2 });
			}
		}
		answer = min(answer, sum);
	}
	if (answer != INF) {
		cout << answer;
	}
	else{
		cout << -1;
	}
}