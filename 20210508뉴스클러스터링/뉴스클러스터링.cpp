#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

int solution(string str1, string str2) {
    int answer = 0;

    vector<string> v1, v2;
    for (int i = 0; i < str1.size() - 1; i++) {
        int n1 = isalpha(str1[i]);
        int n2 = isalpha(str1[i + 1]);
        // ����ó��
        if (n1 == 0 || n2 == 0) { // 0�̶�� ���ĺ��� �ƴ϶�� �ǹ�
            if (n2 == 0) {
                i++;
                continue;
            }
            continue;
        }

        // 2���ھ� ���տ� push
        if (str1[i] < 91) { // �빮�ڶ��
            str1[i] += 32;
        }
        if (str1[i + 1] < 91) { // �빮�ڶ��
            str1[i + 1] += 32;
        }
        string s1, s2;
        s1.push_back(str1[i]);
        s2.push_back(str1[i + 1]);

        v1.push_back(s1 + s2);
    }

    for (int i = 0; i < str2.size() - 1; i++) {
        int n1 = isalpha(str2[i]);
        int n2 = isalpha(str2[i + 1]);
        // ����ó��
        if (n1 == 0 || n2 == 0) { // 0�̶�� ���ĺ��� �ƴ϶�� �ǹ�
            if (n2 == 0) {
                i++;
                continue;
            }
            continue;
        }

        // 2���ھ� ���տ� push
        if (str2[i] < 91) { // �빮�ڶ��
            str2[i] += 32;
        }
        if (str2[i + 1] < 91) { // �빮�ڶ��
            str2[i + 1] += 32;
        }
        string s1, s2;
        s1.push_back(str2[i]);
        s2.push_back(str2[i + 1]);

        v2.push_back(s1 + s2);
    }

    // ������ && ������ J(str1, str2)
    int M = 0; // ������ ����
    int P = 0; // ������ ����

    while (!v1.empty()) {
        string tmp1 = v1.back();
        v1.pop_back();

        for (int i = 0; i < v2.size(); i++) {
            if (tmp1 == v2[i]) { // ������
                M++;
                v2.erase(v2.begin() + i);
                break;
            }
        }
        P++;
    }
    P += v2.size();

    if (M == 0 && P == 0) {
        return 65536;
    }
    answer = ((float)M / (float)P) * 65536;

    return answer;
}