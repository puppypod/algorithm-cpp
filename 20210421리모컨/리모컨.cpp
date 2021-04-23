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

	// ���峭 ��ȣ check
	for (int i = 0; i < M; i++) {
		int num;
		cin >> num;
		remotecontrol[num] = false;
	}

	
	// + �Ǵ� - �� ���� ���� ���� ��
	int minimum = abs(N - 100);

	for (int i = 0; i <= 1000000; i++) {
		// �ش� ���ڰ� �����Ѵٸ�
		if (isTrue(i)) {
			// ��ȣ�� ���� Ƚ���� ���ϱ� ���� �۾�
			string str_tmp = to_string(i);
			// �� ���ڿ� N�� ���� + ������ ��ȣ ���� Ƚ��
			int tmp = abs(N - i) + str_tmp.size();

			// �ּ� �� ���ϱ�
			minimum = min(minimum, tmp);
		}
	}

	//���
	cout << minimum << '\n';
}