#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    int mx;
    int j;
    int cnt;
    int next;
    reverse(stones.begin(), stones.end());

    for (int i = k; i <= stones.size(); i++) {
        mx = 0;
        j = i - k;
        cnt = 0;
        while (cnt != k) {
            if (mx < stones[j + cnt]) { mx = stones[j + cnt]; next = cnt; }
            cnt++;
        }
        if (answer > mx || j == 0) {
            i += next;
            answer = mx;
        }
        else {
            i += next;
        }
    }

    return answer;
}
int main()
{
    cout << solution({ 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 }, 3);
}