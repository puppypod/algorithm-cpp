#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<pair<int,int>> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(v.front().second);
	for (int i = 1; i < n; i++) {
		bool isNew = true;
		if (pq.top() <= v[i].first) { // 기존 class 유지
			pq.pop();
			pq.push(v[i].second);
		}
		else { // new class 필요
			pq.push(v[i].second);
		}
	}
	cout << pq.size() << endl;
}