#include <string>
#include <vector>
#include <iostream>
using namespace std;

void dlt(int overlapNum, vector<vector<int>>& routes, vector<int>& itg) {
    vector<int>::iterator it;

    it = itg.begin();
    it += 30000;
    // 조건에 만족하는 route 삭제
    for (int i = 0; i < routes.size(); i++) {
        if (overlapNum >= routes[i][0] && overlapNum <= routes[i][1]) {
            // 특정 루트를 지웠으니 통합 루트의 숫자를 1씩 지워줌.
            for (int j = routes[i][0]; j <= routes[i][1]; j++) {
                it[j]--;
            }
            routes.erase(routes.begin() + i);
            i = -1;
        }
    }

    return;
}
int solution(vector<vector<int>> routes) {
    int answer = 0;
    vector<int> v(60001);
    vector<int>::iterator it;
    int mx = -1;
    int start = 30001;
    int end = -30001;
    it = v.begin();
    it += 30000;
    // 모든 루트의 범위를 구하여 가장 많이 겹친 루트를 찾습니다.
    for (int i = 0; i < routes.size(); i++) {

        if (start > routes[i][0]) { start = routes[i][0]; } // 시작 방 번호
        if (end < routes[i][1]) { end = routes[i][1]; } // 마지막 방 번호
        
        for (int j = routes[i][0]; j <= routes[i][1]; j++) {
            it[j]++;
            if (mx < it[j]) { mx = it[j]; } //가장 많이 겹친 방 번호
        }
    }
    
    for (int i = mx; i >= 1; i--) {
        for (int j = start; j <= end; j++) {
            if (it[j] == i) { //가장많이 겹친 곳
                dlt(j, routes, v);
                answer++;
                
            }
        }
        
        if (routes.empty()) {
            break;
        }
    }

    
    return answer;
}
int main()
{
    cout << solution({ {-20,15},{-14,-5},{-18,-13},{-5,-3} });
}