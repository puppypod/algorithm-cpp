#include <iostream>
#include <vector>
#include <set>
using namespace std;

int village[50];
int map[50][50][2];
int village_num;
int purpose;
int visit_value[50];
set<int> s;

void dfs(int v, long long sum) {
    village[v] = 1;
    for (int i = 0; i < village_num; i++) {
        if (!village[i] && map[v][i][0] && (sum + map[v][i][1]) <= purpose) {
            if (visit_value[i] == 0 || visit_value[i] > sum + map[v][i][1]) {
                visit_value[i] = sum + map[v][i][1];
                s.insert(i);
                dfs(i, visit_value[i]);
                village[i] = 0;
            }
        }
    }
}
int solution(int N, vector<vector<int> > road, int K) {
    purpose = K;
    village_num = N;
    for (int i = 0; i < road.size(); i++) {
        if (map[road[i][0] - 1][road[i][1] - 1][0] != 0) {
            if (map[road[i][0] - 1][road[i][1] - 1][1] < road[i][2]) {
                road[i][2] = map[road[i][0] - 1][road[i][1] - 1][1];
            }
        }
        map[road[i][0]-1][road[i][1] - 1][0] = 1;
        map[road[i][1]-1][road[i][0] - 1][0] = 1;

        map[road[i][0] - 1][road[i][1] - 1][1] = road[i][2];
        map[road[i][1] - 1][road[i][0] - 1][1] = road[i][2];
    }
   
    s.insert(0);
    dfs(0, 0);
    return s.size();
}
int main()
{
    //cout << solution(5,{ { 1,2,1 }, { 2,3,3 }, { 5,2,2 }, { 1,4,2 }, { 5,3,1 }, { 5,4,2 } },3) << endl;
    cout << solution(6, { { 1,2,1 }, { 1,3,2 }, { 2,3,2 }, { 3,4,3}, { 5,3,2 }, { 3,5,3 },{5,6,1} }, 4) << endl;
}