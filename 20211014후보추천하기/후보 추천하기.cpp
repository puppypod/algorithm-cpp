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
	
	// 사진 틀 개수
	int N;
	cin >> N;
	// 추천 횟수
	int recommandN;
	cin >> recommandN;

	vector<info> candidate(101);
	// 현재 게시된 사진 개수
	int pictureN = 0;

	for (int i = 0; i < recommandN; i++) {
		// 최소 추천횟수 구하는 변수
		int mnRecommand = 1001;
		// 가장 오래된 시간 구하는 변수
		int mxTime = 1001;

		// 추천 받은 학생
		int id; cin >> id;

		// 1. 처음 추천 받는 경우
		if (!candidate[id].isExist) {
			// 1-1. 아직 비어있는 사진틀이 있다면
			if (pictureN < N) {
				pictureN++;
				candidate[id].cnt++;
				candidate[id].time = i + 1;
				candidate[id].isExist = true;
			}
			// 1-2. 사진틀이 꽉 차있다면
			else {
				int delId = 0;
				// 1-2-1. 추천횟수가 가장 작고, 가장 오래된 사진 구하기
				for (int j = 1; j <= 100; j++) {
					if (candidate[j].isExist) {
						if (mnRecommand >= candidate[j].cnt) {
							// 추천횟수가 같다면
							if (mnRecommand == candidate[j].cnt) {
								// 가장 오래된 사진 구하기
								if (mxTime > candidate[j].time) {
									delId = j;
									mxTime = candidate[j].time;
								}
							}
							// 추천횟수가 더 작은 것이 발견된다면
							else {
								delId = j;
								mnRecommand = candidate[j].cnt;
								mxTime = candidate[j].time;
							}
						}
					}
				}

				// 1-2-2. 사진을 삭제하고, 새로운 사진 업로드
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