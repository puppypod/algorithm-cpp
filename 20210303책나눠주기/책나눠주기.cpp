#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second != b.second) {
		return a.second < b.second;
	}
	return a.first < b.first;
}
int main()
{
	int t;
	
	cin >> t;
	while (t--) {
		int n, m;
		int visit[1001]{ 0, };
		vector<pair<int, int>> dq;
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			dq.push_back({ a,b });
		}
		sort(dq.begin(), dq.end(), cmp);
		
		int ans = 0;
		for (int i =0; i < m; i++) {
			for (int j = dq[i].first; j <= dq[i].second; j++) {
				if (!visit[j]) {
					visit[j] = 1;
					ans++;
					break;
				}
			}
		}
		cout << ans << endl;
	}
}