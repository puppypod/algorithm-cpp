#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int DP[2][1000][1000];
int card[1000];

int divideConquer(int left, int right, int flag) {
	// left�� ����, right�� ������, flag�� 0�̶�� �ٿ� 1�̶�� �����.

	// 1. ���� ���� Ȯ��
	if (left == right) {
		// 1-1. �ٿ���
		if (flag == 0) {
			return DP[flag][left][right] = card[left];
		}
		// 1-2. �����
		else {
			return DP[flag][left][right] = 0;
		}
	}

	// 2. �̹� ���� �����Ѵٸ�
	if (DP[flag][left][right] != 0) {
		return DP[flag][left][right];
	}

	// 3. �ٿ��� �ִ�ġ ���ϱ� �˰���
	// ��, �������� �˰���

	// 3-1. �ٿ� �϶�
	if (flag == 0) {
		int leftValue = divideConquer(left + 1, right, 1) + card[left];
		int rightValue = divideConquer(left, right - 1, 1) + card[right];
		DP[flag][left][right] = max(leftValue, rightValue);
	}
	// 3-2. ��� �϶�
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