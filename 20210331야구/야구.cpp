#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

vector<vector<int>> player;
deque<int> dq;
int innings;
int score = 0;
deque<int> randomNum(8);
deque<int> resultNumArr;
int mx = -1;

void scoreCount() {
	int next = 0;
	for (int i = 0; i < innings; i++) {
		int outCnt = 0;
		int playerNum = 0;
		int sum = 0;
		while (outCnt!=3) {
			next = resultNumArr.front();
			resultNumArr.pop_front();
			resultNumArr.push_back(next);
			int number = player[i][next];
			// 선수가 아웃되었다면 outCnt + 1
			if (number == 0) {
				outCnt++;
			}
			else {
				
				if (dq.empty()) {
					if (number != 4) {
						dq.push_back(number);
					}
					else{
						score++;
					}
				}
				else {
					int a = dq.size();
					if (number == 4) {
						while (!dq.empty()) { dq.pop_front(); }
						score += a + 1;
					}
					else {
						while (a--) {
							if (dq.front() + number >= 4) {
								score++;
								dq.pop_front();
							}
							else {
								dq.push_back(dq.front() + number);
								dq.pop_front();
							}
						}
						dq.push_back(number);
					}
				}
			}
		}
		dq.clear();
	}
}
int main()
{
	cin >> innings;
	player.resize(innings, vector<int>(9));
	for (int i = 0; i < innings; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> player[i][j];
		}
	}
	for (int i = 1; i < 9; i++) {
		randomNum[i - 1] = i;
	}
	// 2~9번 타자 순열로 섞어줘야함.
	do {
		
		resultNumArr = randomNum;
		resultNumArr.insert(resultNumArr.begin() + 3, 0); // 순서 세팅
		score = 0;

		scoreCount();

		mx = max(mx, score);
		
	} while (next_permutation(randomNum.begin(), randomNum.end()));
	cout << mx << endl;
}