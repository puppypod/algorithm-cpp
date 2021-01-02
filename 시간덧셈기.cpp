#include<iostream>
using namespace std;

int main()
{
	int hour=0, minute, second;
	int sSum = 0;
	int mSum = 0;
	int hSum = 0;
	int cnt = 0;

	cout << "시간 덧셈기입니다. -1 -1을 입력하면 종료됩니다.";
	cout << endl << endl;

	
	while (1) {
		cnt++;
		cout << cnt << "번 강좌 '분' '초' 입력 -> ";
		cin >> minute >> second;
		if (second < 0 || minute < 0) { break; }
		
		sSum += second;
		if (sSum >= 60) {
			minute++;
			sSum -= 60;
		}
		mSum += minute;
		if (mSum >= 60) {
			hour++;
			mSum -= 60;
		}
		cout << "누적 시간 -> " << hour << "시 " << mSum << "분 " << sSum << "초";
		cout << endl << endl;
	}

	return 0;
}