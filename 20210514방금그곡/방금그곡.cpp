#include <string>
#include <vector>
#include <iostream>
#include <cctype>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, string>& a, const pair<int, string>& b) {
    if (a.first != b.first) {
        return a.first > b.first;
    }
    return false;
}
string solution(string m, vector<string> musicinfos) {
    string answer = "";
    vector<string> mToken;
    vector<pair<int, string>> v;
    // m 분리
    for (int i = 0; i < m.size(); i++) {
        if (isalpha(m[i])) {
            if (i + 1 != m.size()) {
                if (!isalpha(m[i + 1])) { // # 이라면
                    string tmp;
                    tmp += m[i];
                    tmp += m[i + 1];
                    mToken.push_back(tmp);
                    i++;
                }
                else { // 다음 문자가 알파벳인 경우
                    string tmp;
                    tmp += m[i];
                    mToken.push_back(tmp);
                }
            }
            else { // 다음 문자가 더이상 없을 경우
                string tmp;
                tmp += m[i];
                mToken.push_back(tmp);
            }
        }
    }

    // musicinfos 분리
    for (int i = 0; i < musicinfos.size(); i++) {
        string str = musicinfos[i];
        string start = str.substr(0, 5);
        string end = str.substr(6, 5);
        int idx = str.find(",", 12);
        // 제목과 곡 정보
        string title = str.substr(12, idx - 12);
        string mInfo = str.substr(idx + 1);
        // 시간
        int s = stoi(start.substr(0, 2)) * 60 + stoi(start.substr(3, 2));
        int e = stoi(end.substr(0, 2)) * 60 + stoi(end.substr(3, 2));

        // mInfo 분리
        vector<string> musicToken;
        for (int j = 0; j < mInfo.size(); j++) {
            if (isalpha(mInfo[j])) {
                if (j + 1 != mInfo.size()) {
                    if (!isalpha(mInfo[j + 1])) { // # 이라면
                        string tmp;
                        tmp += mInfo[j];
                        tmp += mInfo[j + 1];
                        musicToken.push_back(tmp);
                        j++;
                    }
                    else { // 다음 문자가 알파벳인 경우
                        string tmp;
                        tmp += mInfo[j];
                        musicToken.push_back(tmp);
                    }
                }
                else { // 다음 문자가 더이상 없을 경우
                    string tmp;
                    tmp += mInfo[j];
                    musicToken.push_back(tmp);
                }
            }
        }
        // mToken과 musicToken 비교
        int num = musicToken.size();
        int num2 = mToken.size();
        int sumT = e - s;


        string str2 = mToken[0];
        int idx1 = 0;
        // 음악 길이보다 재생된 시간이 짧을 때
        if (mInfo.size() > sumT) {
            for (int i = 0; i < sumT; i++) {
                bool isTrue = true;
                if (str2 == musicToken[i]) {
                    int k = i;
                    for (int j = 1; j < mToken.size(); j++) {
                        if (k == sumT) {
                            isTrue = false;
                            break;
                        }
                        k++;
                        if (mToken[j] != musicToken[k]) {
                            isTrue = false;
                            break;
                        }
                    }
                    if (isTrue) {
                        v.push_back({ sumT, title });
                        break;
                    }
                }
            }
        }
        else {
            while (idx1 != num) {
                if (musicToken[idx1] == str2) {
                    bool isTrue = true;
                    int cpyNum = idx1;
                    int sumTcpy = sumT - 1;
                    for (int j = 1; j < num2; j++) {

                        if (mToken[j] != musicToken[(cpyNum + j) % num]) { // false
                            isTrue = false;
                            break;
                        }
                        else if (!(sumTcpy--)) {
                            isTrue = false;
                            break;
                        }
                    }
                    if (isTrue) {
                        v.push_back({ sumT, title });
                        break;
                    }
                }
                idx1++;
            }
        }
    }
    stable_sort(v.begin(), v.end(), cmp);
    // 아무것도 없을 때 예외 처리
    if (v.empty()) {
        return "(None)";
    }

    return v[0].second;
}