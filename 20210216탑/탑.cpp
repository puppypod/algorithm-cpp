#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int num;
	vector<int> answer;
	vector<pair<int, int>> check;
	for (int i = 0; i < n; i++) {
		cin >> num;
		while (!check.empty()) {
			if (num < check.back().first) {
				answer.push_back(check.back().second);
				check.push_back(make_pair(num, i + 1));
				break;
			}
			check.pop_back();
		}
		if (check.empty()) {
			answer.push_back(0);
			check.push_back(make_pair(num, i + 1));
		}
	}
	
	
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
	cout << endl;
}