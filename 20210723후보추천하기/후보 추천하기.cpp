#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, K;
	int candidate[101] = { 0, };
	cin >> N >> K;
	// 첫번째는 번호
	// 두번째는 입력 순 idx 값 -> 오래된 사진을 찾기 위함.
	vector<pair<int, int>> v(N);

	for (int i = 0; i < K; i++) {
		int n;
		cin >> n;
		candidate[n]++;
		bool flag = true;
		for (int j = 0; j < N; j++) {
			// new 후보자
			if (v[j].first == 0) {
				v[j].first = n;
				v[j].second = i;
				flag = false;
				break;
			}
			// 중복 후보자
			else if (v[j].first == n)
			{ 
				flag = false; break;
			}
		}
		// 사진이 꽉차있다면
		if (flag) {
			int idx = 0;
			for (int j = 1; j < N; j++) {
				// 낮은 득표수 후보자 구하기
				if (candidate[v[idx].first] > candidate[v[j].first]) {
					idx = j;
				}
				// 같은 득표수가 존재한다면
				else if (candidate[v[idx].first] == candidate[v[j].first]) {
					// 먼저 등록된 것이라면 swap
					if (v[idx].second > v[j].second) {
						idx = j;
					}
				}
			}
			// 후보에서 지우기
			candidate[v[idx].first] = 0;

			v[idx].first = n;
			v[idx].second = i;
		}
	}
	vector<int> answer;
	for (int i = 0; i < N; i++) {
		answer.push_back(v[i].first);
	}
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
}