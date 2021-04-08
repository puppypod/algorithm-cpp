#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
vector<pair<int, int>> v[100001];
vector<int> visit;
int costMx = -1;
int src, dest;

bool isPossible;

void bfs(int costTmp) {
	queue<int> q;
	q.push(src);
	visit[src] = 1;
	while (!q.empty()) {
		int dv = q.front();
		q.pop();
		if (dv == dest) {
			isPossible = true;
			return;
		}

		for (pair<int, int> tmp : v[dv]) {
			int next = tmp.first;
			int costNext = tmp.second;
			if (!visit[next] && costNext >= costTmp) {
				visit[next] = 1;
				q.push(next);
			}
		}
	}
	isPossible = false;
	return;
}
int main()
{
	cin >> N >> M;
	visit.resize(N + 1, 0);
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });

		costMx = max(costMx, c);
	}
	cin >> src >> dest;

	int low = 0;
	int high = costMx;
	vector<int> init(N + 1, 0);

	while (low <= high) {
		visit = init;

		int mid = (low + high) / 2;
		isPossible = false;
		bfs(mid);
		if (isPossible) { // mid 무게로 가능
			low = mid + 1;
		}
		else { // mid 무게로 불가능
			high = mid - 1;
		}
	}
	cout << high << endl;
}