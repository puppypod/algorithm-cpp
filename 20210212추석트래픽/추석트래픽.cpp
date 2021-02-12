#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> h;
vector<int> m;
vector<double> s;
vector<double> scope;
vector<vector<int>> s_sum;
int solution(vector<string> lines) {
    
    int prev, idx;
    vector<string> time;
    for (int i = 0; i < lines.size(); i++) {
        prev = lines[i].find(' ', 0);
        prev++;
        idx = lines[i].find(' ', prev);
        time.push_back(lines[i].substr(prev, idx - prev)); // 시간 문자열
        idx++;
        scope.push_back(stod(lines[i].substr(idx, lines.size() - 1 - idx))); // 범위
    }
    // 시,분,초로 쪼개기
    for (int i = 0; i < time.size(); i++) {
        prev = 0; idx = 0;
        idx = time[i].find(":", prev);
        h.push_back(stoi(time[i].substr(prev, idx - prev))); // 시
        
        prev = idx + 1;
        idx = time[i].find(":", prev);
        m.push_back(stoi(time[i].substr(prev, idx - prev))); // 분

        prev = idx + 1;
        s.push_back(stod(time[i].substr(prev, time[i].size() - prev))); // 초
    }
    s_sum.resize(time.size(), vector<int>(2,0));
    for (int i = 0; i < time.size(); i++) {
        s_sum[i][1] = (h[i] * 3600.0 + m[i] * 60.0)*1000 + s[i]*1000;
        s_sum[i][0] = (h[i] * 3600.0 + m[i] * 60.0)*1000 + (s[i] - scope[i] + 0.001)*1000;
    }

    // 알고리즘 시작
    int cnt = 0;
    int answer = -1;
    for (int i = 0; i < s_sum.size(); i++) {
        // 1초 막대기 생성
        int start_t = s_sum[i][1];
        int end_t = s_sum[i][1] + 999;
        cnt = 1;

        for (int j = i + 1; j < s_sum.size(); j++) {
            if (s_sum[j][0] <= end_t) {
                if (start_t <= s_sum[j][1]) {
                    cnt++;
                }
            }
            else { break; }
        }
        if (answer < cnt) {
            answer = cnt;
        }
    }
    return answer;
}
int main()
{
    cout << solution({ "2016-09-15 01:00:04.002 2.0s",
"2016-09-15 01:00:07.000 2s" }) << endl;
}