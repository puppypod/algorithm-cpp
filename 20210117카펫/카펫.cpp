#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int sum = brown + yellow;
    int col, row;

    for (int i = 3; i <= sqrt(sum); i++) {
        if (sum % i == 0) {
            row = sum / i;
            col = i;
            if (row * 2 + col * 2 - 4 == brown) { break; }
        }
    }
    answer.push_back(row);
    answer.push_back(col);

    return answer;
}
int main()
{
    vector<int> a;
    a = solution(24, 24);
    cout << a[0] << " " << a[1] << endl;
}