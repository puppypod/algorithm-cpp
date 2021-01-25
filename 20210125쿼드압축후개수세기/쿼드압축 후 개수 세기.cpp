#include <string>
#include <vector>
#include <iostream>
using namespace std;

int zero_cnt = 0;
int one_cnt = 0;
vector<vector<int>> cpy;
void dfs(int r, int c, int size) {
    if (size == 1) { 
        return; 
    }
    bool is_all;
    // 왼쪽 상단
    is_all = true;
    for (int i = r; i < r + (size / 2); i++) { 
        for (int j = c; j < c + (size / 2); j++) {
            if (cpy[r][c] != cpy[i][j]) {
                is_all = false;
                break;
            }
        }
    }
    if (!is_all) { dfs(r, c, size / 2); }
    else {
        if (cpy[r][c]) { one_cnt++; }
        else { zero_cnt++; }
    }
    // 왼쪽 하단
    is_all = true;
    for (int i = r + (size / 2); i < r + size; i++) {
        for (int j = c; j < c + (size / 2); j++) {
            if (cpy[r + (size / 2)][c] != cpy[i][j]) {
                is_all = false;
                break;
            }
        }
    }
    if (!is_all) { dfs(r + (size / 2), c, size / 2); }
    else {
        if (cpy[r + (size / 2)][c]) { one_cnt++; }
        else { zero_cnt++; }
    }
    //오른쪽 상단
    is_all = true;
    for (int i = r; i < r + (size / 2); i++) {
        for (int j = c + (size / 2); j < c + size; j++) {
            if (cpy[r][c + (size / 2)] != cpy[i][j]) {
                is_all = false;
                break;
            }
        }
    }
    if (!is_all) { dfs(r, c + (size / 2), size / 2); }
    else {
        if (cpy[r][c + (size / 2)]) { one_cnt++; }
        else { zero_cnt++; }
    }
    //오른쪽 하단
    is_all = true;
    for (int i = r + (size / 2); i < r + size; i++) {
        for (int j = c + (size / 2); j < c + size; j++) {
            if (cpy[r + (size / 2)][c + (size / 2)] != cpy[i][j]) {
                is_all = false;
                break;
            }
        }
    }
    if (!is_all) { dfs(r + (size / 2), c + (size / 2), size / 2); }
    else {
        if (cpy[r + (size / 2)][c + (size / 2)]) { one_cnt++; }
        else { zero_cnt++; }
    }
}
vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer = { 0,0 };
    bool isAll = true;
    cpy = arr;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr.size(); j++) {
            if (arr[0][0] != arr[i][j]) {
                isAll = false;
                break;
            }
        }
    }
    if (isAll) {
        if (arr[0][0]) { answer[0] = 0; answer[1] = 1; }
        else{ answer[0] = 1; answer[1] = 0; }
        return answer;
    }

    if (!isAll && arr.size() != 1) {
        dfs(0, 0, arr.size());
    }
    else {
        if (arr[0][0]) { one_cnt = 1; }
        else { zero_cnt = 1; }
    }
    answer[0] = zero_cnt;
    answer[1] = one_cnt;
    return answer;
}
int main()
{
    vector<int> pr;
    //pr = solution({ {1,1,1,1,1,1,1,1},{0,1,1,1,1,1,1,1},{0,0,0,0,1,1,1,1},{0,1,0,0,1,1,1,1},{0,0,0,0,0,0,1,1},{0,0,0,0,0,0,0,1},{0,0,0,0,1,0,0,1},{0,0,0,0,1,1,1,1} });
    //pr = solution({ { 1,1,0,0 }, { 1,0,0,0 }, { 1,0,0,1 }, { 1,1,1,1 } });
    pr = solution({ {1,1},{1,1} });
    cout << pr[0] << " " << pr[1] << endl;
}