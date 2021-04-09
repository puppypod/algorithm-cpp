#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int testcase;
	cin >> testcase;
	while (testcase--) {
		int repeatNum;
		char oper;
		int number;
		priority_queue<pair<int,int>> pq_mx;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq_mn;

		cin >> repeatNum;
		vector<int> visit(repeatNum, 0);
		// 명령어 수행문
		for (int i = 0; i < repeatNum; i++) {
			cin >> oper;
			cin >> number;

			

			if (oper == 'I') {
				visit[i] = 1;
				pq_mn.push({ number,i });
				pq_mx.push({ number,i });
			}
			else if (oper == 'D') {
				if (number == 1) { // 최댓값 제거
					// 유효하지 않은 숫자는 제거
					while (!pq_mx.empty() && !visit[pq_mx.top().second]) {
						pq_mx.pop();
					}
					if (pq_mx.empty()) { continue; }

					int tmp = pq_mx.top().second;
					visit[tmp] = 0;
					pq_mx.pop();
				}
				else if (number == -1) { // 최솟값 제거
					// 유효하지 않은 숫자는 제거
					while (!pq_mn.empty() && !visit[pq_mn.top().second]) {
						pq_mn.pop();
					}
					if (pq_mn.empty()) { continue; }
					int tmp = pq_mn.top().second;
					visit[tmp] = 0;
					pq_mn.pop();
				}
			}
		}
		while (!pq_mx.empty() && !visit[pq_mx.top().second]) {
			pq_mx.pop();
		}
		while (!pq_mn.empty() && !visit[pq_mn.top().second]) {
			pq_mn.pop();
		}
		// 출력
		if (pq_mx.empty() && pq_mn.empty()) {
			cout << "EMPTY" << '\n';
		}
		else {
			cout << pq_mx.top().first << " " << pq_mn.top().first << '\n';
		}
	}
}