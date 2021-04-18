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

		// ���ĺ� ���� ���� && K�� �̻��� ���ĺ� ���ϱ�
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

		// �ĺ� ���ĺ��� ���������� �˻�
		for (int i = 0; i < v.size(); i++) {
			int count = m[v[i]] - K;
			// start iterator ���ϱ�
			string::iterator itr_start = find(str.begin(), str.end(), v[i]);
			
			int repeat = K - 1;
			// �ʹ� ����
			string::iterator itr_end = find(str.begin(), str.end(), v[i]);
			while (repeat--) { // k�� ���ĺ� ���ϱ�
				itr_end = find(itr_end + 1, str.end(), v[i]);
			}
			string cpy(itr_start, itr_end+1);
			candidate.push_back(cpy);
			
			// ���ĺ� �ĺ��� ������ K �̻��̶�� N-K �� �� �˻��ؾ���.
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