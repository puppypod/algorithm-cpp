#include <string>
#include <vector>
#include <iostream>
using namespace std;

int answer;
int cmp = 9;

void dfs(int N, int number, int cnt, int result) {
    // Ƚ���� �ʰ��ߴٸ� -1 ����� ��ȯ
    if (cnt > 8) {
        if (cmp == 9) {
            answer = -1;
        }
        return; 
    }
    // ���Ƚ���� ��ȿ�ϸ� ������� ��ǥ���� ���ٸ� ��ȯ
    if(number == result) {
        if (cnt < cmp) {
            answer = cnt;
            cmp = cnt;
        }
        return; 
    }

    int tmp = 0; // ������ ����� ����
    for (int i = 1; i < 6; i++) {
        tmp = tmp * 10 + N;
        dfs(N, number, cnt + i, result + tmp); // ����
        dfs(N, number, cnt + i, result - tmp); // ����
        if (result != 0) {
            dfs(N, number, cnt + i, result * tmp); // ����
            dfs(N, number, cnt + i, result / tmp); // ������
        }
    }
}
int solution(int N, int number) {
    dfs(N, number, 0, 0);

    return answer;
}

int main()
{
    cout << solution(2, 11);
}