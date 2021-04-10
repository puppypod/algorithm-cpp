#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> map;
int flagNum = -1000000000;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int N;
	priority_queue<int, vector<int>, greater<int>> pq;
	
	cin >> N;
	map.resize(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (i == N - 1) {
				flagNum = min(flagNum, map[i][j]);
			}
		}
	}

	

	for (int j = 0; j < N; j++) {
		for (int i = N - 1; i >= 0; i--) {
			if (flagNum <= map[i][j]) {
				if (pq.size() == N) {
					if (pq.top() < map[i][j]) {
						pq.pop();
						pq.push(map[i][j]);
					}
				}
				else {
					pq.push(map[i][j]);
				}
			}
			else break;
		}
	}
	cout << pq.top() << '\n';
}