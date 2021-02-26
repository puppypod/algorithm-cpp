#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> parents;

int find(int idx) {
	if (idx == parents[idx]) {
		return idx;
	}
	return parents[idx] = find(parents[idx]);
}
void merge(int parent, int child) {
	parents[child] = parents[parent];
}
int main()
{
	int v, e;
	cin >> v >> e;
	parents.resize(v + 1);

	int a, b, c;
	vector<vector<int>> dist;
 	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		dist.push_back({ c,a,b });
	}
	for (int i = 1; i <= v; i++) {
		parents[i] = i;
	}
	// 알고리즘 시작
	sort(dist.begin(), dist.end());
	int parent1, parent2;
	int cost;
	int sum = 0;
	for (int i = 0; i < dist.size(); i++) {
		parent1 = find(dist[i][1]);
		parent2 = find(dist[i][2]);
		cost = dist[i][0];

		if (parent1 != parent2) {
			merge(parent1, parent2);
			sum += cost;
		}
	}
	cout << sum << endl;
}