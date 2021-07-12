#include <iostream>
#include <deque>
#include <cmath>

using namespace std;

#define MAX 11

int N, M, K;
deque<int> tree[MAX][MAX];
int A[MAX][MAX];
int board[MAX][MAX];
int dir[8][2] = { {0,1} ,{1,1} ,{1,0} ,{1,-1} ,{0,-1} ,{-1,-1} ,{-1,0} ,{-1,1} };

void springAndSummer() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (tree[i][j].empty())continue;

			for (int k = 0; k < tree[i][j].size(); k++) {
				// 봄
				if (board[i][j] - tree[i][j][k] >= 0) {
					board[i][j] -= tree[i][j][k];
					tree[i][j][k]++;
				}
				else {
					int limit = tree[i][j].size();
					// 여름
					while (k != limit) {
						board[i][j] += trunc(tree[i][j].back() / 2.0);
						tree[i][j].pop_back();
						k++;
					}
					break;
				}
			}
		}
	}
}
bool isTrue(int r, int c) {
	return r >= 1 && r <= N && c >= 1 && c <= N;
}
void autumn() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (tree[i][j].empty())continue;

			for (int k = 0; k < tree[i][j].size(); k++) {
				if (tree[i][j][k] % 5 == 0) {
					for (int a = 0; a < 8; a++) {
						int dx = i + dir[a][0];
						int dy = j + dir[a][1];
						
						if (!isTrue(dx, dy)) continue;

						tree[dx][dy].push_front(1);
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
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			board[i][j] = 5;
			cin >> A[i][j];
		}
	}

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		tree[a][b].push_front(c);
	}

	for (int i = 0; i < K; i++) {
		springAndSummer();
		autumn();
		winter();
	}
	int answer = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (tree[i][j].empty()) continue;

			answer += tree[i][j].size();
		}
	}
	cout << answer;
}