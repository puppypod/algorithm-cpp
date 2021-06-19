#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
vector<int> v;
set<vector<int>> s;
vector<int> tmp;
priority_queue < vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

void combination(int a, int b) {
	if (b == M) {
		vector<int> sTmp;
		for (int num : tmp) {
			sTmp.push_back(num);
		}
		// 존재하지 않는 조합이라면
		do {
			if (s.find(sTmp) == s.end()) {
				s.insert(sTmp);

				pq.push(sTmp);
			}
		} while (next_permutation(sTmp.begin(), sTmp.end()));
		

		return;
	}
	for (int i = a; i < v.size(); i++) {
		tmp[b] = v[i];
		combination(i + 1, b + 1);
	}
}
int main()
{
	cin >> N >> M;
	tmp.resize(M, 0);
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	combination(0, 0);
	while (!pq.empty()) {
		vector<int> ans = pq.top();
		pq.pop();
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
}