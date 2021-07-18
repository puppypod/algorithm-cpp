// �־����� ������ 2���� Gap(���� �� gap ���ϱ�)�� ���ϴ� ����
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
            // 0�� ���̰� ��ȿ�ϴٸ�
            if (flag2) {
                answer = max(answer, cnt);
            }
            cnt = 0;
        }
        // 1�� ��� 1���� �߰ߵǾ�� ����� �� ���� ���� �� ����.
        else if (flag && cpyN % 2 == 0) {
            cnt++;
            flag2 = true;
        }
        cpyN /= 2;
    }

    return answer;
}