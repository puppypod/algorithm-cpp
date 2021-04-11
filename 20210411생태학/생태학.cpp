#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string str;
	map<string, int> m;
	int cnt = 0;
	while (getline(cin, str)) {
		cnt++;
		if (m.find(str) != m.end()) {
			m[str]++;
		}
		else {
			m[str] = 1;
		}
	}
	cout << fixed;
	cout.precision(4);

	vector<pair<string, int>> v(m.begin(), m.end());
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		double tmp = (double)v[i].second / (double)cnt * 100;
		cout << v[i].first << " " << tmp<< endl;
	}
}