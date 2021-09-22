#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define MAX 987654321

using namespace std;

int N, M;
vector<vector<int>> map;
vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;
vector<pair<int, int>> candidate;
int answer = MAX;

void combination(int a, int b) {
    if (b == M) {
        int sum = 0;
        for (pair<int, int> chPoint : houses) {
            int y1 = chPoint.first;
            int x1 = chPoint.second;
            int mn = MAX;
            for (pair<int, int> pointer : candidate) {
                int y2 = pointer.first;
                int x2 = pointer.second;

                mn = min(mn, abs(y2 - y1) + abs(x2 - x1));
            }
            sum += mn;
            //if (answer < sum) return;
        }

        answer = min(answer, sum);

        return;
    }

    for (int i = a; i < chickens.size(); i++) {
        candidate[b].first = chickens[i].first;
        candidate[b].second = chickens[i].second;

        combination(i + 1, b + 1);
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> N >> M;

    map.resize(N+1, vector<int>(N+1));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
            // 치킨집
            if (map[i][j] == 2) {
                chickens.push_back({ i,j });
            }
            // 집
            else if (map[i][j] == 1) {
                houses.push_back({ i,j });
            }
        }
    }
    candidate.resize(M);

    combination(0, 0);

    cout << answer;
}