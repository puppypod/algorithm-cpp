#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int cnt = 0;
	long long tmp;
	int a, b; // a(������) -> b(������) �� �����ؾ� �����ϴ� ����
	bool isTrue;
	int n;
	long long ans = -1;
	long long i = 0;
	int rset;
	cin >> n;

	while (1) {
		rset = 0;
		if (i >= 10) {
			isTrue = true;
			tmp = i;
			if (tmp > 9876543210) { break; }
			while (tmp >= 10) {
				a = tmp % 10;
				tmp /= 10;
				b = tmp % 10;
				if (a >= b) { // �����ϴ� ���� �ƴ� ���
					isTrue = false;
					tmp += 1;
					rset++;
				}
			}
			if (rset) {
				i /= (pow(10, rset));
				i += 1;
				i *= pow(10, rset);
				i--; // i�� ������ �������� �۾�
			}
			if (isTrue) {
				if (n == cnt) {

					ans = i;
					break; 
				}
				cnt++;
			}
			if (cnt >= 1000000) {
				break;
			}
		}
		else {
			if (n == cnt) {
				ans = i;
				break;
			}
			cnt++;
		}
		i++;
	}
	cout << ans << endl;
}