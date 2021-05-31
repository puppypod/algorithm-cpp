#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<vector<string>> v;
set<string> s;
set<set<string>> answerS;
int answer = 0;
void dfs(int idx) {
    if (idx == v.size()) {
        answerS.insert(s);
        return;
    }
    for (int i = 0; i < v[idx].size(); i++) {
        if (s.find(v[idx][i]) == s.end()) {
            s.insert(v[idx][i]);
            dfs(idx + 1);
            s.erase(s.find(v[idx][i]));
        }
    }
}
int solution(vector<string> user_id, vector<string> banned_id) {

    
    // 후보 토큰화
    for (int i = 0; i < banned_id.size(); i++) {
        string str = banned_id[i];
        vector<string> tmp;
        for (int j = 0; j < user_id.size(); j++) {
            string userStr = user_id[j];
            if (str.size() == userStr.size()) {
                bool isTrue = true;
                for (int k = 0; k < str.size(); k++) {
                    if (str[k] != '*') {
                        if (str[k] != userStr[k]) {
                            isTrue = false;
                            break;
                        }
                    }
                }
                if (isTrue) {
                    tmp.push_back(userStr);
                }
            }
        }
        v.push_back(tmp);
    }

    // 알고리즘 시작
    dfs(0);
    answer = answerS.size();
    return answer;
}