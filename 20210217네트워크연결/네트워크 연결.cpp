#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> parents;
vector<int> vertex_num;
vector<pair<int,pair<int, int>>> relation;

int find(int idx) {
	if (idx == parents[idx]) {
		return parents[idx];
	}
	return parents[idx] = find(parents[idx]);
}
void merge(int parent, int child) {
	parents[child] = parents[parent];
	vertex_num[parent] += vertex_num[child];
	vertex_num[child] = 1;
}
int main()
{
	int n, m;
	cin >> n >> m;
	vertex_num.resize(n + 1, 1);
	parents.resize(n + 1);
	relation.resize(m);
	int a, b, c; // a<->b 의 비용은 c라는 의미
	for (int i = 1; i <= m; i++) {
		cin >> a >> b >> c;
		relation.push_back(make_pair(c, make_pair(a, b)));
	}
	for (int i = 1; i <= n; i++) {
		parents[i] = i;
	}
	sort(relation.begin(), relation.end());
	int parent1, parent2;
	int cost;
	int sum = 0;
	int cnt = 1;

	for (int i = 0; i < relation.size(); i++) {
		parent1 = find(relation[i].second.first);
		parent2 = find(relation[i].second.second);
		cost = relation[i].first;

		if (parent1 != parent2) {
			cnt++;
			merge(parent1, parent2);
			sum += cost;
			if (cnt == n) { break; }
		}
	}
	cout << sum << endl;
}