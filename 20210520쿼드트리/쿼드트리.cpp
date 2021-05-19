#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int>> map;
string answer;

void dfs(int r, int c, int n) {
	if (n == 0) { return; }
	bool isTrue = true;
	cout << "(";

	// 왼쪽 위
	int target = map[r][c];
	for (int i = r; i < r + n; i++) {
		for (int j = c; j < c + n; j++) {
			if (map[i][j] != target) {
				dfs(r, c, n / 2);
				isTrue = false;
				break;
			}
		}
		if (!isTrue) { break; }
	}
	if (isTrue) {
		cout << target;
	}

	// 오른쪽 위
	isTrue = true;
	target = map[r][c + n];
	for (int i = r; i < r + n; i++) {
		for (int j = c + n; j < c + 2*n; j++) {
			if (map[i][j] != target) {
				dfs(r, c + n, n / 2);
				isTrue = false;
				break;
			}
		}
		if (!isTrue) { break; }
	}
	if (isTrue) {
		cout << target;
	}

	// 왼쪽 아래
	isTrue = true;
	target = map[r + n][c];
	for (int i = r + n; i < r + 2 * n; i++) {
		for (int j = c; j < c + n; j++) {
			if (map[i][j] != target) {
				dfs(r + n, c, n / 2);
				isTrue = false;
				break;
			}
		}
		if (!isTrue) { break; }
	}
	if (isTrue) {
		cout << target;
	}

	// 오른쪽 아래
	isTrue = true;
	target = map[r + n][c + n];
	for (int i = r + n; i < r + 2 * n; i++) {
		for (int j = c + n; j < c + 2 * n; j++) {
			if (map[i][j] != target) {
				dfs(r + n, c + n, n / 2);
				isTrue = false;
				break;
			}
		}
		if (!isTrue) { break; }
	}
	if (isTrue) {
		cout << target;
	}

	cout << ")";
	return;
}
int main()
{
	cin >> N;
	map.resize(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char ch;
			cin >> ch;
			map[i][j] = ch - 48;
		}
	}

	int target = map[0][0];
	bool isTrue = true;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] != target) {
				dfs(0, 0, N/2);
				isTrue = false;
				break;
			}
		}
		if (!isTrue) { break; }
	}
	if (isTrue) {
		cout << target;
	}

}