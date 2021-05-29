#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	vector<int> v;
	for (int i = 0; i < 3; i++) {
		string str;
		cin >> str;
		v.push_back(stoi(str.substr(0, 2)) * 60 + stoi(str.substr(3, 2)));
	}

	set<string> s;
	int answer = 0;
	while (1) {
		string time, nickname;
		cin >> time >> nickname;
		if (cin.eof()) { break; }

		int t = stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
		if (v[0] >= t) {
			s.insert(nickname);
		}
		else if (t >= v[1] && t <= v[2]) {
			set<string>::iterator iter;
			if ((iter =s.find(nickname)) != s.end()) {
				s.erase(iter);
				answer++;
			}
		}
	}
	cout << answer;
}