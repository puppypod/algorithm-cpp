#include <iostream>
#include <vector>

using namespace std;

vector<int> minHeap;

void dfsPop(int node) {
	int left = node * 2;
	int right = node * 2 + 1;
	int mSize = minHeap.size()-1;

	if (right <= mSize) {
		// 1. ���� �ڽ��� ������ �ڽĺ��� �۴ٸ�
		if (minHeap[left] < minHeap[right]) {
			if (minHeap[node] > minHeap[left]) {
				// ���� ����
				int tmp = minHeap[node];
				minHeap[node] = minHeap[left];
				minHeap[left] = tmp;
				dfsPop(left);
			}
		}

		// 2. ������ �ڽ��� �� �۴ٸ�
		else {
			if (minHeap[node] > minHeap[right]) {
				// ���� ����
				int tmp = minHeap[node];
				minHeap[node] = minHeap[right];
				minHeap[right] = tmp;
				dfsPop(right);
			}
		}
	}
	else if(left <= mSize){
		if (minHeap[node] > minHeap[left]) {
			// ���� ����
			int tmp = minHeap[node];
			minHeap[node] = minHeap[left];
			minHeap[left] = tmp;
		}
	}
}
void dfsPush(int node) {
	int pIdx = node / 2;

	if (pIdx == 0) return;

	// 1. �θ� �ڽź��� �� ũ�ٸ�
	if (minHeap[pIdx] > minHeap[node]) {
		// ���� ����
		int tmp = minHeap[pIdx];
		minHeap[pIdx] = minHeap[node];
		minHeap[node] = tmp;
		dfsPush(pIdx);
	}
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	// �ǹ� ���� ��
	minHeap.push_back(0);
	
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		if (num != 0) {
			minHeap.push_back(num);
			dfsPush(minHeap.size() - 1);
		}
		else {
			if (minHeap.size() == 1) {
				cout << 0 << '\n';
				continue;
			}

			cout << minHeap[1] << '\n';
			// �ּ��� �˰��� ����
			minHeap[1] = minHeap[minHeap.size() - 1];
			minHeap.pop_back();
			dfsPop(1);
		}
	}
}