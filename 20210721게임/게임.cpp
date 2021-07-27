#include <iostream>
#include <vector>

using namespace std;

int main()
{

	long long x, y;
	cin >> x >> y;
	long long target = 100 * y / x;
	
	long long start = 0;
	long long end = x;
	long long answer = -1;
	long long mid = 0;
	if (target >= 99) {
		cout << -1;
	}
	else {
		while (start < end) {
			mid = (start + end) / 2;
			long long percent = (100 * (y + mid) / (x + mid));
			
			if (percent == target) {
				start = mid + 1;
			}
			else{
				end = mid;
			}
		}
		cout << end;
	}
}