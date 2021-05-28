#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, M;
	int answer = 0;
	cin >> N >> M;
	set<string> s;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		s.insert(str);
	}
	for (int i = 0; i < M; i++) {
		string str;
		cin >> str;
		if (s.find(str) != s.end()) {
			answer++;
		}
	}
	
	cout << answer;
	
}