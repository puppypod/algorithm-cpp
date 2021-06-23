#include <iostream>
#include <vector>

using namespace std;
int a, b, c;
long long POW(long long target, long long cnt) {
	if (cnt == 0) {
		return 1;
	}
	else if (cnt == 1) {
		return target;
	}
	else if (cnt % 2 != 0) { // 홀수라면 정확히 반으로 나눌 수 없음.
		// 반으로 나눌 수 있게 cnt-1 연산
		return POW(target, cnt - 1) * target;
	}
	long long leftNum = POW(target, cnt / 2);
	leftNum %= c;
	long long rightNum = (leftNum * leftNum) % c;
	return rightNum;
}
int main()
{
	cin >> a >> b >> c;
	cout << POW(a, b) % c << endl;
}