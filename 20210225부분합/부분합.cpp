#include <iostream>
#include <vector>
using namespace std;
#define INF 987654321
vector<int> arr;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int left_p, right_p;
	int n, s;
	cin >> n >> s;
	int a;
	int answer = INF;
	int t = 0;
	int sum;
	bool isfisrt = true;

	left_p = 0;
	for (int i = 0; i < n; i++) {
		cin >> a;
		t += a;
		if (t >= s && isfisrt) {
			sum = t;
			right_p = i;
			isfisrt = false;
		}
		arr.push_back(a);
	}
	if (isfisrt) {
		right_p = n;
	}
	while (left_p <= right_p && right_p < n) {
		if (sum < s) {
			right_p++;
			if (right_p < n) {
				sum += arr[right_p];
			}
		}
		else {
			answer = min(answer, right_p - left_p + 1);
			sum -= arr[left_p];
			left_p++;
		}
	}
	if (answer != INF) {
		cout << answer << endl;
	}
	else {
		cout << 0 << endl;
	}
}