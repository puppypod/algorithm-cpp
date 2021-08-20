#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 다익스트라를 위한 우선순위 큐
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

// K 번째 최단 소요시간을 위한 최대힙
vector<priority_queue<int>> heap;

// u->v 백터
vector<pair<int, int>> v[1001];


int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	heap.resize(n + 1);
	// 출발지 초기화
	pq.push({ 0,1 });
	heap[1].push(0);

	// K번째 최단경로 구하기 알고리즘
	while (!pq.empty()) {
		int cost = pq.top().first;
		int now = pq.top().second;
		pq.pop();

		for (int i = 0; i < v[now].size(); i++) {
			int dcost = v[now][i].second;
			int next = v[now][i].first;

			// 아직 k번째 경로가 나오지 않은 경우는 힘에 넣어줌
			if (heap[next].size() < k) {
				heap[next].push(cost + dcost);
				pq.push({ cost + dcost, next });
			}
			// k번째 경로가 이미 존재한다면 
			else {
				// max heap top 부분이 현재 구한값보다 더 크다면
				// max heap의 top 부분은 k+1번째 최단경로이기 때문에 필요없음
				// 즉 pop 해주면 됨.
				if (heap[next].top() > cost + dcost) {
					heap[next].pop();
					heap[next].push(cost + dcost);
					pq.push({ cost + dcost,next });
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (heap[i].size() < k) {
			cout << -1 << '\n';
		}
		else {
			cout << heap[i].top() << '\n';
		}
	}
}