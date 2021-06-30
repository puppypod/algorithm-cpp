#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> board;

vector<vector<int>> bar(4, vector<int>(4)); // 막대기
vector<vector<int>> square(4, vector<int>(4)); // 정사각형
vector<vector<int>> L(4, vector<int>(4)); // L모양
vector<vector<int>> Z(4, vector<int>(4)); // 지그재그 모양
vector<vector<int>> U(4, vector<int>(4)); // ㅗ 모양

vector<vector<int>> rotation(vector<vector<int>> figure) {
	vector<vector<int>> tmp(4, vector<int>(4, 0));
	// 시계방향으로 회전
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			tmp[i][j] = figure[j][3 - i];
		}
	}
	return tmp;
}
vector<vector<int>> reversal(vector<vector<int>> figure) {
	vector<vector<int>> tmp(4, vector<int>(4, 0));
	// 좌우 반전
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			tmp[i][j] = figure[i][3 - j];
		}
	}

	return tmp;
}

int main()
{
	int answer = -1;

	for (int i = 0; i < 4; i++) {
		bar[i][0] = 1;
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			square[i][j] = 1;
		}
	}
	L[0][0] = 1;
	L[1][0] = 1;
	L[2][0] = 1;
	L[2][1] = 1;

	Z[0][0] = 1;
	Z[1][0] = 1;
	Z[1][1] = 1;
	Z[2][1] = 1;

	U[0][0] = 1;
	U[1][0] = 1;
	U[1][1] = 1;
	U[2][0] = 1;

	cin >> N >> M;
	board.resize(N + 6, vector<int>(M + 6, 0));
	for (int i = 3; i < N + 3; i++) {
		for (int j = 3; j < M + 3; j++) {
			cin >> board[i][j];
		}
	}

	// 일자 막대
	int rn;
	rn = 2;
	while (rn--) {
		for (int i = 0; i < N + 3; i++) {
			for (int j = 0; j < M + 3; j++) {
				int sum = 0;

				for (int a = i; a < i + 4; a++) {
					for (int b = j; b < j + 4; b++) {
						sum += bar[a - i][b - j] * board[a][b];
					}
				}
				answer = max(answer, sum);
			}
		}
		bar = rotation(bar);
	}

	// 정사각형
	for (int i = 0; i < N + 3; i++) {
		for (int j = 0; j < M + 3; j++) {
			int sum = 0;

			for (int a = i; a < i + 4; a++) {
				for (int b = j; b < j + 4; b++) {
					sum += square[a - i][b - j] * board[a][b];
				}
			}
			answer = max(answer, sum);
		}
	}

	// L자 모형
	rn = 8;
	while (rn--) {
		if (rn == 3) {
			L = reversal(L);
		}
		for (int i = 0; i < N + 3; i++) {
			for (int j = 0; j < M + 3; j++) {
				int sum = 0;

				for (int a = i; a < i + 4; a++) {
					for (int b = j; b < j + 4; b++) {
						sum += L[a - i][b - j] * board[a][b];
					}
				}
				answer = max(answer, sum);
			}
		}
		L = rotation(L);
	}

	// 지그재그 모형
	rn = 4;
	while (rn--) {
		if (rn == 1) {
			Z = reversal(Z);
		}
		for (int i = 0; i < N + 3; i++) {
			for (int j = 0; j < M + 3; j++) {
				int sum = 0;

				for (int a = i; a < i + 4; a++) {
					for (int b = j; b < j + 4; b++) {
						sum += Z[a - i][b - j] * board[a][b];
					}
				}
				answer = max(answer, sum);
			}
		}
		Z = rotation(Z);
	}

	// ㅗ 모형
	rn = 4;
	while (rn--) {
		for (int i = 0; i < N + 3; i++) {
			for (int j = 0; j < M + 3; j++) {
				int sum = 0;

				for (int a = i; a < i + 4; a++) {
					for (int b = j; b < j + 4; b++) {
						sum += U[a - i][b - j] * board[a][b];
					}
				}
				answer = max(answer, sum);
			}
		}
		U = rotation(U);
	}


	cout << answer;
}