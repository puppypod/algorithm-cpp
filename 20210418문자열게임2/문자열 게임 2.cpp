#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

bool cmp(const string& a, const string& b) {
	return a.size() < b.size();
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testcase;
	cin >> testcase;
	while (testcase--) {
		map<char, int> m;
		vector<char> v;
		vector<string> candidate;
		int K;
		string str;
		cin >> str;
		cin >> K;

		if (K == 1) {
			cout << 1 << " " << 1 << '\n';
			continue;
		}

		// 알파벳 개수 세기 && K개 이상의 알파벳 구하기
		for (int i = 0; i < str.size(); i++) {
			if (m.find(str[i]) != m.end()) {
				m[str[i]]++;
				if (m[str[i]] == K) {
					v.push_back(str[i]);
				}
			}
			else {
				m[str[i]] = 1;
			}
		}

		// 후보 알파벳을 순차적으로 검사
		for (int i = 0; i < v.size(); i++) {
			int count = m[v[i]] - K;
			// start iterator 구하기
			string::iterator itr_start = find(str.begin(), str.end(), v[i]);
			
			int repeat = K - 1;
			// 초반 세팅
			string::iterator itr_end = find(str.begin(), str.end(), v[i]);
			while (repeat--) { // k개 알파벳 구하기
				itr_end = find(itr_end + 1, str.end(), v[i]);
			}
			string cpy(itr_start, itr_end+1);
			candidate.push_back(cpy);
			
			// 알파벳 후보의 갯수가 K 이상이라면 N-K 번 더 검사해야함.
			for (int j = 0; j < count; j++) {
				itr_start = find(itr_start + 1, str.end(), v[i]);
				itr_end = find(itr_end + 1, str.end(), v[i]);
				string cpy2(itr_start, itr_end+1);
				candidate.push_back(cpy2);
			}
		}
		if (!candidate.empty()) {
			sort(candidate.begin(), candidate.end(), cmp);
			cout << candidate[0].size() << " " << candidate[candidate.size() - 1].size() << '\n';
		}
		else {
			cout << -1 << '\n';
		}
	}
}