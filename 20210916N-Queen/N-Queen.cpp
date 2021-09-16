#include <iostream>
#define MAX 15
using namespace std;

int col[MAX];
int N, total = 0;

bool check(int level)
{
    for (int i = 0; i < level; i++) {
        // 대각선이거나 같은 라인
        if (col[i] == col[level] || abs(col[level] - col[i]) == level - i) {
            return false;
        }
    }
    //col[i]가 의미하는 것이 Y좌표,  
    // i가 의미하는것이 X좌표이므로 차이가 일정하다면 대각선에 있다고 볼 수 있다.
    return true;
}

void nqueen(int y)
{
    if (y == N)
        total++;
    else
    {
        for (int i = 0; i < N; i++)
        {
            col[y] = i; // 해당 위치에 퀸을 배치
            // 유효하다면 다음행의 퀸 배치, 유효하지않다면 다른 위치로 퀸 배치 변경
            if (check(y)) 
                nqueen(y + 1);
        }
    }
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    nqueen(0);
    cout << total;
}