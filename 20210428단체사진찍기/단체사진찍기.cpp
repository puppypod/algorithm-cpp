#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;

    string v = "ACFJMNRT";
    do {
        char first;
        char second;
        char oper;
        int distance;
        bool isTrue = true;

        for (int i = 0; i < data.size(); i++) {
            const char* ch = data[i].c_str();
            sscanf(ch, "%c~%c%c%d", &first, &second, &oper, &distance);
            int a = v.find(first);
            int b = v.find(second);
            if (oper == '=') {
                if (abs(b - a) - 1 != distance) {
                    isTrue = false;
                    break;
                }
            }
            else if (oper == '<') {
                if (abs(b - a) - 1 >= distance) {
                    isTrue = false;
                    break;
                }
            }
            else {
                if (abs(b - a) - 1 <= distance) {
                    isTrue = false;
                    break;
                }
            }
        }
        if (isTrue) answer++;
    } while (next_permutation(v.begin(), v.end()));

    return answer;
}