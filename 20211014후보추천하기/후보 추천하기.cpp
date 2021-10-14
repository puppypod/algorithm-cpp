#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct info {
	int cnt = 0;
	int time = 0;
	bool isExist = false;
};

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	// ���� Ʋ ����
	int N;
	cin >> N;
	// ��õ Ƚ��
	int recommandN;
	cin >> recommandN;

	vector<info> candidate(101);
	// ���� �Խõ� ���� ����
	int pictureN = 0;

	for (int i = 0; i < recommandN; i++) {
		// �ּ� ��õȽ�� ���ϴ� ����
		int mnRecommand = 1001;
		// ���� ������ �ð� ���ϴ� ����
		int mxTime = 1001;

		// ��õ ���� �л�
		int id; cin >> id;

		// 1. ó�� ��õ �޴� ���
		if (!candidate[id].isExist) {
			// 1-1. ���� ����ִ� ����Ʋ�� �ִٸ�
			if (pictureN < N) {
				pictureN++;
				candidate[id].cnt++;
				candidate[id].time = i + 1;
				candidate[id].isExist = true;
			}
			// 1-2. ����Ʋ�� �� ���ִٸ�
			else {
				int delId = 0;
				// 1-2-1. ��õȽ���� ���� �۰�, ���� ������ ���� ���ϱ�
				for (int j = 1; j <= 100; j++) {
					if (candidate[j].isExist) {
						if (mnRecommand >= candidate[j].cnt) {
							// ��õȽ���� ���ٸ�
							if (mnRecommand == candidate[j].cnt) {
								// ���� ������ ���� ���ϱ�
								if (mxTime > candidate[j].time) {
									delId = j;
									mxTime = candidate[j].time;
								}
							}
							// ��õȽ���� �� ���� ���� �߰ߵȴٸ�
							else {
								delId = j;
								mnRecommand = candidate[j].cnt;
								mxTime = candidate[j].time;
							}
						}
					}
				}

				// 1-2-2. ������ �����ϰ�, ���ο� ���� ���ε�
				candidate[delId].isExist = false;
				candidate[delId].cnt = 0;

				candidate[id].cnt++;
				candidate[id].time = i + 1;
				candidate[id].isExist = true;
			}
		}
		else {
			candidate[id].cnt++;
		}
	}

	for (int i = 1; i <= 100; i++) {
		if (candidate[i].isExist) {
			cout << i << " ";
		}
	}
}