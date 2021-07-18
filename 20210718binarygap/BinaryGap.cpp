// 주어지는 숫자의 2진수 Gap(가장 긴 gap 구하기)을 구하는 문제
// ex. -> 1000 0001 -> 6
// ex. -> 1000 0000 -> 0
// ex. -> 1111 1111 -> 0
// ex. -> 1010 0010 -> 3

#include <iostream>
#include <algorithm>

using namespace std;

int solution(int N) {
    int cpyN = N;
    int cnt = 0;
    bool flag = false;
    bool flag2 = false;
    int answer = 0;
    while (cpyN != 0) {
        if (cpyN % 2 == 1) {
            flag = true;
            // 0의 길이가 유효하다면
            if (flag2) {
                answer = max(answer, cnt);
            }
            cnt = 0;
        }
        // 1이 적어도 1번은 발견되어야 제대로 된 값을 구할 수 있음.
        else if (flag && cpyN % 2 == 0) {
            cnt++;
            flag2 = true;
        }
        cpyN /= 2;
    }

    return answer;
}