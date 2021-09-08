#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int DP[200][200];
int light[200];
int N, K;

// left의 색으로 전부 만들었다고 가정한다.
int divideConquer(int left, int right) {
	//1. 반환 조건
	if (left == right) {
		return 0;
	}

	// 2. 이미 값을 구했을 경우
	if (DP[left][right] != 0) {
		return DP[left][right];
	}

	// 3. 탐색 시작
	int mn = 987654321;
	for (int i = left;  i < right; i++) {
		int l_v = divideConquer(left, i);
		int r_v = divideConquer(i + 1, right);
		// 서로 같은 구간이라면
		if (light[left] == light[i+1]) {
			mn = min(mn, l_v + r_v);
		}
		// 서로 같은 구간이라면
		else {
			mn = min(mn, l_v + r_v + 1);
		}
		
	}

	return DP[left][right] = mn;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> light[i];
	}

	cout<<divideConquer(0, N - 1);
}