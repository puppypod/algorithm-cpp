#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, L;
vector<int> restN;

int main()
{
	cin >> N >> M >> L;
	
	restN.push_back(0); // 고속도록 시작
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		restN.push_back(tmp);
	}
	restN.push_back(L); // 고속도로 끝

	sort(restN.begin(), restN.end()); // 정렬

	int left = 1;
	int right = L - 1;

	while (left <= right) {
		int cnt = 0;
		int mid = (left + right) / 2;
		//cout << left << " " << right << endl;
		for (int i = 0; i <= N; i++) {
			if (restN[i + 1] - restN[i] > mid) {
				cnt += (restN[i + 1] - restN[i] - 1) / mid;
			}
		}
		if (cnt > M) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << left << endl;
}