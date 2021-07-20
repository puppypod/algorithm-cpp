#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int solution(int X, int Y, int D) {
    if (X == Y) {
        return 0;
    }
    else if ((Y - X) % D == 0) {
        return (int)trunc((Y - X) / (double)D);
    }
    else {
        return (int)trunc((Y - X) / (double)D) + 1;
    }
}