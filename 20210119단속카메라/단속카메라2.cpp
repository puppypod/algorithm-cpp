#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    
    sort(routes.begin(), routes.end());
    int outNum = routes[0][1];
    for (int i = 1; i < routes.size() - 1; i++) {
        if (outNum > routes[i][1]) { outNum = routes[i][1]; }
        if (outNum < routes[i + 1][0]) {
            answer++;
            outNum = routes[i + 1][1];
        }
    }
    
    return answer;
}
int main()
{
    cout << solution({ {-20,15}, {-14, -5}, {-18, -13}, {-5, -3} });
}