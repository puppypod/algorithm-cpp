#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N, L;
vector<vector<int>> map;

int main()
{
	cin >> N >> L;
	map.resize(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	int answer = 0;
	for (int i = 0; i < N; i++) {
		int num = map[i][0];
		int cnt = 0;
		int j;
		for (j = 0; j < N; j++) {
			//cout << i << " " << j << endl;
			if (num == map[i][j]) {
				cnt++;
			}
			else {
				// ������ �� �ִ� ������ Ȯ��
				if (abs(num - map[i][j])==1) {
					// ��������
					if (num - map[i][j] < 0) {
						if (cnt >= L) {
							cnt = 1;
							num = map[i][j];
						}
						else break;
						
					}
					// ��������
					else {
						num = map[i][j];
						cnt = 0;
						int limit = j + L;

						if (limit > N) break;

						for (; j< limit; j++) {
							if (num == map[i][j]) cnt++;
							else break;
						}
						if (cnt != L) break;
						
						if (j == N) break;

						// ��������
						if (num - map[i][j] < 0) break;
						// ���� ������ ��
						else if (num - map[i][j] == 0) {
							cnt = 1;
							num = map[i][j];
						}
						// ��������
						else j -= 2;
					}
				}
				// ������ �� ���� ����.
				else { break; }
				
			}
		}
		if (j == N)	answer++; 
	}
	// ���� ����
	for (int j = 0; j < N; j++) {
		int num = map[0][j];
		int cnt = 0;
		int i;
		for (i = 0; i < N; i++) {
			if (num == map[i][j]) {
				cnt++;
			}
			else {
				// ������ �� �ִ� ������ Ȯ��
				if (abs(num - map[i][j]) == 1) {
					// ��������
					if (num - map[i][j] < 0) {
						if (cnt >= L) {
							cnt = 1;
							num = map[i][j];
						}
						else break;

					}
					// ��������
					else {
						num = map[i][j];
						cnt = 0;
						int limit = i + L;

						if (limit > N) break;

						for (; i < limit; i++) {
							if (num == map[i][j]) cnt++;
							else break;
						}
						if (cnt != L) break;

						if (i == N) break;

						// ��������
						if (num - map[i][j] < 0) break;
						// ���� ������ ��
						else if (num - map[i][j] == 0) {
							cnt = 1;
							num = map[i][j];
						}
						// ��������
						else i -= 2;
					}
				}
				// ������ �� ���� ����.
				else { break; }

			}
		}
		if (i == N) answer++;
	}
	cout << answer;
}