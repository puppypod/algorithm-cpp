#include <iostream>
#include <vector>
#include <queue>
#include <cctype>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testcase;
	cin >> testcase;
	while (testcase--) {
		string oper;
		int n;
		string arr;
		deque<int> d;
		cin >> oper >> n >> arr;
		int prev = 1;
		int idx = 1;
		while ((idx = arr.find(",", prev)) != string::npos) {
			d.push_back(stoi(arr.substr(prev, idx - prev)));
			prev = idx + 1;
		}
		if (isdigit(arr[prev])) {
			d.push_back(stoi(arr.substr(prev, arr.size() - 1 - prev)));
		}

		bool isTrue = true;
		bool flag = true;
		int rev = 0;
		int del = 0;
		idx = 0;
		for (int i = 0; i < oper.size()-1; i++) {
			if (oper[i] != oper[i + 1]) {
				if (oper[i] == 'R') {
					rev = i + 1 - idx;
					idx = i + 1;
					if (rev % 2 == 1) {
						flag = !flag;
					}
				}
				else {
					del = i + 1 - idx;
					idx = i + 1;
					if (d.size() < del) {
						isTrue = false;
						cout << "error" << '\n';
						break;
					}
					for (int j = 0; j < del; j++) {
						if (flag) {
							d.pop_front();
						}
						else {
							d.pop_back();
						}
					}
				}
			}
		}
		if (isTrue) {
			if (oper[idx] == 'R') {
				if ((oper.size() - idx) % 2 == 1) {
					flag = !flag;
				}
			}
			else {
				del = oper.size() - idx;
				if (d.size() < del) {
					cout << "error" << "\n";
					continue;
				}
				else {
					for (int j = 0; j < del; j++) {
						if (flag) {
							d.pop_front();
						}
						else {
							d.pop_back();
						}
					}
				}
			}
			cout << "[";
			if (!d.empty()) {
				if (!flag) {
					reverse(d.begin(), d.end());
				}
				for (int i = 0; i < d.size() - 1; i++) {
					cout << d[i] << ",";
				}
				cout << d[d.size() - 1];
			}
			cout << "]" << '\n';

		}
	}
}