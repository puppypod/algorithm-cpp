#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool>> isTrue; // 같은지 check해주는 배열
void change(int r, int c) {
	for (int i = r; i < r + 3; i++) {
		for (int j = c; j < c + 3; j++) {
			isTrue[i][j] = !isTrue[i][j];
		}
	}
}
int main()
{
	vector<vector<int>> src;
	vector<vector<int>> dest;
	int n, m;
	cin >> n >> m;
	src.resize(n, vector<int>(m));
	dest.resize(n, vector<int>(m));
	isTrue.resize(n, vector<bool>(m));
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &src[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &dest[i][j]);
			if (src[i][j] != dest[i][j]) {
				isTrue[i][j] = false;
			}
			else {
				isTrue[i][j] = true;
			}
		}
	}
	if (n < 3 || m < 3) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!isTrue[i][j]) {
					cout << -1 << endl;
					return 0;
				}
			}
		}
		cout << 0 < endl;
		return 0;
	}
	// 본격적인 알고리즘 시작
	for (int i = 0; i <= n - 3; i++) {
		for (int j = 0; j <= m - 3; j++) {
			if (!isTrue[i][j]) {
				answer++;
				change(i, j);
			}
		}
		
		// 끝부분 check
		for (int j = m - 3; j < m; j++) {
			if (!isTrue[i][j]) {
				answer = -1;
				break;
			}
		}
		if (answer == -1) { break; }
	}
	if (answer == -1) { cout << -1 << endl; }
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!isTrue[i][j]) {
					cout << -1 << endl;
					return 0;
				}
			}
		}
		cout << answer << endl;
	}
	
}