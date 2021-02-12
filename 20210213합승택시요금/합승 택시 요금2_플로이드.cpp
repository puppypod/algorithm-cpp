#include <string>
#include <vector>
using namespace std;

#define INF 1e9
#define MAX_NODE 201

// �÷��̵� �ͼ� �˰����� ���� �ʱ� ����
vector<vector<int>> graph(MAX_NODE, vector<int>(MAX_NODE, INF));

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	long long answer = INF;

	// �÷��̵� �ͼ� �˰����� ���� �ʱ� ����
	for (int i = 1; i <= n; i++) {
		graph[i][i] = 0;
	}
	for (auto info : fares) {
		graph[info[0]][info[1]] = info[2];
		graph[info[1]][info[0]] = info[2];
	}

	// �÷��̵� �ͼ� �˰��� ����
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (graph[i][j] > graph[i][k] + graph[k][j]) {
					graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
	}

	// ���Ʈ ���� �˰���
	// ���⼭ i�� �ս� ��, �������� ��� ��ȣ�� �� ����
	// �ս��� �� ����, ���� ���� �־ ���ǹ��� ����
	for (int i = 1; i <= n; i++) {
		if (answer > graph[s][i] + graph[i][a] + graph[i][b]) {
			answer = graph[s][i] + graph[i][a] + graph[i][b];
		}
	}

	return answer;
}