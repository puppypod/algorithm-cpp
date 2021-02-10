#include <iostream>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int scp = 2 * w + 1;
    int answer = 0;
    int x1 = 1, x2;
    int size;
    bool isLast = true;
    // x1 ~ x2 범위 지정 초기화
    for (int i = 0; i < stations.size(); i++) {
        x2 = stations[i] - 1 - w;
        if (x1 > x2) {
            x1 = stations[i] + 1 + w;
            continue;
        }
        cout << x1 << " " << x2 << endl;
        size = x2 - x1 + 1;
        answer += (size / scp);
        if (size % scp != 0) {
            answer++;
        }
        x1 = stations[i] + 1 + w;
        if (x1 > n) {
            isLast = false;
        }
    }

    if (isLast) {
        x2 = n;
        size = x2 - x1 + 1;
        if (size >= 1) {
            answer += (size / scp);
            if (size % scp != 0) {
                answer++;
            }
        }
    }

    return answer;
}
int main()
{
    cout << solution(13, { 4,5 }, 1) << endl;
}