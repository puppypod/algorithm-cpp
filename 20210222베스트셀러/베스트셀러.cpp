#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool cmp(pair<string, int> a, pair<string, int> b) {
	return a.second > b.second;
}
int main()
{
	map<string, int> m;
	queue<string> q;
	string str;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		if (m.find(str) == m.end()) {// key가 없다는 뜻
			q.push(str);
			m.insert(make_pair(str, 1));
		}
		else {
			m[str]++;
		}
	}
	int tmp;
	int ans = -1;
	vector<pair<string, int>> v;
	while (!q.empty()) {
		tmp = m[q.front()];
		if (ans <= tmp) {
			ans = tmp;
			v.push_back(make_pair(q.front(), ans));
		}
		q.pop();
	}

	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < v.size(); i++) {
		if (ans != v[i].second) {
			v.erase(v.begin() + i, v.end());
			break;
		}
	}
	sort(v.begin(), v.end());
	cout << v[0].first << endl;
}