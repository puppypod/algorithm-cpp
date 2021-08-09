#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool notPrimeNum[1000001] = { false, };
vector<int> primeArr;
int K;
string numStr;

// x는 소수
bool checkIsBad(int x) {
	int ret = 0;
	for (int i = 0; i < numStr.size(); i++) {
		ret = (ret * 10 + (numStr[i] - '0')) % x;
	}

	if (ret == 0) return false;

	else return true;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> numStr >> K;

	// 에라토스테네스의 체
	notPrimeNum[1] = true;
	for (int i = 2; i <= 1000000; i++) {
		if (notPrimeNum[i] == false) {
			primeArr.push_back(i);
			for (int j = i * 2; j <= 1000000; j += i) {
				notPrimeNum[j] = true;
			}
		}
	}

	for (int prime : primeArr) {
		if (prime >= K) {

			break;
		}
		else if (!checkIsBad(prime)) {
			cout << "BAD " << prime << '\n';
			return 0;
		}
	}
	cout << "GOOD" << '\n';
	return 0;
}