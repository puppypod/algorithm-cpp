#include <cmath>

int solution(int A, int B, int K) {
    int tmpNum = A % K;
    int answer = 0;

    if (tmpNum == 0) answer = 1;

    // K로 나눌 수 있는 숫자 만들기
    A -= tmpNum;
    A += K;

    // 적어도 1개 이상 존재
    if (A <= B) {
        answer++;
        int difNum = B - A;
        answer += (int)trunc(difNum / (double)K);
        return answer;
    }
    // 1개 이하로 존재
    else {
        return answer;
    }
}