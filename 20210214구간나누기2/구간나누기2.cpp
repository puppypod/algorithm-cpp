#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;

int getMinMaxGap(vector<int>& k)
{
	int min_num = *min_element(k.begin(), k.end());
	int max_num = *max_element(k.begin(), k.end());
	return max_num - min_num;
}

bool calc(vector<int>& cpy, int mid)
{
	vector<int> tmp_list;
	int cnt = 1; // 구간 최솟값
	int dif;
	for (int i = 0; i < n; i++) {
		tmp_list.push_back(cpy[i]);
		dif = getMinMaxGap(tmp_list);
		if (mid < dif) {
			cnt++;
			tmp_list.clear();
			tmp_list.push_back(cpy[i]);
			if (cnt > m) { break; }
		}
	}
	return cnt <= m;
}

int main()
{
	cin >> n >> m;
	vector<int> nList(n);
	for (int i = 0; i < n; i++) {
		cin >> nList[i];
	}

	int left = 0;
	int right = *max_element(nList.begin(), nList.end());
	int result = right; // 가능한의 최댓값
	int mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (calc(nList, mid)) {
			if (result > mid) {
				result = mid;
			}
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << result << endl;
}