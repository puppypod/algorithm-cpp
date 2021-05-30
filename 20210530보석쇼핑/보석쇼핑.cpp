#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;


// 투포인터 문제
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    return (a.second - a.first) < (b.second - b.first);
}
vector<int> solution(vector<string> gems) {
    vector<int> answer;
    
    int left = 0;
    int right = 0;
    map<string, int> m;
    set<string> s;
    queue<string> q;
    int kindNum = 0;
    vector<pair<int,int>> candidate;

    for (string str : gems) {
        if (s.find(str) == s.end()) {
            s.insert(str);
            kindNum++;
        }
    }

    for (int i = 0; i < gems.size(); i++) {
        string str = gems[i];
        q.push(str);
        if (m.find(str) == m.end()) {
            m[str] = 1;
        }
        else {
            m[str]++;
        }
        right++;

        if (m.size() == kindNum) {
            string tmp;
            while (1) {
                tmp = q.front();
                q.pop();
                m[tmp]--;
                left++;
                if (m[tmp] == 0) {
                    map<string, int>::iterator it = m.find(tmp);
                    m.erase(it);
                    break;
                }
            }
            candidate.push_back({ left,right});
        }
        
    }

    if (m.size() == kindNum) {
        candidate.push_back({ left + 1,right});
    }
    stable_sort(candidate.begin(), candidate.end(), cmp);
    answer.push_back(candidate[0].first);
    answer.push_back(candidate[0].second);

    return answer;
}