#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> parents;

struct Nat {
	int a, b;
	int cost;
};
struct compare {
	bool operator()(const Nat& num1,const Nat& num2) {
		return (num1.cost > num2.cost);
	}
};
priority_queue<Nat, vector<Nat>, compare> pq;

int Find(int idx) {
	if (parents[idx] == idx) return idx;
	return parents[idx] = Find(parents[idx]);
}
void Union(int a, int b) {
	parents[b] = a;
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
	

	for (int i = 0; i < M; i++) {
		int a1, b1, c;
		Nat tmp;
		cin >> a1 >> b1 >> c;
		tmp.a = a1; tmp.b = b1; tmp.cost = c;
		pq.push(tmp);
	}
	int cnt = 0;
	long long sum = 0;
	while (!pq.empty()) {
		int a1 = pq.top().a;
		int b1 = pq.top().b;
		int cost1 = pq.top().cost;
		pq.pop();

		if (cnt == N - 1) break;

		int parent1 = Find(a1);
		int parent2 = Find(b1);

		if (parent1 != parent2) {
			sum += (long long)cost1;
			Union(parent1, parent2);
			cnt++;
		}
	}
	cout << sum << endl;
}