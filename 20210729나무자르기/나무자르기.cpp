#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<long long> trees;
	long long minNum = 0;
	long long maxNum = -1;
	for (int i = 0; i < N; i++) {
		long long tmp; cin >> tmp; trees.push_back(tmp);
		maxNum = max(maxNum, tmp);
	}
	long long start = 0;
	long long end = maxNum;
	long long mid = 0;
	long long answer = 0;

	while (start <= end) {
		mid = (start + end) / 2;
		long long sum = 0;
		for (int i = 0; i < N; i++) {
			if (trees[i] > mid) {
				sum += trees[i]-mid;
			}
		}
		if (sum == M) {
			answer = mid;
			break;
		}
		else if (sum < M) {
			end = mid - 1;
		}
		else {
			start = mid + 1;
			// 이부분이 가장 중요한 포인트
			answer = mid;
		}
	}
	cout << answer;
}