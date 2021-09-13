#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int DP[2][1000][1000];
int card[1000];

int divideConquer(int left, int right, int flag) {
	// left는 왼쪽, right는 오른쪽, flag는 0이라면 근우 1이라면 명우임.

	// 1. 기저 조건 확인
	if (left == right) {
		// 1-1. 근우라면
		if (flag == 0) {
			return DP[flag][left][right] = card[left];
		}
		// 1-2. 명우라면
		else {
			return DP[flag][left][right] = 0;
		}
	}

	// 2. 이미 값이 존재한다면
	if (DP[flag][left][right] != 0) {
		return DP[flag][left][right];
	}

	// 3. 근우의 최대치 구하기 알고리즘
	// 즉, 분할정복 알고리즘

	// 3-1. 근우 일때
	if (flag == 0) {
		int leftValue = divideConquer(left + 1, right, 1) + card[left];
		int rightValue = divideConquer(left, right - 1, 1) + card[right];
		DP[flag][left][right] = max(leftValue, rightValue);
	}
	// 3-2. 명우 일때
	else {
		int leftValue = divideConquer(left + 1, right, 0);
		int rightValue = divideConquer(left, right - 1, 0);
		DP[flag][left][right] = min(leftValue, rightValue);
	}

	return DP[flag][left][right];

}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int T;
	cin >> T;

	while (T--) {
		memset(DP, 0, sizeof(DP));
		int N; cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> card[i];
		}

		cout << divideConquer(0, N - 1, 0) << '\n';
	}

}