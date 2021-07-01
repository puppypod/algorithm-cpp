#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<deque<int>> gears(1);
vector<int> check(5, 0);

// 시계방향 회전
void rightCycle(int ID) {
	// 톱니바퀴 회전 시키기
	int tmp = gears[ID].back();
	gears[ID].pop_back();
	gears[ID].push_front(tmp);
}
// 반시계방향 회전
void leftCycle(int ID) {
	// 톱니바퀴 회전 시키기
	int tmp = gears[ID].front();
	gears[ID].pop_front();
	gears[ID].push_back(tmp);
}
// 돌릴 톱니바퀴 확인하기
void checkGear(int leftPole, int rightPole, int ID, int dir) {
	int tmpDir = dir;
	int cnt = ID;
	// 우측 톱니바퀴's check
	while (cnt < 4) {
		cnt++;
		// 6번방은 좌측 극
		if (rightPole != gears[cnt][6]) {
			tmpDir = -tmpDir;
			check[cnt] = tmpDir;
		}
		else { break; }
		// 2번방은 우측 극
		rightPole = gears[cnt][2];
	}

	tmpDir = dir;
	cnt = ID;
	// 좌측 톱니바퀴's check
	while (cnt > 1) {
		cnt--;
		// 2번방은 우측 극
		if (leftPole != gears[cnt][2]) {
			tmpDir = -tmpDir;
			check[cnt] = tmpDir;
		}
		else { break; }
		// 6번방은 좌측 극
		leftPole = gears[cnt][6];
	}

	return;
}
// 주변 톱니바퀴 회전 시키기
void restCycle() {
	for (int i = 1; i <= 4; i++) {
		if (check[i] == 0) continue;
		
		// 시계방향
		if (check[i] == 1) {
			rightCycle(i);
		}
		// 반시계방향
		else {
			leftCycle(i);
		}
	}

	return;
}
int main()
{
	int K;
	// 톱니바퀴 정보 입력
	// 0번방 -> 우측, 6번방 -> 좌측
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
	// 톱니바퀴 명령 입력
	for (int i = 0; i < K; i++) {
		int ID;
		int dir;
		cin >> ID >> dir;
		int rightPole = gears[ID][2];
		int leftPole = gears[ID][6];
		vector<int> init(5, 0);
		check = init;

		// 돌릴 톱니바퀴 선정
		checkGear(leftPole, rightPole, ID, dir);

		// 시계방향 회전일 경우
		if (dir == 1) {
			rightCycle(ID);
		}
		// 반시계방향을 경우
		else {
			leftCycle(ID);
		}
		// 나머지 톱니바퀴 돌리기
		restCycle();
	}

	int answer = 0;
	int score[5] = { 0,1,2,4,8 };
	for (int i = 1; i <= 4; i++) {
		// S극 점수 구하기
		if (gears[i][0] == 1) {
			answer += score[i];
		}
	}
	cout << answer << '\n';

	return 0;
}