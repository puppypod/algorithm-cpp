#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

#define MAX_NODE 201
#define INF 1e9
vector<pair<int, int>> graph[MAX_NODE];
vector<int> d_cost(MAX_NODE, INF);
void dijkstra(int start) {
    // 첫번째는 cost, 두번째는 노드번호
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));
    d_cost[start] = 0;

    int now_dist;
    int now_node;
    int tmp_cost;
    while (!pq.empty()) {
        now_dist = -pq.top().first;
        now_node = pq.top().second;
        pq.pop();
        if (d_cost[now_node] < now_dist) {
            continue;
        }
        for (int i = 0; i < graph[now_node].size(); i++) {
            tmp_cost = now_dist + graph[now_node][i].second;
            if (tmp_cost < d_cost[graph[now_node][i].first]) {
                d_cost[graph[now_node][i].first] = tmp_cost;
                pq.push(make_pair(-tmp_cost, graph[now_node][i].first));
            }
        }
    }
    return;
}
int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    
    
    for (int i = 0; i < fares.size(); i++) {
        // 다익스트라 알고리즘을 위한 초기 세팅
        graph[fares[i][0]].push_back(make_pair(fares[i][1], fares[i][2]));
    }
    dijkstra(s);
    for (int i = 1; i <= n; i++) {
        cout << d_cost[i] << " ";
    }
    cout << endl;
    return answer;
}
int main()
{
    cout << solution(6, 4, 6, 2, { {4, 1, 10},{3, 5, 24},{5, 6, 2},{1, 3, 41},{1, 5, 24},
    {4, 6, 50},{4, 2, 66},{2, 3, 22},{1, 6, 25} }) << endl;
}