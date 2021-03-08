#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> DP;

int main()
{
	string str;
	string cmp;
	cin >> str >> cmp;
	DP.resize(str.size() + 1, vector<int>(cmp.size() + 1, 0));
	for (int i = 1; i <= str.size(); i++) {
		for (int j = 1; j <= cmp.size(); j++) {
			if (str[i - 1] == cmp[j - 1]) {
				DP[i][j] = DP[i - 1][j - 1] + 1;
			}
			else {
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
			}
		}
	}
	cout << DP[str.size()][cmp.size()] << endl;
}