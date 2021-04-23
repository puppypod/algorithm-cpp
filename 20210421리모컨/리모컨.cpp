#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int N, M;
vector<bool> remotecontrol(10, true);

bool isTrue(int number) {
	string str = to_string(number);

	for (int i = 0; i < str.size(); i++) {
		if (!remotecontrol[str[i] - '0']) {
			return false;
		}
	}

	return true;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M;

	// 고장난 번호 check
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		remotecontrol[num] = false;
	}

	
	// + 또는 - 만 했을 때의 연산 수
	int minimum = abs(N - 100);

	for (int i = 0; i <= 1000000; i++) {
		// 해당 숫자가 존재한다면
		if (isTrue(i)) {
			// 번호를 누른 횟수를 더하기 위한 작업
			string str_tmp = to_string(i);
			// 비교 숫자와 N의 차이 + 리모컨 번호 누른 횟수
			int tmp = abs(N - i) + str_tmp.size();

			// 최솟 값 구하기
			minimum = min(minimum, tmp);
		}
	}

	//출력
	cout << minimum << '\n';
}