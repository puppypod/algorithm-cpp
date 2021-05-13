#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
#include <iostream>

using namespace std;
bool cmp(const vector<string>& a, const vector<string>& b) {
    string aHead = a[0];
    string bHead = b[0];
    string aNum = a[1];
    string bNum = b[1];
    if (aHead != bHead) {
        return aHead < bHead;
    }
    else {
        if (stoi(aNum) != stoi(bNum)) {
            return stoi(aNum) < stoi(bNum);
        }
        else {
            return false;
        }
    }
}
vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<vector<string>> token;

    for (int i = 0; i < files.size(); i++) {
        string str = files[i];
        int j = 0;
        while (!isdigit(str[j])) j++;
        string head = str.substr(0, j);
        int prev = j;
        int cnt = 0;
        bool isEnd = false;
        while (isdigit(str[j])) {
            cnt++;
            j++;
            if (cnt == 5 || j == str.size()) {
                if (j == str.size()) {
                    isEnd = true;
                    break;
                }
                break;
            }
        }
        string number, tail;
        if (isEnd) {
            number = str.substr(prev);
        }
        else {
            number = str.substr(prev, j - prev);
            tail = str.substr(j);
        }
        string origin = head + number + tail;
        transform(head.begin(), head.begin() + prev, head.begin(), ::tolower); // 소문자 변경
        token.push_back({ head,number,origin });
    }
    stable_sort(token.begin(), token.end(), cmp);
    for (int i = 0; i < token.size(); i++) {
        answer.push_back(token[i][2]);
    }

    return answer;
}