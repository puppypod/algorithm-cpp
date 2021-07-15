#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> A;
vector<vector<bool>> lineCheck;
int sum = 0;
int answer = 40000;

int makeBoard(int d1, int d2, int x, int y) {
	int maxNum = -1;
	int minNum = 40000;

	int tmp = 0;
	int area5 = 0;
	// 1번 선거구
	for (int r = 1; r < x + d1; r++) {
		for (int c = 1; c <= y; c++) {
			if (!lineCheck[r][c]) continue;
			tmp += A[r][c];
			area5 += A[r][c];
		}
	}
	maxNum = max(maxNum, tmp);
	minNum = min(minNum, tmp);

	// 2번 선거구
	tmp = 0;
	for (int r = 1; r <= x + d2; r++) {
		for (int c = y + 1; c <= N; c++) {
			if (!lineCheck[r][c]) continue;
			tmp += A[r][c];
			area5 += A[r][c];
		}
	}
	maxNum = max(maxNum, tmp);
	minNum = min(minNum, tmp);

	// 3번 선거구
	tmp = 0;
	for (int r = x + d1; r <= N; r++) {
		for (int c = 1; c < y - d1 + d2; c++) {
			if (!lineCheck[r][c]) continue;
			tmp += A[r][c];
			area5 += A[r][c];
		}
	}
	maxNum = max(maxNum, tmp);
	minNum = min(minNum, tmp);

	// 4번 선거구
	tmp = 0;
	for (int r = x + d2 + 1; r <= N; r++) {
		for (int c = y - d1 + d2; c <= N; c++) {
			if (!lineCheck[r][c]) continue;
			tmp += A[r][c];
			area5 += A[r][c];
		}
	}
	maxNum = max(maxNum, tmp);
	minNum = min(minNum, tmp);

	// 5번 선거구
	area5 = sum - area5;
	maxNum = max(maxNum, area5);
	minNum = min(minNum, area5);

	return maxNum - minNum;
}
void makeLine(vector<vector<bool>>& v, int d1, int d2, int x, int y) {
	int limit = d1 + d2;
	int tmp = 0;
	int dd1 = d1;
	int dd2 = d2;
	v[x][y] = false;
	int rightLimit = y;
	while (tmp != limit) {
		x++;
		if (d2 > 0) rightLimit++;
		else rightLimit--;

		if (d1 > 0) y--;
		else y++;

		for (int i = y; i <= rightLimit; i++) {
			v[x][i] = false;
		}

		d2--;
		d1--;

		tmp++;
	}

}
int main()
{
	cin >> N;
	A.resize(N + 1, vector<int>(N + 1));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
			sum += A[i][j];
		}
	}
	// d1 -> i, d2 -> j
	for (int i = 1; i <= N - 1; i++) {
		for (int j = 1; j <= N - i; j++) {
			for (int x = 1; x <= N - 2; x++) {
				if (x + i + j > N) continue;
				for (int y = 2; y <= N - 1; y++) {
					if ((y - i < 1) || (y + j > N)) continue;
					
					vector<vector<bool>> init(N + 1, vector<bool>(N + 1, true));
					lineCheck = init;
					makeLine(lineCheck, i, j, x, y);

					answer = min(makeBoard(i, j, x, y), answer);
				}
			}
		}
	}

	cout << answer;
}