#include <iostream>
#include <vector>

using namespace std;

int N, M, H;
vector<vector<int>> ladder;
vector<pair<int, int>> candidate;
bool isEnd = false;
vector<pair<int, int>> tmp(3);

int checkNum = 0;

bool isTrue() {
	for (int i = 1; i <= N; i++) {
		checkNum = i;
		for (int j = 1; j <= H; j++) {
			if (ladder[j][checkNum] != 0) {
				if (ladder[j][checkNum]<0) {
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
void combination(int K, int a, int b, int ID) {
	if (b == K) {
		// ��ٸ� ������ �����ٸ� i��(���) == i��(����) check �ϱ�
		if (isTrue()) {
			isEnd = true;
		}

		return;
	}


	for (int i = a; i < candidate.size(); i++) {
		// ��ٸ� ����
		if (ladder[candidate[i].first][candidate[i].second] != 0) {
			continue;
		}
		ladder[candidate[i].first][candidate[i].second] = ID;
		ladder[candidate[i].first][candidate[i].second+1] = -ID;
		combination(K, i + 1, b + 1, ID + 1);
		if (isEnd) return;

		ladder[candidate[i].first][candidate[i].second] = 0;
		ladder[candidate[i].first][candidate[i].second + 1] = 0;
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
	int ID = 1;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		// ��ٸ� ����
		ladder[a][b] = ID;
		ladder[a][b + 1] = -ID;
		ID++;
	}
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N-1; j++) {
			// ���� ������ ��ٸ� �ĺ� ���ϱ�
			if (ladder[i][j] == 0 && ladder[i][j+1]==0) {
				candidate.push_back({ i,j });
			}
		}
	}
	int answer = -1;
	for (int i = 0; i <= 3; i++) {
		tmp;
		combination(i, 0, 0, ID);
		if (isEnd) {
			answer = i;
			break;
		}
	}
	cout << answer;
}