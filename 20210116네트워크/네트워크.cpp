#include <string>
#include <vector>
#include <iostream>
using namespace std;

int visit[200];
vector<vector<int>> cpy;

int num;

void dfs(int v) {
    for (int i = 0; i < num; i++) {
        if (cpy[v][i] && !visit[i]) {
            visit[i] = 1;
            dfs(i);
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    
    cpy = computers;
    num = n;
    int answer = 0;

    for (int i = 0; i < n; i++) {
        if (!visit[i]) {
            answer++;
            visit[i] = 1;
            dfs(i);
        }
    }
    
    return answer;
}
int main()
{
    vector<vector<int>> a = { {1, 1, 0 },{1, 1, 0 } ,{0,0,1 } };
    cout << solution(3,a) << endl;
}