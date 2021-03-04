#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> crain;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		crain.push_back(n);
	}
	sort(crain.begin(), crain.end(), greater<int>()); // 내림차순 정렬

	int M;
	cin >> M;
	vector<int> box;
	for (int i = 0; i < M; i++) {
		int m;
		cin >> m;
		box.push_back(m);
	}
	sort(box.begin(), box.end(), greater<int>()); // 내림차순 정렬
	if (crain[0] < box[0]) {
		cout << -1;
	}
	else {
		int ans = 0;
		while (box.size()) {
			int idx = 0;
			for (int i = 0; i < box.size(); i++) {
				if (idx == N) { break; }
				if (crain[idx] >= box[i]) {
					idx++;
					box.erase(box.begin() + i);
					i--;
				}
			}
			ans++;
		}
		cout << ans;
	}
}