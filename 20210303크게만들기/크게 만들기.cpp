#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	string str;
	cin >> str;
	deque<char> dq;

	for (int i = 0; i < str.size(); i++) {
		while (k && !dq.empty() && dq.back() < str[i]) {
			dq.pop_back();
			k--;
		}
		dq.push_back(str[i]);
	}
	
	for (int i = 0; i < dq.size()-k; i++) {
		cout << dq[i];
	}
}