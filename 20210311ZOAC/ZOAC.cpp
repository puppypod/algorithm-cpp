#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


vector<int> visit;
string str;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> str;
	visit.resize(str.size(), 0);

	for (int i = 0; i < str.size(); i++) {
		vector<pair<string, int>> v;
		//문자의 수를 늘려가며 비교
		for (int j = 0; j < str.size(); j++) {
			if (!visit[j]) {
				string tmp;
				for (int k = 0; k < str.size(); k++) {
					if (j == k || visit[k]) {
						tmp += str[k];
					}
				}
				v.push_back({ tmp,j });
			}
		}
		sort(v.begin(), v.end());
		cout << v[0].first << '\n';
		visit[v[0].second] = 1;
	}
}