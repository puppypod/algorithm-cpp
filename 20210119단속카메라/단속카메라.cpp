#include <string>
#include <vector>
#include <iostream>
using namespace std;

void dlt(int overlapNum, vector<vector<int>>& routes, vector<int>& itg) {
    vector<int>::iterator it;

    it = itg.begin();
    it += 30000;
    // ���ǿ� �����ϴ� route ����
    for (int i = 0; i < routes.size(); i++) {
        if (overlapNum >= routes[i][0] && overlapNum <= routes[i][1]) {
            // Ư�� ��Ʈ�� �������� ���� ��Ʈ�� ���ڸ� 1�� ������.
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
    // ��� ��Ʈ�� ������ ���Ͽ� ���� ���� ��ģ ��Ʈ�� ã���ϴ�.
    for (int i = 0; i < routes.size(); i++) {

        if (start > routes[i][0]) { start = routes[i][0]; } // ���� �� ��ȣ
        if (end < routes[i][1]) { end = routes[i][1]; } // ������ �� ��ȣ
        
        for (int j = routes[i][0]; j <= routes[i][1]; j++) {
            it[j]++;
            if (mx < it[j]) { mx = it[j]; } //���� ���� ��ģ �� ��ȣ
        }
    }
    
    for (int i = mx; i >= 1; i--) {
        for (int j = start; j <= end; j++) {
            if (it[j] == i) { //���帹�� ��ģ ��
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