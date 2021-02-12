#include <string>
#include <vector>
using namespace std;

#define INF 1e9
#define MAX_NODE 201

// 플로이드 와샬 알고리즘을 위한 초기 세팅
vector<vector<int>> graph(MAX_NODE, vector<int>(MAX_NODE, INF));

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	long long answer = INF;

	// 플로이드 와샬 알고리즘을 위한 초기 세팅
	for (int i = 1; i <= n; i++) {
		graph[i][i] = 0;
	}
	for (auto info : fares) {
		graph[info[0]][info[1]] = info[2];
		graph[info[1]][info[0]] = info[2];
	}

	// 플로이드 와샬 알고리즘 시작
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (graph[i][j] > graph[i][k] + graph[k][j]) {
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}

	// 브루트 포스 알고리즘
	// 여기서 i는 합승 후, 갈림길의 노드 번호가 될 것임
	// 합승을 할 수도, 안할 수도 있어서 조건문을 나눔
	for (int i = 1; i <= n; i++) {
		if (answer > graph[s][i] + graph[i][a] + graph[i][b]) {
			answer = graph[s][i] + graph[i][a] + graph[i][b];
		}
	}

	return answer;
}