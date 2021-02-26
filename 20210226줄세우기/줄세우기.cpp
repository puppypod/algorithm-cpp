#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
// 위상정렬 알고리즘
int map[32001]; // 진입차수 기록
vector<int> v[32001]; // i -> 진입번호 check
int main()
{
	queue<int> ans;
	int n, m;
	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		map[b]++;
	}
	for (int i = 1; i <= n; i++) {
		if (map[i] == 0) {
			ans.push(i);
		}
	}
	while (!ans.empty()) {
		int tmp = ans.front();
		cout << tmp << " ";
		ans.pop();
		
		for (int i = 0; i < v[tmp].size(); i++) {
			map[v[tmp][i]]--;
			if (map[v[tmp][i]] == 0) {
				ans.push(v[tmp][i]);
			}
		}
	}
	cout << endl;
}