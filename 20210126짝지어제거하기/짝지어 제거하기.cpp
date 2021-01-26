#include <iostream>
#include <vector>
#include <string>
using namespace std;

int solution(string s)
{
    int answer = 0;
    int idx;
    vector<char> c;
    if (s.empty()) { return 1; } // ��� ���ڵ� �� ���� ���� ���

    idx = 0;
    if (s.size() % 2) { return 0; }

    while (idx < s.size()) { // idx �� ������ Ȯ���� ������ ���� ���
        if (s[idx] == s[idx + 1]) { // ���ڰ� ¦�������� ���
            idx += 2;
        }
        else { // ¦�������� �ʾҴٸ�
            if (c.empty()) {
                c.push_back(s[idx]);
            }
            else {
                if (c[c.size() - 1] != s[idx]) {
                    c.push_back(s[idx]);
                }
                else {
                    c.pop_back();
                }
            }
            idx++;
        }
    }
    if (c.empty()) { answer = 1; }
    else { answer = 0; }
    
    return answer;
}
int main()
{
    cout << solution("baabaacbbeddec") << endl;
}