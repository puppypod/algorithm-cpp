#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int r, c, k;
vector<vector<int>> board;

vector<int> row[101];
vector<int> col[101];

int main()
{
	int rSize = 3;
	int cSize = 3;
	cin >> r >> c >> k;
	board.resize(101, vector<int>(101, 0));
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> board[i][j];
			row[i].push_back(board[i][j]);
		}
	}
	int cnt = 0;
	while (board[r][c] != k) {
		vector<vector<int>> init(101, vector<int>(101, 0));
		board = init;
		cnt++;

		if (rSize >= cSize) { // R 연산
			cSize = 0;
			for (int i = 1; i <= 100; i++) {
				if (row[i].empty())break;
				// 중복숫자 찾는 용도
				map<int, int> m;
				// 첫번째는 count 개수
				// 두번째는 count 관련 숫자
				priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
				
				while (!row[i].empty()) {
					int num = row[i].back();
					row[i].pop_back();

					if (num == 0) continue;

					if (m.find(num) == m.end()) {
						m[num] = 1;
					}
					else {
						m[num]++;
					}
				}
				for (auto iter = m.begin(); iter != m.end(); iter++) {
					// (수의 등장 횟수, 수)로 삽입, 배열에 저장할때엔 반대로 저장
					pq.push({ iter->second, iter->first });
				}

				cSize = max(cSize, (int)pq.size() * 2);
				
				int limit = pq.size();

				for (int j = 0; j < limit; j++) {
					board[i][j * 2+1] = pq.top().second;
					board[i][j * 2 + 2] = pq.top().first;
					pq.pop();
				}
			}
		}
		else { // C 연산
			rSize = 0;
			for (int j = 1; j <= 100; j++) {
				if (col[j].empty())break;
				// 중복숫자 찾는 용도
				map<int, int> m;
				// 첫번째는 count 개수
				// 두번째는 count 관련 숫자
				priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

				while (!col[j].empty()) {
					int num = col[j].back();
					col[j].pop_back();
					if (num == 0) continue;

					if (m.find(num) == m.end()) {
						m[num] = 1;
					}
					else {
						m[num]++;
					}
				}

				for (auto iter = m.begin(); iter != m.end(); iter++) {
					// (수의 등장 횟수, 수)로 삽입, 배열에 저장할때엔 반대로 저장
					pq.push({ iter->second, iter->first });
				}

				rSize = max(rSize, (int)pq.size() * 2);
				int limit = pq.size();

				for (int i = 0; i < limit; i++) {
					board[i * 2+1][j] = pq.top().second;
					board[i * 2 + 2][j] = pq.top().first;
					pq.pop();
				}
			}
		}

		if (cnt == 101) { // 종료 조건
			cout << -1;
			return 0;
		}

		// row와 col 다시 세팅
		if (rSize >= cSize) {
			for (int i = 1; i <= rSize; i++) {
				for (int j = 1; j <= cSize; j++) {
					
					if (board[i][j] == 0) continue;
					row[i].push_back(board[i][j]);
				}
			}
		}
		else {
			for (int j = 1; j <= cSize; j++) {
				for (int i = 1; i <= rSize; i++) {
					if (board[i][j] == 0) continue;
					col[j].push_back(board[i][j]);
				}
			}
		}

		
	}
	cout << cnt;
	return 0;
}