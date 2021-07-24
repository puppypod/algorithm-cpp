#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

bool alphabet[26];
int N, K;
int mx = 0;
bool pickAlpha[26];
vector<string> arr;


void combination(int a, int b) {
	if (b == K-5) {
		int cnt = 0;

		for (int i = 0; i < arr.size(); i++) {
			bool isRight = true;
			for (int j = 0; j < arr[i].size(); j++) {
				if (!pickAlpha[arr[i][j] - 97]) {
					isRight = false; break;
				}
			}
			if (isRight) cnt++;
		}
		mx = max(mx, cnt);

		return;
	}
	for (int i = a; i < 26; i++) {
		if (!pickAlpha[i]) {
			// 0 ~ 25 == a ~ z
			pickAlpha[i] = true;
			combination(i + 1, b + 1);
			pickAlpha[i] = false;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	pickAlpha['a' - 97] = true;
	pickAlpha['n' - 97] = true;
	pickAlpha['t' - 97] = true;
	pickAlpha['i' - 97] = true;
	pickAlpha['c' - 97] = true;

	// ют╥б
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		string str; cin >> str;
		arr.push_back(str.substr(4, str.size() - 8));
	}

	combination(0, 0);
	cout << mx;
}