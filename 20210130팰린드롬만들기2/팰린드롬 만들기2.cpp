#include<iostream>
using namespace std;

bool check(string str) {
	for (int i = 0; i < str.size() / 2; i++) {
		if (str[i] != str[str.size() - 1 - i]) { // 팰린드롬이 아닐때
			return false;
		}
	}
	return true; // 위 반복문을 거치는 것이 성공한다면 팰린드롬임.
}
int main()
{
	string s;
	cin >> s;

	int idx = 0;
	do {
		if (check(s)) { break; }
		else {
			s.erase(s.size() - idx);
		}
		for (int i = idx; i >= 0; i--) {
			s.push_back(s[i]);
		}
		idx++;
	} while (idx != s.size());
	cout << s.size() << endl;
}