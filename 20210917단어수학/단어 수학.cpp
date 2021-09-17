#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

int score[8] = { 1,10,100,1000,10000,100000,1000000,10000000 };
vector<int> alphabet(26, 0);

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    map<char, int> m;
    vector<string> s;
    int maxLength = 0;

    cin >> n;
    s.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        maxLength = max(maxLength, (int)s[i].size());
    }

    for (int i = maxLength; i >= 1; i--) {
        int sco = score[i - 1];
        for (int j = 0; j < s.size(); j++) {
            string str = s[j];
            if ((int)str.size() - i >= 0) {
                alphabet[str[str.size() - i]-'A'] += sco;
            }
        }
    }

    sort(alphabet.begin(), alphabet.end());
    reverse(alphabet.begin(), alphabet.end());

    int num = 9;
    int answer = 0;
    for (int i = 0; i < 10; i++) {
        if (alphabet[i] == 0) break;

        answer += alphabet[i] * num;
        num--;
    }
    cout << answer;
}