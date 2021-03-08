#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> W;
vector<int> V;
// DP�� �� ���� Value�� �ִ�
vector<vector<int>> DP;

int solution() {
	// 1��° �����ۺ��� N��° �����۱��� ����
	for (int i = 1; i <= N; i++) {
		// i��° �����۱��� ����� ���� ��, weight 1���� weight K������ �ִ� value ���ϱ�
		for (int j = 1; j <= K; j++) {
			if (j >= W[i]) {
				DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - W[i]] + V[i]);
			}
			else {
				DP[i][j] = DP[i - 1][j];
			}
		}
	}
	return DP[N][K];
}
int main()
{
	cin >> N >> K;
	DP.resize(N+1, vector<int>(K+1, 0));
	W.push_back(0);
	V.push_back(0);
	for (int i = 0; i < N; i++) {
		int w, v;
		cin >> w >> v;
		W.push_back(w);
		V.push_back(v);
	}
	cout << solution() << endl;

}