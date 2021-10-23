#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N, C;
	cin >> N >> C;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		int n; cin >> n;
		v.push_back(n);
	}
	sort(v.begin(), v.end());

	int mn = 1;
	int mx = v[N - 1]- v[0];
	int answer = -1;

	while (mn <= mx) {
		int mid = (mn + mx) / 2;

		int left = 0;
		int right = 1;
		int cnt = 1;

		int tmp = 1000000001;
		// mid 거리 간격 만큼이라 가정했을 때 설치 가능한 공유기 갯수구하기
		while (left != N - 1 && right != N) {
			if (v[right] - v[left] >= mid) {
				// 최솟값 구하기
				tmp = min(v[right] - v[left], tmp);
				cnt++;
				left = right;
				right++;
			}
			else {
				right++;
			}
		}
		// 공유기 갯수 충분할 때, 간격 넓히기
		if (cnt >= C) {
			answer = max(tmp, answer);
			mn = mid + 1;
		}
		// 공유기 갯수 충분하지 않을 때, 간격 좁히기
		else {
			mx = mid - 1;
		}
	}
	cout << answer;
}