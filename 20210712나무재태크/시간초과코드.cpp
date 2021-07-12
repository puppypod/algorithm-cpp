#include <iostream>
#include <vector>
#include <map>
#include <deque>
#include <cmath>

using namespace std;

int N, M, K;
vector<vector<int>> A; // 1년에 한 번씩 양분 공급
vector<vector<int>> board; // 현재 땅에 존재하는 양분 정보
map<pair<int, int>, deque<int>> m; // 현재 존재하는 나무 정보
map<pair<int, int>, deque<int>> dieTree; // 죽은 나무 정보
int dir[8][2] = { {0,1} ,{1,1} ,{1,0} ,{1,-1} ,{0,-1} ,{-1,-1} ,{-1,0} ,{-1,1} };

void spring() {
	map<pair<int, int>, deque<int>>::iterator iter;
	for (iter = m.begin(); iter != m.end(); iter++) {
		int r = iter->first.first;
		int c = iter->first.second;
		for (int i = 0; i < m[{r, c}].size(); i++) {
			int age = m[{r, c}][i];
			// 양분을 줄 수 있다면
			if (board[r][c] - age >= 0) {
				board[r][c] -= age;
				m[{r, c}][i]++;
			}
			// 양분을 더 이상 줄수 없다면
			else {
				// 죽을 나무 구하기
				int limit = m[{r, c}].size();
				while (i != limit) {
					/* 현재 나무에서 죽을 나무를 구하여 dieTree에 정보 저장
					 dieTree[{r, c}].push_front(m[{r, c}].back());*/
					board[r][c] += trunc(m[{r, c}].back() / 2.0);
					m[{r, c}].pop_back();
					i++;
				}
				break;
			}
		}
	}
}
/*void summer() {
	auto iter = dieTree.begin();
	for (iter; iter != dieTree.end(); iter++) {
		int r = iter->first.first;
		int c = iter->first.second;
		for (int i = 0; i < dieTree[{r, c}].size(); i++) {
			int plus = trunc(dieTree[{r, c}][i] / 2.0);
			// 죽은 나무가 존재했던 위치에 양분 추가
			board[r][c] += plus;
		}
	}
	// 죽은 나무 정보 초기화
	map<pair<int, int>, deque<int>> init;
	dieTree = init;
}*/
bool isTrue(int r, int c) {
	return r >= 1 && r <= N && c >= 1 && c <= N;
}
void autumn() {
	map<pair<int, int>, deque<int>>::iterator iter;
	for (iter = m.begin(); iter != m.end(); iter++) {
		int r = iter->first.first;
		int c = iter->first.second;

		for (int i = 0; i < m[{r, c}].size(); i++) {
			int age = m[{r, c}][i];
			// 나이가 5의 배수라면
			if (age % 5 == 0) {
				for (int j = 0; j < 8; j++) {
					int dx = r + dir[j][0];
					int dy = c + dir[j][1];
					if (isTrue(dx, dy)) {
						m[{dx, dy}].push_front(1);
					}
				}
			}
		}
	}
}
void winter() {
	// 양분 공급
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			board[i][j] += A[i][j];
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M >> K;
	A.resize(N+1, vector<int>(N+1));
	board.resize(N+1, vector<int>(N+1, 5));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}
	for (int i = 1; i <= M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		m[{a, b}].push_front(c);
	}

	for (int i = 0; i < K; i++) {
		spring();
		//summer();
		autumn();
		winter();
	}

	int answer = 0;
	map<pair<int, int>, deque<int>>::iterator iter;
	for (iter = m.begin(); iter != m.end(); iter++) {
		int r = iter->first.first;
		int c = iter->first.second;
		answer += m[{r, c}].size();
	}
	cout << answer;
}