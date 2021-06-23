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
	else if (cnt % 2 != 0) { // Ȧ����� ��Ȯ�� ������ ���� �� ����.
		// ������ ���� �� �ְ� cnt-1 ����
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