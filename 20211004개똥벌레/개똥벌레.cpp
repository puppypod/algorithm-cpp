#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> bottom;
vector<int> up;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, H;
	cin >> N >> H;

	for (int i = 0; i < N; i++) {
		int n; cin >> n;
		// 석순일 때
		if (i % 2 == 0) {
			bottom.push_back(n);
		}
		// 종유석일 때
		else {
			up.push_back(H - n);
		}
	}

	sort(bottom.begin(), bottom.end());
	sort(up.begin(), up.end());

	int bottomSize = N / 2;

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 1; i <= H; i++) {
		int idx = 0;
		int sum = 0;

		// 1. 석순일 때 확인되는 개수 구하기
		auto bottom_iter = lower_bound(bottom.begin(), bottom.end(), i);
		idx = bottom_iter - bottom.begin();
		sum += (bottomSize - idx);

		// 2. 종유석일 때 확인되는 개수 구하기
		auto up_iter = lower_bound(up.begin(), up.end(), i);
		idx = up_iter - up.begin();
		sum += idx;

		pq.push(sum);
	}

	int standardH = pq.top();
	int countH = 0;
	while (!pq.empty()) {
		if (standardH == pq.top()) {
			countH++;
		}
		else {
			break;
		}
		pq.pop();
	}
	cout << standardH << " " << countH;
}