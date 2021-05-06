#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N, M;
	
	cin >> N >> M;
	vector<vector<int>> map(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char ch;
			cin >> ch;
			map[i][j] = ch - 48;
		}
	}

	// 예외처리
	int result = 0;
	if (N == 1 || M == 1) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 1) {
					cout << 1 << endl;
					return 0;
				}
			}
		}
		cout << 0;
		return 0;
	}
	else {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (i == 0 || j == 0) {
					if (map[i][j] == 1) {
						result = 1;
						break;
					}
				}
			}
			if (result == 1) { break; }
		}
	}


	// DP 알고리즘 시작
	
	int dir[3][2] = { {0,-1} ,{-1,-1} ,{-1,0} };
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < M; j++) {
			if (map[i][j] == 1) {
				int minimum = 1001;
				for (int k = 0; k < 3; k++) {
					int dy = i + dir[k][0];
					int dx = j + dir[k][1];
					minimum = min(map[dy][dx], minimum);
				}
				map[i][j] = minimum + 1;
				result = max(result, map[i][j]);
			}
		}
	}
	cout << result*result << endl;
}