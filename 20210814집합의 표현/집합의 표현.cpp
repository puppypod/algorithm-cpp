#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> parents;

int find(int idx) {
	if (parents[idx] == idx) return idx;

	return parents[idx] = find(parents[idx]);
}
void Union(int a, int b) {
	int pa = find(a);
	int pb = find(b);

	parents[pa] = pb;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;
	parents.resize(N + 1);
	// 배열 초기화
	for (int i = 0; i <= N; i++) {
		parents[i] = i;
	}


	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		// union
		if (a == 0) {
			Union(b, c);
		}
		// find
		else {
			int bp = find(b);
			int cp = find(c);
			if (bp == cp) {
				cout << "YES" << '\n';
			}
			else {
				cout << "NO" << '\n';
			}
		}
	}
}