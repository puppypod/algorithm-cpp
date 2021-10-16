#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int s = 1;

vector<int> tree;
vector<int> performance;
vector<int> sortPerformance;
int answer = 0;

bool cmp(int a, int b) {
	return a > b;
}
void update(int left, int right, int node, int target, int result) {
	// 1. 범위를 벗어났다면
	if (target < left || right < target) {
		return;
	}
	// 2. 범위에 포함된다면
	else {
		tree[node]++;
		if (left == right) {
			answer = result;
			return;
		}
		int mid = (left + right) / 2;
		// 2-1. 왼쪽
		update(left, mid, node * 2, target, result);
		// 2-2. 오른쪽
		update(mid + 1, right, node * 2 + 1, target, result + tree[node * 2]);

		return;
	}
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n; cin >> n;
		performance.push_back(n);
		sortPerformance.push_back(n);
	}
	sort(sortPerformance.begin(), sortPerformance.end());
	
	while (s < N) s *= 2;
	tree.resize(s * 2, 0);

	for (int pf : performance) {
		auto iter = lower_bound(sortPerformance.begin(), sortPerformance.end(), pf);
		int idx = (iter - sortPerformance.begin());
		// 1. 선수 update
		update(1, s, 1, N - idx, 1);
		cout << answer << '\n';
	}
}