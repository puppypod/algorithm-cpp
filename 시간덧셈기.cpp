#include<iostream>
using namespace std;

int main()
{
	int hour=0, minute, second;
	int sSum = 0;
	int mSum = 0;
	int hSum = 0;
	int cnt = 0;

	cout << "�ð� �������Դϴ�. -1 -1�� �Է��ϸ� ����˴ϴ�.";
	cout << endl << endl;

	
	while (1) {
		cnt++;
		cout << cnt << "�� ���� '��' '��' �Է� -> ";
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
		cout << "���� �ð� -> " << hour << "�� " << mSum << "�� " << sSum << "��";
		cout << endl << endl;
	}

	return 0;
}