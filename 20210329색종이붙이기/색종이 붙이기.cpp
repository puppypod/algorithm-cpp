#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MIN 987654321
vector<vector<int>> map(10, vector<int>(10, 0));
int paperCnt = 0;
int mn = MIN;
vector<int> paperArr(5, 5);

// paperSize��ŭ �����̸� ���� �� �ִ��� Ȯ��
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
// ���� ���̱�
void pastePaper(int r, int c, int paperSize) {
	paperArr[paperSize - 1]--;
	for (int i = r; i < r + paperSize; i++) {
		for (int j = c; j < c + paperSize; j++) {
			map[i][j] = 0;
		}
	}
	paperCnt -= paperSize * paperSize;
}
// ���� �ٿ��� ���� �ǵ�����
void restoration(int r, int c, int paperSize) {
	paperArr[paperSize - 1]++;
	for (int i = r; i < r + paperSize; i++) {
		for (int j = c; j < c + paperSize; j++) {
			map[i][j] = 1;
		}
	}
	paperCnt += paperSize * paperSize;
}
// �����̸� �ٿ��� ���� ����Ž���ϱ�(��Ʈ��ŷ ����)
void dfs(int r, int c, int cnt) {
	if (paperCnt == 0) {
		mn = min(mn, cnt);
		return;
	}

	// map[][]�� 1�� �߰��ϸ� �����̸� ū �ͺ��� ���ʷ� ���̱� �õ�
	for (int i = r; i < 10; i++) {
		for (int j = c; j < 10; j++) {
			if (map[i][j] == 1) {
				// size�� 5 ~ 1������ �ٿ�����
				for (int k = 5; k >= 1; k--) {
					if (isPaste(i, j, k)) {
						
						pastePaper(i, j, k); // ������ ���̱� (1 -> 0)
						dfs(i, j + k, cnt + 1);
						restoration(i, j, k); // ������ ���� (0 -> 1)

					}
				}
				// ���̻� ���� �� �ִ� �����̰� �����Ƿ� return
				return;
			}
		}
		// �������� �ٽ� �����ؾ��ϹǷ� c=0 ���� ����
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