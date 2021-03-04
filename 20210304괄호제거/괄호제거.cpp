#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

vector<char> c;
vector<int> tmp;
vector<pair<int, int>> v;
vector<int> dv(20);
priority_queue<string, vector<string>, greater<string>> pq;
int limit;
int n;
void dfs(int a, int b) {
	if (b == limit) {
		string tmp;
		vector<int> ddv(dv.begin(), dv.begin() + limit * 2);
		sort(ddv.begin(), ddv.end());
		int cnt = 0;
		for (int i = 0; i < c.size(); i++) {
			if (i != ddv[cnt]) {
				tmp.push_back(c[i]);
			}
			else{ 
				cnt++;
				if (cnt == ddv.size()) { cnt--; }
			}
		}
		pq.push(tmp);
		return;
	}
	for (int i = a; i < n; i++) {
		dv[b * 2] = v[i].first;
		dv[b * 2 + 1] = v[i].second;
		dfs(i + 1, b + 1);
	}
}
int main()
{
	string str;
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		c.push_back(str[i]);
		if (str[i] == '(') {
			tmp.push_back(i);
		}
		else if(str[i]==')'){
			v.push_back({ tmp.back(), i });
			tmp.pop_back();
		}
	}
	n = v.size();
	
	for (int i = 1; i <= v.size(); i++) {
		limit = i;
		dfs(0, 0);
	}
	set<string> s;
	while (!pq.empty()) {
		if (s.find(pq.top()) == s.end()) {
			cout << pq.top() << endl;
			s.insert(pq.top());
			pq.pop();
		}
		else {
			pq.pop();
		}
		
	}
}