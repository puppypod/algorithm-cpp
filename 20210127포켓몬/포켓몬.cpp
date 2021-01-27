#include <vector>
#include <set>

#include <iostream>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    int size = nums.size() / 2;
    set<int> s;
    for (int i = 0; i < nums.size(); i++) {
        s.insert(nums[i]);
    }
    if (size <= s.size()) {
        return size;
    }
    else {
        return s.size();
    }

    return answer;
}
int main()
{
    cout << solution({ 3,1,2,3 }) << endl;
}