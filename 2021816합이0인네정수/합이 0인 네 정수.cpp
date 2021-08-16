#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> arr[4];
vector<long long> A, B;
int N;

bool cmp(long long a, long long b) {
    return a > b;
}
vector<long long> SUM(const vector<long long>& a, const vector<long long>& b) {
    vector<long long> tmp;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            long long sum = a[i] + b[j];
            tmp.push_back(sum);
        }
    }
    return tmp;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 4; j++) {
            long long a; cin >> a;
            arr[j].push_back(a);
        }
    }

    A = SUM(arr[0], arr[1]);
    B = SUM(arr[2], arr[3]);

    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), cmp);
    
    int apointer = 0;
    int bpointer = 0;
    long long answer = 0;

    N = A.size();
    while (apointer != N && bpointer != N) {
        if (A[apointer] + B[bpointer] == 0) {
            long long acnt = 1;
            long long bcnt = 1;
            
            while ((apointer + 1) != N && A[apointer] == A[apointer + 1]) {
                acnt++;
                apointer++;
            }
            while ((bpointer + 1) != N && B[bpointer] == B[bpointer + 1]) {
                bcnt++;
                bpointer++;
            }

            answer += acnt * bcnt;
            if ((apointer+1) == N || (bpointer+1) == N) break;
            apointer++;
            bpointer++;
        }
        else if(A[apointer] + B[bpointer] < 0){
            apointer++;
        }
        else {
            bpointer++;
        }
    }
    cout << answer;
}