#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// 누적합 문제임 + 유클리드 호제법

// gcd(a,b) == gcd(b, a%b), stop when a%b==0
int gcd(int a, int b) {
	int r;
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	vector<int> v;
	cin >> N;
	
	vector<pair<int, int>> LtoR_RtoL(N);
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		v.push_back(a);
	}
	int a = v[0];

	for (int i = -1; i < N-1; i++) {
		if (i == -1) {
			LtoR_RtoL[0].first = v[0];
			continue;
		}
		
		int b = v[i + 1];
		a = LtoR_RtoL[i+1].first = gcd(a, b);
	}

	a = v[N - 1];

	for (int i = N; i >= 1; i--) {
		if (i == N) {
			LtoR_RtoL[N - 1].second = v[N - 1];
			continue;
		}
		int b = v[i - 1];
		a = LtoR_RtoL[i-1].second = gcd(a, b);
	}

	int answer = -1;
	int K = -1;

	for (int i = 0; i < N; i++) {
		if (i == 0) {
			if (answer < LtoR_RtoL[1].second) {
				if (v[i] % LtoR_RtoL[1].second != 0) {
					K = v[i];
					answer = LtoR_RtoL[1].second;
				}
			}
		}
		else if (i == N - 1) {
			if (answer < LtoR_RtoL[N - 2].first) {
				if (v[i] % LtoR_RtoL[N - 2].first != 0) {
					K = v[i];
					answer = LtoR_RtoL[N - 2].first;
				}
			}
		}
		else {
			
			int tmp = gcd(LtoR_RtoL[i - 1].first, LtoR_RtoL[i + 1].second);
			if (answer < tmp) {
				if (v[i] % tmp != 0) {
					K = v[i];
					answer = tmp;
				}
			}
			
		}
	}
	if (answer == -1) {
		cout << answer << '\n';
	}
	else {
		cout << answer << " " << K << '\n';
	}
}