#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int K, orderSize;
int length;
vector<string> cpy;
vector<char> tmp(26);
int visit[20][26];
int cnt = 1;
string str_tmp;
int mx = 1;
vector<pair<int, string>> output[11];

bool cmp(const string& a, const string& b) {
    return a.size() < b.size();
}
bool cmp2(pair<int,string> a, pair<int,string> b) {
    return a.first > b.first;
}
void combination(int a, int b, int idx) {
    if (b == K) { // 뽑기 완료
        bool isSame;
        cnt = 1;
        for (int i = idx + 1; i < length; i++) {
            isSame = true;
            for (int j = 0; j < b; j++) {
                if (!visit[i][tmp[j] - 'A']) {
                    isSame = false;
                    break;
                }
            }
            if (isSame) {
                cnt++;
            }
        }

        if (cnt >= 2) {
            for (int i = 0; i < b; i++) {
                str_tmp.push_back(tmp[i]);
            }
            output[b].push_back({ cnt,str_tmp });
        }
        str_tmp.clear();

        return;
    }

    for (int i = a; i < orderSize; i++) {
        tmp[b] = cpy[idx][i];
        combination(i + 1, b + 1, idx);
    }
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    length = orders.size();
    
    sort(orders.begin(), orders.end(), cmp);
    cpy = orders;
    for (int i = 0; i < orders.size(); i++) {
        for (int j = 0; j < orders[i].size(); j++) {
            visit[i][orders[i][j] - 'A'] = 1;
        }
    }
    

    for (int i = 0; i < orders.size(); i++) {
        // 문자열 길이
        orderSize = orders[i].size();

        for (int num : course) {
            if (num > orderSize) { break; }
            K = num;
            combination(0, 0, i);

            
        }

    }
    for (int i : course) {
        if (!output[i].empty()) {
            sort(output[i].begin(), output[i].end(), cmp2);
            int compareNum = output[i][0].first;
            for (int j = 0; j < output[i].size(); j++) {
                if (compareNum == output[i][j].first) {
                    answer.push_back(output[i][j].second);
                }
                else { break; }
            }
        }
    }
    
    sort(answer.begin(), answer.end());

    return answer;
}
int main()
{
    vector<string> s;
    s.push_back("ABCFG");
    s.push_back("AC");
    s.push_back("CDE");
    s.push_back("ACDE");
    s.push_back("BCFG");
    s.push_back("ACDEH");
    solution(s, { 2,3,4 });
}