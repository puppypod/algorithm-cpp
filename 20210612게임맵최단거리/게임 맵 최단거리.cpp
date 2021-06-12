#include <vector>
#include <queue>
using namespace std;

vector<vector<int> > cpy;
vector<vector<int>> visited;
int N, M;
int dir[4][2] = { {0,1} ,{1,0} ,{0,-1}, {-1,0} };
bool isTrue(int r, int c) {
    return r >= 0 && r < N&& c >= 0 && c < M;
}
int bfs(int r, int c) {
    queue<pair<pair<int, int>, int>> q;
    q.push({ { r,c },0 });
    visited[r][c] = 1;
    int cnt = 0;
    while (!q.empty()) {
        r = q.front().first.first;
        c = q.front().first.second;
        cnt = q.front().second + 1;
        if (r == N - 1 && c == M - 1) {
            return cnt;
        }
        
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int dy = r + dir[i][0];
            int dx = c + dir[i][1];

            if (isTrue(dy, dx) && cpy[dy][dx] == 1 && !visited[dy][dx]) {
                visited[dy][dx] = 1;
                q.push({ {dy,dx},cnt });
            }
        }
    }
    return -1;
}
int solution(vector<vector<int> > maps)
{
    N = maps.size();
    M = maps[0].size();
    cpy = maps;
    visited.resize(N, vector<int>(M, 0));
    
    return bfs(0, 0);
}