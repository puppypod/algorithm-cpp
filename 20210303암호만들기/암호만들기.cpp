#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> candidate;
vector<char> answer;
int L, C;
vector<char> mList;
void dfs(int a, int b, int mo, int ja) {
	if (b == L) {
		if (mo<1 || ja<2) { return; }
		for (int i = 0; i < L; i++) {
			cout << answer[i];
		}
		cout << endl;
		return;
	}
	for (int i = a; i < C; i++) {
		answer[b] = candidate[i];
		if (candidate[i] == 'a' || candidate[i] == 'e' ||
			candidate[i] == 'i' || candidate[i] == 'o' || candidate[i] == 'u') {
			dfs(i + 1, b + 1, mo + 1, ja);
		}
		else {
			dfs(i + 1, b + 1, mo, ja + 1);
		}
	}
}
int main()
{
	cin >> L >> C;
	answer.resize(L);
	for (int i = 0; i < C; i++) {
		char c;
		cin >> c;
		
		candidate.push_back(c);
	}
	sort(candidate.begin(), candidate.end());

	dfs(0, 0, 0, 0);
}