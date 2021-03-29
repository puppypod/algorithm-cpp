#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MIN 987654321
vector<vector<int>> map(10, vector<int>(10, 0));
int paperCnt = 0;
int mn = MIN;
vector<int> paperArr(5, 5);

// paperSize만큼 색종이를 붙일 수 있는지 확인
bool isPaste(int r, int c, int paperSize) {
	if (r + paperSize > 10 || c + paperSize > 10 || paperArr[paperSize - 1] == 0) {
		return false;
	}
	for (int i = r; i < r + paperSize; i++) {
		for (int j = c; j < c + paperSize; j++) {
			if (map[i][j] == 0) {
				return false;
			}
		}
	}
	return true;
}
// 종이 붙이기
void pastePaper(int r, int c, int paperSize) {
	paperArr[paperSize - 1]--;
	for (int i = r; i < r + paperSize; i++) {
		for (int j = c; j < c + paperSize; j++) {
			map[i][j] = 0;
		}
	}
	paperCnt -= paperSize * paperSize;
}
// 종이 붙였던 것을 되돌리기
void restoration(int r, int c, int paperSize) {
	paperArr[paperSize - 1]++;
	for (int i = r; i < r + paperSize; i++) {
		for (int j = c; j < c + paperSize; j++) {
			map[i][j] = 1;
		}
	}
	paperCnt += paperSize * paperSize;
}
// 색종이를 붙였다 떼며 완전탐색하기(백트래킹 응용)
void dfs(int r, int c, int cnt) {
	if (paperCnt == 0) {
		mn = min(mn, cnt);
		return;
	}

	// map[][]에 1을 발견하면 색종이를 큰 것부터 차례로 붙이기 시도
	for (int i = r; i < 10; i++) {
		for (int j = c; j < 10; j++) {
			if (map[i][j] == 1) {
				// size는 5 ~ 1순으로 붙여보기
				for (int k = 5; k >= 1; k--) {
					if (isPaste(i, j, k)) {
						
						pastePaper(i, j, k); // 색종이 붙이기 (1 -> 0)
						dfs(i, j + k, cnt + 1);
						restoration(i, j, k); // 색종이 떼기 (0 -> 1)

					}
				}
				// 더이상 붙일 수 있는 색종이가 없으므로 return
				return;
			}
		}
		// 좌측부터 다시 시작해야하므로 c=0 으로 세팅
		c = 0;
	}
}
int main()
{
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> map[i][j];
			if (map[i][j]) {
				paperCnt++;
			}
		}
	}

	dfs(0, 0, 0);
	if (mn == MIN) {
		cout << -1 << endl;
	}
	else {
		cout << mn << endl;
	}
}