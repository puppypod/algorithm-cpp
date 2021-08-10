#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define MAX 1000000000

struct EGResult {
	long long s, t, r;

	EGResult() {
		;
	}
	EGResult(long long s, long long t, long long r) {
		this->r = r;
		this->s = s;
		this->t = t;
	}
};

EGResult extendedGcd(long long a, long long b) { // -> s, t, r 반환
	long long s0 = 1, t0 = 0, r0 = a;
	long long s1 = 0, t1 = 1, r1 = b;

	long long tmp;
	while (r1!=0) {
		long long q = r0 / r1;

		tmp = r0 - r1 * q;
		r0 = r1;
		r1 = tmp;

		tmp = s0 - s1 * q;
		s0 = s1;
		s1 = tmp;

		tmp = t0 - t1 * q;
		t0 = t1;
		t1 = tmp;
	}

	return EGResult(s0, t0, r0);
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// x : 인당 나눠줄 사탕의 수
	// y : 사탕 봉지의 수
	// A(사람 수) * x + 1(하나 더 구매) = B(사탕수) * y
	// Ax + By = C의 형태로 변환
	// -> -Ax + By = 1
	// A(-x) + By = 1 의 형태로 변환

	// 0 < x
	// 0 < y <= 10^9
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		long long A, B; cin >> A >> B;
		EGResult result = extendedGcd(A, B);

		// D = gcd(A,B)
		// Ax + By = c 일때, C%D == 0 이어야 해를 가질 수 있음.
		if (result.r != 1) {
			cout << "IMPOSSIBLE" << '\n';
		}
		else {
			// x0 = s * C/D
			// y0 = t * C/D
			long long x0 = result.s;
			long long y0 = result.t;
			// x = x0 + B/D * k
			// y = y0 - A/D * k
			

			// x < 0 ( -x로 치환하였기 때문에 )
			// x0 + B * k < 0 (치환)
			// k < - x0 / B
			// 0 < y <= 10^9
			// 0 < y0 - A * k <= 10^9
			// - y0 < - A & k <= 10^9 - y0


			// 최종 범위
			// ( y0 - 10^9 ) / A  < k < y0 / A
			//						k < - x0 / B
			long long kFromY = (long long)ceil((double)y0 / (double)A) - 1;
			long long kFromX = (long long)ceil(-(double)x0 / (double)B) - 1;

			// 우측 경계 끝을 만족하는 k
			long long k = min(kFromX, kFromY); 
			long long y = y0 - A * k;

			if (y <= MAX) {
				cout << y << '\n';
			}
			else {
				cout << "IMPOSSIBLE" << '\n';
			}

		}
	}
}