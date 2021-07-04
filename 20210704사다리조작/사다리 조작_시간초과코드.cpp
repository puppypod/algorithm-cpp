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
		// ��ٸ� ����
		for (int i = 0; i < K; i++) {
			int r = tmp[i].first;
			int c = tmp[i].second;
			if (board[r][c] == 0 && board[r][c + 1] == 0) {
				board[r][c] = num;
				board[r][c + 1] = num;
				num++;
			}
			else {
				// ������ �� ���� ��ٸ��̱� ������.
				return;
			}
		}

		// ��ٸ� ������ �����ٸ� i��(���) == i��(����) check �ϱ�
		if (isTrue(board)) {
			isEnd = true;
		}

		return;
	}


	for (int i = a; i < candidate.size(); i++) {
		// ��ٸ� ����
		tmp[b].first = candidate[i].first;
		tmp[b].second = candidate[i].second;

		combination(board, K, i + 1, b + 1);
		if (isEnd) return;

	}
}
int main()
{
	// N : ������ ����
	// H : ���μ��� ���� �� �ִ� ��ġ�� ����
	// M : ���μ� ����
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N >> M >> H;
	ladder.resize(H + 2, vector<int>(N + 1, 0));

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		// ��ٸ� ����
		ladder[a][b] = ID;
		ladder[a][b + 1] = ID;
		ID++;
	}
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N - 1; j++) {
			// ���� ������ ��ٸ� �ĺ� ���ϱ�
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