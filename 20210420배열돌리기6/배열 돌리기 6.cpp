#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int>> map;
int N, R;

void operation_matrix(int K, int l) {
	int L = pow(2, l);
	int r = 0;
	int c = 0;
	int cnt = pow(N / L, 2);
	vector<vector<int>> tmp = map;
	if (K == 1) { // 상하
		while (cnt--) {
			for (int i = r; i < r + L; i++) {
				for (int j = c; j < c + L; j++) {
					map[i][j] = tmp[r*2 + L - 1 - i][j];
				}
			}
			c = (c + L) % N;
			if (c == 0) {
				r = (r + L) % N;
			}
		}
	}
	else if (K == 2) { // 좌우
		while (cnt--) {
			for (int i = r; i < r + L; i++) {
				for (int j = c; j < c + L; j++) {
					map[i][j] = tmp[i][c * 2 + L - 1 - j];
				}
			}
			c = (c + L) % N;
			if (c == 0) {
				r = (r + L) % N;
			}
		}
	}
	else if (K == 3) { // 시계방향 90
		while (cnt--) {
			for (int i = r; i < r + L; i++) {
				for (int j = c; j < c + L; j++) {
					map[i][j] = tmp[c + L - 1 - j + r][i + c - r];
				}
			}
			c = (c + L) % N;
			if (c == 0) {
				r = (r + L) % N;
			}
		}
	}
	else if (K == 4) { // 반시계방향 90
		while (cnt--) {
			for (int i = r; i < r + L; i++) {
				for (int j = c; j < c + L; j++) {
					map[i][j] = tmp[j + r - c][c + L - 1 - i + r];
				}
			}
			c = (c + L) % N;
			if (c == 0) {
				r = (r + L) % N;
			}
		}
	}
	else if (K == 5) {
		for (int a = 0; a < N; a += L) {
			for (int b = 0; b < N; b += L) {

				for (int i = 0; i < L; i++) {
					for (int j = b; j < b + L; j++) {
						map[i + a][j] = tmp[N - L - a + i][j];
					}
				}

			}
		}
	}
	else if (K == 6) {
		for (int a = 0; a < N; a += L) {
			for (int b = 0; b < N; b += L) {

				for (int i = a; i < a + L; i++) {
					for (int j = 0; j < L; j++) {
						map[i][j + b] = tmp[i][N - L - b + j];
					}
				}

			}
		}
	}
	else if (K == 7) {
		for (int a = 0; a < N; a += L) {
			for (int b = 0; b < N; b += L) {

				for (int i = 0; i < L; i++) {
					for (int j = 0; j < L; j++) {
						map[i + a][j + b] = tmp[N - b - L + i][a + j];
					}
				}

			}
		}
	}
	else if (K == 8) {
		for (int a = 0; a < N; a += L) {
			for (int b = 0; b < N; b += L) {

				for (int i = 0; i < L; i++) {
					for (int j = 0; j < L; j++) {
						map[i + a][j + b] = tmp[b + i][N - a -L + j];
					}
				}

			}
		}
	}

	return;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n >> R;
	N = pow(2, n);
	map.resize(N, vector<int>(N));

	// map 입력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	// 명령어 입력 및 수행
	for (int i = 0; i < R; i++) {
		int k, l;
		cin >> k >> l;
		// 명령을 수행하는 함수
		operation_matrix(k, l);
	}

	// 결과 출력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j] << " ";
		}
		cout << '\n';
	}

}