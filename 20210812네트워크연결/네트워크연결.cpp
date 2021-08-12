#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> parents;
vector<int> vertex;

struct Nat {
	int a, b;
	int cost;
};

int Find(int idx) {
	if (parents[idx] == idx) return idx;
	return parents[idx] = Find(parents[idx]);
}
void Union(int a, int b) {

	parents[b] = a;
	vertex[b] += vertex[a];
	vertex[a] = 1;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M;

	cin >> N >> M;

	parents.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		parents[i] = i;
	}
	vertex.resize(N + 1, 1);
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		pq.push({ c,{a,b} });
	}
	int cnt = 0;
	long long sum = 0;
	while (!pq.empty()) {
		int a = pq.top().second.first;
		int b = pq.top().second.second;
		int cost = pq.top().first;
		pq.pop();

		if (cnt == N - 1) break;

		int parent1 = Find(a);
		int parent2 = Find(b);

		if (parent1 != parent2) {
			sum += (long long)cost;
			Union(parent1, parent2);
			cnt++;
		}
	}
	cout << sum << endl;
}