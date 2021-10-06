#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int N, M;
int parents[100001];
int DP[100001];

int Find(int idx) {
	if (parents[idx] == idx) {
		return idx;
	}
	
	int prevIdx = parents[idx];
	parents[idx] = Find(parents[idx]);
	DP[idx] += DP[prevIdx];

	return parents[idx];
	
}
void merge(int a, int b, int w) {
	int pa = Find(a);
	int pb = Find(b);

	if (pa == pb) return;

	DP[pb] = DP[a] - DP[b] + w;
	parents[pb] = pa;
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> N >> M;

	while (N != 0 && M != 0) {
		memset(DP, 0, sizeof(DP));
		memset(parents, 0, sizeof(parents));
		for (int i = 1; i <= N; i++) {
			parents[i] = i;
		}
		
		for (int i = 0; i < M; i++) {
			char Q; cin >> Q;
			int a, b, w;
			if (Q == '!') {
				cin >> a >> b >> w;
				// 1. Union
				merge(a, b, w);
			}
			else {
				// 2. Find
				cin >> a >> b;
				int pa = Find(a);
				int pb = Find(b);

				// 2-1. �� ������ ���
				if (pa == pb) {
					// b�� a���� �󸶳� ���ſ��� ����ϱ�
					cout << DP[b] - DP[a] << '\n';
				}
				// 2-2. ���� �� ���� ���
				else {
					cout << "UNKNOWN" << '\n';
				}
			}
		}

		cin >> N >> M;
	}
}