#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int h, w;
	cin >> h >> w;
	vector<int> map(w);
	vector<int> left;
	vector<int> right;
	for (int i = 0; i < w; i++) {
		cin >> map[i];
	}
	int left_max;
	int right_max;
	int min_number;
	int sum = 0;
	for (int j = 0; j < 1; j++) {
		left.push_back(map[j]);
	}
	for (int j = 2; j < w; j++) {
		right.push_back(map[j]);
	}

	for (int i = 1; i < w - 1; i++) {
		left_max = -1;
		right_max = -1;
		
		left_max = *max_element(left.begin(), left.end());
		
		right_max = *max_element(right.begin(), right.end());
	
		min_number = min(left_max, right_max);
		
		if (min_number - map[i] > 0) {
			sum += min_number - map[i];
		}

		left.push_back(map[i]);
		right.erase(right.begin(), right.begin()+1);
	}
	cout << sum << endl;
}