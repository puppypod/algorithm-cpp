#include <iostream>
#include <vector>
#include <string>
using namespace std;

int solution(string s)
{
    int answer = 0;
    int idx;
    vector<char> c;
    if (s.empty()) { return 1; } // 어떠한 문자도 들어가 있지 않을 경우

    idx = 0;
    if (s.size() % 2) { return 0; }

    while (idx < s.size()) { // idx 가 끝까지 확인을 마무리 했을 경우
        if (s[idx] == s[idx + 1]) { // 문자가 짝지어졌을 경우
            idx += 2;
        }
        else { // 짝지어지지 않았다면
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