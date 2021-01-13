#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> citations) {
    int answer;
    
    for (int i = 10000; i >= 0; i--) { // 인용횟수 범위
        answer = 0;
        for (int j = 0; j < citations.size(); j++) {
            if (citations[j] >= i) {
                answer++;
            }
        }
        if (answer >= i) { answer = i; break; }
    }

    return answer;
}
int main()
{
    cout << solution({ 0, 0, 0, 0, 0 });
}