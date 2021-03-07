#include <iostream>
#include <vector>

using namespace std;

vector<int> parents;
vector<vector<int>> map;
int find(int idx) {
	if (idx == parents[idx]) {
		return idx;
	}
	return parents[idx] = find(parents[idx]);
}
void merge(int parent, int child) {
	parents[child] = parents[parent];
	return;
}
int main()
{
	int n, m;
	cin >> n >> m;
	parents.resize(n + 1);
	map.resize(n + 1, vector<int>(n + 1, 0));
	for (int i = 1; i <= n; i++) {
		parents[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int n;
			cin >> n;
			map[i][j] = n;
			if (i < j && map[i][j]) {
				int parent1 = find(i);
				int parent2 = find(j);
				if (parent1 != parent2) {
					merge(parent1, parent2);
				}
			}
		}
	}
	int num;
	cin >> num;
	int cmp = find(parents[num]);
	for (int i = 0; i < m - 1; i++) {
		cin >> num;
		if (cmp != find(parents[num])) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}