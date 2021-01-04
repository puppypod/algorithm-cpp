#include <string>

using namespace std;

int solution(string s) {
    int answer = s.length();
    if (answer == 2) { // 2�� ��� ���� �����ϴ��� ���̴� 2�� �Ȱ��� ������ ���̰� 2�� ������� ����.
        return answer;
    }
    int i, j;
    int cnt;
    string subCpy;
    string cmp;
    for (i = 1; i <= s.length() / 2; i++) {
        subCpy = s.substr(0, i);
        cmp.clear();
        cnt = 1;
        for (j = i; j < s.length(); j += i) {
            if (subCpy == s.substr(j, i)) {
                cnt++;
                if (j + i >= s.length()) {
                    if (cnt != 1) {
                        cmp += to_string(cnt) + subCpy;
                    }
                    else {
                        cmp += subCpy;
                    }
                }
            }
            else {
                if (cnt != 1) {
                    cmp += to_string(cnt) + subCpy;
                }
                else {
                    cmp += subCpy;
                }
                subCpy = s.substr(j, i);
                if (j + i >= s.length()) {
                    cmp += subCpy;
                }
                cnt = 1;
            }
        }
        if (cmp.length() < answer) {
            answer = cmp.length();
        }
    }
    return answer;
}