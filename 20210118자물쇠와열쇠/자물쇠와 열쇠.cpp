#include <string>
#include <vector>
#include <iostream>
using namespace std;

void rotation(vector<vector<int>>& v) {
    vector<vector<int>> tmp = v;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size(); j++) {
            v[i][j] = tmp[v.size() - 1 - j][i];
        }
    }
    return;
}
bool check(const vector<vector<int>>& key, const vector<vector<int>> lock, int keySize, int lockSize) {
    vector<vector<int>> cmp = lock;
    int a = 0;
    int b = 0;
    bool isTrue;
    while (1) {
        for (int i = 0; i < key.size(); i++) {
            for (int j = 0; j < key.size(); j++) {
                cmp[i+a][j+b] += key[i][j];
            }
        }
        for (int j = 0; j < cmp.size(); j++) {
            for (int k = 0; k < cmp.size(); k++) {
                cout << cmp[j][k];
            }
            cout << endl;
        }
        cout << endl;
        isTrue = true;
        for (int i = keySize - 1; i < keySize + lockSize - 1; i++) {
            for (int j = keySize - 1; j < keySize + lockSize - 1; j++) {
                if (cmp[i][j] != 1) { isTrue = false; }
            }
        }
        
        if (isTrue) { return isTrue; }
        a++;
        if (a == keySize + lockSize - 1) {
            a = 0;
            b++;
            if (b == keySize + lockSize - 1) { break; }
        }

        cmp.clear();
        cmp = lock;

    }
    return isTrue;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int lockSize = lock.size();
    int keySize = key.size();
    int lock_key_size = keySize * 2 - 2 + lockSize;
    vector<vector<int>> cpy(lock_key_size, vector<int>(lock_key_size));
    bool confirm;
    for (int i = 0; i < 4; i++) {
        // lock과 key를 합친 map 만들기
        for (int j = keySize - 1; j < keySize + lockSize - 1; j++) {
            for (int k = keySize - 1; k < keySize + lockSize - 1; k++) {
                cpy[j][k] = lock[j - (keySize - 1)][k - (keySize - 1)];
            }
        }
        confirm = check(key, cpy, keySize, lockSize);
        if (confirm) { return confirm; }
        
        

        rotation(key); // 회전
        
    }
    return confirm;
}
int main()
{
    cout << solution({ {0, 0, 0},{1, 0, 0},{0, 1, 1 } }, { {1, 1, 1},{1, 1, 0},{1, 0, 1} });
}