#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0);
    int personNum = 0;
    int gameRound = 0;
    set<string> s;
    bool isPass = true;

    for (int i = 0; i < words.size(); i++) {
        personNum = i % n + 1;
        if (personNum == 1) {
            gameRound++;
        }
        if (s.find(words[i]) == s.end()) { // 새로운 단어
            if (i != 0) {
                if (words[i - 1][words[i - 1].size() - 1] != words[i][0]) {
                    isPass = false;
                    break;
                }
            }
            s.insert(words[i]);
        }
        else { // 중복된 단어일 때
            isPass = false;
            break;
        }

    }

    if (!isPass) {
        answer[0] = personNum;
        answer[1] = gameRound;
    }

    return answer;

}