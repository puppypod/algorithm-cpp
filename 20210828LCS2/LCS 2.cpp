#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int DP[4001][4001];

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string str1, str2;
	cin >> str1 >> str2;
	int N = str1.size();
	int M = str2.size();

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (str1[i-1] == str2[j-1]) {
				DP[i][j] = DP[i-1][j-1] + 1;
			}
			else {
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
			}
		}
	}
	
	int length = DP[N][M];
	if (length == 0) {
		cout << 0;
	}
	else {
		deque<char> d;
		cout << length << '\n';
		while (N != 0 && M != 0) {
			if (str1[N - 1] == str2[M - 1]) {
				d.push_front(str1[N - 1]);
				N--;
				M--;
			}
			else if (DP[N][M] == DP[N][M - 1]) {
				M--;
			}
			else if (DP[N][M] == DP[N - 1][M]) {
				N--;
			}
		}
		for (int i = 0; i < d.size(); i++) {
			cout << d[i];
		}
	}
}