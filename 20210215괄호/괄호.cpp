#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int n;
	vector<string> answer;
	cin >> n;
	vector<vector<string>> problem;
	problem.resize(n);
	string str;
	for (int i = 0; i < n; i++) {
		cin >> str;
		problem[i].push_back(str);
	}
	for (int i = 0; i < n; i++) {
		str = problem[i][0];
		if (str.size() % 2) {
			answer.push_back("NO");
			continue;
		}
		vector<int> v;
		for (int j = 0; j < str.size(); j++) {
			if (str[j] == '(') {
				v.push_back(1);
			}
			else {
				v.push_back(-1);
			}
		}
		int sum = 0;
		bool isTrue = true;
		for (int j = 0; j < v.size(); j++) {
			sum += v[j];
			if (sum < 0) {
				answer.push_back("NO");
				isTrue = false;
				break;
			}
		}
		if (!isTrue) {
			continue;
		}
		if (sum == 0) {
			answer.push_back("YES");
		}
		else {
			answer.push_back("NO");
		}
	}
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}
}