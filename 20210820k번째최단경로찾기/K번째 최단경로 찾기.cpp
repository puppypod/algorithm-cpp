#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// ���ͽ�Ʈ�� ���� �켱���� ť
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

// K ��° �ִ� �ҿ�ð��� ���� �ִ���
vector<priority_queue<int>> heap;

// u->v ����
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
	// ����� �ʱ�ȭ
	pq.push({ 0,1 });
	heap[1].push(0);

	// K��° �ִܰ�� ���ϱ� �˰���
	while (!pq.empty()) {
		int cost = pq.top().first;
		int now = pq.top().second;
		pq.pop();

		for (int i = 0; i < v[now].size(); i++) {
			int dcost = v[now][i].second;
			int next = v[now][i].first;

			// ���� k��° ��ΰ� ������ ���� ���� ���� �־���
			if (heap[next].size() < k) {
				heap[next].push(cost + dcost);
				pq.push({ cost + dcost, next });
			}
			// k��° ��ΰ� �̹� �����Ѵٸ� 
			else {
				// max heap top �κ��� ���� ���Ѱ����� �� ũ�ٸ�
				// max heap�� top �κ��� k+1��° �ִܰ���̱� ������ �ʿ����
				// �� pop ���ָ� ��.
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