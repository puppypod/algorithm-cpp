#include <iostream>
#include <vector>

using namespace std;

int N, M, H;
vector<vector<int>> ladder;
vector<pair<int, int>> candidate;
bool isEnd = false;
vector<pair<int, int>> tmp(3);
int ID = 1;
int checkNum = 0;

bool isTrue(const vector<vector<int>>& board) {
	for (int i = 1; i <= N; i++) {
		checkNum = i;
		for (int j = 1; j <= H; j++) {
			if (board[j][checkNum] != 0) {
				if (board[j][checkNum] == board[j][checkNum - 1]) {
					checkNum--;
				}
				else {
					checkNum++;
				}
			}
		}
		if (checkNum != i) return false;
	}
	return true;
}
void combination(vector<vector<int>> board, int K, int a, int b) {
	if (b == K) {
		int num = ID;
		// 사다리 연결
		for (int i = 0; i < K; i++) {
			int r = tmp[i].first;
			int c = tmp[i].second;
			if (board[r][c] == 0 && board[r][c + 1] == 0) {
				board[r][c] = num;
				board[r][c + 1] = num;
				num++;
			}
			else {
				// 연결할 수 없는 사다리이기 때문임.
				return;
			}
		}

		// 사다리 연결이 끝났다면 i번(출발) == i번(도착) check 하기
		if (isTrue(board)) {
			isEnd = true;
		}

		return;
	}


	for (int i = a; i < candidate.size(); i++) {
		// 사다리 조작
		tmp[b].first = candidate[i].first;
		tmp[b].second = candidate[i].second;

		combination(board, K, i + 1, b + 1);
		if (isEnd) return;

	}
}
int main()
{
	// N : 세로줄 개수
	// H : 가로선을 놓을 수 있는 위치의 개수
	// M : 가로선 개수
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M >> H;
	ladder.resize(H + 2, vector<int>(N + 1, 0));

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		// 사다리 연결
		ladder[a][b] = ID;
		ladder[a][b + 1] = ID;
		ID++;
	}
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N - 1; j++) {
			// 연결 가능한 사다리 후보 구하기
			if (ladder[i][j] == 0 && ladder[i][j + 1] == 0) {
				candidate.push_back({ i,j });
			}
		}
	}
	int answer = -1;
	for (int i = 0; i <= 3; i++) {
		tmp;
		combination(ladder, i, 0, 0);
		if (isEnd) {
			answer = i;
			break;
		}
	}
	cout << answer;
}