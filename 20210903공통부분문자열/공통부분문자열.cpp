#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int DP[4001][4001];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str1, str2;
	cin >> str1 >> str2;

	for (int i = 0; i < str1.size(); i++) {
		for (int j = 0; j < str2.size(); j++) {
			if (str1[i] == str2[j]) {
				DP[i+1][j+1] = 1;
			}
		}
	}
	int answer = 0;
	for (int i = 1; i <= str1.size(); i++) {
		for (int j = 1; j <= str2.size(); j++) {
			if (DP[i][j] == 1) {
				DP[i][j] = DP[i - 1][j - 1] + 1;
				answer = max(answer, DP[i][j]);
			}
		}
	}
	cout << answer;
}