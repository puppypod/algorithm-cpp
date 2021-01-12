#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(string a, string b) {
    return a + b > b + a;
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> str;
    
    for (int i = 0; i < numbers.size(); i++) {
        str.push_back(to_string(numbers[i]));
    }
    sort(str.begin(), str.end(), cmp);
    for (int i = 0; i < str.size(); i++) {
        answer += str[i];
    }
    if (answer[0] == '0') { return "0"; }
    return answer;
}
int main()
{
    cout << solution({ 3, 30, 34, 5, 9 }) << endl;
}