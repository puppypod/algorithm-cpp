#include <cmath>

int solution(int A, int B, int K) {
    int tmpNum = A % K;
    int answer = 0;

    if (tmpNum == 0) answer = 1;

    // K�� ���� �� �ִ� ���� �����
    A -= tmpNum;
    A += K;

    // ��� 1�� �̻� ����
    if (A <= B) {
        answer++;
        int difNum = B - A;
        answer += (int)trunc(difNum / (double)K);
        return answer;
    }
    // 1�� ���Ϸ� ����
    else {
        return answer;
    }
}