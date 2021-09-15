#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

vector<char> input;
string candidate;



void selectAlpha(int a, int b, int k, int cnsNum, int gthNum) {
	if (b == k) {
		// 자음은 최소 2개, 모음은 최소 1개를 갖춰야하기 때문임.
		if (cnsNum < 2 || gthNum < 1) return;

		cout << candidate << '\n';

		return;
	}

	for (int i = a; i < input.size(); i++) {
		candidate[b] = input[i];

		if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i'
			|| input[i] == 'o' || input[i] == 'u') {
			selectAlpha(i + 1, b + 1, k, cnsNum, gthNum + 1);
		}
		else {
			selectAlpha(i + 1, b + 1, k, cnsNum + 1, gthNum);
		}

		
	}
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int L, C;
	cin >> L >> C;
	candidate.resize(L);
	for (int i = 0; i < C; i++) {
		char c; cin >> c;
		input.push_back(c);
	}
	sort(input.begin(), input.end());

	selectAlpha(0, 0, L, 0, 0);
}
