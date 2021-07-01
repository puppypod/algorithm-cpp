#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<deque<int>> gears(1);
vector<int> check(5, 0);

// �ð���� ȸ��
void rightCycle(int ID) {
	// ��Ϲ��� ȸ�� ��Ű��
	int tmp = gears[ID].back();
	gears[ID].pop_back();
	gears[ID].push_front(tmp);
}
// �ݽð���� ȸ��
void leftCycle(int ID) {
	// ��Ϲ��� ȸ�� ��Ű��
	int tmp = gears[ID].front();
	gears[ID].pop_front();
	gears[ID].push_back(tmp);
}
// ���� ��Ϲ��� Ȯ���ϱ�
void checkGear(int leftPole, int rightPole, int ID, int dir) {
	int tmpDir = dir;
	int cnt = ID;
	// ���� ��Ϲ���'s check
	while (cnt < 4) {
		cnt++;
		// 6������ ���� ��
		if (rightPole != gears[cnt][6]) {
			tmpDir = -tmpDir;
			check[cnt] = tmpDir;
		}
		else { break; }
		// 2������ ���� ��
		rightPole = gears[cnt][2];
	}

	tmpDir = dir;
	cnt = ID;
	// ���� ��Ϲ���'s check
	while (cnt > 1) {
		cnt--;
		// 2������ ���� ��
		if (leftPole != gears[cnt][2]) {
			tmpDir = -tmpDir;
			check[cnt] = tmpDir;
		}
		else { break; }
		// 6������ ���� ��
		leftPole = gears[cnt][6];
	}

	return;
}
// �ֺ� ��Ϲ��� ȸ�� ��Ű��
void restCycle() {
	for (int i = 1; i <= 4; i++) {
		if (check[i] == 0) continue;
		
		// �ð����
		if (check[i] == 1) {
			rightCycle(i);
		}
		// �ݽð����
		else {
			leftCycle(i);
		}
	}

	return;
}
int main()
{
	int K;
	// ��Ϲ��� ���� �Է�
	// 0���� -> ����, 6���� -> ����
	for (int i = 1; i <= 4; i++) {
		deque<int> d;
		for (int j = 0; j < 8; j++) {
			char ch;
			cin >> ch;
			d.push_back(ch - 48);
		}
		gears.push_back(d);
	}

	cin >> K;
	// ��Ϲ��� ��� �Է�
	for (int i = 0; i < K; i++) {
		int ID;
		int dir;
		cin >> ID >> dir;
		int rightPole = gears[ID][2];
		int leftPole = gears[ID][6];
		vector<int> init(5, 0);
		check = init;

		// ���� ��Ϲ��� ����
		checkGear(leftPole, rightPole, ID, dir);

		// �ð���� ȸ���� ���
		if (dir == 1) {
			rightCycle(ID);
		}
		// �ݽð������ ���
		else {
			leftCycle(ID);
		}
		// ������ ��Ϲ��� ������
		restCycle();
	}

	int answer = 0;
	int score[5] = { 0,1,2,4,8 };
	for (int i = 1; i <= 4; i++) {
		// S�� ���� ���ϱ�
		if (gears[i][0] == 1) {
			answer += score[i];
		}
	}
	cout << answer << '\n';

	return 0;
}