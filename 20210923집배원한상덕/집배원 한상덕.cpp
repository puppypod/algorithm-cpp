#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>

using namespace std;
// first -> minimum, second -> maximum
vector<vector<pair<int, int>>> DP;
vector<string> map;
vector<vector<int>> input;
vector<vector<bool>> visited;
vector<int> v;
int N;
int Kcnt = 0;
int px, py;
int dir[8][2] = { {0,1} ,{1,0} ,{0,-1} ,{-1,0} ,{1,1} ,{1,-1} ,{-1,1} ,{-1,-1} };

bool isTrue(int r, int c) {
    return r >= 0 && r < N&& c >= 0 && c < N;
}
bool bfs(int r, int c, int mn, int mx) {
    queue<pair<int, int>> q;
    q.push({ r,c });

    if (input[r][c]<mn || input[r][c]>mx) {
        return false;
    }
    visited[r][c] = true;
    int count = 0;

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        
        q.pop();

        // 2.. 목적지에 도달하였는가?
        if (map[r][c] == 'K') {
            // 2-1. 목적지 개수 count
            count++;
            // 2-2. count 개수를 만족하였다면
            if (count == Kcnt) {
                return true;
            }
        }

        // 3. 순회하기
        for (int i = 0; i < 8; i++) {
            int dy = r + dir[i][0];
            int dx = c + dir[i][1];

            if (!isTrue(dy, dx)) continue;

            // 4. 가능한곳 순회
            if (!visited[dy][dx] && input[dy][dx] >= mn && input[dy][dx] <= mx) {
                // 1. 체크인
                visited[dy][dx] = true;

                // 5. 간다.
                q.push({ dy,dx });
            }
        }
    }

    return false;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> N;
    DP.resize(N, vector<pair<int, int>>(N));
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        map.push_back(s);
        for (int j = 0; j < N; j++) {
            if (s[j] == 'P') {
                py = i;
                px = j;
            }
            else if (s[j] == 'K') {
                Kcnt++;
            }
        }
    }
    input.resize(N, vector<int>(N));
    set<int> s;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> input[i][j];
            if (s.find(input[i][j]) == s.end()) {
                s.insert(input[i][j]);
                v.push_back(input[i][j]);
            }
        }
    }
    sort(v.begin(), v.end());
    int left = 0;
    int right = 0;
    int answer = 1000001;
    while (right!=v.size()) {
        while (left != v.size()) {
            // 방문지 초기화
            visited.clear();
            visited.resize(N, vector<bool>(N, false));
            
            bool possible = bfs(py, px, v[left], v[right]);
            
            /*cout << endl;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    cout << visited[i][j] << " ";
                }cout << endl;
            }*/

            //cout << v[right] << " " << v[left] << endl;
            if (!possible) break;
            answer = min(answer, v[right] - v[left]);

            left++;

            
        }
        right++;
    }

    cout << answer;
}