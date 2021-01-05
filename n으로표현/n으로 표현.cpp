#include <string>
#include <vector>
#include <iostream>
using namespace std;

int answer;
int cmp = 9;

void dfs(int N, int number, int cnt, int result) {
    // 횟수가 초과했다면 -1 결과값 반환
    if (cnt > 8) {
        if (cmp == 9) {
            answer = -1;
        }
        return; 
    }
    // 사용횟수가 유효하며 결과값과 목표값이 같다면 반환
    if(number == result) {
        if (cnt < cmp) {
            answer = cnt;
            cmp = cnt;
        }
        return; 
    }

    int tmp = 0; // 임의의 결과값 저장
    for (int i = 1; i < 6; i++) {
        tmp = tmp * 10 + N;
        dfs(N, number, cnt + i, result + tmp); // 덧셈
        dfs(N, number, cnt + i, result - tmp); // 뺄셈
        if (result != 0) {
            dfs(N, number, cnt + i, result * tmp); // 곱셈
            dfs(N, number, cnt + i, result / tmp); // 나눗셈
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