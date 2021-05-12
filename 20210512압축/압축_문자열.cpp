#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;

    map<string, int> m;
    for (int i = 1; i <= 26; i++) {
        string tmp;
        char ch = 64 + i;
        tmp.push_back(ch);
        m[tmp] = i;
    }
    unsigned int length = msg.size();
    string str;
    int nextNum = 27;

    for (int i = 0; i < length; i++) {
        str.push_back(msg[i]);
        if (m.find(str) != m.end()) {
            if (i + 1 == length) { 
                answer.push_back(m[str]);
                break; 
            }
            if (m.find(str + msg[i + 1]) != m.end()) {
                continue;
            }
        }
        if (m.find(str) != m.end()) {
            answer.push_back(m[str]);
        }
        else {
            m[str] = nextNum;
            nextNum++;
            string init;
            str = init;
           
            i--;
        }
    }

    return answer;
}