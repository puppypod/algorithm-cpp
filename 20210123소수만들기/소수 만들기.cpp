#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int answer = 0;
vector<int> cpy;
int arr[3];
int sum;
bool isTrue;

void dfs(int a, int b) {
    if (b == 3) {
        isTrue = true;
        sum = 0;
        for (int i = 0; i < 3; i++) {
            sum += arr[i];
        }
        for (int i = 2; i <= sqrt(sum); i++) {
            if (sum % i == 0) { isTrue = false; break; }
        }
        if (isTrue) {
            cout << sum << endl;
            answer++;
        }
        return;
    }
    for (int i = a; i < cpy.size(); i++) {
        arr[b] = cpy[i];
        dfs(i + 1, b + 1);
    }
}
int solution(vector<int> nums) {
    cpy = nums;
    dfs(0, 0);

    return answer;
}
int main()
{
    cout << solution({ 1,2,7,6,4 });
}