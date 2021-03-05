#include <iostream>
#include <vector>

using namespace std;
vector<string> tmp{ "1","2","3" };
int n;
bool isEnd = false;
string answer;
bool check(string str) {
	int cmp = 1;
	while (1) {
		for (int i = 0; i + cmp * 2 <= str.size(); i++) {
			if (str.substr(i, cmp) == str.substr(i + cmp, cmp)) {
				return false;
			}
		}
		cmp++;
		if (cmp > str.size() / 2) { break; }
	}
	return true;
}
void dfs(string str) {
	if (str.size() == n) {
		answer = str;
		isEnd = true;
		return;
	}
	for (int i = 0; i < 3; i++) {
		if (!str.empty()) {
			if (check(str+tmp[i])) {
				dfs(str + tmp[i]);
				if (isEnd) { return; }
			}
		}
		else {
			dfs(str + tmp[i]);
			if (isEnd) { return; }
		}
	}
}
int main()
{
	cin >> n;
	dfs("");
	cout << answer << endl;
}