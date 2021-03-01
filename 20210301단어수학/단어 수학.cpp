#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

bool cmp(const pair<char, long long>& a, const pair<char, long long>& b) {
	return a.second > b.second;
}
int main()
{
	map<char, long long> m;
	string str;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < str.size(); j++) {
			if (m.find(str[j]) == m.end()) {
				m[str[j]] = (long long)pow(10, str.size() - j-1);
			}
			else {
				m[str[j]] += (long long)pow(10, str.size() - j - 1);
			}
		}
	}
	vector<pair<char, long long>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), cmp);
	long long ans = 0;
	int flag = v.size();
	for (int i = 9; i >= 0; i--) {
		if (flag-- == 0) { break; }
		ans += v[9 - i].second * i;
	}
	cout << ans << endl;
}