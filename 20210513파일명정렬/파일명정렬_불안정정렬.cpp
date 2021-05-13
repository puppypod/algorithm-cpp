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

    if (aHead.size() != bHead.size()) { // ���ڿ� ���̰� �ٸ��ٸ�
        return aHead < bHead;
    }
    else { // ���ڿ� ���̰� ���ٸ�
        // �ҹ��ڷ� ����
        for (int i = 0; i < aHead.size(); i++) {
            char ch1 = tolower(aHead[i]);
            char ch2 = tolower(bHead[i]);
            aHead[i] = ch1;
            bHead[i] = ch2;
        }
        if (aHead != bHead) { // ���ڿ��� ���� �ٸ��ٸ�
            return aHead < bHead;
        }
        else { // ���ڿ��� ���� ���ٸ�
            int num1 = stoi(aNumber);
            int num2 = stoi(bNumber);
            if (num1 != num2) { // ���ڰ� ���δٸ��ٸ�
                return num1 < num2;
            }
            else { // ���ڱ��� ���� ���ٸ� ������ �ٲ��� �ʰ� ����
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

        // ���ڿ� 3������ �и�
        for (int j = 0; j < str.size(); j++) {
            if (str[j] >= 48 && str[j] <= 57) { // ���ڶ��
                head = str.substr(0, j);
                int idx = j;
                j++;
                int cnt = 1;
                while (j != str.size()) {
                    // ���ڴ� 5���ڰ� �ִ���.
                    cnt++;
                    // ���ڶ��
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