#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 987654321

struct info {
	long long A, B, C;
	info(long long a, long long b, long long c) {
		this->A = a;
		this->B = b;
		this->C = c;
	}
};
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int N, M;
	cin >> N >> M;
	vector<long long> dist;
	vector<info> edgeList;
	dist.resize(N + 1, INF);

	// 벨만-포드 초기화
	dist[1] = 0;

	// 간선 리스트 Make
	for (int i = 1; i <= M; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		edgeList.push_back(info(a, b, c));
	}

	// 벨만-포드 알고리즘 시작
	for (int i = 1; i <= N-1; i++) {
		for (int j = 0; j < M; j++) {
			info tmp = edgeList[j];
			// 출발지가 무한대이면 continue
			if (dist[tmp.A] == INF) continue;

			// 최솟값으로 값 갱신 가능하면 갱신
			dist[tmp.B] = min(dist[tmp.B], dist[tmp.A] + tmp.C);
		}
	}
	bool flag = true;
	for (int j = 0; j < M; j++) {
		info tmp = edgeList[j];
		// 출발지가 무한대이면 continue
		if (dist[tmp.A] == INF) continue;

		// 최솟값으로 값 갱신 가능하면 무한루프에 빠짐
		if (dist[tmp.A] + tmp.C < dist[tmp.B]) {
			flag = false;
			break;
		}
	}

	if (flag) {
		for (int i = 2; i <= N; i++) {
			if (dist[i] == INF) {
				cout << -1 << '\n';
			}
			else {
				cout << dist[i] << '\n';
			}
		}
	}
	else {
		cout << -1 << '\n';
	}
}