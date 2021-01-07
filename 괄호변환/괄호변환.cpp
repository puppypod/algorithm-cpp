#include <string>
#include <vector>
#include <iostream>
using namespace std;




string solution(string p) {
    if (p.empty()) {
        return "";
    }
    string result = "";
    string u, v;
    string tmp = "";
    int current = 0;
    int previous = 0;
    int left = 0;
    int right = 0;

    while (1) {
        if (p[current] == '(') {
            left++;
        }
        else if (p[current] == ')') {
            right++;
        }
        current++;

        if (left == right) { // u,v를 나누는 순간
            u = p.substr(previous, current - previous);

            v = p.substr(current, p.size());
            
            break;
        }
        
    }
    if (u[0] == '(') { // 올바른 괄호 문자열
            result += u;
            result += solution(v);
            return result;
    }
    else if (u[0] == ')') { // 틀린 괄호 문자열
        tmp += "(";
        tmp += solution(v);
        tmp += ")";
        for (int i = 1; i < u.size() - 1; i++) {
            if (u[i] == '(') { u[i] = ')'; }
            else if (u[i] == ')') { u[i] = '('; }
        }
        tmp += u.substr(1, u.size() - 2);
        return tmp;
    }
    
    
    return result;
}
int main()
{
    cout << solution("()))((()))((()") << endl;
}