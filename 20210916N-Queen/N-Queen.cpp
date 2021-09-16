#include <iostream>
#define MAX 15
using namespace std;

int col[MAX];
int N, total = 0;

bool check(int level)
{
    for (int i = 0; i < level; i++) {
        // �밢���̰ų� ���� ����
        if (col[i] == col[level] || abs(col[level] - col[i]) == level - i) {
            return false;
        }
    }
    //col[i]�� �ǹ��ϴ� ���� Y��ǥ,  
    // i�� �ǹ��ϴ°��� X��ǥ�̹Ƿ� ���̰� �����ϴٸ� �밢���� �ִٰ� �� �� �ִ�.
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
            col[y] = i; // �ش� ��ġ�� ���� ��ġ
            // ��ȿ�ϴٸ� �������� �� ��ġ, ��ȿ�����ʴٸ� �ٸ� ��ġ�� �� ��ġ ����
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