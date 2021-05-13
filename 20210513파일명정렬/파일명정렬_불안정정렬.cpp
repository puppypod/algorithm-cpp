#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(const vector<string>& a, const vector<string>& b) {
    string aHead = a[0];
    string aNumber = a[1];
    
    string bHead = b[0];
    string bNumber = b[1];
    
    int aIdx = stoi(a[3]);
    int bIdx = stoi(b[3]);

    if (aHead.size() != bHead.size()) { // 문자열 길이가 다르다면
        return aHead < bHead;
    }
    else { // 문자열 길이가 같다면
        // 소문자로 통일
        for (int i = 0; i < aHead.size(); i++) {
            char ch1 = tolower(aHead[i]);
            char ch2 = tolower(bHead[i]);
            aHead[i] = ch1;
            bHead[i] = ch2;
        }
        if (aHead != bHead) { // 문자열이 서로 다르다면
            return aHead < bHead;
        }
        else { // 문자열이 서로 같다면
            int num1 = stoi(aNumber);
            int num2 = stoi(bNumber);
            if (num1 != num2) { // 숫자가 서로다르다면
                return num1 < num2;
            }
            else { // 숫자까지 서로 같다면 순서를 바꾸지 않고 유지
                return aIdx < bIdx;
            }
        }
    }
}
vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<vector<string>> token;

    for (int i = 0; i < files.size(); i++) {
        string str = files[i];
        string head, number, tail = "";

        // 문자열 3가지로 분리
        for (int j = 0; j < str.size(); j++) {
            if (str[j] >= 48 && str[j] <= 57) { // 숫자라면
                head = str.substr(0, j);
                int idx = j;
                j++;
                int cnt = 1;
                while (j != str.size()) {
                    // 숫자는 5글자가 최대임.
                    cnt++;
                    // 문자라면
                    if (str[j] < 48 || str[j] > 57) { 
                        number = str.substr(idx, j - idx);
                        tail = str.substr(j);
                        break;
                    }
                    if (cnt == 5) { break; }
                    j++;
                }
                if (cnt==5) {
                    number = str.substr(idx, 5);
                    if (idx + 5 < str.size()) {
                        tail = str.substr(idx + 5);
                    }
                }
                else if (j == str.size()) {
                    number = str.substr(idx);
                }
                break;
            }
        }
        token.push_back({ head, number, tail, to_string(i) });
    }
    
    sort(token.begin(), token.end(), cmp);

    for (int i = 0; i < token.size(); i++) {
        //cout << token[i][0] << " " << token[i][1] << " " << token[i][2] << endl;
        answer.push_back(token[i][0] + token[i][1] + token[i][2]);
    }

    return answer;
}