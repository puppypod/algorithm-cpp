#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
int lcm(int a, int b) {
	return a * b / gcd(a, b);
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int testcase;
	cin >> testcase;

	while (testcase--) {
		int M, N, x, y;
		cin >> M >> N >> x >> y;
		int limit = lcm(M, N);
		int i;
		for (i = x; i <= limit; i+=M) {
			int tmp = (i % N == 0) ? N : i % N;
			if (tmp == y) {
				cout << i << '\n';
				break;
			}
		}
		if (i > limit) { cout << -1 << '\n'; }
	}
}