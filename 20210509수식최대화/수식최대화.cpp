#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

long long solution(string expression) {
    long long answer = 0;
    vector<long long> number;
    vector<char> operList;

    set<char> s;
    vector<char> v;
    unsigned int idx = 0;
    for (int i = 0; i < expression.size(); i++) {
        char ch = expression[i];
        if (ch < 48) { // operation
            operList.push_back(ch);
            string s1 = expression.substr(idx, i - idx);
            idx = i + 1;
            number.push_back(stoll(s1));
            s.insert(ch);
        }
        if (i == expression.size() - 1) {
            string s1 = expression.substr(idx, expression.size() - idx);
            number.push_back(stoll(s1));
        }
    }

    set<char>::iterator itr;
    for (itr = s.begin(); itr != s.end(); itr++) {
        v.push_back(*itr);
    }
    sort(v.begin(), v.end());

    do {
        vector<long long> numberCpy = number;
        vector<char> operListCpy = operList;
        for (int i = 0; i < v.size(); i++) {
            vector<char>::iterator it;
            char ch = v[i];
            while ((it = find(operListCpy.begin(), operListCpy.end(), ch)) != operListCpy.end()) {
                long long tmp;
                idx = it - operListCpy.begin();
                if (ch == '*') {
                    tmp = numberCpy[idx] * numberCpy[idx + 1];
                }
                else if (ch == '+') {
                    tmp = numberCpy[idx] + numberCpy[idx + 1];
                }
                else { // -
                    tmp = numberCpy[idx] - numberCpy[idx + 1];
                }
                numberCpy.erase(numberCpy.begin() + idx);
                operListCpy.erase(operListCpy.begin() + idx);
                numberCpy[idx] = tmp;
            }
        }
        answer = max(answer, abs(numberCpy[0]));
    } while (next_permutation(v.begin(), v.end()));

    return answer;
}