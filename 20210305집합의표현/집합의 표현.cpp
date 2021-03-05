#include <iostream>
#include <vector>

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
	return;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	parents.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		parents[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int flag, a, b;
		cin >> flag >> a >> b;
		int parent1 = find(a);
		int parent2 = find(b);
		if (flag) { // 확인
			if (parent1 == parent2) {
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}
		}
		else { // 합치기
			if (parent1 != parent2) {
				merge(parent1, parent2);
			}
		}
	}
}