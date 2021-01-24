#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int zero_rm = 0;
    int zero_sum = 0;
    int binary_trans = 0;
    int idx = 0;
    int len;
    int a;

    while (1) {
        
        binary_trans++;
        zero_rm = 0;
        int idx = 0;
        while ((idx = s.find("0",idx)) != string::npos) {
            zero_rm++;
            s.erase(idx, 1);
        }
        zero_sum += zero_rm;
        if (s.size() == 1) { break; }
        len = s.size();
        s.clear();

        while ((len / 2)) {
            a = len % 2;
            len /= 2;
            s.push_back(a + 48);
        }
        a = len % 2;
        s.push_back(a + 48);
    }
    answer.push_back(binary_trans);
    answer.push_back(zero_sum);
    return answer;
}
int main()
{
     for (int i = 0; i < 2; i++) {
         cout << solution("110010101001")[i] << " ";
     }
    cout << endl;
}